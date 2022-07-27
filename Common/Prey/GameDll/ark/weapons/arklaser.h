// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arklaser.h
class CArkLaserBeam : public _i_reference_target<int> // Id=80197FC Size=48
{
public:
	struct ArkLaserParams // Id=80197FD Size=32
	{
		string m_initialBeamGeometry;
		string m_reflectedBeamGeometry;
		float m_minThickness;
		float m_maxThickness;
		int m_numReflections;
		int m_laserSubMaterial;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	CArkLaserBeam::ArkLaserParams const *m_pLaserParams;
	bool m_bLaserOn;
	unsigned m_ownerEntityId;
	unsigned m_laserEntityId;
	int m_laserGeometrySlot;
	float m_lastLength;
	float m_thicknessScale;
	
	CArkLaserBeam();
	virtual ~CArkLaserBeam();
	void Initialize(const bool _bInitialAmmo, const unsigned _ownerEntityId, const float _range, CArkLaserBeam::ArkLaserParams const *_pParams, const bool bIsPlayerWeapon) { FInitialize(this,_bInitialAmmo,_ownerEntityId,_range,_pParams,bIsPlayerWeapon); }
	void UpdateLaser(Vec3 const &_position, Vec3 const &_direction, Vec3 const &_upVector) { FUpdateLaser(this,_position,_direction,_upVector); }
	void SetLastLength(const float _lastLength) { FSetLastLength(this,_lastLength); }
	void TurnOnLaser() { FTurnOnLaser(this); }
	void TurnOffLaser() { FTurnOffLaser(this); }
	void SetLaserEntitySlots(const bool _freeSlots, const bool _bInitialAmmo, const bool bIsPlayerWeapon) { FSetLaserEntitySlots(this,_freeSlots,_bInitialAmmo,bIsPlayerWeapon); }
	void UpdateLaserMaterial() { FUpdateLaserMaterial(this); }
	
#if 0
	float GetLastLength() const;
	void SetThicknessScale(const float arg0);
	float GetThicknessScale() const;
	void SetLaserEntityId(unsigned arg0);
	bool IsLaserActivated() const;
	IEntity *CreateLaserEntity(const bool arg0, const bool arg1);
	IEntity *GetLaserEntity();
#endif
	
	static inline auto FBitNotCArkLaserBeam = PreyFunction<void(CArkLaserBeam *const _this)>(0x16436F0);
	static inline auto FInitialize = PreyFunction<void(CArkLaserBeam *const _this, const bool _bInitialAmmo, const unsigned _ownerEntityId, const float _range, CArkLaserBeam::ArkLaserParams const *_pParams, const bool bIsPlayerWeapon)>(0x1643860);
	static inline auto FUpdateLaser = PreyFunction<void(CArkLaserBeam *const _this, Vec3 const &_position, Vec3 const &_direction, Vec3 const &_upVector)>(0x1643BF0);
	static inline auto FSetLastLength = PreyFunction<void(CArkLaserBeam *const _this, const float _lastLength)>(0x1643B40);
	static inline auto FTurnOnLaser = PreyFunction<void(CArkLaserBeam *const _this)>(0x1643BA0);
	static inline auto FTurnOffLaser = PreyFunction<void(CArkLaserBeam *const _this)>(0x1643B60);
	static inline auto FSetLaserEntitySlots = PreyFunction<void(CArkLaserBeam *const _this, const bool _freeSlots, const bool _bInitialAmmo, const bool bIsPlayerWeapon)>(0x1643A10);
	static inline auto FUpdateLaserMaterial = PreyFunction<void(CArkLaserBeam *const _this)>(0x1644190);
};

