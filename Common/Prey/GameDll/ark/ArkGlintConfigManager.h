// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/iface/IArkGlintConfigManager.h>

struct ArkGlintConfig;

// Header: FromCpp
// Prey/GameDll/ark/ArkGlintConfigManager.h
class ArkGlintConfigManager : public IArkGlintConfigManager // Id=8015389 Size=72
{
public:
	std::unordered_map<unsigned __int64,std::unique_ptr<ArkGlintConfig>> m_configs;
	
	ArkGlintConfigManager();
	~ArkGlintConfigManager();
	virtual ArkGlintConfig const *ConfigFromId(uint64_t _id) const;
	void Initialize() { FInitialize(this); }
	void LoadFromDisk() { FLoadFromDisk(this); }
	
	static inline auto FBitNotArkGlintConfigManager = PreyFunction<void(ArkGlintConfigManager *const _this)>(0x117C240);
	static inline auto FConfigFromId = PreyFunction<ArkGlintConfig const *(ArkGlintConfigManager const *const _this, uint64_t _id)>(0x117C270);
	static inline auto FInitialize = PreyFunction<void(ArkGlintConfigManager *const _this)>(0x117C370);
	static inline auto FLoadFromDisk = PreyFunction<void(ArkGlintConfigManager *const _this)>(0x117C380);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/iface/IArkGlintConfigManager.h>

struct ArkGlintConfig;

// ArkGlintConfigManager
// Header:  Prey/GameDll/ark/ArkGlintConfigManager.h
class ArkGlintConfigManager : public IArkGlintConfigManager
{ // Size=72 (0x48)
public:
	std::unordered_map<uint64_t, std::unique_ptr<ArkGlintConfig>> m_configs;

	ArkGlintConfigManager();
	~ArkGlintConfigManager();
	virtual const ArkGlintConfig* ConfigFromId(uint64_t _id) const;
	void Initialize() { FInitialize(this); }
	void LoadFromDisk() { FLoadFromDisk(this); }

	static inline auto FArkGlintConfigManagerOv1 = PreyFunction<void(ArkGlintConfigManager* const _this)>(0x11F74A0);
	static inline auto FBitNotArkGlintConfigManager = PreyFunction<void(ArkGlintConfigManager* const _this)>(0x11F7590);
	static inline auto FConfigFromId = PreyFunction<const ArkGlintConfig* (const ArkGlintConfigManager* const _this, uint64_t _id)>(0x11F75C0);
	static inline auto FInitialize = PreyFunction<void(ArkGlintConfigManager* const _this)>(0x11F76C0);
	static inline auto FLoadFromDisk = PreyFunction<void(ArkGlintConfigManager* const _this)>(0x11F76D0);
};
#endif // !MOONCRASH
