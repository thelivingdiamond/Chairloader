// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkPlayerMimicRigidController;
class CCryName;
struct IEntity;
struct IPhysicalEntity;

// ArkMimicCameraCylinder
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidCamera.h
class ArkMimicCameraCylinder
{ // Size=20 (0x14)
public:
	Vec3 m_position;
	float m_radius;
	float m_height;

	Vec3 GetPointOnCylinder(const Vec3& _position) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPointOnCylinder(this, reinterpret_cast<Vec3*>(_return_buf_), _position); }

#if 0
	ArkMimicCameraCylinder();
	Vec3 GetPointOnSphere(const Vec3& _arg0_) const;
	float GetRadius() const;
	float GetHeight() const;
	void SetRadius(const float _arg0_);
	void SetHeight(const float _arg0_);
	void SetPosition(const Vec3& _arg0_);
	void Serialize(TSerialize _arg0_);
#endif

	static inline auto FGetPointOnCylinder = PreyFunction<Vec3*(const ArkMimicCameraCylinder* const _this, Vec3* _return_value_, const Vec3& _position)>(0x1317EC0);
};

// ArkMimicCameraPathFinder
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidCamera.h
class ArkMimicCameraPathFinder
{ // Size=24 (0x18)
public:
	// ArkMimicCameraPathFinder::PathNode
	// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidCamera.h
	struct PathNode
	{ // Size=12 (0xC)
		Vec3 m_position;

	#if 0
		PathNode();
		PathNode(const Vec3& _arg0_);
		bool operator==(const ArkMimicCameraPathFinder::PathNode& _arg0_) const;
	#endif
	};

	std::vector<ArkMimicCameraPathFinder::PathNode> m_path;

	void Update(const Vec3& _position) { FUpdate(this, _position); }

#if 0
	Vec3 GetBest(const Vec3& _arg0_, const Vec3& _arg1_);
	Vec3 GetNearest(const Vec3& _arg0_, const float _arg1_);
#endif

	static inline auto FUpdate = PreyFunction<void(ArkMimicCameraPathFinder* const _this, const Vec3& _position)>(0x1318730);
};

// ArkPlayerMimicRigidCamera
// Header:  Prey/GameDll/ark/player/psipower/ArkPlayerMimicRigidCamera.h
class ArkPlayerMimicRigidCamera
{ // Size=408 (0x198)
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
	std::array<Vec3_tpl<float>,20> m_positionCorrectionVectors;
	float m_pitchDelta;
	float m_positionLerpSpeed;
	int m_updateCorrectionVectorIndex;
	bool m_bInGravShaft;

	ArkPlayerMimicRigidCamera();
	virtual ~ArkPlayerMimicRigidCamera();
	void Update(const float _frameTime, const IEntity& _mimicEntity) { FUpdate(this, _frameTime, _mimicEntity); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Quat GetRotation() const { alignas(Quat) std::byte _return_buf_[sizeof(Quat)]; return *FGetRotation(this, reinterpret_cast<Quat*>(_return_buf_)); }
	void SetPosition(const Vec3& _position) { FSetPosition(this, _position); }
	void SetRotation(const Quat& _rotation) { FSetRotation(this, _rotation); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void UpdatePositionCorrection(const float _frameTime) { FUpdatePositionCorrection(this, _frameTime); }
	void UpdateG(const float _frameTime, const IEntity& _mimicEntity) { FUpdateG(this, _frameTime, _mimicEntity); }
	void UpdateZeroG(const float _frameTime, const IEntity& _mimicEntity) { FUpdateZeroG(this, _frameTime, _mimicEntity); }
	void UpdateGravShaft(const float _frameTime, const IEntity& _mimicEntity) { FUpdateGravShaft(this, _frameTime, _mimicEntity); }
	void UpdateCameraCylinderRadius(const float _frameTime, const float _radialSpeed, const float _maxRadius, IPhysicalEntity* _pIgnoreEntity) { FUpdateCameraCylinderRadius(this, _frameTime, _radialSpeed, _maxRadius, _pIgnoreEntity); }
	bool HasStaticCollision(const Vec3& _start, const Vec3& _end, IPhysicalEntity* _pIgnoreEntity) const { return FHasStaticCollision(this, _start, _end, _pIgnoreEntity); }

#if 0
	void Initialize(const ArkPlayerMimicRigidController& _arg0_);
	void SetInGravShaft(const bool _arg0_);
	void ProcessInput(const CCryName& _arg0_, const bool _arg1_);
#endif

	static inline auto FArkPlayerMimicRigidCameraOv1 = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this)>(0x1317AA0);
	static inline auto FBitNotArkPlayerMimicRigidCamera = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this)>(0x1317B50);
	static inline auto FUpdate = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x1318820);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkPlayerMimicRigidCamera* const _this, Vec3* _return_value_)>(0x1318180);
	static inline auto FGetRotation = PreyFunction<Quat*(const ArkPlayerMimicRigidCamera* const _this, Quat* _return_value_)>(0x13181B0);
	static inline auto FSetPosition = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const Vec3& _position)>(0x1318630);
	static inline auto FSetRotation = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const Quat& _rotation)>(0x13186D0);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, TSerialize _ser)>(0x13183A0);
	static inline auto FUpdatePositionCorrection = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const float _frameTime)>(0x131AA60);
	static inline auto FUpdateG = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x1318B40);
	static inline auto FUpdateZeroG = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x131AF00);
	static inline auto FUpdateGravShaft = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const float _frameTime, const IEntity& _mimicEntity)>(0x131A250);
	static inline auto FUpdateCameraCylinderRadius = PreyFunction<void(ArkPlayerMimicRigidCamera* const _this, const float _frameTime, const float _radialSpeed, const float _maxRadius, IPhysicalEntity* _pIgnoreEntity)>(0x13188A0);
	static inline auto FHasStaticCollision = PreyFunction<bool(const ArkPlayerMimicRigidCamera* const _this, const Vec3& _start, const Vec3& _end, IPhysicalEntity* _pIgnoreEntity)>(0x1318280);
};

