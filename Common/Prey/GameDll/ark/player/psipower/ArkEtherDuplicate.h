// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

struct IEntity;

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/ArkEtherDuplicate.h
class ArkEtherDuplicate // Id=801930A Size=48
{
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
	ArkEtherDuplicate(const char *_pArchetypeName, Vec3 const &_position, Quat const &_rotation, Quat const &_viewRotation, ArkEtherDuplicate::ArkShiftDirection _shiftDirection);
	~ArkEtherDuplicate() { FBitNotArkEtherDuplicate(this); }
	Vec3 GetHeadPosition() const { return FGetHeadPosition(this); }
	Vec3 GetChestPosition() const { return FGetChestPosition(this); }
	QuatT GetEyePositionRotation() const { return FGetEyePositionRotation(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void SpawnAnimatedCharacter(IEntity &_entity) { FSpawnAnimatedCharacter(this,_entity); }
	void EnableAttentionObject(const bool _bEnable) { FEnableAttentionObject(this,_bEnable); }
	
#if 0
	unsigned GetEntityId() const;
#endif
	
	static inline auto FBitNotArkEtherDuplicate = PreyFunction<void(ArkEtherDuplicate *const _this)>(0x146A0D0);
	static inline auto FGetHeadPosition = PreyFunction<Vec3(ArkEtherDuplicate const *const _this)>(0x146A720);
	static inline auto FGetChestPosition = PreyFunction<Vec3(ArkEtherDuplicate const *const _this)>(0x146A480);
	static inline auto FGetEyePositionRotation = PreyFunction<QuatT(ArkEtherDuplicate const *const _this)>(0x146A4F0);
	static inline auto FSerialize = PreyFunction<void(ArkEtherDuplicate *const _this, TSerialize _ser)>(0x146A9F0);
	static inline auto FSpawnAnimatedCharacter = PreyFunction<void(ArkEtherDuplicate *const _this, IEntity &_entity)>(0x146AA90);
	static inline auto FEnableAttentionObject = PreyFunction<void(ArkEtherDuplicate *const _this, const bool _bEnable)>(0x146A390);
};

