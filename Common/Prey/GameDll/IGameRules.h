// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IGameObject.h>

struct HitInfo;
struct IActor;
struct IEntity;
struct IHitListener;
struct INetChannel;
struct SEntitySpawnParams;
class XmlNodeRef;
struct EventPhysCollision;

// Prey/GameDll/IGameRules.h
struct IGameRules : public IGameObjectExtension // Id=8001FA0 Size=64
{
	struct SGameCollision // Id=8001FA1 Size=40
	{
		EventPhysCollision const *pCollision;
		IGameObject *pSrc;
		IGameObject *pTrg;
		IEntity *pSrcEntity;
		IEntity *pTrgEntity;
	};

	virtual bool ShouldKeepClient(int arg0, EDisconnectionCause arg1, const char *arg2) const = 0;
	virtual void PrecacheLevel() = 0;
	virtual void PrecacheLevelResource(const char *arg0, EGameResourceType arg1) = 0;
	virtual XmlNodeRef FindPrecachedXmlFile(const char *arg0) = 0;
	virtual void OnConnect(INetChannel *arg0) = 0;
	virtual void OnDisconnect(EDisconnectionCause arg0, const char *arg1) = 0;
	virtual bool OnClientConnect(int arg0, bool arg1) = 0;
	virtual void OnClientDisconnect(int arg0, EDisconnectionCause arg1, const char *arg2, bool arg3) = 0;
	virtual bool OnClientEnteredGame(int arg0, bool arg1) = 0;
	virtual void OnEntitySpawn(IEntity *arg0) = 0;
	virtual void OnEntityRemoved(IEntity *arg0) = 0;
	virtual void OnEntityReused(IEntity *arg0, SEntitySpawnParams &arg1, unsigned arg2) = 0;
	virtual void SendTextMessage(ETextMessageType arg0, const char *arg1, unsigned arg2, int arg3, const char *arg4, const char *arg5, const char *arg6, const char *arg7) = 0;
	virtual void SendChatMessage(EChatMessageType arg0, unsigned arg1, unsigned arg2, const char *arg3) = 0;
	virtual void ClientHit(HitInfo const &arg0) = 0;
	virtual void ServerHit(HitInfo const &arg0) = 0;
	virtual int GetHitTypeId(const unsigned arg0) const = 0;
	virtual int GetHitTypeId(const char *arg0) const = 0;
	virtual const char *GetHitType(int arg0) const = 0;
	virtual void CreateEntityRespawnData(unsigned arg0) = 0;
	virtual bool HasEntityRespawnData(unsigned arg0) const = 0;
	virtual void ScheduleEntityRespawn(unsigned arg0, bool arg1, float arg2) = 0;
	virtual void AbortEntityRespawn(unsigned arg0, bool arg1) = 0;
	virtual void ScheduleEntityRemoval(unsigned arg0, float arg1, bool arg2) = 0;
	virtual void AbortEntityRemoval(unsigned arg0) = 0;
	virtual void AddHitListener(IHitListener *arg0) = 0;
	virtual void RemoveHitListener(IHitListener *arg0) = 0;
	virtual bool OnCollision(IGameRules::SGameCollision const &arg0) = 0;
	virtual void ShowStatus() = 0;
	virtual bool IsTimeLimited() const = 0;
	virtual float GetRemainingGameTime() const = 0;
	virtual void SetRemainingGameTime(float arg0) = 0;
	virtual void ClearAllMigratingPlayers() = 0;
	virtual unsigned SetChannelForMigratingPlayer(const char *arg0, uint16_t arg1) = 0;
	virtual void StoreMigratingPlayer(IActor *arg0) = 0;
	virtual const char *GetTeamName(int arg0) const = 0;
};

