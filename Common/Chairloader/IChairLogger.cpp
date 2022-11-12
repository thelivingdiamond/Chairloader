#include <Chairloader/IChairLogger.h>

static void CryLogf(EChairLogType type, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	gEnv->pLog->LogV((ILog::ELogType)type, format, args);
	va_end(args);
}

void VCryLog(EChairLogType type, std::string_view format, fmt::format_args args)
{
	std::string text = fmt::vformat(format, args);
	CryLogf(type, "%s", text.c_str());
}

void VCryFatalError(std::string_view format, fmt::format_args args)
{
	std::string text = fmt::vformat(format, args);
	gEnv->pSystem->FatalError("%s", text.c_str());
}
