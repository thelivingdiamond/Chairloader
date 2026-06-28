// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// CAdvantagePointOccupancyControl
// Header:  Prey/GameDll/ai/AdvantagePointOccupancyControl.h
class CAdvantagePointOccupancyControl
{ // Size=16 (0x10)
public:
	using OccupiedAdvantagePoints = std::map<unsigned int, Vec3>;

	std::map<unsigned int, Vec3> m_occupiedAdvantagePoints;

	CAdvantagePointOccupancyControl();
	~CAdvantagePointOccupancyControl();
	void Reset() { FReset(this); }
	void OccupyAdvantagePoint(unsigned entityId, const Vec3& position) { FOccupyAdvantagePoint(this, entityId, position); }
	void ReleaseAdvantagePoint(unsigned entityId) { FReleaseAdvantagePoint(this, entityId); }
	bool IsAdvantagePointOccupied(const Vec3& position) const { return FIsAdvantagePointOccupiedOv1(this, position); }
	bool IsAdvantagePointOccupied(const Vec3& position, const unsigned ignoreEntityId) const { return FIsAdvantagePointOccupiedOv0(this, position, ignoreEntityId); }
	void Update() { FUpdate(this); }

#if 0
	bool MatchAdvantagePointPosition(const Vec3& _arg0_, const Vec3& _arg1_) const;
#endif

	static inline auto FCAdvantagePointOccupancyControlOv1 = PreyFunction<void(CAdvantagePointOccupancyControl* const _this)>(0x10C01F0);
	static inline auto FBitNotCAdvantagePointOccupancyControl = PreyFunction<void(CAdvantagePointOccupancyControl* const _this)>(0x10C0220);
	static inline auto FReset = PreyFunction<void(CAdvantagePointOccupancyControl* const _this)>(0x2F8A40);
	static inline auto FOccupyAdvantagePoint = PreyFunction<void(CAdvantagePointOccupancyControl* const _this, unsigned entityId, const Vec3& position)>(0x10C03E0);
	static inline auto FReleaseAdvantagePoint = PreyFunction<void(CAdvantagePointOccupancyControl* const _this, unsigned entityId)>(0x10C0460);
	static inline auto FIsAdvantagePointOccupiedOv1 = PreyFunction<bool(const CAdvantagePointOccupancyControl* const _this, const Vec3& position)>(0x10C0250);
	static inline auto FIsAdvantagePointOccupiedOv0 = PreyFunction<bool(const CAdvantagePointOccupancyControl* const _this, const Vec3& position, const unsigned ignoreEntityId)>(0x10C0320);
	static inline auto FUpdate = PreyFunction<void(CAdvantagePointOccupancyControl* const _this)>(0x1333E90);
};
#endif // MOONCRASH
