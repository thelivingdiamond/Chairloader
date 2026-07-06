// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/ILocalizationManager.h>

class ArkDialogPlayer;
struct ICVar;
struct SubtitleInfo;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkDialogSubtitleManager.h
class ArkDialogSubtitleManager // Id=801666F Size=168
{
public:
	using TSubtitleParts = std::vector<std::pair<unsigned int,float>>;
	
	std::unordered_map<unsigned __int64,SubtitleInfo> m_subtitles;
	std::vector<std::pair<unsigned int,float>> m_subtitleParts;
	SLocalizedInfoGame m_localizedSubtitle;
	ArkSimpleTimer m_lastSpeakerTimer;
	ArkSimpleTimer m_subtitleTimer;
	string m_lastSpeaker;
	uint64_t m_currentSubtitle;
	unsigned m_currentSubtitlePart;
	unsigned m_maxSubtitleCharacters;
	unsigned m_lookbackCharacters;
	float m_subtitleTimeout;
	ICVar *m_pDebugCvar;
	
	ArkDialogSubtitleManager();
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Reset(bool _bLoadConfig) { FReset(this,_bLoadConfig); }
	void AddSubtitle(uint64_t _conversationId, ArkDialogPlayer const &_dialogPlayer, uint64_t _dialogId, uint64_t _voiceId, const char *_pSpeakerName, bool _bMetaGameMenu, bool _bMain) { FAddSubtitle(this,_conversationId,_dialogPlayer,_dialogId,_voiceId,_pSpeakerName,_bMetaGameMenu,_bMain); }
	void RemoveSubtitle(const uint64_t _conversationId, uint64_t _dialogId) { FRemoveSubtitle(this,_conversationId,_dialogId); }
	static ArkDialogSubtitleManager &Get() { return FGet(); }
	static boost::optional<Vec3> GetListenerPos() { return FGetListenerPos(); }
	static bool GetSubtitle(const uint64_t _dialogId, const uint64_t _voiceId, SLocalizedInfoGame &_subtitleInfo) { return FGetSubtitle(_dialogId,_voiceId,_subtitleInfo); }
	void LoadConfig() { FLoadConfig(this); }
	void OnSubtitleChanged(SubtitleInfo &_subtitleInfo) { FOnSubtitleChanged(this,_subtitleInfo); }
	void ShowSubtitlePart(unsigned _subtitlePart, wstring const *_pSpeakerName, bool _bMetaGameMenu) { FShowSubtitlePart(this,_subtitlePart,_pSpeakerName,_bMetaGameMenu); }
	void SplitSubtitleText(wstring const &_subtitle, unsigned _nameLength, std::vector<std::pair<unsigned int,float>> &_parts) { FSplitSubtitleText(this,_subtitle,_nameLength,_parts); }
	
	static inline auto FUpdate = PreyFunction<void(ArkDialogSubtitleManager *const _this, float _frameTime)>(0x11B53A0);
	static inline auto FReset = PreyFunction<void(ArkDialogSubtitleManager *const _this, bool _bLoadConfig)>(0x11B4AD0);
	static inline auto FAddSubtitle = PreyFunction<void(ArkDialogSubtitleManager *const _this, uint64_t _conversationId, ArkDialogPlayer const &_dialogPlayer, uint64_t _dialogId, uint64_t _voiceId, const char *_pSpeakerName, bool _bMetaGameMenu, bool _bMain)>(0x11B4240);
	static inline auto FRemoveSubtitle = PreyFunction<void(ArkDialogSubtitleManager *const _this, const uint64_t _conversationId, uint64_t _dialogId)>(0x11B4A40);
	static inline auto FGet = PreyFunction<ArkDialogSubtitleManager &()>(0x11B4330);
	static inline auto FGetListenerPos = PreyFunction<boost::optional<Vec3>()>(0x11B4350);
	static inline auto FGetSubtitle = PreyFunction<bool(const uint64_t _dialogId, const uint64_t _voiceId, SLocalizedInfoGame &_subtitleInfo)>(0x11B44B0);
	static inline auto FLoadConfig = PreyFunction<void(ArkDialogSubtitleManager *const _this)>(0x11B45A0);
	static inline auto FOnSubtitleChanged = PreyFunction<void(ArkDialogSubtitleManager *const _this, SubtitleInfo &_subtitleInfo)>(0x11B4770);
	static inline auto FShowSubtitlePart = PreyFunction<void(ArkDialogSubtitleManager *const _this, unsigned _subtitlePart, wstring const *_pSpeakerName, bool _bMetaGameMenu)>(0x11B4BF0);
	static inline auto FSplitSubtitleText = PreyFunction<void(ArkDialogSubtitleManager *const _this, wstring const &_subtitle, unsigned _nameLength, std::vector<std::pair<unsigned int,float>> &_parts)>(0x11B4E30);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CrySystem/ILocalizationManager.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <_unknown/SubtitleInfo.h>

class ArkDialogPlayer;
struct ICVar;

// ArkDialogSubtitleManager
// Header:  Prey/GameDll/ark/dialog/ArkDialogSubtitleManager.h
class ArkDialogSubtitleManager
{ // Size=168 (0xA8)
public:
	using TSubtitleParts = std::vector<std::pair<unsigned int, float>>;

	std::unordered_map<uint64_t, SubtitleInfo> m_subtitles;
	std::vector<std::pair<unsigned int, float>> m_subtitleParts;
	SLocalizedInfoGame m_localizedSubtitle;
	ArkSimpleTimer m_lastSpeakerTimer;
	ArkSimpleTimer m_subtitleTimer;
	string m_lastSpeaker;
	uint64_t m_currentSubtitle;
	unsigned m_currentSubtitlePart;
	unsigned m_maxSubtitleCharacters;
	unsigned m_lookbackCharacters;
	float m_subtitleTimeout;
	ICVar* m_pDebugCvar;

	ArkDialogSubtitleManager();
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void Reset(bool _bLoadConfig) { FReset(this, _bLoadConfig); }
	void AddSubtitle(uint64_t _conversationId, const ArkDialogPlayer& _dialogPlayer, uint64_t _dialogId, uint64_t _voiceId, const char* _pSpeakerName, bool _bMetaGameMenu, bool _bMain) { FAddSubtitle(this, _conversationId, _dialogPlayer, _dialogId, _voiceId, _pSpeakerName, _bMetaGameMenu, _bMain); }
	void RemoveSubtitle(const uint64_t _conversationId, uint64_t _dialogId) { FRemoveSubtitle(this, _conversationId, _dialogId); }
	static ArkDialogSubtitleManager& Get() { return FGet(); }
	static boost::optional<Vec3_tpl<float> > GetListenerPos() { return FGetListenerPos(); }
	static bool GetSubtitle(const uint64_t _dialogId, const uint64_t _voiceId, SLocalizedInfoGame& _subtitleInfo) { return FGetSubtitle(_dialogId, _voiceId, _subtitleInfo); }
	void LoadConfig() { FLoadConfig(this); }
	void OnSubtitleChanged(SubtitleInfo& _subtitleInfo) { FOnSubtitleChanged(this, _subtitleInfo); }
	void ShowSubtitlePart(unsigned _subtitlePart, const wstring* _pSpeakerName, bool _bMetaGameMenu) { FShowSubtitlePart(this, _subtitlePart, _pSpeakerName, _bMetaGameMenu); }
	void SplitSubtitleText(const wstring& _subtitle, unsigned _nameLength, std::vector<std::pair<unsigned int, float>>& _parts) { FSplitSubtitleText(this, _subtitle, _nameLength, _parts); }

	static inline auto FArkDialogSubtitleManagerOv2 = PreyFunction<void(ArkDialogSubtitleManager* const _this)>(0x12318D0);
	static inline auto FUpdate = PreyFunction<void(ArkDialogSubtitleManager* const _this, float _frameTime)>(0x1232C30);
	static inline auto FReset = PreyFunction<void(ArkDialogSubtitleManager* const _this, bool _bLoadConfig)>(0x1232360);
	static inline auto FAddSubtitle = PreyFunction<void(ArkDialogSubtitleManager* const _this, uint64_t _conversationId, const ArkDialogPlayer& _dialogPlayer, uint64_t _dialogId, uint64_t _voiceId, const char* _pSpeakerName, bool _bMetaGameMenu, bool _bMain)>(0x1231AC0);
	static inline auto FRemoveSubtitle = PreyFunction<void(ArkDialogSubtitleManager* const _this, const uint64_t _conversationId, uint64_t _dialogId)>(0x12322D0);
	static inline auto FGet = PreyFunction<ArkDialogSubtitleManager& ()>(0x1231BB0);
	static inline auto FGetListenerPos = PreyFunction<boost::optional<Vec3_tpl<float> >()>(0x1231BD0);
	static inline auto FGetSubtitle = PreyFunction<bool(const uint64_t _dialogId, const uint64_t _voiceId, SLocalizedInfoGame& _subtitleInfo)>(0x1231D30);
	static inline auto FLoadConfig = PreyFunction<void(ArkDialogSubtitleManager* const _this)>(0x1231E20);
	static inline auto FOnSubtitleChanged = PreyFunction<void(ArkDialogSubtitleManager* const _this, SubtitleInfo& _subtitleInfo)>(0x1232000);
	static inline auto FShowSubtitlePart = PreyFunction<void(ArkDialogSubtitleManager* const _this, unsigned _subtitlePart, const wstring* _pSpeakerName, bool _bMetaGameMenu)>(0x1232480);
	static inline auto FSplitSubtitleText = PreyFunction<void(ArkDialogSubtitleManager* const _this, const wstring& _subtitle, unsigned _nameLength, std::vector<std::pair<unsigned int, float>>& _parts)>(0x12326C0);
};
#endif // !MOONCRASH
