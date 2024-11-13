#pragma once
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <array>

const std::unordered_map<std::string, std::byte> logTypeMap = {
	{"[TRACE]", std::byte{0xfa}},
	{"[DEBUG]", std::byte{0xfb}},
	{"[INFO]", std::byte{0xfc}},
	{"[WARN]", std::byte{0xfd}},
	{"[ERROR]", std::byte{0xfe}},
	{"[FATAL]", std::byte{0xff}}
};

const std::unordered_map<char, std::byte> charMap = {
	{' ', std::byte{0x00}},
	{'a', std::byte{0x01}},
	{'b', std::byte{0x02}},
	{'c', std::byte{0x03}},
	{'d', std::byte{0x04}},
	{'e', std::byte{0x05}},
	{'f', std::byte{0x06}},
	{'g', std::byte{0x07}},
	{'h', std::byte{0x08}},
	{'i', std::byte{0x09}},
	{'j', std::byte{0x0a}},
	{'k', std::byte{0x0b}},
	{'l', std::byte{0x0c}},
	{'m', std::byte{0x0d}},
	{'n', std::byte{0x0f}},
	{'o', std::byte{0x10}},
	{'p', std::byte{0x11}},
	{'q', std::byte{0x12}},
	{'r', std::byte{0x13}},
	{'s', std::byte{0x14}},
	{'t', std::byte{0x15}},
	{'u', std::byte{0x16}},
	{'v', std::byte{0x17}},
	{'w', std::byte{0x18}},
	{'x', std::byte{0x19}},
	{'y', std::byte{0x1a}},
	{'z', std::byte{0x1b}},
	{'A', std::byte{0x1c}},
	{'B', std::byte{0x1d}},
	{'C', std::byte{0x1e}},
	{'D', std::byte{0x1f}},
	{'E', std::byte{0x20}},
	{'F', std::byte{0x21}},
	{'G', std::byte{0x22}},
	{'H', std::byte{0x23}},
	{'I', std::byte{0x24}},
	{'J', std::byte{0x25}},
	{'K', std::byte{0x26}},
	{'L', std::byte{0x27}},
	{'M', std::byte{0x28}},
	{'N', std::byte{0x29}},
	{'O', std::byte{0x2a}},
	{'P', std::byte{0x2b}},
	{'Q', std::byte{0x2c}},
	{'R', std::byte{0x2d}},
	{'S', std::byte{0x2e}},
	{'T', std::byte{0x2f}},
	{'U', std::byte{0x30}},
	{'V', std::byte{0x31}},
	{'W', std::byte{0x32}},
	{'X', std::byte{0x33}},
	{'Y', std::byte{0x34}},
	{'Z', std::byte{0x35}},
	{'0', std::byte{0x36}},
	{'1', std::byte{0x37}},
	{'2', std::byte{0x38}},
	{'3', std::byte{0x39}},
	{'4', std::byte{0x3a}},
	{'5', std::byte{0x3b}},
	{'6', std::byte{0x3c}},
	{'7', std::byte{0x3d}},
	{'8', std::byte{0x3e}},
	{'9', std::byte{0x3f}},
	{'!', std::byte{0x40}},
	{'@', std::byte{0x41}},
	{'#', std::byte{0x42}},
	{'$', std::byte{0x43}},
	{'%', std::byte{0x44}},
	{'^', std::byte{0x45}},
	{'&', std::byte{0x46}},
	{'*', std::byte{0x47}},
	{'(', std::byte{0x48}},
	{')', std::byte{0x49}},
	{'`', std::byte{0x4a}},
	{'~', std::byte{0x4b}},
	{'-', std::byte{0x4c}},
	{'_', std::byte{0x4d}},
	{'=', std::byte{0x4e}},
	{'+', std::byte{0x4f}},
	{'[', std::byte{0x50}},
	{']', std::byte{0x51}},
	{'{', std::byte{0x52}},
	{'}', std::byte{0x53}},
	{'\\', std::byte{0x54}},
	{';', std::byte{0x55}},
	{':', std::byte{0x56}},
	{'\'', std::byte{0x57}},
	{'"', std::byte{0x58}},
	{',', std::byte{0x59}},
	{'.', std::byte{0x5a}},
	{'<', std::byte{0x5b}},
	{'>', std::byte{0x5c}},
	{'/', std::byte{0x5d}},
	{'?', std::byte{0x5e}},
	{'\n', std::byte{0x5f}}
};

enum LogLevel {
	TRACE,
	DEBUG,
	INFO,
	WARN,
	ERR,
	FATAL
};

const std::array<std::string, 6> logLevelArray = {"[TRACE]", "[DEBUG]", "[INFO]", "[WARN]", "[ERROR]", "[FATAL]"};

class Logger
{
private:
	std::ofstream logFile;
	std::vector<std::string> logStrings{};
public:
	Logger(std::string logPath, std::string logName);
	static void log(Logger logger, LogLevel severity, std::string msg);
};