#pragma once

class CD3D9Renderer;

namespace RenderDll::Shaders
{

bool GetShaderModsRegistered();
void AddShadersDir(const fs::path& path);
void RefreshShaderFileList();

void InitHooks();
void ShutdownRenderer();

}
