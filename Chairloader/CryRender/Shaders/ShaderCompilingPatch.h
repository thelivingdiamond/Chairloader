#pragma once

class CD3D9Renderer;

namespace RenderDll::Shaders
{

void AddShadersMod(const std::string& name);
bool GetShaderModsRegistered();

void InitHooks();
void ShutdownRenderer();

}
