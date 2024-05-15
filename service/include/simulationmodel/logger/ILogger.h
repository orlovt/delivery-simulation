#ifndef ILOGGER_H_
#define ILOGGER_H_

#include <IEntity.h>
#include <LogLevel.h>

#include <fstream>
#include <iostream>
#include <string>

/**
 *@brief ILogger abstract class for polymorphic decoupled loggers
 **/
class ILogger {
 public:
  /**
   * @brief defines contract of behavior for logging
   * @param level level of the log to display before message
   * @param message message to log
   */
  virtual void log(const LogLevel level, const IEntity& entity) = 0;

 protected:
  std::ofstream logFile_;
  /**
   * @brief Converts a level from the LogLevel enum into a string
   * @param level to be converted into string
   * @return std::string representing the level
   */
  std::string logLevelToString(const LogLevel level);
};

#endif
