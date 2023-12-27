// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef _RENDERAUXGEOMNULL_H_
#define _RENDERAUXGEOMNULL_H_
#include <Prey/CryRenderer/IRenderAuxGeom.h>

class CAuxGeomCB_Null : public IRenderAuxGeom
{
public:
	// interface
	virtual void                SetRenderFlags(const SAuxGeomRenderFlags& renderFlags)                                                                         {}
	virtual SAuxGeomRenderFlags GetRenderFlags()                                                                                                               { return SAuxGeomRenderFlags(); }

	virtual void                DrawPoint(const Vec3& v, const ColorB& col, uint8 size = 1)                                                                    {}
	virtual void                DrawPoints(const Vec3* v, uint32 numPoints, const ColorB& col, uint8 size = 1)                                                 {}
	virtual void                DrawPoints(const Vec3* v, uint32 numPoints, const ColorB* col, uint8 size = 1)                                                 {}

	virtual void                DrawLine(const Vec3& v0, const ColorB& colV0, const Vec3& v1, const ColorB& colV1, float thickness = 1.0f)                     {}
	virtual void                DrawLines(const Vec3* v, uint32 numPoints, const ColorB& col, float thickness = 1.0f)                                          {}
	virtual void                DrawLines(const Vec3* v, uint32 numPoints, const ColorB* col, float thickness = 1.0f)                                          {}
	virtual void                DrawLines(const Vec3* v, uint32 numPoints, const vtx_idx* ind, uint32 numIndices, const ColorB& col, float thickness = 1.0f)   {}
	virtual void                DrawLines(const Vec3* v, uint32 numPoints, const vtx_idx* ind, uint32 numIndices, const ColorB* col, float thickness = 1.0f)   {}
	virtual void                DrawPolyline(const Vec3* v, uint32 numPoints, bool closed, const ColorB& col, float thickness = 1.0f)                          {}
	virtual void                DrawPolyline(const Vec3* v, uint32 numPoints, bool closed, const ColorB* col, float thickness = 1.0f)                          {}

	virtual void                DrawTriangle(const Vec3& v0, const ColorB& colV0, const Vec3& v1, const ColorB& colV1, const Vec3& v2, const ColorB& colV2)    {}
	virtual void                DrawTriangles(const Vec3* v, uint32 numPoints, const ColorB& col)                                                              {}
	virtual void                DrawTriangles(const Vec3* v, uint32 numPoints, const ColorB* col)                                                              {}
	virtual void                DrawTriangles(const Vec3* v, uint32 numPoints, const vtx_idx* ind, uint32 numIndices, const ColorB& col)                       {}
	virtual void                DrawTriangles(const Vec3* v, uint32 numPoints, const vtx_idx* ind, uint32 numIndices, const ColorB* col)                       {}

	virtual void                DrawAABB(const AABB& aabb, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle)                           {}
	virtual void                DrawAABBs(const AABB* aabbs, uint32 aabbCount, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle)       {}
	virtual void                DrawAABB(const AABB& aabb, const Matrix34& matWorld, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle) {}

	virtual void                DrawOBB(const OBB& obb, const Vec3& pos, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle)             {}
	virtual void                DrawOBB(const OBB& obb, const Matrix34& matWorld, bool bSolid, const ColorB& col, const EBoundingBoxDrawStyle& bbDrawStyle)    {}

	virtual void                DrawSphere(const Vec3& pos, float radius, const ColorB& col, bool drawShaded = true)                                           {}
	virtual void                DrawCone(const Vec3& pos, const Vec3& dir, float radius, float height, const ColorB& col, bool drawShaded = true)              {}
	virtual void                DrawCylinder(const Vec3& pos, const Vec3& dir, float radius, float height, const ColorB& col, bool drawShaded = true)          {}

	virtual void                DrawBone(const Vec3& rParent, const Vec3& rBone, ColorB col)                                                                   {}

	virtual void                RenderText(Vec3 pos, SDrawTextInfo& ti, const char* format, va_list args)                                                      {}

	virtual int                 PushMatrix(const Matrix34&  mat)                                                                                                      { return -1; }
	virtual Matrix34*           GetMatrix()                                                                                                                    { return nullptr; }
	virtual void                SetMatrixIndex(int matID)                                                                                                    {}

	virtual void                Flush()                                                                                                                        {}
	virtual void                Commit(uint frames = 0)                                                                                                        {}

public:
	CAuxGeomCB_Null() {}
	~CAuxGeomCB_Null() {}
};

#endif // #ifndef _RENDERAUXGEOMNULL_H_
