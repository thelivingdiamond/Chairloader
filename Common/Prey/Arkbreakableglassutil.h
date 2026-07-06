// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryRenderer/VertexFormats.h>
#include <_unknown/FragEdge.h>

// ArkGlassFrag
// Header:  Prey/Arkbreakableglassutil.h
class ArkGlassFrag
{ // Size=36 (0x24)
public:
	int stability;
	AABB m_bounds;
	int m_offset;
	int m_count;

	float GetVolume() const { return FGetVolume(this); }

#if 0
	ArkGlassFrag();
	ArkGlassFrag(int _arg0_, int _arg1_, const AABB& _arg2_, unsigned _arg3_);
	Vec3 lsCenter() const;
	AABB GetBBox() const;
	void SetOffset(int _arg0_);
	int Offset() const;
	int Count() const;
#endif

	static inline auto FGetVolume = PreyFunction<float(const ArkGlassFrag* const _this)>(0xD01C0);
};

// ArkGlassGeo
// Header:  Prey/Arkbreakableglassutil.h
class ArkGlassGeo
{ // Size=112 (0x70)
public:
	std::vector<SVF_P3F_C4B_T2F> m_vertices;
	std::vector<SPipTangents> m_tangents;
	std::vector<FragEdge> m_edges;
	SPipTangents m_tanFront;
	SPipTangents m_tanBack;
	int m_head;
	int m_tail;

	ArkGlassGeo(uint64_t _capacity);
	ArkGlassFrag Insert(const ArkGlassFrag& _frag, const ArkGlassGeo& _geo) { alignas(ArkGlassFrag) std::byte _return_buf_[sizeof(ArkGlassFrag)]; return *FInsert(this, reinterpret_cast<ArkGlassFrag*>(_return_buf_), _frag, _geo); }
	uint64_t EdgeCount() const { return FEdgeCount(this); }

#if 0
	int NextHead(int _arg0_, int _arg1_, int _arg2_);
	bool AddData(const SVF_P3F_C4B_T2F& _arg0_, const SPipTangents& _arg1_, const SVF_P3F_C4B_T2F& _arg2_, const SPipTangents& _arg3_, const FragEdge& _arg4_);
	void Reset();
	void Release(int _arg0_, int _arg1_);
	uint64_t MaxEdges() const;
	int Head() const;
	void FillFragData(std::vector<SVF_P3F_C4B_T2F>& _arg0_, std::vector<SVF_P3F_C4B_T2F>& _arg1_, std::vector<FragEdge>& _arg2_, const ArkGlassFrag& _arg3_) const;
	const SVF_P3F_C4B_T2F* VertexData(long _arg0_) const;
	const SPipTangents* TangentData(long _arg0_) const;
	const FragEdge* EdgeData(long _arg0_) const;
	void SetTangents(const SPipTangents& _arg0_, const SPipTangents& _arg1_);
	void GetTangents(SPipTangents& _arg0_, SPipTangents& _arg1_) const;
#endif

	static inline auto FArkGlassGeoOv2 = PreyFunction<void(ArkGlassGeo* const _this, uint64_t _capacity)>(0xCADC0);
	static inline auto FInsert = PreyFunction<ArkGlassFrag*(ArkGlassGeo* const _this, ArkGlassFrag* _return_value_, const ArkGlassFrag& _frag, const ArkGlassGeo& _geo)>(0xD04A0);
	static inline auto FEdgeCount = PreyFunction<uint64_t(const ArkGlassGeo* const _this)>(0xCFCE0);
};
#endif // MOONCRASH
