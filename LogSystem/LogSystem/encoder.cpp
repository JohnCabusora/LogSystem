#include "pch.h"
#include "encoder.h"
#include <chrono>
#include <filesystem>
#include <iostream>

Logger::Logger(std::string logPath, std::string logName) {
	const auto timeNow = std::chrono::system_clock::now();
	auto timeUnix = std::chrono::duration_cast<std::chrono::seconds>(timeNow.time_since_epoch()).count();

	std::string fileName = logPath + "/latest_" + logName + ".tilo";
	std::string newName = logPath + "/" + logName + "-" + std::to_string(timeUnix) + ".tilo";

	if (std::filesystem::exists(fileName)) {
		std::filesystem::rename(fileName, newName);
	}

	std::ofstream logFile(fileName);
	logFile.close();

	logFileName = fileName;
}

void Logger::log(LogLevel severity, std::string msg) {
	std::string logLine = logLevelArray.at(severity) + "\t" + msg + "\n";
	std::vector<std::byte> logBytes;
	logBytes.push_back(logTypeMap.at(logLevelArray.at(severity)));
	for (char& ch : msg) {
		if (charMap.find(ch) != charMap.end())
			logBytes.push_back(charMap.at(ch));
	}
	logBytes.push_back(charMap.at('\n'));

	logByteLines.push_back(logBytes);

#ifdef _DEBUG
	std::cout << logLine << std::endl;
#endif
}

void Logger::writeLog() {
	for (std::vector<std::byte> line : logByteLines) {
		std::ofstream logFile;
		logFile.open(logFileName, std::ios_base::binary);
		for (std::byte byte : line) {
			logFile.write((char*) &byte, sizeof(std::byte));
		}
		logFile.close();
	}
}
