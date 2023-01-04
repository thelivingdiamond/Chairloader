// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/psipower/IArkPsiPower.h>

enum class EArkPsiPowers;

// ArkPsiPowerEmpty
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerEmpty.h
class ArkPsiPowerEmpty : public IArkPsiPower
{ // Size=8 (0x8)
public:
	virtual void Cancel();
	virtual bool StartTargeting();
	virtual bool Start();
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual EArkPsiPowers GetEnum() const;
	virtual const char* GetErrorString() const;

	static inline auto FCancel = PreyFunction<void(ArkPsiPowerEmpty* const _this)>(0x1327D80);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerEmpty* const _this)>(0x1327DC0);
	static inline auto FStart = PreyFunction<bool(ArkPsiPowerEmpty* const _this)>(0xDD23F0);
	static inline auto FGetLevel = PreyFunction<int(const ArkPsiPowerEmpty* const _this)>(0xA38740);
	static inline auto FGetMaxLevel = PreyFunction<int(const ArkPsiPowerEmpty* const _this)>(0xA38740);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerEmpty* const _this)>(0x8F9B30);
	static inline auto FGetErrorString = PreyFunction<const char* (const ArkPsiPowerEmpty* const _this)>(0x158AF00);
};

