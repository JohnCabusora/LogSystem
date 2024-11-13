#include "pch.h"
#include "encoder.h"

class Logger {
private:
	std::ofstream logFile;
	std::vector<std::string> logStrings{};
public:
	Logger(std::string logPath, std::string logName) {
		logFile << new std::ofstream(logPath + "/" + logName);
	}

	void log(Logger logger, LogLevel severity, std::string msg) {
		std::string logLine = logLevelArray.at(severity) + "\t" + msg;
	}
};
