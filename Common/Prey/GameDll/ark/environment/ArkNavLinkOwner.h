// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ai/ArkOffMeshLinkHelper.h>
#include <_unknown/TNavigationID.h>

struct IGameObjectExtension;

// ArkNavLinkOwner
// Header:  Prey/GameDll/ark/environment/ArkNavLinkOwner.h
class ArkNavLinkOwner
{ // Size=136 (0x88)
public:
	ArkOffMeshLinkHelper m_navLinksForward;
	ArkOffMeshLinkHelper m_navLinksReverse;
	IGameObjectExtension& m_owningExtension;
	Vec3 m_linkPosOffset;
	ArkSimpleTimer m_updateEditorPosTimer;
	bool m_bRebuildLinks;

	ArkNavLinkOwner(IGameObjectExtension& _extension);
	void OnRelease() { FOnRelease(this); }
	void OnNavMeshChange() { FOnNavMeshChange(this); }
	void RebuildLinks() { FRebuildLinks(this); }
	virtual void ClearLinks();
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void RequestRebuildLinks() { FRequestRebuildLinks(this); }
	void LoadProperties() { FLoadProperties(this); }
	void CalculateLinkPositions(TNavigationID<1> _navAgentID, Vec3& _start, Vec3& _end, Vec3& _startOffsetDirection, Vec3& _endOffsetDirection) const { FCalculateLinkPositions(this, _navAgentID, _start, _end, _startOffsetDirection, _endOffsetDirection); }
	bool TestValidMeshLinkPositions(TNavigationID<1> _navAgentID, Vec3& _start, Vec3& _end, float _radius, bool _bGloo) const { return FTestValidMeshLinkPositions(this, _navAgentID, _start, _end, _radius, _bGloo); }
	bool OffsetForNearbyGloo(Vec3& _position, const Vec3& _offsetDirection) const { return FOffsetForNearbyGloo(this, _position, _offsetDirection); }

#if 0
	bool CalculateValidMeshLinkPositions(TNavigationID<1> _arg0_, Vec3& _arg1_, Vec3& _arg2_) const;
	bool CalculateValidGridLinkPositions(TNavigationID<1> _arg0_, Vec3& _arg1_, Vec3& _arg2_) const;
	bool TestValidGridLinkPositions(TNavigationID<1> _arg0_, Vec3& _arg1_, Vec3& _arg2_) const;
#endif

	static inline auto FArkNavLinkOwnerOv2 = PreyFunction<void(ArkNavLinkOwner* const _this, IGameObjectExtension& _extension)>(0x11CE600);
	static inline auto FOnRelease = PreyFunction<void(ArkNavLinkOwner* const _this)>(0x11CEE70);
	static inline auto FOnNavMeshChange = PreyFunction<void(ArkNavLinkOwner* const _this)>(0x11CEE40);
	static inline auto FRebuildLinks = PreyFunction<void(ArkNavLinkOwner* const _this)>(0x11CEEA0);
	static inline auto FClearLinks = PreyFunction<void(ArkNavLinkOwner* const _this)>(0x11CEAE0);
	static inline auto FUpdate = PreyFunction<void(ArkNavLinkOwner* const _this, float _frameTime)>(0x11CFC50);
	static inline auto FRequestRebuildLinks = PreyFunction<void(ArkNavLinkOwner* const _this)>(0x11CEE40);
	static inline auto FLoadProperties = PreyFunction<void(ArkNavLinkOwner* const _this)>(0x11CEB60);
	static inline auto FCalculateLinkPositions = PreyFunction<void(const ArkNavLinkOwner* const _this, TNavigationID<1> _navAgentID, Vec3& _start, Vec3& _end, Vec3& _startOffsetDirection, Vec3& _endOffsetDirection)>(0x11CE670);
	static inline auto FTestValidMeshLinkPositions = PreyFunction<bool(const ArkNavLinkOwner* const _this, TNavigationID<1> _navAgentID, Vec3& _start, Vec3& _end, float _radius, bool _bGloo)>(0x11CF860);
	static inline auto FOffsetForNearbyGloo = PreyFunction<bool(const ArkNavLinkOwner* const _this, Vec3& _position, const Vec3& _offsetDirection)>(0x11CED40);
};
#endif // MOONCRASH
