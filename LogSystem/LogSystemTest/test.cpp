#include "pch.h"
#include "../LogSystem/encoder.h"
#include <chrono>
#include <filesystem>
#include <string>

auto cwd = std::filesystem::path{ std::filesystem::current_path() }.string();

static Logger setUp() {
	Logger initialLogger = Logger(cwd, "testLog");
	return initialLogger;
}

static void tearDown() {
	for (const auto& entry : std::filesystem::directory_iterator(cwd)) {
		if (entry.path().string().find(".tilo") != std::string::npos)
			std::filesystem::remove(entry.path());
	}
}

TEST(EncoderTest, CreatesFile) {
	Logger logger = setUp();

	ASSERT_TRUE(std::filesystem::exists(cwd + "/latest_testLog.tilo"));

	tearDown();
}

TEST(EncoderTest, RenamesFile) {
	Logger logger = setUp();

	Logger newLogger = Logger(cwd, "testLog");
	int count = 0;

	for (const auto& entry : std::filesystem::directory_iterator(cwd)) {
		if (entry.path().string().find(".tilo") != std::string::npos)
			count++;
	}

	ASSERT_EQ(2, count);

	tearDown();
}

TEST(EncoderTest, LogsandWritesMessage) {
	Logger logger = setUp();

	logger.log(LogLevel::DEBUG, "TEST");
	logger.writeLog();

	std::ifstream file(cwd + "/latest_testLog.tilo", std::ios::binary);
	char bytes[7] = {};
	
	file.read((char *) &bytes, 6 * sizeof(char));

	for (char byte : bytes) {
		std::cout << std::hex << (int) byte << std::endl;
	}
}