// Header file automatically created from a PDB.

#pragma once
#include <Chairloader/PreyFunction.h>
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CrySystem/IConsole.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/CrySystem/XConsole.h>


struct CConsoleCommand // Id=800F8F6 Size=40
{
    string m_sName;
    string m_sCommand;
    string m_sHelp;
    int m_nFlags;
    void (*m_func)(IConsoleCmdArgs *);

#if 0
    uint64_t sizeofThis() const;
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};
class CCrc32;
class CSystem;
struct ICVar;
struct ICVarDumpSink;
struct IConsoleArgumentAutoComplete;
struct IConsoleVarSink;
class ICrySizer;
struct IFFont;
struct IInput;
struct IKeyBindDumpSink;
struct INetwork;
struct IOutputPrintSink;
struct IRenderer;
class ITexture;
struct ITimer;

enum ScrollDir {
    sdDown,
    sdUp,
    sdNone
};

// Header: Exact
// CryEngine/crysystem/xconsole.h
struct CConsoleCommandArgs : public IConsoleCmdArgs // Id=800F8F7 Size=24
{
    std::vector<string> &m_args;
    string &m_line;

    CConsoleCommandArgs();

    virtual int GetArgCount() const;
    virtual const char *GetArg(int nIndex) const;
    virtual const char *GetCommandLine() const;
    virtual ~CConsoleCommandArgs();

    static inline auto FGetArgCount = PreyFunction<int(CConsoleCommandArgs const *const _this)>(0xDF48C0);
    static inline auto FGetArg = PreyFunction<const char *(CConsoleCommandArgs const *const _this, int nIndex)>(0xDF4870);
    static inline auto FGetCommandLine = PreyFunction<const char *(CConsoleCommandArgs const *const _this)>(0xDF4AA0);
};

// Header: Exact
// CryEngine/crysystem/xconsole.h
class CXConsole : public IConsole, public IInputEventListener, public IRemoteConsoleListener // Id=800F90A Size=576
{
public:
    using ConsoleBuffer = std::deque<string,std::allocator<string>>;
    using ConsoleBufferItor = std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<string>>>;
    using ConsoleBufferRItor = std::reverse_iterator<std::_Deque_iterator<std::_Deque_val<std::_Deque_simple_types<string>>>>;
    using ConsoleVariablesMap = std::map<char const *,ICVar *>;
    using ConsoleVariablesMapItor = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<char const * const,ICVar *> > > >;
    using ConsoleVariablesVector = std::vector<std::pair<char const *,ICVar *>>;
    using ConsoleCommandsMap = std::map<string,CConsoleCommand>;
    using ConsoleCommandsMapItor = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const ,CConsoleCommand> > > >;
    using ConsoleBindsMap = std::map<string,string,std::less<string>,std::allocator<std::pair<CryStringT<char> const,string>>>;
    using ConsoleBindsMapItor = std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CryStringT<char> const,string>>>>;
    using ArgumentAutoCompleteMap = std::map<string,IConsoleArgumentAutoComplete *>;

    struct SConfigVar // Id=800F980 Size=16
    {
        string m_value;
        bool m_partOfGroup;
    };

    using ConfigVars = std::map<string,CXConsole::SConfigVar>;

    struct SDeferredCommand // Id=800F99F Size=16
    {
        string command;
        bool silentMode;
    };

    using TDeferredCommandList = std::list<CXConsole::SDeferredCommand,std::allocator<CXConsole::SDeferredCommand> >;
    using ConsoleVarSinks = std::list<IConsoleVarSink *,std::allocator<IConsoleVarSink *> >;

    std::deque<string,std::allocator<string>> m_dqConsoleBuffer;
    std::deque<string,std::allocator<string>> m_dqHistory;
    bool m_bStaticBackground;
    int m_nLoadingBackTexID;
    int m_nWhiteTexID;
    int m_nProgress;
    int m_nProgressRange;
    string m_sInputBuffer;
    string m_sReturnString;
    string m_sPrevTab;
    int m_nTabCount;
    ConsoleCommandsMap m_mapCommands;
    ConsoleBindsMap m_mapBinds;
    ConsoleVariablesMap m_mapVariables;
    std::vector<std::pair<char const *,ICVar *>> m_randomCheckedVariables;
    std::vector<std::pair<char const *,ICVar *>> m_alwaysCheckedVariables;
    std::vector<IOutputPrintSink *> m_OutputSinks;
    std::list<CXConsole::SDeferredCommand,std::allocator<CXConsole::SDeferredCommand> > m_deferredCommands;
    bool m_deferredExecution;
    int m_waitFrames;
    CTimeValue m_waitSeconds;
    int m_blockCounter;
    ArgumentAutoCompleteMap m_mapArgumentAutoComplete;
    std::list<IConsoleVarSink *,std::allocator<IConsoleVarSink *> > m_consoleVarSinks;
    ConfigVars m_configVars;
    int m_nScrollPos;
    int m_nTempScrollMax;
    int m_nScrollMax;
    int m_nScrollLine;
    int m_nHistoryPos;
    int m_nCursorPos;
    ITexture *m_pImage;
    float m_fRepeatTimer;
    SInputEvent m_nRepeatEvent;
    float m_fCursorBlinkTimer;
    bool m_bDrawCursor;
    ScrollDir m_sdScrollDir;
    bool m_bConsoleActive;
    bool m_bActivationKeyEnable;
    bool m_bIsProcessingGroup;
    uint64_t m_nCheatHashRangeFirst;
    uint64_t m_nCheatHashRangeLast;
    bool m_bCheatHashDirty;
    uint64_t m_nCheatHash;
    CSystem *m_pSystem;
    IFFont *m_pFont;
    IRenderer *m_pRenderer;
    IInput *m_pInput;
    ITimer *m_pTimer;
    INetwork *m_pNetwork;
    ICVar *m_pSysDeactivateConsole;
    static inline auto con_display_last_messages = PreyGlobal<int>(0x2B07980);
    static inline auto con_line_buffer_size = PreyGlobal<int>(0x226ADF0);
    static inline auto con_showonload = PreyGlobal<int>(0x2B07984);
    static inline auto con_debug = PreyGlobal<int>(0x2B07988);
    static inline auto con_restricted = PreyGlobal<int>(0x2B0798C);
    bool m_bConsoleIsEmerging;

    CXConsole();
    virtual ~CXConsole();
    void Init(CSystem *pSystem) { FInit(this,pSystem); }
    virtual bool GetStatus();
    void FreeRenderResources() { FFreeRenderResources(this); }
    virtual void CopyToClipboard(const char *_sToCopy);
    virtual void Release();
    virtual ICVar *RegisterString(const char *sName, const char *sValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *));
    virtual ICVar *RegisterInt(const char *sName, int iValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *));
    virtual ICVar *RegisterInt64(const char *sName, int64_t iValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *));
    virtual ICVar *RegisterFloat(const char *sName, float fValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *));
    virtual ICVar *Register(const char *sName, float *src, float fValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *), bool allowModify);
    virtual ICVar *Register(const char *sName, int *src, int iValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *), bool allowModify);
    virtual ICVar *Register(const char *sName, const char **src, const char *defaultValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *), bool allowModify);
    virtual void UnregisterVariable(const char *sVarName, bool bDelete);
    virtual void SetScrollMax(int value);
    virtual void AddOutputPrintSink(IOutputPrintSink *inpSink);
    virtual void RemoveOutputPrintSink(IOutputPrintSink *inpSink);
    virtual void ShowConsole(bool show, const int iRequestScrollMax);
    virtual void DumpCVars(ICVarDumpSink *pCallback, unsigned nFlagsFilter);
    virtual void DumpCVarsToFile(const char *fileName, unsigned nFlagsFilter);
    virtual void DumpKeyBinds(IKeyBindDumpSink *pCallback);
    virtual void CreateKeyBind(const char *sCmd, const char *sRes);
    virtual const char *FindKeyBind(const char *sCmd) const;
    virtual void SetImage(ITexture *pImage, bool bDeleteCurrent);
    virtual ITexture *GetImage();
    virtual void StaticBackground(bool bStatic);
    virtual bool GetLineNo(const int indwLineNo, char *outszBuffer, const int indwBufferSize) const;
    virtual int GetLineCount() const;
    virtual ICVar *GetCVar(const char *sName);
    virtual char *GetVariable(const char *szVarName, const char *szFileName, const char *def_val);
    virtual float GetVariable(const char *szVarName, const char *szFileName, float def_val);
    virtual void PrintLine(const char *s);
    virtual void PrintLinePlus(const char *s);
    virtual void Clear();
    virtual void Update();
    virtual void Draw();
    virtual void AddCommand(const char *sCommand, void (*func)(IConsoleCmdArgs *), int nFlags, const char *sHelp);
    virtual void AddCommand(const char *sCommand, const char *sScriptFunc, int nFlags, const char *sHelp);
    virtual void RemoveCommand(const char *sName);
    virtual void ExecuteString(const char *command, const bool bSilentMode, const bool bDeferExecution);
    virtual void Exit(const char *szExitComments, ... );
    virtual bool IsOpened();
    virtual int GetNumVars();
    virtual uint64_t GetSortedVars(const char **pszArray, uint64_t numItems, const char *szPrefix);
    virtual int GetNumCheatVars();
    virtual void SetCheatVarHashRange(uint64_t firstVar, uint64_t lastVar);
    virtual void CalcCheatVarHash();
    virtual bool IsHashCalculated();
    virtual uint64_t GetCheatVarHash();
    virtual void FindVar(const char *substr);
    virtual const char *AutoComplete(const char *substr);
    virtual const char *AutoCompletePrev(const char *substr);
    virtual const char *ProcessCompletion(const char *szInputBuffer);
    virtual void RegisterAutoComplete(const char *sVarOrCommand, IConsoleArgumentAutoComplete *pArgAutoComplete);
    virtual void UnRegisterAutoComplete(const char *sVarOrCommand);
    virtual void ResetAutoCompletion();
    virtual void GetMemoryUsage(ICrySizer *pSizer) const;
    virtual void ResetProgressBar(int nProgressBarRange);
    virtual void TickProgressBar();
    virtual void SetLoadingImage(const char *szFilename);
    virtual void AddConsoleVarSink(IConsoleVarSink *pSink);
    virtual void RemoveConsoleVarSink(IConsoleVarSink *pSink);
    virtual const char *GetHistoryElement(const bool bUpOrDown);
    virtual void AddCommandToHistory(const char *szCommand);
    virtual void SetInputLine(const char *szLine);
    virtual void LoadConfigVar(const char *sVariable, const char *sValue);
    virtual void EnableActivationKey(bool bEnable);
    virtual bool OnInputEvent(SInputEvent const &event);
    virtual bool OnInputEventUI(SInputEvent const &event);
    virtual void OnConsoleCommand(const char *cmd);
    virtual bool OnBeforeVarChange(ICVar *pVar, const char *sNewValue);
    virtual void OnAfterVarChange(ICVar *pVar);
    ICVar *RegisterCVarGroup(const char *szName, const char *szFileName) { return FRegisterCVarGroup(this,szName,szFileName); }
    virtual void PrintCheatVars(bool bUseLastHashRange);
    virtual char *GetCheatVarAt(unsigned nOffset);
    void DrawBuffer(int nScrollPos, const char *szEffect) { FDrawBuffer(this,nScrollPos,szEffect); }
    void RegisterVar(ICVar *pCVar, void (*pChangeFunc)(ICVar *)) { FRegisterVar(this,pCVar,pChangeFunc); }
    void AddLine(const char *inputStr) { FAddLine(this,inputStr); }
    void AddLinePlus(const char *inputStr) { FAddLinePlus(this,inputStr); }
    void ExecuteCommand(CConsoleCommand &cmd, string &str, bool bIgnoreDevMode) { FExecuteCommand(this,cmd,str,bIgnoreDevMode); }
//    void ConsoleLogInputResponse(const char *format, ... arg1) { FConsoleLogInputResponse(this,format,arg1); }
//    void ConsoleLogInput(const char *format, ... arg1) { FConsoleLogInput(this,format,arg1); }
//    void ConsoleWarning(const char *format, ... arg1) { FConsoleWarning(this,format,arg1); }
    void DisplayHelp(const char *help, const char *name) { FDisplayHelp(this,help,name); }
    void DisplayVarValue(ICVar *pVar) { FDisplayVarValue(this,pVar); }
    void SplitCommands(const char *line, std::list<string,std::allocator<string>> &split) { FSplitCommands(this,line,split); }
    void ExecuteStringInternal(const char *command, const bool bFromConsole, const bool bSilentMode) { FExecuteStringInternal(this,command,bFromConsole,bSilentMode); }
    void AddCheckedCVar(std::vector<std::pair<char const *,ICVar *>> &vector, std::pair<char const *,ICVar *> const &value) { FAddCheckedCVar(this,vector,value); }
    void RemoveCheckedCVar(std::vector<std::pair<char const *,ICVar *>> &vector, std::pair<char const *,ICVar *> const &value) { FRemoveCheckedCVar(this,vector,value); }
    static void AddCVarsToHash(std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<char const *,ICVar *> > > > begin, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<char const *,ICVar *> > > > end, CCrc32 &runningNameCrc32, CCrc32 &runningNameValueCrc32) { FAddCVarsToHash(begin,end,runningNameCrc32,runningNameValueCrc32); }
    static bool CVarNameLess(std::pair<char const *,ICVar *> const &lhs, std::pair<char const *,ICVar *> const &rhs) { return FCVarNameLess(lhs,rhs); }

#if 0
    void SetStatus(bool arg0);
	bool GetStatus() const;
	void Copy();
	void Paste();
	void SetProcessingGroup(bool arg0);
	bool GetIsProcessingGroup() const;
	bool ProcessInput(SInputEvent const &arg0);
	void AddInputChar(const char arg0);
	void RemoveInputChar(bool arg0);
	void ExecuteInputBuffer();
	void ScrollConsole();
	void ExecuteDeferredCommands();
	static const char *GetFlagsString(const unsigned arg0);
	static void CmdDumpAllAnticheatVars(IConsoleCmdArgs *arg0);
	static void CmdDumpLastHashedAnticheatVars(IConsoleCmdArgs *arg0);
#endif

    static inline auto FBitNotCXConsole = PreyFunction<void(CXConsole *const _this)>(0xDEEAF0);
    static inline auto FInit = PreyFunction<void(CXConsole *const _this, CSystem *pSystem)>(0xDF5270);
    static inline auto FGetStatusOv0 = PreyFunction<bool(CXConsole *const _this)>(0xDF5160);
    static inline auto FFreeRenderResources = PreyFunction<void(CXConsole *const _this)>(0xDF4800);
    static inline auto FCopyToClipboard = PreyFunction<void(CXConsole *const _this, const char *_sToCopy)>(0xDF0E80);
    static inline auto FRelease = PreyFunction<void(CXConsole *const _this)>(0xA97D40);
    static inline auto FRegisterString = PreyFunction<ICVar *(CXConsole *const _this, const char *sName, const char *sValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *))>(0xDF6F20);
    static inline auto FRegisterInt = PreyFunction<ICVar *(CXConsole *const _this, const char *sName, int iValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *))>(0xDF6E40);
    static inline auto FRegisterInt64 = PreyFunction<ICVar *(CXConsole *const _this, const char *sName, int64_t iValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *))>(0xDF6D60);
    static inline auto FRegisterFloat = PreyFunction<ICVar *(CXConsole *const _this, const char *sName, float fValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *))>(0xDF6C80);
    static inline auto FRegisterOv2 = PreyFunction<ICVar *(CXConsole *const _this, const char *sName, float *src, float fValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *), bool allowModify)>(0xDF6850);
    static inline auto FRegisterOv1 = PreyFunction<ICVar *(CXConsole *const _this, const char *sName, int *src, int iValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *), bool allowModify)>(0xDF6750);
    static inline auto FRegisterOv0 = PreyFunction<ICVar *(CXConsole *const _this, const char *sName, const char **src, const char *defaultValue, int nFlags, const char *help, void (*pChangeFunc)(ICVar *), bool allowModify)>(0xDF6950);
    static inline auto FUnregisterVariable = PreyFunction<void(CXConsole *const _this, const char *sVarName, bool bDelete)>(0xDF8C00);
    static inline auto FSetScrollMax = PreyFunction<void(CXConsole *const _this, int value)>(0xDF85E0);
    static inline auto FAddOutputPrintSink = PreyFunction<void(CXConsole *const _this, IOutputPrintSink *inpSink)>(0xDF0700);
    static inline auto FRemoveOutputPrintSink = PreyFunction<void(CXConsole *const _this, IOutputPrintSink *inpSink)>(0xDF76F0);
    static inline auto FShowConsole = PreyFunction<void(CXConsole *const _this, bool show, const int iRequestScrollMax)>(0xDF85F0);
    static inline auto FDumpCVars = PreyFunction<void(CXConsole *const _this, ICVarDumpSink *pCallback, unsigned nFlagsFilter)>(0xDF1FB0);
    static inline auto FDumpCVarsToFile = PreyFunction<void(CXConsole *const _this, const char *fileName, unsigned nFlagsFilter)>(0xDF2070);
    static inline auto FDumpKeyBinds = PreyFunction<void(CXConsole *const _this, IKeyBindDumpSink *pCallback)>(0xDF2300);
    static inline auto FCreateKeyBind = PreyFunction<void(CXConsole *const _this, const char *sCmd, const char *sRes)>(0xDF0F10);
    static inline auto FFindKeyBind = PreyFunction<const char *(CXConsole const *const _this, const char *sCmd)>(0xDF45A0);
    static inline auto FSetImage = PreyFunction<void(CXConsole *const _this, ITexture *pImage, bool bDeleteCurrent)>(0xDF8480);
    static inline auto FGetImage = PreyFunction<ITexture *(CXConsole *const _this)>(0xDF4C20);
    static inline auto FStaticBackground = PreyFunction<void(CXConsole *const _this, bool bStatic)>(0xDF8960);
    static inline auto FGetLineNo = PreyFunction<bool(CXConsole const *const _this, const int indwLineNo, char *outszBuffer, const int indwBufferSize)>(0xDF4C30);
    static inline auto FGetLineCount = PreyFunction<int(CXConsole const *const _this)>(0x5371C0);
    static inline auto FGetCVar = PreyFunction<ICVar *(CXConsole *const _this, const char *sName)>(0xDF48E0);
    static inline auto FGetVariableOv1 = PreyFunction<char *(CXConsole *const _this, const char *szVarName, const char *szFileName, const char *def_val)>(0x158AEF0);
    static inline auto FGetVariableOv0 = PreyFunction<float(CXConsole *const _this, const char *szVarName, const char *szFileName, float def_val)>(0xB5F050);
    static inline auto FPrintLine = PreyFunction<void(CXConsole *const _this, const char *s)>(0xDF5DE0);
    static inline auto FPrintLinePlus = PreyFunction<void(CXConsole *const _this, const char *s)>(0xDF5DF0);
    static inline auto FClear = PreyFunction<void(CXConsole *const _this)>(0xDF0CB0);
    static inline auto FUpdate = PreyFunction<void(CXConsole *const _this)>(0xDF8D00);
    static inline auto FDraw = PreyFunction<void(CXConsole *const _this)>(0xDF16D0);
    static inline auto FAddCommandOv1 = PreyFunction<void(CXConsole *const _this, const char *sCommand, void (*func)(IConsoleCmdArgs *), int nFlags, const char *sHelp)>(0xDEF4F0);
    static inline auto FAddCommandOv0 = PreyFunction<void(CXConsole *const _this, const char *sCommand, const char *sScriptFunc, int nFlags, const char *sHelp)>(0xDEF220);
    static inline auto FRemoveCommand = PreyFunction<void(CXConsole *const _this, const char *sName)>(0xDF7510);
    static inline auto FExecuteString = PreyFunction<void(CXConsole *const _this, const char *command, const bool bSilentMode, const bool bDeferExecution)>(0xDF3640);
//    static inline auto FExit = PreyFunction<void(CXConsole *const _this, const char *szExitComments, ... )>(0xDF44E0);
    static inline auto FIsOpened = PreyFunction<bool(CXConsole *const _this)>(0xDF56D0);
    static inline auto FGetNumVars = PreyFunction<int(CXConsole *const _this)>(0xDF4EE0);
    static inline auto FGetSortedVars = PreyFunction<uint64_t(CXConsole *const _this, const char **pszArray, uint64_t numItems, const char *szPrefix)>(0xDF4F60);
    static inline auto FGetNumCheatVars = PreyFunction<int(CXConsole *const _this)>(0xDF4EC0);
    static inline auto FSetCheatVarHashRange = PreyFunction<void(CXConsole *const _this, uint64_t firstVar, uint64_t lastVar)>(0xDF8460);
    static inline auto FCalcCheatVarHash = PreyFunction<void(CXConsole *const _this)>(0xDF0BF0);
    static inline auto FIsHashCalculated = PreyFunction<bool(CXConsole *const _this)>(0xDF56C0);
    static inline auto FGetCheatVarHash = PreyFunction<uint64_t(CXConsole *const _this)>(0xDF4A90);
    static inline auto FFindVar = PreyFunction<void(CXConsole *const _this, const char *substr)>(0xDF4610);
    static inline auto FAutoComplete = PreyFunction<const char *(CXConsole *const _this, const char *substr)>(0xDF0720);
    static inline auto FAutoCompletePrev = PreyFunction<const char *(CXConsole *const _this, const char *substr)>(0xDF0930);
    static inline auto FProcessCompletion = PreyFunction<const char *(CXConsole *const _this, const char *szInputBuffer)>(0xDF5E00);
    static inline auto FRegisterAutoComplete = PreyFunction<void(CXConsole *const _this, const char *sVarOrCommand, IConsoleArgumentAutoComplete *pArgAutoComplete)>(0xDF6A60);
    static inline auto FUnRegisterAutoComplete = PreyFunction<void(CXConsole *const _this, const char *sVarOrCommand)>(0xDF8AE0);
    static inline auto FResetAutoCompletion = PreyFunction<void(CXConsole *const _this)>(0xDF7760);
    static inline auto FGetMemoryUsage = PreyFunction<void(CXConsole const *const _this, ICrySizer *pSizer)>(0xDF4D20);
    static inline auto FResetProgressBar = PreyFunction<void(CXConsole *const _this, int nProgressBarRange)>(0xDF7790);
    static inline auto FTickProgressBar = PreyFunction<void(CXConsole *const _this)>(0xDF8A70);
    static inline auto FSetLoadingImage = PreyFunction<void(CXConsole *const _this, const char *szFilename)>(0xDF8520);
    static inline auto FAddConsoleVarSink = PreyFunction<void(CXConsole *const _this, IConsoleVarSink *pSink)>(0xDEF980);
    static inline auto FRemoveConsoleVarSink = PreyFunction<void(CXConsole *const _this, IConsoleVarSink *pSink)>(0xDF7630);
    static inline auto FGetHistoryElement = PreyFunction<const char *(CXConsole *const _this, const bool bUpOrDown)>(0xDF4B20);
    static inline auto FAddCommandToHistory = PreyFunction<void(CXConsole *const _this, const char *szCommand)>(0xDEF780);
    static inline auto FSetInputLine = PreyFunction<void(CXConsole *const _this, const char *szLine)>(0xDF84D0);
    static inline auto FLoadConfigVar = PreyFunction<void(CXConsole *const _this, const char *sVariable, const char *sValue)>(0xDF56E0);
    static inline auto FEnableActivationKey = PreyFunction<void(CXConsole *const _this, bool bEnable)>(0xDF23B0);
    static inline auto FOnInputEvent = PreyFunction<bool(CXConsole *const _this, SInputEvent const &event)>(0xDD23F0);
    static inline auto FOnInputEventUI = PreyFunction<bool(CXConsole *const _this, SInputEvent const &event)>(0xDD23F0);
    static inline auto FOnConsoleCommand = PreyFunction<void(CXConsole *const _this, const char *cmd)>(0xDF5DC0);
    static inline auto FOnBeforeVarChange = PreyFunction<bool(CXConsole *const _this, ICVar *pVar, const char *sNewValue)>(0xDF5B60);
    static inline auto FOnAfterVarChange = PreyFunction<void(CXConsole *const _this, ICVar *pVar)>(0xDF5B00);
    static inline auto FRegisterCVarGroup = PreyFunction<ICVar *(CXConsole *const _this, const char *szName, const char *szFileName)>(0xDF6BC0);
    static inline auto FPrintCheatVars = PreyFunction<void(CXConsole *const _this, bool bUseLastHashRange)>(0xA13080);
    static inline auto FGetCheatVarAt = PreyFunction<char *(CXConsole *const _this, unsigned nOffset)>(0xDF49B0);
    static inline auto FDrawBuffer = PreyFunction<void(CXConsole *const _this, int nScrollPos, const char *szEffect)>(0xDF1CB0);
    static inline auto FRegisterVar = PreyFunction<void(CXConsole *const _this, ICVar *pCVar, void (*pChangeFunc)(ICVar *))>(0xDF7040);
    static inline auto FAddLine = PreyFunction<void(CXConsole *const _this, const char *inputStr)>(0xDEFA00);
    static inline auto FAddLinePlus = PreyFunction<void(CXConsole *const _this, const char *inputStr)>(0xDEFFA0);
    static inline auto FExecuteCommand = PreyFunction<void(CXConsole *const _this, CConsoleCommand &cmd, string &str, bool bIgnoreDevMode)>(0xDF23C0);
    //FIXME: make these functions work
//    static inline auto FConsoleLogInputResponse = PreyFunction<void(CXConsole *const _this, const char *format, ... arg1)>(0xDF0DE0);
//    static inline auto FConsoleLogInput = PreyFunction<void(CXConsole *const _this, const char *format, ... arg1)>(0xDF0DA0);
//    static inline auto FConsoleWarning = PreyFunction<void(CXConsole *const _this, const char *format, ... arg1)>(0xDF0E40);
    static inline auto FDisplayHelp = PreyFunction<void(CXConsole *const _this, const char *help, const char *name)>(0xDF0FA0);
    static inline auto FDisplayVarValue = PreyFunction<void(CXConsole *const _this, ICVar *pVar)>(0xDF11D0);
    static inline auto FSplitCommands = PreyFunction<void(CXConsole *const _this, const char *line, std::list<string,std::allocator<string>> &split)>(0xDF86A0);
    static inline auto FExecuteStringInternal = PreyFunction<void(CXConsole *const _this, const char *command, const bool bFromConsole, const bool bSilentMode)>(0xDF3930);
    static inline auto FAddCheckedCVar = PreyFunction<void(CXConsole *const _this, std::vector<std::pair<char const *,ICVar *>> &vector, std::pair<char const *,ICVar *> const &value)>(0xDEF150);
    static inline auto FRemoveCheckedCVar = PreyFunction<void(CXConsole *const _this, std::vector<std::pair<char const *,ICVar *>> &vector, std::pair<char const *,ICVar *> const &value)>(0xDF7420);
    static inline auto FAddCVarsToHash = PreyFunction<void(std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<char const *,ICVar *> > > > begin, std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<char const *,ICVar *> > > > end, CCrc32 &runningNameCrc32, CCrc32 &runningNameValueCrc32)>(0xDEEFC0);
    static inline auto FCVarNameLess = PreyFunction<bool(std::pair<char const *,ICVar *> const &lhs, std::pair<char const *,ICVar *> const &rhs)>(0xDF0BC0);
};

