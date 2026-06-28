// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryGame/IGameRef.h>
#include <Prey/CryGame/IGameStartup.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/basiceventlistener.h>

struct IConsoleCmdArgs;
struct IGame;
struct IGameFramework;
struct SSystemInitParams;

// Header: FromCpp
// Prey/GameDll/gamestartup.h
class GameStartupErrorObserver : public IErrorObserver // Id=801CE54 Size=8
{
public:
	virtual void OnAssert(const char *condition, const char *message, const char *fileName, unsigned fileLineNumber);
	virtual void OnScriptWarning(const char *_message);
	virtual void OnFatalError(const char *message);
	virtual ~GameStartupErrorObserver();
	
	static inline auto FOnAssert = PreyFunction<void(GameStartupErrorObserver *const _this, const char *condition, const char *message, const char *fileName, unsigned fileLineNumber)>(0x173A290);
	static inline auto FOnScriptWarning = PreyFunction<void(GameStartupErrorObserver *const _this, const char *_message)>(0xA13080);
	static inline auto FOnFatalError = PreyFunction<void(GameStartupErrorObserver *const _this, const char *message)>(0x173A2F0);
};

// Header: FromCpp
// Prey/GameDll/gamestartup.h
class CGameStartup : public IGameStartup, public ISystemEventListener // Id=801CECF Size=104
{
public:
	IBasicEventListener &m_basicEventListener;
	IGame *m_pMod;
	IGameRef m_modRef;
	bool m_initWindow;
	bool m_quit;
	int8_t m_nVOIPWasActive;
	HINSTANCE *m_modDll;
	HINSTANCE *m_frameworkDll;
	string m_reqModName;
	bool m_reqModUnload;
	IGameFramework *m_pFramework;
	GameStartupErrorObserver m_errorObsever;
	bool m_bDecrementHardwareMouseOnFocusGained;
	
	virtual IGameRef Init(SSystemInitParams &startupParams);
	virtual IGameRef Reset(const char *pModName);
	virtual void Shutdown();
	virtual int Update(bool haveFocus, unsigned updateFlags);
	virtual bool GetRestartLevel(char **levelName);
	virtual const char *GetPatch() const;
	virtual bool GetRestartMod(char *pModNameBuffer, int modNameBufferSizeInBytes);
	virtual int Run(const char *autoStartLevelName);
	virtual const uint8_t *GetRSAKey(unsigned *pKeySize) const;
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	static CGameStartup *Create(IBasicEventListener &basicEventListener) { return FCreate(basicEventListener); }
	virtual ~CGameStartup();
	static int64_t WndProcHndl(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam) { return FWndProcHndl(hWnd,msg,wParam,lParam); }
	IBasicEventListener::EAction ProcessMessage(HWND *hWnd, unsigned msg, uint64_t wParam, int64_t lParam) { return FProcessMessage(this,hWnd,msg,wParam,lParam); }
	
#if 0
	bool IsModAvailable(string const &arg0);
	void HandleResizeForVOIP(uint64_t arg0);
	bool InitWindow(SSystemInitParams &arg0);
	void ShutdownWindow();
	bool InitFramework(SSystemInitParams &arg0);
	void ShutdownFramework();
	int64_t WndProc(HWND *arg0, unsigned arg1, uint64_t arg2, int64_t arg3);
#endif
	
	static inline auto FInit = PreyFunction<IGameRef(CGameStartup *const _this, SSystemInitParams &startupParams)>(0x1739A90);
	static inline auto FReset = PreyFunction<IGameRef(CGameStartup *const _this, const char *pModName)>(0x173AB80);
	static inline auto FShutdown = PreyFunction<void(CGameStartup *const _this)>(0x173B2E0);
	static inline auto FUpdate = PreyFunction<int(CGameStartup *const _this, bool haveFocus, unsigned updateFlags)>(0x173B3F0);
	static inline auto FGetRestartLevel = PreyFunction<bool(CGameStartup *const _this, char **levelName)>(0x17399D0);
	static inline auto FGetPatch = PreyFunction<const char *(CGameStartup const *const _this)>(0x158AEF0);
	static inline auto FGetRestartMod = PreyFunction<bool(CGameStartup *const _this, char *pModNameBuffer, int modNameBufferSizeInBytes)>(0x1739A20);
	static inline auto FRun = PreyFunction<int(CGameStartup *const _this, const char *autoStartLevelName)>(0x173ADB0);
	static inline auto FGetRSAKey = PreyFunction<const uint8_t *(CGameStartup const *const _this, unsigned *pKeySize)>(0x17399B0);
	static inline auto FOnSystemEvent = PreyFunction<void(CGameStartup *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x173A330);
	static inline auto FCreate = PreyFunction<CGameStartup *(IBasicEventListener &basicEventListener)>(0x1739910);
	static inline auto FWndProcHndl = PreyFunction<int64_t(HWND hWnd, unsigned msg, uint64_t wParam, int64_t lParam)>(0x173B580);
	static inline auto FProcessMessage = PreyFunction<IBasicEventListener::EAction(CGameStartup *const _this, HWND *hWnd, unsigned msg, uint64_t wParam, int64_t lParam)>(0x173A400);
};

// Header: FromCpp
// Prey/GameDll/gamestartup.h
class CCVarsWhiteList : public ICVarsWhitelist // Id=801D31C Size=8
{
public:
	virtual bool IsWhiteListed(string const &command, bool silent);
	virtual ~CCVarsWhiteList();
	
	static inline auto FIsWhiteListed = PreyFunction<bool(CCVarsWhiteList *const _this, string const &command, bool silent)>(0x1738CB0);
};

// Header: FromCpp
// Prey/GameDll/gamestartup.h
class CGameStartupStatic // Id=801D31D Size=1
{
public:
	static inline auto g_pGameStartup = PreyGlobal<CGameStartup *>(0x2C122F8);
	
	static void RequestLoadMod(IConsoleCmdArgs *pCmdArgs) { FRequestLoadMod(pCmdArgs); }
	static void RequestUnloadMod(IConsoleCmdArgs *pCmdArgs) { FRequestUnloadMod(pCmdArgs); }
	
#if 0
	static void ForceCursorUpdate();
#endif
	
	static inline auto FRequestLoadMod = PreyFunction<void(IConsoleCmdArgs *pCmdArgs)>(0x173A9D0);
	static inline auto FRequestUnloadMod = PreyFunction<void(IConsoleCmdArgs *pCmdArgs)>(0x173AB20);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryGame/IGameRef.h>
#include <Prey/CryGame/IGameStartup.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/BasicEventListener.h>

enum ESystemEvent;
struct HINSTANCE__;
struct HWND__;
struct IBasicEventListener;
struct IGame;
struct IGameFramework;
struct SSystemInitParams;

// CCVarsWhiteList
// Header:  Prey/GameDll/GameStartup.h
class CCVarsWhiteList : public ICVarsWhitelist
{ // Size=8 (0x8)
public:
	virtual bool IsWhiteListed(const string& command, bool silent);

	static inline auto FIsWhiteListed = PreyFunction<bool(CCVarsWhiteList* const _this, const string& command, bool silent)>(0x185FB40);
};

// GameStartupErrorObserver
// Header:  Prey/GameDll/GameStartup.h
class GameStartupErrorObserver : public IErrorObserver
{ // Size=8 (0x8)
public:
	virtual void OnAssert(const char* condition, const char* message, const char* fileName, unsigned fileLineNumber);
	virtual void OnScriptWarning(const char* _message);
	virtual void OnFatalError(const char* message);

	static inline auto FOnAssert = PreyFunction<void(GameStartupErrorObserver* const _this, const char* condition, const char* message, const char* fileName, unsigned fileLineNumber)>(0x1861050);
	static inline auto FOnScriptWarning = PreyFunction<void(GameStartupErrorObserver* const _this, const char* _message)>(0x1333E90);
	static inline auto FOnFatalError = PreyFunction<void(GameStartupErrorObserver* const _this, const char* message)>(0x18610B0);
};

// CGameStartup
// Header:  Prey/GameDll/GameStartup.h
class CGameStartup : public IGameStartup, public ISystemEventListener
{ // Size=104 (0x68)
public:
	IBasicEventListener& m_basicEventListener;
	IGame* m_pMod;
	IGameRef m_modRef;
	bool m_initWindow;
	bool m_quit;
	int8_t m_nVOIPWasActive;
	HINSTANCE__* m_modDll;
	HINSTANCE__* m_frameworkDll;
	string m_reqModName;
	bool m_reqModUnload;
	IGameFramework* m_pFramework;
	GameStartupErrorObserver m_errorObsever;
	bool m_bDecrementHardwareMouseOnFocusGained;

	virtual IGameRef Init(SSystemInitParams& startupParams);
	virtual IGameRef Reset(const char* pModName);
	virtual void Shutdown();
	virtual int Update(bool haveFocus, unsigned updateFlags);
	virtual bool GetRestartLevel(char* * levelName);
	virtual const char* GetPatch() const;
	virtual bool GetRestartMod(char* pModNameBuffer, int modNameBufferSizeInBytes);
	virtual int Run(const char* autoStartLevelName);
	virtual const uint8_t* GetRSAKey(unsigned* pKeySize) const;
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	static CGameStartup* Create(IBasicEventListener& basicEventListener) { return FCreate(basicEventListener); }
	virtual ~CGameStartup();
	static int64_t WndProcHndl(HWND__* hWnd, unsigned msg, uint64_t wParam, int64_t lParam) { return FWndProcHndl(hWnd, msg, wParam, lParam); }
	IBasicEventListener::EAction ProcessMessage(HWND__* hWnd, unsigned msg, uint64_t wParam, int64_t lParam) { return FProcessMessage(this, hWnd, msg, wParam, lParam); }

#if 0
	CGameStartup(IBasicEventListener& _arg0_);
	bool IsModAvailable(const string& _arg0_);
	void HandleResizeForVOIP(uint64_t _arg0_);
	bool InitWindow(SSystemInitParams& _arg0_);
	void ShutdownWindow();
	bool InitFramework(SSystemInitParams& _arg0_);
	void ShutdownFramework();
	int64_t WndProc(HWND__* _arg0_, unsigned _arg1_, uint64_t _arg2_, int64_t _arg3_);
#endif

	static inline auto FInit = PreyFunction<IGameRef*(CGameStartup* const _this, IGameRef* _return_value_, SSystemInitParams& startupParams)>(0x1860920);
	static inline auto FReset = PreyFunction<IGameRef*(CGameStartup* const _this, IGameRef* _return_value_, const char* pModName)>(0x1861780);
	static inline auto FShutdown = PreyFunction<void(CGameStartup* const _this)>(0x1861EC0);
	static inline auto FUpdate = PreyFunction<int(CGameStartup* const _this, bool haveFocus, unsigned updateFlags)>(0x1861FD0);
	static inline auto FGetRestartLevel = PreyFunction<bool(CGameStartup* const _this, char* * levelName)>(0x1860860);
	static inline auto FGetPatch = PreyFunction<const char* (const CGameStartup* const _this)>(0x1CBB0B0);
	static inline auto FGetRestartMod = PreyFunction<bool(CGameStartup* const _this, char* pModNameBuffer, int modNameBufferSizeInBytes)>(0x18608B0);
	static inline auto FRun = PreyFunction<int(CGameStartup* const _this, const char* autoStartLevelName)>(0x18619B0);
	static inline auto FGetRSAKey = PreyFunction<const uint8_t* (const CGameStartup* const _this, unsigned* pKeySize)>(0x1860840);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x18610F0);
	static inline auto FCreate = PreyFunction<CGameStartup* (IBasicEventListener& basicEventListener)>(0x18607A0);
	static inline auto FWndProcHndl = PreyFunction<int64_t(HWND__* hWnd, unsigned msg, uint64_t wParam, int64_t lParam)>(0x1862160);
	static inline auto FProcessMessage = PreyFunction<IBasicEventListener::EAction(CGameStartup* const _this, HWND__* hWnd, unsigned msg, uint64_t wParam, int64_t lParam)>(0x18611C0);
};
#endif // !MOONCRASH
