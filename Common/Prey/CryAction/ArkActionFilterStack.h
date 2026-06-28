// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/IActionFilterStack.h>

struct IActionFilter;

// ArkActionFilterStack
// Header:  CryEngine/cryaction/ArkActionFilterStack.h
class ArkActionFilterStack : public IActionFilterStack
{ // Size=32 (0x20)
public:
	using TActionFilterList = std::vector<IActionFilter*>;
	using TActionFilterStack = std::vector<std::vector<IActionFilter*>>;

	std::vector<std::vector<IActionFilter*>> m_FilterStack;

	virtual void PushFrame();
	virtual void PopFrame();

	static inline auto FPushFrame = PreyFunction<void(ArkActionFilterStack* const _this)>(0x2BB050);
	static inline auto FPopFrame = PreyFunction<void(ArkActionFilterStack* const _this)>(0x2BAF10);
};
#endif // !MOONCRASH
