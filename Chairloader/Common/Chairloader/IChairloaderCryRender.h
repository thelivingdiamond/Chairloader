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
	static std::unique_ptr<IChairloaderCryRender> CreateInstance();
	virtual ~IChairloaderCryRender() {}

	//! System initialization
	virtual void InitSystem(const SCryRenderInitParams& params) = 0;

	//! Game initialization.
	virtual void InitGame() = 0;

	//! Sets whether the render thread is currently idle.
	//! It's considered idle after two SyncMainWithRender calls.
	virtual void SetRenderThreadIsIdle(bool state) = 0;

	//! Adds a shader mod directory. This will also enable the shader compiler (if enabled in CMake).
	virtual void AddShadersDir(const fs::path& path) = 0;

	//! Refreshes the list of shader files. Needs to be called after AddShadersDir or when file structure has changed.
	virtual void RefreshShaderFileList() = 0;
};

} // namespace Internal
