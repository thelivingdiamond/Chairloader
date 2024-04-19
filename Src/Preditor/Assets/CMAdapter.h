#pragma once
#include <Manager/IChairManager.h>

//! Helper functions to implement IChairManager in Preditor.
namespace Assets::CMAdapter
{

//! Converts severity level into ChairLogger log type.
::EChairLogType ConvertLogType(::severityLevel level);

//! IChairManager::LogString implementation using CryLog.
void LogString(severityLevel level, std::string_view str);

} // namespace Assets::CMAdapter
