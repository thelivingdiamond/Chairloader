#pragma once
#include <Chairloader/IChairRender.h>

namespace RenderDll::AuxGeom
{

void InitAuxGeom();
void SetAuxGeomFactory(const IChairRender::AuxGeomFactory& factory);
void InitRenderer();
void RT_Shutdown();
void ShutdownSystem();

} // namespace RenderDll::AuxGeom

