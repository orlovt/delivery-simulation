#include <CompositeLogger.h>

CompositeLogger* CompositeLogger::instance_ = nullptr;

CompositeLogger::CompositeLogger() {}

CompositeLogger::~CompositeLogger() {
  for (auto i = 0; i < loggers_.size(); i++) {
    delete loggers_[i];
  }
}

CompositeLogger* CompositeLogger::getInstance() {
  if (instance_ == nullptr) {
    instance_ = new CompositeLogger();
  }

  return instance_;
}

void CompositeLogger::addLogger(ILogger* logger) { loggers_.push_back(logger); }

void CompositeLogger::log(const LogLevel level, const IEntity& entity) {
  for (auto i = 0; i < loggers_.size(); i++) {
    loggers_.at(i)->log(level, entity);
  }
}
