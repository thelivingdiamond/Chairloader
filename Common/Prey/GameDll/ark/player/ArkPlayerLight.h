// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/arkplayerlight.h>

class IArkPlayerLightOwner;
struct IEntity;
struct ParticleLoc;
struct SEntityEvent;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerLight.h
class ArkPlayerLight // Id=80134CE Size=24
{
public:
	bool m_bWantsToBeVisible;
	bool m_bVisible;
	EArkPlayerLightPriority m_priority;
	IArkPlayerLightOwner *m_pOwner;
	
	void SetLightVisible(bool _bVisible) { FSetLightVisible(this,_bVisible); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	virtual unsigned GetLightAttachmentEntity() const;
	virtual void AttachLightEntity() const;
	virtual void SpawnLightEntity();
	virtual void SetLightVisible_Internal(bool arg0) = 0;
	
#if 0
	bool IsLightVisible() const;
	void SetLightWantsToBeVisible(bool arg0);
	bool DoesLightWantToBeVisible() const;
	EArkPlayerLightPriority GetPriority() const;
#endif
	
	static inline auto FSetLightVisible = PreyFunction<void(ArkPlayerLight *const _this, bool _bVisible)>(0x1238180);
	static inline auto FSerialize = PreyFunction<void(ArkPlayerLight *const _this, TSerialize _ser)>(0x1238160);
	static inline auto FGetLightAttachmentEntity = PreyFunction<unsigned(ArkPlayerLight const *const _this)>(0x158AEF0);
	static inline auto FAttachLightEntity = PreyFunction<void(ArkPlayerLight const *const _this)>(0xA13080);
	static inline auto FSpawnLightEntity = PreyFunction<void(ArkPlayerLight *const _this)>(0xA13080);
};

// Header: FromCpp
// Prey/GameDll/ark/player/arkplayerlight.h
class ArkPlayerLightVFX : public ArkPlayerLight // Id=80134CD Size=136
{
public:
	ArkLooseEffect m_lightVFX;
	
	ArkPlayerLightVFX(EArkPlayerLightPriority _priority, IArkPlayerLightOwner *_pOwner);
	virtual void SetLightVisible_Internal(bool _bVisible);
	
#if 0
	void SetData(const char *arg0);
	void SetLocation(ParticleLoc arg0);
#endif
	
	static inline auto FSetLightVisible_Internal = PreyFunction<void(ArkPlayerLightVFX *const _this, bool _bVisible)>(0x1238200);
};

// Header: FromCpp
// Prey/GameDll/ark/player/arkplayerlight.h
class ArkPlayerLightEntity : public ArkPlayerLight, public IEntityEventListener // Id=801601C Size=56
{
public:
	unsigned m_attachmentEntity;
	unsigned m_lightEntity;
	string m_archetypeName;
	string m_attachmentName;
	
	virtual ~ArkPlayerLightEntity();
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	virtual unsigned GetLightAttachmentEntity() const;
	virtual void AttachLightEntity() const;
	virtual void SpawnLightEntity();
	void RemoveLightEntity() { FRemoveLightEntity(this); }
	virtual void SetLightVisible_Internal(bool _bVisible);
	
#if 0
	unsigned GetLightEntity() const;
	bool HasValidData() const;
	void SetData(string const &arg0, string const &arg1, unsigned arg2);
	void CleanupLightEntity();
#endif
	
	static inline auto FBitNotArkPlayerLightEntity = PreyFunction<void(ArkPlayerLightEntity *const _this)>(0x1237E60);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkPlayerLightEntity *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x12380C0);
	static inline auto FGetLightAttachmentEntity = PreyFunction<unsigned(ArkPlayerLightEntity const *const _this)>(0x12380B0);
	static inline auto FAttachLightEntity = PreyFunction<void(ArkPlayerLightEntity const *const _this)>(0x1237FF0);
	static inline auto FSpawnLightEntity = PreyFunction<void(ArkPlayerLightEntity *const _this)>(0x1238220);
	static inline auto FRemoveLightEntity = PreyFunction<void(ArkPlayerLightEntity *const _this)>(0x1238110);
	static inline auto FSetLightVisible_Internal = PreyFunction<void(ArkPlayerLightEntity *const _this, bool _bVisible)>(0x12381C0);
};

