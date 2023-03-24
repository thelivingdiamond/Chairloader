#pragma once

struct IGameViewport;

namespace Engine
{

class GameViewportPatch
{
public:
	static void InitHooks();
	static void SetGameViewport(IGameViewport* pVP);
};

} // namespace Engine
