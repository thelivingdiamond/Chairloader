#pragma once
#include <Prey/CrySystem/ILog.h>
#include <fmt/format.h>

enum class EChairLogType
{
	Message = ILog::eAlways,
	Warning = ILog::eWarningAlways,
	Error = ILog::eErrorAlways,
};

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
inline void CryWarning(std::string_view format, const Args &...args) { VCryLog(EChairLogType::Message, format, fmt::make_format_args(args...)); }

//! CryLog but in red and with [Error] prefix.
template <typename... Args>
inline void CryError(std::string_view format, const Args &...args) { VCryLog(EChairLogType::Message, format, fmt::make_format_args(args...)); }

//! Displays error message, logs it to console and file and error message box, then terminates execution.
template <typename... Args>
inline void CryFatalError(std::string_view format, const Args &...args) { VCryFatalError(format, fmt::make_format_args(args...)); }
