// Header file automatically created from a PDB.
#pragma once

struct ArkBinkPlaybackInfo;
struct ArkBinkPlayerHandle;

enum class EArkBinkMovieType : uint8_t
{
	Unknown = 0,
	Fullscreen = 1,
	Background = 2,
	Texture = 3,
};

enum class EArkBinkLoadFlags : uint8_t
{
	None = 0,
	AutoStart = 1,
	Looping = 2,
};

// Header: MadeUp
// _unknown/IArkBinkManager.h
class IArkBinkManager // Id=8001A60 Size=8
{
public:
	virtual void UseTelemetry(void *arg0, unsigned arg1) const = 0;
	virtual void EF_Update(int *arg0) = 0;
	virtual void EF_Render() = 0;
	virtual ArkBinkPlayerHandle MT_LoadMovie(const char *arg0, int16_t arg1, EArkBinkMovieType arg2, EArkBinkLoadFlags arg3) = 0;
	virtual void MT_ReleaseMovie(ArkBinkPlayerHandle arg0) = 0;
	virtual bool MT_StartMovie(ArkBinkPlayerHandle arg0) = 0;
	virtual bool MT_StopMovie(ArkBinkPlayerHandle arg0) = 0;
	virtual bool MT_PauseMovie(ArkBinkPlayerHandle arg0, bool arg1) = 0;
	virtual bool MT_IsMoviePlaying(ArkBinkPlayerHandle arg0) const = 0;
	virtual bool MT_GetMoviePlaybackInfo(ArkBinkPlayerHandle arg0, ArkBinkPlaybackInfo &arg1) const = 0;
	virtual bool MT_IsFullScreenMoviePlaying() const = 0;
	virtual void MT_PauseMovies(const bool arg0) const = 0;
};
