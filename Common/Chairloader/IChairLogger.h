#pragma once
#include <Prey/CrySystem/ILog.h>
#include <fmt/format.h>

//! Type of the log message.
enum class EChairLogType
{
	Message,
	Warning,
	Error,
};

//! A logger used by mods. Stores all messages in a global log manager prefixed with the mod name.
//! Log messages are printed to the console and mod log window.
struct IChairLogger
{
	//! Size of the stack-allocatd buffer for the message.
	//! Larger strings will go to the heap and will be formatted twice.
	static constexpr size_t MSG_BUF_SIZE = 256;

	virtual ~IChairLogger() {}

	//! Logs the message.
	//! @param	type	Message type
	//! @param	msg		Message text
	//! @param	size	Message length
	virtual void Log(EChairLogType type, const char* msg, size_t size) = 0;

	//! Causes a fatal error with specified reason.
	//! @param	msg		Message text
	virtual void FatalError(const char* msg) = 0;

	//! @returns the name of the mod.
	virtual const char* GetName() = 0;

	//! Sets the name of the mod.
	virtual void SetName(const char* name) = 0;
};

//! Initializes logger for this module. Must be called after gCL was set.
void ModuleInitIChairLogger(const char* modName);
void ModuleShutdownIChairLogger();

//! Prints a log message to the Chairloader log and the console.
void VCryLog(EChairLogType type, std::string_view format, fmt::format_args args);

//! Crashes the game.
//! @see CryFatalError
void VCryFatalError(std::string_view format, fmt::format_args args);

//! Simple logs of data with low verbosity.
template <typename... Args>
inline void CryLog(std::string_view format, const Args &...args) { VCryLog(EChairLogType::Message, format, fmt::make_format_args(args...)); }

//! CryLog but in yellow and with [Warning] prefix. Different from Engine's CryWarning
template <typename... Args>
inline void CryWarning(std::string_view format, const Args &...args) { VCryLog(EChairLogType::Warning, format, fmt::make_format_args(args...)); }

//! CryLog but in red and with [Error] prefix.
template <typename... Args>
inline void CryError(std::string_view format, const Args &...args) { VCryLog(EChairLogType::Error, format, fmt::make_format_args(args...)); }

//! Displays error message, logs it to console and file and error message box, then terminates execution.
template <typename... Args>
inline void CryFatalError(std::string_view format, const Args &...args) { VCryFatalError(format, fmt::make_format_args(args...)); }
