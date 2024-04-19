#pragma once
#include <Chairloader/IChairloaderCryRender.h>

namespace RenderDll
{

class ChairloaderCryRender : public Internal::IChairloaderCryRender
{
public:
	void InitSystem(const Internal::SCryRenderInitParams& params) override;
	void InitGame() override;
	void ShutdownSystem() override;
	void SetRenderThreadIsIdle(bool state) override;
	void AddShadersMod(const std::string& name) override;
};

} // namespace RenderDll

