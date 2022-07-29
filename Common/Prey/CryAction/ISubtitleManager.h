// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

// -------------------------------------------------------------------------
//  File name:   ISubtitleManager.h
//  Version:     v1.00
//  Created:     29/01/2007 by AlexL.
//  Compilers:   Visual Studio.NET 2005
//  Description: Interface to the Subtitle Manager
// -------------------------------------------------------------------------
//  History:
//
////////////////////////////////////////////////////////////////////////////

#ifndef __ISUBTITLEMANAGER_H__
#define __ISUBTITLEMANAGER_H__
#pragma once

struct ArkBinkPlayerHandle;

//////////////////////////////////////////////////////////////////////////
struct ISubtitleHandler
{
	virtual ~ISubtitleHandler();
	virtual void ShowSubtitle(const char* arg0, bool arg1, const char* const arg2) = 0;
	virtual void SetEnabled(bool _bEnabled);
	virtual void OnMovieLoad(const char* const _movieName, ArkBinkPlayerHandle const& _movieHandle);
	virtual void OnMovieStart(ArkBinkPlayerHandle const& _movieHandle);
	virtual void OnMovieStop(ArkBinkPlayerHandle const& _movieHandle);

	static inline auto FSetEnabled = PreyFunction<void(ISubtitleHandler* const _this, bool _bEnabled)>(0xA13080);
	static inline auto FOnMovieLoad = PreyFunction<void(ISubtitleHandler* const _this, const char* const _movieName, ArkBinkPlayerHandle const& _movieHandle)>(0xA13080);
	static inline auto FOnMovieStart = PreyFunction<void(ISubtitleHandler* const _this, ArkBinkPlayerHandle const& _movieHandle)>(0xA13080);
	static inline auto FOnMovieStop = PreyFunction<void(ISubtitleHandler* const _this, ArkBinkPlayerHandle const& _movieHandle)>(0xA13080);
};

//////////////////////////////////////////////////////////////////////////
struct ISubtitleManager
{
	virtual ~ISubtitleManager(){}
	virtual void SetHandler(ISubtitleHandler* pHandler) = 0;
	virtual ISubtitleHandler* GetHandler() = 0;

	// enables/disables subtitles manager
	virtual void SetEnabled(bool bEnabled) = 0;

	// automatic mode. Will inform the subtitleHandler about every executed/stopped audio trigger.
	// You can use this mode, if you want to drive your subtitles by started sounds and not manually.
	virtual void SetAutoMode(bool bOn) = 0;

	virtual void ShowSubtitle(const char* subtitleLabel, bool bShow, const char* const arg2) = 0;
};

#endif // __ISUBTITLEMANAGER_H__
