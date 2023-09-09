#pragma once

#include <Chairloader/pch.h>
#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/CryRenderer/CryDX.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <Prey/CryRenderer/IShader.h>
#include <Prey/CryRenderer/ITexture.h>
#include <Prey/CryRenderer/Tarray.h>

//! Enable async shader compilation in Chairloader
//! Prey's CHWShader_D3D::mfGatherFXParameters is not safe to be called from the shader thread because
//! it accesses global state. Disable for now. -- Never mind, it's not called from shader thread
// #define SHADER_ASYNC_COMPILATION

// Profiler not supported
#define PROFILE_FRAME(id)

// #define ASSERT_IN_SHADER(expr) assert(expr)
#define ASSERT_IN_SHADER(expr)

#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
