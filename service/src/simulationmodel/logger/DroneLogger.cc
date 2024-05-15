#include <DroneLogger.h>

DroneLogger::~DroneLogger() {
  if (logFile_.is_open()) {
    logFile_.close();
  }
}

DroneLogger::DroneLogger(const std::string& filepath,
                         const std::string& csvfileheader) {
  logFile_.open(filepath, std::ios::out | std::ios::app);
  if (!logFile_.is_open()) {
    std::cerr << "Error opening log file for drones!" << std::endl;
  }

  logFile_ << csvfileheader << std::endl;
}

void DroneLogger::log(const LogLevel level, const IEntity& entity) {
  std::string type = entity.getDetails()["type"];
  if (type.compare("drone") == 0) {
    // Get current timestamp
    std::time_t now = std::time(nullptr);
    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S",
                  std::localtime(&now));

    // Log to console
    std::cout << "[" << logLevelToString(level) << "] [" << timestamp << "] "
              << entity.tocsv() << std::endl;

    // Log to file
    if (logFile_.is_open()) {
      logFile_ << logLevelToString(level) << "," << timestamp << ","
               << entity.tocsv() << std::endl;
    }
  }
}
