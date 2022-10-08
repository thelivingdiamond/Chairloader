#pragma once

class CD3D9Renderer;

namespace RenderDll::Shaders
{

bool GetShaderModsRegistered();
void InitHooks();
void ShutdownRenderer();

}
