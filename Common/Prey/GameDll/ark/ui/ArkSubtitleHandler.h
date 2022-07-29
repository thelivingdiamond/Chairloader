// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/ISubtitleManager.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>

struct IUIElement;

// Header: Exact
// Prey/GameDll/ark/ui/ArkSubtitleHandler.h
class ArkSubtitleHandler : public ISubtitleHandler, public IUIGameEventSystem, public IUIModule, public ISystemEventListener // Id=8019567 Size=200
{
public:
	struct ArkBinkSubtitleEntry // Id=8019568 Size=24
	{
		uint64_t m_dialogId;
		uint64_t m_voiceId;
		unsigned m_frameStart;
		unsigned m_frameEnd;
		
#if 0
		bool IsValid() const;
#endif
	};

	using TArkBinkSubtitleList = std::vector<ArkSubtitleHandler::ArkBinkSubtitleEntry>;
	
	std::unordered_map<string,std::vector<ArkSubtitleHandler::ArkBinkSubtitleEntry>,std::hash<string>,std::equal_to<string>,std::allocator<std::pair<CryStringT<char> const,std::vector<ArkSubtitleHandler::ArkBinkSubtitleEntry>>>> m_binkSubtitles;
	std::unordered_map<ArkBinkPlayerHandle,string> m_movieHandles;
	ArkBinkPlayerHandle m_activeMovieHandle;
	int m_subtitleIndex;
	int m_lastSubtitleFrame;
	string m_LastSubtitle;
	IUIElement *m_pUIElement;
	bool m_bEnabled;
	bool m_bBinkSubtitleShown;
	
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual void Init();
	virtual void UpdateModule(float _fDelta);
	virtual void Shutdown();
	virtual void ShowSubtitle(const char *_subtitleLabel, bool _bShow, const char *const _name);
	void ShowSubtitle(wstring const &_localizedSubtitle, const bool _bMetaGameMenu) const { FShowSubtitleOv0(this,_localizedSubtitle,_bMetaGameMenu); }
	virtual void SetEnabled(bool _bEnabled);
	void HideSubtitle(bool _bMetaGameMenu) const { FHideSubtitle(this,_bMetaGameMenu); }
	void SetPDAVisible(bool _bVisible) { FSetPDAVisible(this,_bVisible); }
	IUIElement *GetUIElement() const { return FGetUIElement(this); }
	virtual void OnMovieLoad(const char *const _movieName, ArkBinkPlayerHandle const &_movieHandle);
	virtual void OnMovieStart(ArkBinkPlayerHandle const &_movieHandle);
	virtual void OnMovieStop(ArkBinkPlayerHandle const &_movieHandle);
	void LoadBinkSubtitles() { FLoadBinkSubtitles(this); }
	virtual ~ArkSubtitleHandler();
	
#if 0
	static const char *GetTypeNameS();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkSubtitleHandler const *const _this)>(0x1631C60);
	static inline auto FInitEventSystem = PreyFunction<void(ArkSubtitleHandler *const _this)>(0x1631CF0);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkSubtitleHandler *const _this)>(0x16323C0);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkSubtitleHandler *const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x1632170);
	static inline auto FInit = PreyFunction<void(ArkSubtitleHandler *const _this)>(0x1631CC0);
	static inline auto FUpdateModule = PreyFunction<void(ArkSubtitleHandler *const _this, float _fDelta)>(0x1632470);
	static inline auto FShutdown = PreyFunction<void(ArkSubtitleHandler *const _this)>(0x16323B0);
	static inline auto FShowSubtitleOv1 = PreyFunction<void(ArkSubtitleHandler *const _this, const char *_subtitleLabel, bool _bShow, const char *const _name)>(0xA13080);
	static inline auto FShowSubtitleOv0 = PreyFunction<void(ArkSubtitleHandler const *const _this, wstring const &_localizedSubtitle, const bool _bMetaGameMenu)>(0x1632330);
	static inline auto FSetEnabled = PreyFunction<void(ArkSubtitleHandler *const _this, bool _bEnabled)>(0x16321A0);
	static inline auto FHideSubtitle = PreyFunction<void(ArkSubtitleHandler const *const _this, bool _bMetaGameMenu)>(0x1631C70);
	static inline auto FSetPDAVisible = PreyFunction<void(ArkSubtitleHandler *const _this, bool _bVisible)>(0x16321E0);
	static inline auto FGetUIElement = PreyFunction<IUIElement *(ArkSubtitleHandler const *const _this)>(0x155AD10);
	static inline auto FOnMovieLoad = PreyFunction<void(ArkSubtitleHandler *const _this, const char *const _movieName, ArkBinkPlayerHandle const &_movieHandle)>(0x1631F30);
	static inline auto FOnMovieStart = PreyFunction<void(ArkSubtitleHandler *const _this, ArkBinkPlayerHandle const &_movieHandle)>(0x1632080);
	static inline auto FOnMovieStop = PreyFunction<void(ArkSubtitleHandler *const _this, ArkBinkPlayerHandle const &_movieHandle)>(0x16320D0);
	static inline auto FLoadBinkSubtitles = PreyFunction<void(ArkSubtitleHandler *const _this)>(0x1631E20);
};

