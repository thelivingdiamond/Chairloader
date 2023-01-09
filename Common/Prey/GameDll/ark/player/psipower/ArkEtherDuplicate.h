// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

class ArkEtherDuplicateAttentionObject;
class ArkEtherDuplicateAction;
struct IEntity;

// ArkEtherDuplicate
// Header:  Prey/GameDll/ark/player/psipower/ArkEtherDuplicate.h
class ArkEtherDuplicate
{ // Size=48 (0x30)
public:
	enum class ArkShiftDirection
	{
		Forward = 0,
		Backward = 1,
		Left = 2,
		Right = 3,
	};

	Vec3 m_eyeOffset;
	Ang3 m_viewRotation;
	_smart_ptr<ArkEtherDuplicateAction> m_pAction;
	std::unique_ptr<ArkEtherDuplicateAttentionObject> m_pAttentionObject;
	unsigned m_entityId;
	ArkEtherDuplicate::ArkShiftDirection m_shiftDirection;

	ArkEtherDuplicate(const unsigned _entityId);
	ArkEtherDuplicate(const char* _pArchetypeName, const Vec3& _position, const Quat& _rotation, const Quat& _viewRotation, const ArkEtherDuplicate::ArkShiftDirection _shiftDirection);
	~ArkEtherDuplicate();
	Vec3 GetHeadPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetHeadPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetChestPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetChestPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	QuatT GetEyePositionRotation() const { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FGetEyePositionRotation(this, reinterpret_cast<QuatT*>(_return_buf_)); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void SpawnAnimatedCharacter(IEntity& _entity) { FSpawnAnimatedCharacter(this, _entity); }
	void EnableAttentionObject(const bool _bEnable) { FEnableAttentionObject(this, _bEnable); }

#if 0
	ArkEtherDuplicate();
	unsigned GetEntityId() const;
#endif

	static inline auto FArkEtherDuplicateOv1 = PreyFunction<void(ArkEtherDuplicate* const _this, const unsigned _entityId)>(0x1469CE0);
	static inline auto FArkEtherDuplicateOv0 = PreyFunction<void(ArkEtherDuplicate* const _this, const char* _pArchetypeName, const Vec3& _position, const Quat& _rotation, const Quat& _viewRotation, const ArkEtherDuplicate::ArkShiftDirection _shiftDirection)>(0x1469DB0);
	static inline auto FBitNotArkEtherDuplicate = PreyFunction<void(ArkEtherDuplicate* const _this)>(0x146A0D0);
	static inline auto FGetHeadPosition = PreyFunction<Vec3*(const ArkEtherDuplicate* const _this, Vec3* _return_value_)>(0x146A720);
	static inline auto FGetChestPosition = PreyFunction<Vec3*(const ArkEtherDuplicate* const _this, Vec3* _return_value_)>(0x146A480);
	static inline auto FGetEyePositionRotation = PreyFunction<QuatT*(const ArkEtherDuplicate* const _this, QuatT* _return_value_)>(0x146A4F0);
	static inline auto FSerialize = PreyFunction<void(ArkEtherDuplicate* const _this, TSerialize _ser)>(0x146A9F0);
	static inline auto FSpawnAnimatedCharacter = PreyFunction<void(ArkEtherDuplicate* const _this, IEntity& _entity)>(0x146AA90);
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkEtherDuplicate* const _this, const bool _bEnable)>(0x146A390);
};

