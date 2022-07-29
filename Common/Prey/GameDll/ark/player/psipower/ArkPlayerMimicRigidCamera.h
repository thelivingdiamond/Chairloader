// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/arkplayermimicrigidcamera.h>

class ArkPlayerMimicRigidController;
class CCryName;
struct IEntity;
struct IPhysicalEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayermimicrigidcamera.h
class ArkMimicCameraCylinder // Id=801B7F0 Size=20
{
public:
	Vec3 m_position;
	float m_radius;
	float m_height;
	
	Vec3 GetPointOnCylinder(Vec3 const &_position) const { return FGetPointOnCylinder(this,_position); }
	
#if 0
	Vec3 GetPointOnSphere(Vec3 const &arg0) const;
	float GetRadius() const;
	float GetHeight() const;
	void SetRadius(const float arg0);
	void SetHeight(const float arg0);
	void SetPosition(Vec3 const &arg0);
	void Serialize(TSerialize arg0);
#endif
	
	static inline auto FGetPointOnCylinder = PreyFunction<Vec3(ArkMimicCameraCylinder const *const _this, Vec3 const &_position)>(0x1317EC0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkplayermimicrigidcamera.h
class ArkMimicCameraPathFinder // Id=801B7F1 Size=24
{
public:
	struct PathNode // Id=801B7F2 Size=12
	{
		Vec3 m_position;
		
#if 0
		bool operator==(ArkMimicCameraPathFinder::PathNode const &arg0) const;
#endif
	};

	std::vector<ArkMimicCameraPathFinder::PathNode> m_path;
	
	void Update(Vec3 const &_position) { FUpdate(this,_position); }
	
#if 0
	Vec3 GetBest(Vec3 const &arg0, Vec3 const &arg1);
	Vec3 GetNearest(Vec3 const &arg0, const float arg1);
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkMimicCameraPathFinder *const _this, Vec3 const &_position)>(0x1318730);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidCamera.h
class ArkPlayerMimicRigidCamera // Id=801B808 Size=408
{
public:
	static constexpr const int s_numHalfAngleSteps = 10;
	ArkMimicCameraPathFinder m_pathFinder;
	ArkMimicCameraCylinder m_cameraCylinder;
	ArkSimpleTimer m_radiusTimer;
	Vec3 m_position;
	Vec3 m_positionOffset;
	Vec3 m_desiredPosition;
	Vec3 m_avgPositionCorrection;
	Quat m_rotation;
	Ang3 m_rotationAngles;
	Ang3 m_inputAngleVelocity;
	std::array<Vec3,20> m_positionCorrectionVectors;
	float m_pitchDelta;
	float m_positionLerpSpeed;
	int m_updateCorrectionVectorIndex;
	bool m_bInGravShaft;
	
	ArkPlayerMimicRigidCamera();
	virtual ~ArkPlayerMimicRigidCamera();
	void Update(const float _frameTime, IEntity const &_mimicEntity) { FUpdate(this,_frameTime,_mimicEntity); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	Quat GetRotation() const { return FGetRotation(this); }
	void SetPosition(Vec3 const &_position) { FSetPosition(this,_position); }
	void SetRotation(Quat const &_rotation) { FSetRotation(this,_rotation); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void UpdatePositionCorrection(const float _frameTime) { FUpdatePositionCorrection(this,_frameTime); }
	void UpdateG(const float _frameTime, IEntity const &_mimicEntity) { FUpdateG(this,_frameTime,_mimicEntity); }
	void UpdateZeroG(const float _frameTime, IEntity const &_mimicEntity) { FUpdateZeroG(this,_frameTime,_mimicEntity); }
	void UpdateGravShaft(const float _frameTime, IEntity const &_mimicEntity) { FUpdateGravShaft(this,_frameTime,_mimicEntity); }
	void UpdateCameraCylinderRadius(const float _frameTime, const float _radialSpeed, const float _maxRadius, IPhysicalEntity *_pIgnoreEntity) { FUpdateCameraCylinderRadius(this,_frameTime,_radialSpeed,_maxRadius,_pIgnoreEntity); }
	bool HasStaticCollision(Vec3 const &_start, Vec3 const &_end, IPhysicalEntity *_pIgnoreEntity) const { return FHasStaticCollision(this,_start,_end,_pIgnoreEntity); }
	
#if 0
	void Initialize(ArkPlayerMimicRigidController const &arg0);
	void SetInGravShaft(const bool arg0);
	void ProcessInput(CCryName const &arg0, const bool arg1);
#endif
	
	static inline auto FBitNotArkPlayerMimicRigidCamera = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this)>(0x1317B50);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, const float _frameTime, IEntity const &_mimicEntity)>(0x1318820);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkPlayerMimicRigidCamera const *const _this)>(0x1318180);
	static inline auto FGetRotation = PreyFunction<Quat(ArkPlayerMimicRigidCamera const *const _this)>(0x13181B0);
	static inline auto FSetPosition = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, Vec3 const &_position)>(0x1318630);
	static inline auto FSetRotation = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, Quat const &_rotation)>(0x13186D0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, TSerialize _ser)>(0x13183A0);
	static inline auto FUpdatePositionCorrection = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, const float _frameTime)>(0x131AA60);
	static inline auto FUpdateG = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, const float _frameTime, IEntity const &_mimicEntity)>(0x1318B40);
	static inline auto FUpdateZeroG = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, const float _frameTime, IEntity const &_mimicEntity)>(0x131AF00);
	static inline auto FUpdateGravShaft = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, const float _frameTime, IEntity const &_mimicEntity)>(0x131A250);
	static inline auto FUpdateCameraCylinderRadius = PreyFunction<void(ArkPlayerMimicRigidCamera *const _this, const float _frameTime, const float _radialSpeed, const float _maxRadius, IPhysicalEntity *_pIgnoreEntity)>(0x13188A0);
	static inline auto FHasStaticCollision = PreyFunction<bool(ArkPlayerMimicRigidCamera const *const _this, Vec3 const &_start, Vec3 const &_end, IPhysicalEntity *_pIgnoreEntity)>(0x1318280);
};

