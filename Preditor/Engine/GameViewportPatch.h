#pragma once

struct IGameViewport;

class GameViewportPatch
{
public:
	static void InitHooks();
	static void SetGameViewport(IGameViewport* pVP);
};
