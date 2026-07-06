// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkDynamicCalledMimicManager
// Header:  Prey/GameDll/ark/npc/ArkDynamicCalledMimicManager.h
class ArkDynamicCalledMimicManager
{ // Size=72 (0x48)
public:
	bool m_bCheckMimics;
	int m_maxNumSummonedMimicsPerLevel;
	std::unordered_map<string, std::vector<unsigned int>> m_levelNameToDynamicMimicIds;

	ArkDynamicCalledMimicManager();
	~ArkDynamicCalledMimicManager();
	void AddMimicToManager(unsigned _mimicIdToAdd) { FAddMimicToManager(this, _mimicIdToAdd); }
	void Update() { FUpdate(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	uint64_t GetNumAvailableMimics() const { return FGetNumAvailableMimics(this); }

#if 0
	void LoadConfig();
#endif

	static inline auto FArkDynamicCalledMimicManagerOv1 = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x127DA10);
	static inline auto FBitNotArkDynamicCalledMimicManager = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x127DB90);
	static inline auto FAddMimicToManager = PreyFunction<void(ArkDynamicCalledMimicManager* const _this, unsigned _mimicIdToAdd)>(0x127DD70);
	static inline auto FUpdate = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x127E070);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x1333E90);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x1333E90);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x127E040);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x118B2D0);
	static inline auto FReset = PreyFunction<void(ArkDynamicCalledMimicManager* const _this, bool _bEnteringGameMode)>(0x1333E90);
	static inline auto FSerialize = PreyFunction<void(ArkDynamicCalledMimicManager* const _this, TSerialize _ser)>(0x127E050);
	static inline auto FPostSerialize = PreyFunction<void(ArkDynamicCalledMimicManager* const _this)>(0x127E040);
	static inline auto FGetNumAvailableMimics = PreyFunction<uint64_t(const ArkDynamicCalledMimicManager* const _this)>(0x127DE80);
};
#endif // MOONCRASH
