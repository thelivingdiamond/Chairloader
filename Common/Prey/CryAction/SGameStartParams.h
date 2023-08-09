// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryGame/IGameFramework.h>

struct SGameContextParams;

// Header: MadeUp
// _unknown/SGameStartParams.h
struct SGameStartParams // Id=8002006 Size=40
{
	const char *hostname;
	const char *connectionString;
	SGameContextParams const *pContextParams;
	unsigned flags;
	int maxPlayers;
	unsigned session;
	uint16_t port;
};

