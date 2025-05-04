#pragma once
#include <Chairloader/IChairloaderModule.h>

namespace Internal
{

struct IModDllManager;

struct SCryRenderInitParams
{
	bool bEnableAuxGeom = false;
};

struct IChairloaderCryRender : public IChairloaderModule
{
	virtual ~IChairloaderCryRender() {}

	//! System initialization
	virtual void InitSystem(const SCryRenderInitParams& params) = 0;

	//! Game initialization.
	virtual void InitGame() = 0;

	//! Sets whether the render thread is currently idle.
	//! It's considered idle after two SyncMainWithRender calls.
	virtual void SetRenderThreadIsIdle(bool state) = 0;

	//! Adds a shader mod name. This will also enable the shader compiler (if enabled in CMake).
	virtual void AddShadersMod(const std::string& name) = 0;
};

} // namespace Internal
