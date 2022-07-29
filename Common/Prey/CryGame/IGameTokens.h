// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

// -------------------------------------------------------------------------
//  File name:   IGameTokens.h
//  Version:     v1.00
//  Created:     20/10/2005 by Timur.
//  Compilers:   Visual Studio.NET
//  Description:
// -------------------------------------------------------------------------
//  History:
//
////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <CryFlowGraph/IFlowSystem.h> // <> required for Interfuscator

enum EGameTokenFlags
{
	EGAME_TOKEN_MODIFIED      = 0x01,    //!< Token is modified from its default value.
	EGAME_TOKEN_GRAPHVARIABLE = 0x02,    //!< Token is constrained to the flowgraph it appears in.
	EGAME_TOKEN_LOCALONLY     = 0x04,    //!< This token will not be synchronized to clients.
};

#ifndef _RELEASE
	//#define _GAMETOKENSDEBUGINFO // just to be able to fast activate it in _release easily if needed.
#endif

//! Game Token can be used as any Plot event in the game.
struct IGameToken
{
	// <interfuscator:shuffle>
	virtual ~IGameToken(){}

	virtual int GetId() const = 0;

	virtual void SetName(const char* arg0) = 0;

	//! Retrieve name of the game token.
	virtual const char* GetName() const = 0;

	//! Sets game token flags.
	virtual void SetFlags(uint32 flags) = 0;

	virtual void AddFlags(unsigned arg0) = 0;
	virtual void RemoveFlags(unsigned arg0) = 0;

	//! Retrieve game token flags.
	virtual uint32 GetFlags() const = 0;

	virtual bool HasFlags(unsigned arg0) const = 0;

	//! Assign data type to the game token.
	virtual void SetType(EFlowDataTypes dataType) = 0;

	//! Retrieve current data type of the game token.
	virtual EFlowDataTypes GetType() const = 0;

	//! Assign a new value to the game token.
	virtual void SetValue(const TFlowInputData& val) = 0;

	//! Retrieve a value of the game token.
	virtual TFlowInputData const& GetValue() const = 0;

	//! Set token value from a string.
	virtual void        SetValueAsString(const char* sValue, bool bDefault = false) = 0;
	virtual const char* GetValueAsString() const = 0;
	virtual void ResetValue(bool arg0) = 0;
	// </interfuscator:shuffle>

	//! A small template helper (yes, in the i/f) to get the value.
	//! Returns true if successful, false otherwise.
	template<typename T>
	bool GetValueAs(T& value)
	{
		TFlowInputData data;
		if (GetValue(data))
		{
			return data.GetValueWithConversion(value);
		}
		return false;
	}
};

//! Events that game token event listener can receive.
enum EGameTokenEvent
{
	EGAMETOKEN_EVENT_CHANGE,
	EGAMETOKEN_EVENT_DELETE
};

//! Game Token iterator, used to access all game tokens currently loaded.
struct IGameTokenIt
{
	// <interfuscator:shuffle>
	virtual ~IGameTokenIt(){}

	virtual void AddRef() = 0;

	//! Deletes this iterator and frees any memory it might have allocated.
	virtual void Release() = 0;

	//! Check whether current iterator position is the end position.
	//! \return True if iterator at end position.
	virtual bool IsEnd() = 0;

	//! Retrieves next entity.
	//! \return The entity that the iterator points to before it goes to the next.
	virtual IGameToken* Next() = 0;

	//! Retrieves current game token.
	//! \return The game token that the iterator points to.
	virtual IGameToken* This() = 0;

	//! Positions the iterator at the begining of the game token list.
	virtual void MoveFirst() = 0;
	// </interfuscator:shuffle>
};

typedef _smart_ptr<IGameTokenIt> IGameTokenItPtr;

//! Derive your class from this interface to listen for game the token events.
//! Listener must also be registered in game token manager.
struct IGameTokenEventListener
{
	// <interfuscator:shuffle>
	virtual ~IGameTokenEventListener(){}
	virtual void OnGameTokenEvent(EGameTokenEvent event, IGameToken* pGameToken) = 0;
	virtual void GetMemoryUsage(class ICrySizer* pSizer) const = 0;
	// </interfuscator:shuffle>
};

//! Manages collection of game tokens.
//! Responsible for saving/loading and acessing game tokens.
struct IGameTokenSystem
{
	// <interfuscator:shuffle>
	virtual ~IGameTokenSystem(){}

	//! Create a new token.
	//virtual IGameToken* SetOrCreateToken(const char* sTokenName, const TFlowInputData& defaultValue) = 0;

	virtual IGameToken* CreateNewToken(const char* arg0, EFlowDataTypes arg1, unsigned arg2) = 0;
	virtual IGameToken* LoadSerializedToken(int arg0, const char* arg1, EFlowDataTypes arg2, unsigned arg3) = 0;

	//! Deletes existing game token.
	virtual void DeleteToken(IGameToken* pToken) = 0;

	//! Find a game token by name.
	virtual IGameToken*   FindToken(const char* sTokenName) = 0;
	virtual IGameToken* FindToken(int arg0) = 0;

	virtual IGameTokenIt* GetGameTokenIterator() = 0;

	//! Rename existing game token.
	virtual void RenameToken(IGameToken* pToken, const char* sNewTokenName) = 0;

	virtual void RegisterListener(IGameToken* arg0, IGameTokenEventListener* arg1) = 0;
	virtual void UnregisterListener(IGameToken* arg0, IGameTokenEventListener* arg1) = 0;
	
	virtual void RegisterSystemListener(IGameTokenEventListener* arg0) = 0;
	virtual void UnregisterSystemListener(IGameTokenEventListener* arg0) = 0;

	//! Load all libraries found with given file spec.
	virtual void LoadLibs(const char* sFileSpec) = 0;

	//! Remove all tokens beginning with prefix (e.g. Library).
	virtual void RemoveLibrary(const char* sPrefix) = 0;

	//! Level to level serialization.
	virtual void SerializeSaveLevelToLevel(const char** ppGameTokensList, uint32 numTokensToSave) = 0;
	virtual void SerializeReadLevelToLevel() = 0;

	//! Reset system (deletes all libraries).
	virtual void Reset() = 0;
	virtual void Unload() = 0;
	virtual void DumpAllTokensToFile(const char* arg0) = 0;
	virtual void Serialize(TSerialize ser) = 0;
	virtual void GetMemoryStatistics(ICrySizer* arg0) = 0;
	virtual void DebugDraw() = 0;
	// </interfuscator:shuffle>

	//! A small template helper (yes, in the i/f) to get the value of a token.
	//! \return true if successful (value found and conversion OK), false otherwise (not found, or conversion failed).
	template<typename T>
	bool GetTokenValueAs(const char* sGameToken, T& value)
	{
		IGameToken* pToken = FindToken(sGameToken);
		if (pToken == 0) return false;
		return pToken->GetValueAs(value);
	}

#ifdef _GAMETOKENSDEBUGINFO
	virtual void AddTokenToDebugList(const char* pToken) = 0;
	virtual void RemoveTokenFromDebugList(const char* pToken) = 0;
#endif
};
