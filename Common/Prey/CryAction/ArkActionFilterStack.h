// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionFilterStack.h>

// Header: FromCpp
// CryEngine/cryaction/ArkActionFilterStack.h
class ArkActionFilterStack : public IActionFilterStack // Id=80045B8 Size=32
{
public:
	using TActionFilterList = std::vector<IActionFilter *>;
	using TActionFilterStack = std::vector<std::vector<IActionFilter *>>;
	
	std::vector<std::vector<IActionFilter *>> m_FilterStack;
	
	virtual void PushFrame();
	virtual void PopFrame();
	
	static inline auto FPushFrame = PreyFunction<void(ArkActionFilterStack *const _this)>(0x2A2AE0);
	static inline auto FPopFrame = PreyFunction<void(ArkActionFilterStack *const _this)>(0x2A29A0);
};

