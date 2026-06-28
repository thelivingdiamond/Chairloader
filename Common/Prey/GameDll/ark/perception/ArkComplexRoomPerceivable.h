// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/perception/ArkComplexRoomPerceivable.h
class ArkComplexRoomPerceivable // Id=8015057 Size=8
{
public:
	unsigned GetEntityId() const { return FGetEntityId(this); }
	unsigned GetCurrentRoomEntityId() const { return FGetCurrentRoomEntityId(this); }
	bool GetIsInMimicryHidden() const { return FGetIsInMimicryHidden(this); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual unsigned DoGetCurrentRoomEntityId() const = 0;
	virtual bool DoGetIsInMimicryHidden() const = 0;
	
	static inline auto FGetEntityId = PreyFunction<unsigned(ArkComplexRoomPerceivable const *const _this)>(0x13B26F0);
	static inline auto FGetCurrentRoomEntityId = PreyFunction<unsigned(ArkComplexRoomPerceivable const *const _this)>(0x172F070);
	static inline auto FGetIsInMimicryHidden = PreyFunction<bool(ArkComplexRoomPerceivable const *const _this)>(0x15AAEA0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkComplexRoomPerceivable
// Header:  Prey/GameDll/ark/perception/ArkComplexRoomPerceivable.h
class ArkComplexRoomPerceivable
{ // Size=8 (0x8)
public:
	unsigned GetEntityId() const { return FGetEntityId(this); }
	unsigned GetCurrentRoomEntityId() const { return FGetCurrentRoomEntityId(this); }
	bool GetIsInMimicryHidden() const { return FGetIsInMimicryHidden(this); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual unsigned DoGetCurrentRoomEntityId() const = 0;
	virtual bool DoGetIsInMimicryHidden() const = 0;

#if 0
	~ArkComplexRoomPerceivable();
	ArkComplexRoomPerceivable& operator=(const ArkComplexRoomPerceivable& _arg0_);
#endif

	static inline auto FGetEntityId = PreyFunction<unsigned(const ArkComplexRoomPerceivable* const _this)>(0x14BE950);
	static inline auto FGetCurrentRoomEntityId = PreyFunction<unsigned(const ArkComplexRoomPerceivable* const _this)>(0x1855F90);
	static inline auto FGetIsInMimicryHidden = PreyFunction<bool(const ArkComplexRoomPerceivable* const _this)>(0x6CBC30);
};
#endif // !MOONCRASH
