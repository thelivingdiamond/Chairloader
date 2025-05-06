#pragma once
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Chairloader/IRenderAuxGeomEx.h>
#include <winerror.h>

//! An implementation of the aux geomertry renderer for D3D.
//! Mods may provide a custom implementation via IChairRender::SetAuxGeomFactory.
//! This interface is provided for very specific mods. It is versioned separately from Mod SDK.
struct IRenderAuxGeomImplD3D : IChairService<IRenderAuxGeomImplD3D>
{

    static const char* NameImpl() { return "IRenderAuxGeomImplD3D"; }

    //! The interface version.
    static constexpr int INTERFACE_VERSION = 1;

    virtual ~IRenderAuxGeomImplD3D() {}

    //! @returns The interface version.
    virtual int GetIRenderAuxGeomImplD3DVersion() const { return INTERFACE_VERSION; }

    virtual IRenderAuxGeom* GetRenderAuxGeom(void* jobID = 0) = 0;
    virtual IRenderAuxGeomEx* GetRenderAuxGeomEx(void* jobID = 0) = 0;

    virtual HRESULT RestoreDeviceObjects() = 0;
    virtual void ReleaseShader() = 0;
    virtual void FreeMemory() = 0;

    virtual void SetOrthoMode(bool enable, Matrix44A* pMatrix = 0) = 0;
    virtual void Process() = 0;
};
