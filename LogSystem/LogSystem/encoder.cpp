#include "pch.h"
#include "encoder.h"
#include <chrono>
#include <filesystem>
#include <iostream>

Logger::Logger(std::string logPath, std::string logName) {
	struct stat buffer;
	const auto timeNow = std::chrono::system_clock::now();
	auto timeUnix = std::chrono::duration_cast<std::chrono::seconds>(timeNow.time_since_epoch()).count();

	std::string fileName = logPath + "/latest_" + logName + ".tilo";
	std::string newName = logPath + "/" + logName + "-" + std::to_string(timeUnix) + ".tilo";

	if (std::filesystem::exists(fileName)) {
		std::cout << "File exists!";
	}

	std::ofstream logFile(fileName);
	logFile.close();
}

void Logger::log(Logger logger, LogLevel severity, std::string msg) {
	std::string logLine = logLevelArray.at(severity) + "\t" + msg;
}
