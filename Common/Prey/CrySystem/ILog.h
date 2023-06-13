// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <Prey/CrySystem/IMiniLog.h> // <> required for Interfuscator

// enable this define to support log scopes to provide more context information for log lines
// this code is disable by default due it's runtime cost
//#define SUPPORT_LOG_IDENTER

enum ELogMode
{
	eLogMode_Normal   = BIT(0),
	eLogMode_AppCrash = BIT(1), //!< Log straight to file. Do not write to console.
};

// forward declarations
class ICrySizer;

//! Callback interface to the ILog.
struct ILogCallback
{
	// <interfuscator:shuffle>
	virtual ~ILogCallback(){}
	virtual void OnWriteToConsole(const char* sText, bool bNewLine) = 0;
	virtual void OnWriteToFile(const char* sText, bool bNewLine) = 0;
	// </interfuscator:shuffle>
};

//! Interface for logging operations based on IMiniLog.
//! Logging in CryEngine should be done using the following global functions:
//! CryLog (eMessage)
//! CryLogAlways (eAlways)
//! CryError (eError)
//! CryWarning (eWarning)
//! CryComment (eComment)
//! ILog gives you more control on logging operations.
struct ILog : public IMiniLog
{
	// <interfuscator:shuffle>
	virtual void Release() = 0;

	//! Set the file used to log to disk.
	virtual bool SetFileName(const char* command = NULL) = 0;

	//! Get the filename used to log to disk.
	virtual const char* GetFileName() const = 0;

	//! Get the filename where the current log backup was copied to on disk.
	virtual const char* GetBackupFileName() const = 0;

	//! All the following functions will be removed are here just to be able to compile the project.

	//! Logs the text both to file and console.
	virtual void LogComment(const char* szCommand, ...) PRINTF_PARAMS(2, 3) = 0;
	virtual void Log(const char* szCommand, ...) PRINTF_PARAMS(2, 3) = 0;
	virtual void LogAlways(const char* szCommand, ...) PRINTF_PARAMS(2, 3) = 0;
	virtual void LogWarning(const char* szFormat, ...) = 0;
	virtual void LogError(const char* szFormat, ...) = 0;

	//! Logs the text both to the end of file and console.
	virtual void LogPlus(const char* command, ...) PRINTF_PARAMS(2, 3) = 0;

	//! Logs to the file specified in SetFileName.
	virtual void LogToFile(const char* command, ...) PRINTF_PARAMS(2, 3) = 0;
	virtual void LogToFilePlus(const char* command, ...) PRINTF_PARAMS(2, 3) = 0;

	//! Logs to console only.
	virtual void LogToConsole(const char* command, ...) PRINTF_PARAMS(2, 3) = 0;
	virtual void LogToConsolePlus(const char* command, ...) PRINTF_PARAMS(2, 3) = 0;

	virtual void UpdateLoadingScreen(const char* command, ...) PRINTF_PARAMS(2, 3) = 0;

	virtual void RegisterConsoleVariables()   {}

	virtual void UnregisterConsoleVariables() {}

	//! Set log verbosity.
	//! Full logging (to console and file) can be enabled with verbosity 4.
	//! In the console 'log_Verbosity 4' command can be used.
	virtual void     SetVerbosity(int verbosity) = 0;

	virtual int      GetVerbosityLevel() const = 0;

	virtual void     AddCallback(ILogCallback* pCallback) = 0;
	virtual void     RemoveCallback(ILogCallback* pCallback) = 0;

	//! \note This is called on every frame by the system.
	virtual void        Update() = 0;

	virtual const char* GetModuleFilter() = 0;

	//! Collect memory statistics in CrySizer.
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;

	//! Asset scope strings help to figure out asset dependencies in case of asset loading errors.
	//! Should not be used directly, only by using define CRY_DEFINE_ASSET_SCOPE.
	//! \see CRY_DEFINE_ASSET_SCOPE.
	virtual void        PushAssetScopeName(const char* sAssetType, const char* sName) {};
	virtual void        PopAssetScopeName()                                           {};
	virtual const char* GetAssetScopeString()                                         { return ""; };
	// </interfuscator:shuffle>

	virtual void FlushAndClose() = 0;
};

#define INDENT_LOG_DURING_SCOPE(...)                   (void)(0)
#define CRY_DEFINE_ASSET_SCOPE(sAssetType, sAssetName) (void)(0)
