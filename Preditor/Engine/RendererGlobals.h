#pragma once
#include <Chairloader/IChairRender.h>

namespace Engine
{

class RendererGlobals : private IChairRenderListener
{
public:
	static void InitSystem();
	static void ShutdownSystem();

private:
	int GetChairRenderListenerFlags() override;
	void InitRendererModule(CD3D9Renderer* pRenderer) override;
};

} // namespace Engine
