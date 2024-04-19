#include "CMAdapter.h"

::EChairLogType Assets::CMAdapter::ConvertLogType(::severityLevel level)
{
    switch (level)
    {
    case severityLevel::trace:
    case severityLevel::debug:
    case severityLevel::info:
        return EChairLogType::Message;
    case severityLevel::warning:
        return EChairLogType::Warning;
    case severityLevel::error:
    case severityLevel::fatal:
    default:
        return EChairLogType::Error;
    }
}

void Assets::CMAdapter::LogString(severityLevel level, std::string_view str)
{
    EChairLogType type = ConvertLogType(level);
    VCryLog(type, "{}", fmt::make_format_args(str));

    if (level == severityLevel::fatal)
        throw std::runtime_error(std::string(str));
}
