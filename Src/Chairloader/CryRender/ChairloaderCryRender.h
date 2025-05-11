#pragma once
#include <Chairloader/IChairloaderCryRender.h>

namespace RenderDll
{
class ChairRender;
class ChairloaderCryRender : public Internal::IChairloaderCryRender
{
public:
	ChairloaderCryRender(std::shared_ptr<IChairRender> pRender);

	void InitSystem(const Internal::SCryRenderInitParams& params) override;
	void InitGame() override;
	void ShutdownSystem() override;
	void SetRenderThreadIsIdle(bool state) override;
	void AddShadersMod(const std::string& name) override;
private:
	std::shared_ptr<ChairRender> m_pRender;
};

} // namespace RenderDll

