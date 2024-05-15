/**
 * @file WebServer.h
 * @brief This file contains the declaration of the WebServerBase class and its derived classes.
 * It also includes JSON support classes.
 * @copyright Copyright (c) 2019 Dan Orban
 */

#ifndef WEBSERVER_H_
#define WEBSERVER_H_

#include <map>
#include <string>
#include <vector>

#include "libwebsockets.h"
#include "libwebsockets/lws-service.h"

/**
 * @brief The base class for a web server.
 */
class WebServerBase {
 public:
  /**
   * @brief Construct a new Web Server Base object.
   * @param port The port to listen on.
   * @param webDir The directory for web files.
   */
  WebServerBase(int port = 8081, const std::string& webDir = ".");
  /**
   * @brief Destroy the Web Server Base object.
   */
  virtual ~WebServerBase();

  /**
   * @brief The Session class represents a client session.
   */
  class Session {
    friend class WebServerBase;

   public:
    /**
     * @brief Construct a new Session object.
     */
    Session();
    /**
     * @brief Destroy the Session object.
     */
    virtual ~Session();
    /**
     * @brief Get the session ID.
     * @return The session ID.
     */
    virtual int getId() const { return id; }
    /**
     * @brief Receive a message from the client.
     * @param msg The message received.
     */
    virtual void receiveMessage(const std::string& msg) {}
    /**
     * @brief Send a message to the client.
     * @param msg The message to send.
     */
    virtual void sendMessage(const std::string& msg);
    /**
     * @brief Update the session state.
     */
    virtual void update() {}
    /**
     * @brief Callback for when data can be written to the session.
     */
    virtual void onWrite();

   private:
    void* state; /**< Session state. */
    int id;     /**< Session ID. */
  };

  /**
   * @brief Service the server.
   * @param time The time to service for (in milliseconds).
   */
  void service(int time = 10);

  /**
   * @brief Create a new session.
   * @param info Information about the session.
   */
  virtual void createSession(void* info);

 protected:
  /**
   * @brief Create a new session.
   * @return A pointer to the newly created session.
   */
  virtual Session* createSession() { return new Session(); }

 public:
  lws_context* context = nullptr; /**< libwebsocket context. */
  std::vector<Session*> sessions; /**< Vector of active sessions. */
  std::map<int, Session*> sessionMap; /**< Map of session IDs to sessions. */
  std::string webDir; /**< Web directory. */
};

/**
 * @brief Template class for a web server.
 * @tparam T The type of session to create.
 */
template <typename T>
class WebServer : public WebServerBase {
 public:
  /**
   * @brief Construct a new WebServer object.
   * @param port The port to listen on.
   * @param webDir The directory for web files.
   */
  WebServer(int port = 8081, const std::string& webDir = ".")
      : WebServerBase(port, webDir) {}

 protected:
  /**
   * @brief Create a new session.
   * @return A pointer to the newly created session.
   */
  Session* createSession() { return new T(); }
};

/**
 * @brief Template class for a web server with state.
 * @tparam T The type of session to create.
 * @tparam STATE The type of state to associate with the server.
 */
template <typename T, typename STATE>
class WebServerWithState : public WebServerBase {
 public:
  /**
   * @brief Construct a new WebServerWithState object.
   * @param state The initial state.
   * @param port The port to listen on.
   * @param webDir The directory for web files.
   */
  WebServerWithState(STATE state, int port = 8081,
                     const std::string& webDir = ".")
      : WebServerBase(port, webDir), state(state) {}

 protected:
  /**
   * @brief Create a new session.
   * @return A pointer to the newly created session.
   */
  Session* createSession() { return new T(state); }

 private:
  STATE state; /**< The state associated with the server. */
};

// JSON support
#include "picojson.h"

/**
 * @brief Session class with JSON support.
 */
class JSONSession : public WebServerBase::Session {
 public:
  /**
   * @brief Receive a JSON message from the client.
   * @param val The received JSON value.
   */
  virtual void receiveJSON(picojson::value& val) {}
  /**
   * @brief Send a JSON message to the client.
   * @param val The JSON value to send.
   */
  virtual void sendJSON(picojson::value& val) { sendMessage(val.serialize()); }

  /**
   * @brief Receive a message from the client.
   * @param msg The message received.
   */
  void receiveMessage(const std::string& msg) {
    static std::string buf = "";
    picojson::value val;
    std::string err = picojson::parse(val, msg);
    if (err.empty() && val.is<picojson::object>()) {
      buf = "";
      receiveJSON(val);
    } else {
      buf += msg;
      err = picojson::parse(val, buf);
      if (err.empty() && val.is<picojson::object>()) {
        buf = "";
        receiveJSON(val);
      }
    }
  }
};

#include "util/json.h"

/**
 * @brief Session class for handling JSON commands.
 */
class JsonSession : public JSONSession {
 public:
  /**
   * @brief Receive a command from the web server.
   * @param val The command (in JSON format).
   */
  void receiveJSON(picojson::value& val) {
    JsonObject data = JsonValue(val);

    std::string cmd = data["command"];

    JsonObject returnValue;
    returnValue["id"] = data["id"];

    receiveCommand(cmd, data, returnValue);
    JsonValue retVal(returnValue);
    sendJSON(retVal.getValue());
  }

  /**
   * @brief Handles specific commands from the web server.
   * @param cmd The command.
   * @param data The data (JSON).
   * @param returnValue The return value (JSON) which will be sent back to the server.
   */
  virtual void receiveCommand(const std::string& cmd, const JsonObject& data,
                              JsonObject& returnValue) = 0;
};

#endif  // WEBSERVER_H_

