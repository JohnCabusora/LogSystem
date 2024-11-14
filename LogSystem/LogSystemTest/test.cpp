#include "pch.h"
#include "../LogSystem/encoder.h"
#include <chrono>
#include <filesystem>
#include <string>

TEST(EncoderTest, CreatesFile) {
	auto cwd = std::filesystem::path{ std::filesystem::current_path()}.string();
	Logger initialLogger = Logger(cwd, "testLog");

	ASSERT_TRUE(std::filesystem::exists(cwd + "/latest_testLog.tilo"));
}