#ifndef COMPOSITELOGGER_H_
#define COMPOSITELOGGER_H_

#include <ILogger.h>

#include <ctime>
#include <vector>

/**
 *@brief Class representing a logger which can log to the console and to a file
 **/
class CompositeLogger : public ILogger {
 public:
  CompositeLogger(CompositeLogger& otherLogger) = delete;
  void operator=(const CompositeLogger& otherLogger) = delete;
  /**
   * @brief Destructor to close the logFile
   */
  ~CompositeLogger();
  /**
   * @brief instantiates first instance of the logger or returns existing
   * instance.   *
   * @return Logger* pointer to the logger instance
   */
  static CompositeLogger* getInstance();
  /**
   * @brief adds a logger to the composite logger
   * @param logger logger to be added
   */
  void addLogger(ILogger* logger);
  /**
   * @brief Logs messages with log levels and timestamps
   * @param level logging level to display before the message
   * @param message message to log
   */
  void log(const LogLevel level, const IEntity& entity);

 private:
  static CompositeLogger* instance_;
  CompositeLogger();
  std::vector<ILogger*> loggers_;
};

#endif
