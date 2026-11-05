// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryRenderer/IRenderAuxGeom.h>

// IArkRenderPersistentAuxGeom: Arkane's aux geometry with a lifetime per primitive
// (IRenderer::GetIArkRenderPersistentAuxGeom).
// Header:  _unknown/IArkRenderPersistentAuxGeom.h
struct IArkRenderPersistentAuxGeom
{ // Size=8 (0x8)
	virtual ~IArkRenderPersistentAuxGeom() {}
	virtual void SetRenderFlags(const SAuxGeomRenderFlags& renderFlags) = 0;
	virtual SAuxGeomRenderFlags GetRenderFlags() = 0;
	virtual void DrawPoint(float lifetime, const Vec3& v, const ColorB& col, uint8 size) = 0;
	virtual void DrawPoints(float lifetime, const Vec3* v, unsigned numPoints, const ColorB& col, uint8 size) = 0;
	virtual void DrawPoints(float lifetime, const Vec3* v, unsigned numPoints, const ColorB* col, uint8 size) = 0;
	virtual void DrawLine(float lifetime, const Vec3& v0, const ColorB& colV0, const Vec3& v1, const ColorB& colV1, float thickness) = 0;
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const ColorB& col, float thickness) = 0;
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const ColorB* col, float thickness) = 0;
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB& col, float thickness) = 0;
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB* col, float thickness) = 0;
	virtual void DrawPolyline(float lifetime, const Vec3* v, unsigned numPoints, bool closed, const ColorB& col, float thickness) = 0;
	virtual void DrawPolyline(float lifetime, const Vec3* v, unsigned numPoints, bool closed, const ColorB* col, float thickness) = 0;
	virtual void DrawTriangle(float lifetime, const Vec3& v0, const ColorB& colV0, const Vec3& v1, const ColorB& colV1, const Vec3& v2, const ColorB& colV2) = 0;
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const ColorB& col) = 0;
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const ColorB* col) = 0;
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB& col) = 0;
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB* col) = 0;
	virtual void DrawAABB(float lifetime, const AABB& aabb, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) = 0;
	virtual void DrawAABB(float lifetime, const AABB& aabb, const Matrix34& matWorld, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) = 0;
	virtual void DrawAABBs(float lifetime, const AABB* aabbs, unsigned aabbCount, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) = 0;
	virtual void DrawOBB(float lifetime, const OBB& obb, const Vec3& pos, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) = 0;
	virtual void DrawOBB(float lifetime, const OBB& obb, const Matrix34& matWorld, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) = 0;
	virtual void DrawSphere(float lifetime, const Vec3& pos, float radius, const ColorB& col, bool drawShaded) = 0;
	virtual void DrawCone(float lifetime, const Vec3& pos, const Vec3& dir, float radius, float height, const ColorB& col, bool drawShaded) = 0;
	virtual void DrawCylinder(float lifetime, const Vec3& pos, const Vec3& dir, float radius, float height, const ColorB& col, bool drawShaded) = 0;
	virtual void Flush() = 0;
};

// CArkRenderPersistentAuxGeom_Null (CD3D9Renderer::m_renderPersistentAuxGeomNull)
// Header:  _unknown/CArkRenderPersistentAuxGeom_Null.h
class CArkRenderPersistentAuxGeom_Null : public IArkRenderPersistentAuxGeom
{ // Size=8 (0x8)
public:
	virtual void SetRenderFlags(const SAuxGeomRenderFlags& renderFlags) {}
	virtual SAuxGeomRenderFlags GetRenderFlags() { return SAuxGeomRenderFlags(); }
	virtual void DrawPoint(float lifetime, const Vec3& v, const ColorB& col, uint8 size) {}
	virtual void DrawPoints(float lifetime, const Vec3* v, unsigned numPoints, const ColorB& col, uint8 size) {}
	virtual void DrawPoints(float lifetime, const Vec3* v, unsigned numPoints, const ColorB* col, uint8 size) {}
	virtual void DrawLine(float lifetime, const Vec3& v0, const ColorB& colV0, const Vec3& v1, const ColorB& colV1, float thickness) {}
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const ColorB& col, float thickness) {}
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const ColorB* col, float thickness) {}
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB& col, float thickness) {}
	virtual void DrawLines(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB* col, float thickness) {}
	virtual void DrawPolyline(float lifetime, const Vec3* v, unsigned numPoints, bool closed, const ColorB& col, float thickness) {}
	virtual void DrawPolyline(float lifetime, const Vec3* v, unsigned numPoints, bool closed, const ColorB* col, float thickness) {}
	virtual void DrawTriangle(float lifetime, const Vec3& v0, const ColorB& colV0, const Vec3& v1, const ColorB& colV1, const Vec3& v2, const ColorB& colV2) {}
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const ColorB& col) {}
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const ColorB* col) {}
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB& col) {}
	virtual void DrawTriangles(float lifetime, const Vec3* v, unsigned numPoints, const vtx_idx* ind, unsigned numIndices, const ColorB* col) {}
	virtual void DrawAABB(float lifetime, const AABB& aabb, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) {}
	virtual void DrawAABB(float lifetime, const AABB& aabb, const Matrix34& matWorld, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) {}
	virtual void DrawAABBs(float lifetime, const AABB* aabbs, unsigned aabbCount, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) {}
	virtual void DrawOBB(float lifetime, const OBB& obb, const Vec3& pos, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) {}
	virtual void DrawOBB(float lifetime, const OBB& obb, const Matrix34& matWorld, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) {}
	virtual void DrawSphere(float lifetime, const Vec3& pos, float radius, const ColorB& col, bool drawShaded) {}
	virtual void DrawCone(float lifetime, const Vec3& pos, const Vec3& dir, float radius, float height, const ColorB& col, bool drawShaded) {}
	virtual void DrawCylinder(float lifetime, const Vec3& pos, const Vec3& dir, float radius, float height, const ColorB& col, bool drawShaded) {}
	virtual void Flush() {}
	virtual ~CArkRenderPersistentAuxGeom_Null() {}
};

static_assert(sizeof(CArkRenderPersistentAuxGeom_Null) == 8);
