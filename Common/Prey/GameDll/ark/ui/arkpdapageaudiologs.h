// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapageaudiologs.h
class CArkPDAPageAudioLogs : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageAudioLogs> // Id=801C9E4 Size=64
{
public:
	uint64_t m_highlightedAudioLog;
	bool m_bPlaybackQueued;
	ArkSimpleTimer m_errorTimer;
	
	CArkPDAPageAudioLogs();
	virtual ~CArkPDAPageAudioLogs();
	virtual void Update(float _frameTime);
	void OnPlaybackComplete(bool _bComplete) { FOnPlaybackComplete(this,_bComplete); }
	void MarkAsListened(uint64_t _audioLogId) { FMarkAsListened(this,_audioLogId); }
	virtual void Open();
	virtual void Close();
	virtual void Refresh() const;
	virtual void SetupInputPrompts();
	virtual bool ManagesInputPrompts() const;
	void UpdateInputPrompts(const bool _bUpdateUI) const { FUpdateInputPrompts(this,_bUpdateUI); }
	void OnStartPlayback(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnStartPlayback(this,_pSender,_event,_args); }
	void OnShowAudioLog(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnShowAudioLog(this,_pSender,_event,_args); }
	
#if 0
	static ArkPDAPage GetPDAPage();
	bool IsAudioLogQueued() const;
#endif
	
	static inline auto FUpdate = PreyFunction<void(CArkPDAPageAudioLogs *const _this, float _frameTime)>(0x1619AB0);
	static inline auto FOnPlaybackComplete = PreyFunction<void(CArkPDAPageAudioLogs *const _this, bool _bComplete)>(0x16186A0);
	static inline auto FMarkAsListened = PreyFunction<void(CArkPDAPageAudioLogs *const _this, uint64_t _audioLogId)>(0x16184E0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageAudioLogs *const _this)>(0x1618FB0);
	static inline auto FClose = PreyFunction<void(CArkPDAPageAudioLogs *const _this)>(0x1618460);
	static inline auto FRefresh = PreyFunction<void(CArkPDAPageAudioLogs const *const _this)>(0x1619010);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageAudioLogs *const _this)>(0x16199A0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageAudioLogs const *const _this)>(0x1B933B0);
	static inline auto FUpdateInputPrompts = PreyFunction<void(CArkPDAPageAudioLogs const *const _this, const bool _bUpdateUI)>(0x1619B10);
	static inline auto FOnStartPlayback = PreyFunction<void(CArkPDAPageAudioLogs *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1618C00);
	static inline auto FOnShowAudioLog = PreyFunction<void(CArkPDAPageAudioLogs *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x16186B0);
};

