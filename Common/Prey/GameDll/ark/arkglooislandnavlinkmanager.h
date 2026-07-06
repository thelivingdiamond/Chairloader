// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
		bool IsLinkValid(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _agentTypeId, Vec3 const &_start, Vec3 const &_end, bool _bStatic, std::vector<IPhysicalEntity *> &_ignores) const { return FIsLinkValid(this,_agentTypeId,_start,_end,_bStatic,_ignores); }
		
#if 0
		void Serialize(TSerialize arg0);
		bool Remove(const unsigned arg0);
		bool IsInside(const unsigned arg0) const;
		bool IsEmpty() const;
		bool IsRemovingLinks() const;
		bool Contains(const unsigned arg0) const;
		void RebuildLinks();
		bool IsAgentTypeSupported(TNavigationID<ENavigationIDTag::AgentTypeIDTag> arg0, AABB const &arg1) const;
#endif
		
		static inline auto FAdd = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this, const unsigned _glooId, bool _bStatic)>(0x117F140);
		static inline auto FCalcAABB = PreyFunction<AABB(CArkGlooIslandNavLinkManager::GlooIsland const *const _this)>(0x1180D10);
		static inline auto FDestroy = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this)>(0x1180EE0);
		static inline auto FBuildLinks = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this)>(0x117F410);
		static inline auto FClearLinks = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this)>(0x1180E80);
		static inline auto FSetLinkDirections = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland *const _this, bool _bStatic)>(0x1181970);
		static inline auto FIsLinkValid = PreyFunction<bool(CArkGlooIslandNavLinkManager::GlooIsland const *const _this, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _agentTypeId, Vec3 const &_start, Vec3 const &_end, bool _bStatic, std::vector<IPhysicalEntity *> &_ignores)>(0x11811C0);
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ai/ArkOffMeshLinkHelper.h>
#include <Prey/GameDll/ark/weapons/IArkGlooIslandNavLinkManager.h>
#include <_unknown/TNavigationID.h>

struct IPhysicalEntity;

// CArkGlooIslandNavLinkManager
// Header:  Prey/GameDll/ark/ArkGlooIslandNavLinkManager.h
class CArkGlooIslandNavLinkManager : public IArkGlooIslandNavLinkManager
{ // Size=80 (0x50)
public:
	// CArkGlooIslandNavLinkManager::GlooIsland
	// Header:  Prey/GameDll/ark/ArkGlooIslandNavLinkManager.h
	struct GlooIsland
	{ // Size=184 (0xB8)
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
		void Add(const unsigned _glooId, bool _bStatic) { FAdd(this, _glooId, _bStatic); }
		AABB CalcAABB() const { alignas(AABB) std::byte _return_buf_[sizeof(AABB)]; return *FCalcAABB(this, reinterpret_cast<AABB*>(_return_buf_)); }
		void Destroy() { FDestroy(this); }
		void BuildLinks() { FBuildLinks(this); }
		void ClearLinks() { FClearLinks(this); }
		void SetLinkDirections(bool _bStatic) { FSetLinkDirections(this, _bStatic); }
		bool IsLinkValid(TNavigationID<1> _agentTypeId, const Vec3& _start, const Vec3& _end, bool _bStatic, std::vector<IPhysicalEntity*>& _ignores) const { return FIsLinkValid(this, _agentTypeId, _start, _end, _bStatic, _ignores); }

	#if 0
		~GlooIsland();
		void Serialize(TSerialize _arg0_);
		bool Remove(const unsigned _arg0_);
		bool IsInside(const unsigned _arg0_) const;
		bool IsEmpty() const;
		bool IsRemovingLinks() const;
		bool Contains(const unsigned _arg0_) const;
		void RebuildLinks();
		bool IsAgentTypeSupported(TNavigationID<1> _arg0_, const AABB& _arg1_) const;
	#endif

		static inline auto FGlooIslandOv1 = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland* const _this)>(0x11F9D00);
		static inline auto FAdd = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland* const _this, const unsigned _glooId, bool _bStatic)>(0x11FA4B0);
		static inline auto FCalcAABB = PreyFunction<AABB*(const CArkGlooIslandNavLinkManager::GlooIsland* const _this, AABB* _return_value_)>(0x11FC080);
		static inline auto FDestroy = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland* const _this)>(0x11FC250);
		static inline auto FBuildLinks = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland* const _this)>(0x11FA780);
		static inline auto FClearLinks = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland* const _this)>(0x11FC1F0);
		static inline auto FSetLinkDirections = PreyFunction<void(CArkGlooIslandNavLinkManager::GlooIsland* const _this, bool _bStatic)>(0x11FCCE0);
		static inline auto FIsLinkValid = PreyFunction<bool(const CArkGlooIslandNavLinkManager::GlooIsland* const _this, TNavigationID<1> _agentTypeId, const Vec3& _start, const Vec3& _end, bool _bStatic, std::vector<IPhysicalEntity*>& _ignores)>(0x11FC530);
	};

	using GlooIslandList = std::unordered_map<int, CArkGlooIslandNavLinkManager::GlooIsland>;

	static inline auto s_kGlooConnectDist = PreyGlobal<const float>(0x1F33938);
	static constexpr const int k_invalidIslandId = 0;
	int m_nextIslandId;
	std::unordered_map<int, CArkGlooIslandNavLinkManager::GlooIsland> m_glooIslands;

	void Shutdown() { FShutdown(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void Reset() { FReset(this); }
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Add(const unsigned _glooId, bool _bStatic) { FAdd(this, _glooId, _bStatic); }
	void Remove(const unsigned _glooId) { FRemove(this, _glooId); }
	void Break(const unsigned _glooId) { FBreak(this, _glooId); }
	virtual unsigned GetNearbyGlooIslandEntityId(const Vec3& _pos, float _radius);

#if 0
	CArkGlooIslandNavLinkManager();
#endif

	static inline auto FShutdown = PreyFunction<void(CArkGlooIslandNavLinkManager* const _this)>(0x11FD3F0);
	static inline auto FSerialize = PreyFunction<void(CArkGlooIslandNavLinkManager* const _this, TSerialize _ser)>(0x11FC9E0);
	static inline auto FReset = PreyFunction<void(CArkGlooIslandNavLinkManager* const _this)>(0x11FC8C0);
	static inline auto FUpdate = PreyFunction<void(CArkGlooIslandNavLinkManager* const _this, const float _frameTime)>(0x11FD400);
	static inline auto FAdd = PreyFunction<void(CArkGlooIslandNavLinkManager* const _this, const unsigned _glooId, bool _bStatic)>(0x11F9DC0);
	static inline auto FRemove = PreyFunction<void(CArkGlooIslandNavLinkManager* const _this, const unsigned _glooId)>(0x11FC7B0);
	static inline auto FBreak = PreyFunction<void(CArkGlooIslandNavLinkManager* const _this, const unsigned _glooId)>(0x11FA530);
	static inline auto FGetNearbyGlooIslandEntityId = PreyFunction<unsigned(CArkGlooIslandNavLinkManager* const _this, const Vec3& _pos, float _radius)>(0x11FC2E0);
};
#endif // !MOONCRASH
