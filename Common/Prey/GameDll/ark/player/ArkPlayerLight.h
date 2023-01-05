// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>

class IArkPlayerLightOwner;
struct IEntity;
struct ParticleLoc;
struct SEntityEvent;

// ArkPlayerLight
// Header:  Prey/GameDll/ark/player/ArkPlayerLight.h
class ArkPlayerLight
{ // Size=24 (0x18)
public:
	bool m_bWantsToBeVisible;
	bool m_bVisible;
	EArkPlayerLightPriority m_priority;
	IArkPlayerLightOwner* m_pOwner;

	void SetLightVisible(bool _bVisible) { FSetLightVisible(this, _bVisible); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual unsigned GetLightAttachmentEntity() const;
	virtual void AttachLightEntity() const;
	virtual void SpawnLightEntity();
	virtual void SetLightVisible_Internal(bool _bVisible) = 0;

#if 0
	ArkPlayerLight(EArkPlayerLightPriority _arg0_, IArkPlayerLightOwner* _arg1_);
	bool IsLightVisible() const;
	void SetLightWantsToBeVisible(bool _arg0_);
	bool DoesLightWantToBeVisible() const;
	EArkPlayerLightPriority GetPriority() const;
#endif

	static inline auto FSetLightVisible = PreyFunction<void(ArkPlayerLight* const _this, bool _bVisible)>(0x1238180);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerLight* const _this, TSerialize _ser)>(0x1238160);
	static inline auto FGetLightAttachmentEntity = PreyFunction<unsigned(const ArkPlayerLight* const _this)>(0x158AEF0);
	static inline auto FAttachLightEntity = PreyFunction<void(const ArkPlayerLight* const _this)>(0xA13080);
	static inline auto FSpawnLightEntity = PreyFunction<void(ArkPlayerLight* const _this)>(0xA13080);
};

// ArkPlayerLightEntity
// Header:  Prey/GameDll/ark/player/ArkPlayerLight.h
class ArkPlayerLightEntity : public ArkPlayerLight, public IEntityEventListener
{ // Size=56 (0x38)
public:
	unsigned m_attachmentEntity;
	unsigned m_lightEntity;
	string m_archetypeName;
	string m_attachmentName;

	virtual ~ArkPlayerLightEntity();
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	virtual unsigned GetLightAttachmentEntity() const;
	virtual void AttachLightEntity() const;
	virtual void SpawnLightEntity();
	void RemoveLightEntity() { FRemoveLightEntity(this); }
	virtual void SetLightVisible_Internal(bool _bVisible);

#if 0
	ArkPlayerLightEntity(EArkPlayerLightPriority _arg0_, IArkPlayerLightOwner* _arg1_);
	unsigned GetLightEntity() const;
	bool HasValidData() const;
	void SetData(const string& _arg0_, const string& _arg1_, unsigned _arg2_);
	void CleanupLightEntity();
#endif

	static inline auto FBitNotArkPlayerLightEntity = PreyFunction<void(ArkPlayerLightEntity* const _this)>(0x1237E60);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x12380C0);
	static inline auto FGetLightAttachmentEntity = PreyFunction<unsigned(const ArkPlayerLightEntity* const _this)>(0x12380B0);
	static inline auto FAttachLightEntity = PreyFunction<void(const ArkPlayerLightEntity* const _this)>(0x1237FF0);
	static inline auto FSpawnLightEntity = PreyFunction<void(ArkPlayerLightEntity* const _this)>(0x1238220);
	static inline auto FRemoveLightEntity = PreyFunction<void(ArkPlayerLightEntity* const _this)>(0x1238110);
	static inline auto FSetLightVisible_Internal = PreyFunction<void(ArkPlayerLightEntity* const _this, bool _bVisible)>(0x12381C0);
};

// ArkPlayerLightVFX
// Header:  Prey/GameDll/ark/player/ArkPlayerLight.h
class ArkPlayerLightVFX : public ArkPlayerLight
{ // Size=136 (0x88)
public:
	ArkLooseEffect m_lightVFX;

	ArkPlayerLightVFX(EArkPlayerLightPriority _priority, IArkPlayerLightOwner* _pOwner);
	virtual void SetLightVisible_Internal(bool _bVisible);

#if 0
	void SetData(const char* _arg0_);
	void SetLocation(const ParticleLoc _arg0_);
#endif

	static inline auto FArkPlayerLightVFXOv2 = PreyFunction<void(ArkPlayerLightVFX* const _this, EArkPlayerLightPriority _priority, IArkPlayerLightOwner* _pOwner)>(0x1237E20);
	static inline auto FSetLightVisible_Internal = PreyFunction<void(ArkPlayerLightVFX* const _this, bool _bVisible)>(0x1238200);
};

