// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPlayableCharacter.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/XML/IXml.h>

struct ArkDamageInfo;
class ArkPlayableCharacter;
class ArkPlayerDeathSummarizer;
struct IConsoleCmdArgs;

// ArkPlayableCharacterManager
// Header:  Prey/GameDll/ark/ArkPlayableCharacterManager.h
class ArkPlayableCharacterManager
{ // Size=264 (0x108)
public:
	// ArkPlayableCharacterManager::SDeathInfo
	// Header:  Prey/GameDll/ark/ArkPlayableCharacterManager.h
	struct SDeathInfo
	{ // Size=16 (0x10)
		uint64_t m_reason;
		uint64_t m_location;

	#if 0
		SDeathInfo();
		SDeathInfo(const uint64_t _arg0_, const uint64_t _arg1_);
		void Serialize(TSerialize _arg0_);
	#endif
	};

	std::vector<uint64_t> m_unlockedCharacters;
	std::unordered_map<uint64_t, ArkPlayableCharacterManager::SDeathInfo> m_deadCharacters;
	std::unordered_map<uint64_t, uint64_t> m_escapedCharacters;
	uint64_t m_currentPlayableCharacter;
	uint64_t m_lastSimRunCharacter;
	uint64_t m_lastSimRunDeathReason;
	unsigned m_statModHandle;
	unsigned m_lastCorpse;
	std::unordered_map<uint64_t, std::vector<uint64_t>> m_backupAbilities;
	XmlNodeRef m_metaInfo;
	std::unique_ptr<ArkPlayerDeathSummarizer> m_pDeathSummarizer;

	ArkPlayableCharacterManager();
	~ArkPlayableCharacterManager();
	void Init() { FInit(this); }
	void CompleteInit() { FCompleteInit(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Reset() { FReset(this); }
	const ArkPlayableCharacter* GetCurrentPlayableCharacter() const { return FGetCurrentPlayableCharacter(this); }
	void SetPlayableCharacter(uint64_t _character) { FSetPlayableCharacter(this, _character); }
	void OnEndSimulationRun() { FOnEndSimulationRun(this); }
	void SwitchToMetaCharacter() { FSwitchToMetaCharacter(this); }
	void CreateCorpse() { FCreateCorpse(this); }
	bool IsMetaCharacter() const { return FIsMetaCharacterOv1(this); }
	static bool IsMetaCharacter(uint64_t _characterId) { return FIsMetaCharacterOv0(_characterId); }
	static bool IsHiddenCharacter(uint64_t _characterId) { return FIsHiddenCharacter(_characterId); }
	bool KillAvailableCharacter(const uint64_t _character) { return FKillAvailableCharacter(this, _character); }
	void MarkCurrentCharacterAsDead(const ArkDamageInfo& _damageInfo) { FMarkCurrentCharacterAsDead(this, _damageInfo); }
	void ResetSimulation() { FResetSimulation(this); }
	bool IsCharacterDead(uint64_t _character) const { return FIsCharacterDead(this, _character); }
	boost::optional<ArkPlayableCharacterManager::SDeathInfo> GetCharacterDeathSummary(const uint64_t _characterId) const { alignas(boost::optional<ArkPlayableCharacterManager::SDeathInfo>) std::byte _return_buf_[sizeof(boost::optional<ArkPlayableCharacterManager::SDeathInfo>)]; return *FGetCharacterDeathSummary(this, reinterpret_cast<boost::optional<ArkPlayableCharacterManager::SDeathInfo>*>(_return_buf_), _characterId); }
	bool HasDeadCharacters() const { return FHasDeadCharacters(this); }
	bool HasEscapedCharacters() const { return FHasEscapedCharacters(this); }
	void UnlockCharacter(uint64_t _character) { FUnlockCharacter(this, _character); }
	bool IsCharacterUnlocked(uint64_t _character) const { return FIsCharacterUnlocked(this, _character); }
	unsigned GetNumUnlockedCharacters() const { return FGetNumUnlockedCharacters(this); }
	unsigned GetNumUnlockedCharactersForStat() const { return FGetNumUnlockedCharactersForStat(this); }
	void CharacterEscaped(uint64_t _character, const char* const _method) { FCharacterEscaped(this, _character, _method); }
	bool HasCharacterEscaped(uint64_t _character) const { return FHasCharacterEscaped(this, _character); }
	uint64_t GetCharacterEscapeMethod(uint64_t _character) const { return FGetCharacterEscapeMethod(this, _character); }
	bool IsCharacterAvailable(uint64_t _character) const { return FIsCharacterAvailable(this, _character); }
	bool HasAvailableCharacters() const { return FHasAvailableCharacters(this); }
	bool HasSkeletonKey() const { return FHasSkeletonKey(this); }
	std::vector<ArkStartingItem> GetStartingItemsForCharacter(uint64_t _character) const { alignas(std::vector<ArkStartingItem>) std::byte _return_buf_[sizeof(std::vector<ArkStartingItem>)]; return *FGetStartingItemsForCharacter(this, reinterpret_cast<std::vector<ArkStartingItem>*>(_return_buf_), _character); }
	const std::vector<uint64_t>* GetCharacterAbilities(uint64_t _character) const { return FGetCharacterAbilities(this, _character); }
	bool RestoreCharacter() { return FRestoreCharacter(this); }
	void UpdateUnlockStat(uint64_t _characterId) const { FUpdateUnlockStat(this, _characterId); }
	static void CmdUnlockAllCharacters(IConsoleCmdArgs* _pArgs) { FCmdUnlockAllCharacters(_pArgs); }

#if 0
	uint64_t GetCurrentPlayableCharacterId() const;
	uint64_t GetLastSimRunCharacter() const;
	uint64_t GetLastSimRunDeathReason() const;
	unsigned GetLastCorpse() const;
	void GrantAdditionalAbilities(uint64_t _arg0_, const std::vector<uint64_t>& _arg1_);
	void BackupCurrentCharacter();
	void ClearStateForCharacterChange();
	bool CharacterCountsForUnlockStat(uint64_t _arg0_) const;
#endif

	static inline auto FArkPlayableCharacterManager = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C5430);
	static inline auto FBitNotArkPlayableCharacterManager = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C55E0);
	static inline auto FInit = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C6540);
	static inline auto FCompleteInit = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C5C10);
	static inline auto FSerialize = PreyFunction<void(ArkPlayableCharacterManager* const _this, TSerialize _ser)>(0x11C72B0);
	static inline auto FReset = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C6AF0);
	static inline auto FGetCurrentPlayableCharacter = PreyFunction<const ArkPlayableCharacter* (const ArkPlayableCharacterManager* const _this)>(0x11C61D0);
	static inline auto FSetPlayableCharacter = PreyFunction<void(ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C7440);
	static inline auto FOnEndSimulationRun = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C68C0);
	static inline auto FSwitchToMetaCharacter = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C75F0);
	static inline auto FCreateCorpse = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C5C20);
	static inline auto FIsMetaCharacterOv1 = PreyFunction<bool(const ArkPlayableCharacterManager* const _this)>(0x11C6730);
	static inline auto FIsMetaCharacterOv0 = PreyFunction<bool(uint64_t _characterId)>(0x11C6750);
	static inline auto FIsHiddenCharacter = PreyFunction<bool(uint64_t _characterId)>(0x11C6710);
	static inline auto FKillAvailableCharacter = PreyFunction<bool(ArkPlayableCharacterManager* const _this, const uint64_t _character)>(0x11C6770);
	static inline auto FMarkCurrentCharacterAsDead = PreyFunction<void(ArkPlayableCharacterManager* const _this, const ArkDamageInfo& _damageInfo)>(0x11C6840);
	static inline auto FResetSimulation = PreyFunction<void(ArkPlayableCharacterManager* const _this)>(0x11C6FF0);
	static inline auto FIsCharacterDead = PreyFunction<bool(const ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C6670);
	static inline auto FGetCharacterDeathSummary = PreyFunction<boost::optional<ArkPlayableCharacterManager::SDeathInfo>*(const ArkPlayableCharacterManager* const _this, boost::optional<ArkPlayableCharacterManager::SDeathInfo>* _return_value_, const uint64_t _characterId)>(0x11C6140);
	static inline auto FHasDeadCharacters = PreyFunction<bool(const ArkPlayableCharacterManager* const _this)>(0x11C64D0);
	static inline auto FHasEscapedCharacters = PreyFunction<bool(const ArkPlayableCharacterManager* const _this)>(0x11C64E0);
	static inline auto FUnlockCharacter = PreyFunction<void(ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C7600);
	static inline auto FIsCharacterUnlocked = PreyFunction<bool(const ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C66A0);
	static inline auto FGetNumUnlockedCharacters = PreyFunction<unsigned(const ArkPlayableCharacterManager* const _this)>(0x11C6200);
	static inline auto FGetNumUnlockedCharactersForStat = PreyFunction<unsigned(const ArkPlayableCharacterManager* const _this)>(0x11C6210);
	static inline auto FCharacterEscaped = PreyFunction<void(ArkPlayableCharacterManager* const _this, uint64_t _character, const char* const _method)>(0x11C59A0);
	static inline auto FHasCharacterEscaped = PreyFunction<bool(const ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C64A0);
	static inline auto FGetCharacterEscapeMethod = PreyFunction<uint64_t(const ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C6190);
	static inline auto FIsCharacterAvailable = PreyFunction<bool(const ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C65C0);
	static inline auto FHasAvailableCharacters = PreyFunction<bool(const ArkPlayableCharacterManager* const _this)>(0x11C6400);
	static inline auto FHasSkeletonKey = PreyFunction<bool(const ArkPlayableCharacterManager* const _this)>(0x11C64F0);
	static inline auto FGetStartingItemsForCharacter = PreyFunction<std::vector<ArkStartingItem>*(const ArkPlayableCharacterManager* const _this, std::vector<ArkStartingItem>* _return_value_, uint64_t _character)>(0x11C6290);
	static inline auto FGetCharacterAbilities = PreyFunction<const std::vector<uint64_t>* (const ArkPlayableCharacterManager* const _this, uint64_t _character)>(0x11C6030);
	static inline auto FRestoreCharacter = PreyFunction<bool(ArkPlayableCharacterManager* const _this)>(0x11C70A0);
	static inline auto FUpdateUnlockStat = PreyFunction<void(const ArkPlayableCharacterManager* const _this, uint64_t _characterId)>(0x11C7720);
	static inline auto FCmdUnlockAllCharacters = PreyFunction<void(IConsoleCmdArgs* _pArgs)>(0x11C5B80);
};
#endif // MOONCRASH
