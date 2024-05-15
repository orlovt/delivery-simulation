#ifndef DRONELOGGER_H_
#define DRONELOGGER_H_

#include <ILogger.h>

#include <ctime>

/**
 *@brief Class representing a drone logger which can log to the console and to a
 *file
 **/
class DroneLogger : public ILogger {
 public:
  /**
   * @brief Parameter constructor
   * @param filepath the filepath to the csv file the dronelogger will log to
   */
  DroneLogger(const std::string& filepath, const std::string& csvfileheader);
  /**
   * @brief Destructor to close the logFile
   */
  ~DroneLogger();
  /**
   * @brief Logs messages with log levels and timestamps
   * @param level logging level to display before the message
   * @param message message to log
   */
  void log(const LogLevel level, const IEntity& entity);
};

#endif
