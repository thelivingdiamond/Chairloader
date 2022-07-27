// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/IArkGlooIslandNavLinkManager.h>

// Header: Exact
// Prey/GameDll/ark/arkglooislandnavlinkmanager.h
class CArkGlooIslandNavLinkManager : public IArkGlooIslandNavLinkManager // Id=8015E5A Size=80
{
public:
	static const float s_kGlooConnectDist;
	
	struct GlooIsland // Id=8015E5B Size=184
	{
		enum class ELinkDirection
		{
			None = 0,
			X = 1,
			Y = 2,
			XPosYPos = 4,
			XPosYNeg = 8,
			XNegYPos = 16,
			XNegYNeg = 32,
		};

		std::vector<unsigned int> m_glooIds;
		ArkOffMeshLinkHelper m_navLinksForward;
		ArkOffMeshLinkHelper m_navLinksReverse;
		unsigned m_navLinkEntityId;
		std::vector<unsigned int> m_linkDirections;
		AABB m_aabb;
		float m_rebuildNavLinksTimer;
		
		GlooIsland();
		void Add(const unsigned _glooId, bool _bStatic) { FAdd(this,_glooId,_bStatic); }
		AABB CalcAABB() const { return FCalcAABB(this); }
		void Destroy() { FDestroy(this); }
		void BuildLinks() { FBuildLinks(this); }
		void ClearLinks() { FClearLinks(this); }
		void SetLinkDirections(bool _bStatic) { FSetLinkDirections(this,_bStatic); }
		bool IsLinkValid(TNavigationID<1> _agentTypeId, Vec3 const &_start, Vec3 const &_end, bool _bStatic, std::vector<IPhysicalEntity *> &_ignores) const { return FIsLinkValid(this,_agentTypeId,_start,_end,_bStatic,_ignores); }
		
#if 0
		void Serialize(TSerialize arg0);
		bool Remove(const unsigned arg0);
		bool IsInside(const unsigned arg0) const;
		bool IsEmpty() const;
		bool IsRemovingLinks() const;
		bool Contains(const unsigned arg0) const;
		void RebuildLinks();
		bool IsAgentTypeSupported(TNavigationID<1> arg0, AABB const &arg1) const;
#endif
		
		static inline auto FAdd = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this, const unsigned _glooId, bool _bStatic)>(0x117F140);
		static inline auto FCalcAABB = PreyFunction<AABB(CArkGlooIslandNavLinkManager::GlooIsland const *const _this)>(0x1180D10);
		static inline auto FDestroy = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this)>(0x1180EE0);
		static inline auto FBuildLinks = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this)>(0x117F410);
		static inline auto FClearLinks = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this)>(0x1180E80);
		static inline auto FSetLinkDirections = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this, bool _bStatic)>(0x1181970);
		static inline auto FIsLinkValid = PreyFunction<bool(CArkGlooIslandNavLinkManager::GlooIsland const *const _this, TNavigationID<1> _agentTypeId, Vec3 const &_start, Vec3 const &_end, bool _bStatic, std::vector<IPhysicalEntity *> &_ignores)>(0x11811C0);
	};

	static constexpr const int k_invalidIslandId = 0;
	int m_nextIslandId;
	
	using GlooIslandList = std::unordered_map<int,CArkGlooIslandNavLinkManager::GlooIsland>;
	
	std::unordered_map<int,CArkGlooIslandNavLinkManager::GlooIsland> m_glooIslands;
	
	void Shutdown() { FShutdown(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Add(const unsigned _glooId, bool _bStatic) { FAdd(this,_glooId,_bStatic); }
	void Remove(const unsigned _glooId) { FRemove(this,_glooId); }
	void Break(const unsigned _glooId) { FBreak(this,_glooId); }
	virtual unsigned GetNearbyGlooIslandEntityId(Vec3 const &_pos, float _radius);
	
	static inline auto FShutdown = PreyFunction<void(CArkGlooIslandNavLinkManager *const _this)>(0x1182080);
	static inline auto FSerialize = PreyFunction<void(CArkGlooIslandNavLinkManager *const _this, TSerialize _ser)>(0x1181670);
	static inline auto FReset = PreyFunction<void(CArkGlooIslandNavLinkManager *const _this)>(0x1181550);
	static inline auto FUpdate = PreyFunction<void(CArkGlooIslandNavLinkManager *const _this, const float _frameTime)>(0x1182090);
	static inline auto FAdd = PreyFunction<void(CArkGlooIslandNavLinkManager *const _this, const unsigned _glooId, bool _bStatic)>(0x117EA50);
	static inline auto FRemove = PreyFunction<void(CArkGlooIslandNavLinkManager *const _this, const unsigned _glooId)>(0x1181440);
	static inline auto FBreak = PreyFunction<void(CArkGlooIslandNavLinkManager *const _this, const unsigned _glooId)>(0x117F1C0);
	static inline auto FGetNearbyGlooIslandEntityId = PreyFunction<unsigned(CArkGlooIslandNavLinkManager *const _this, Vec3 const &_pos, float _radius)>(0x1180F70);
};

