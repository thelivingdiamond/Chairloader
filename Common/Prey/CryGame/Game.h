#pragma once
#include <ChairLoader/PreyFunction.h>

struct IGameFramework;

class CGame
{
public:
	static inline auto FInit = PreyFunction<bool(CGame* _this, IGameFramework* pFramework)>(0x16D0A90);
	static inline auto FUpdate = PreyFunction<int(CGame* _this, bool haveFocus, unsigned int updateFlags)>(0x16D6230);
	static inline auto FShutdown = PreyFunction<void(CGame* _this)>(0x16D6150);
};
