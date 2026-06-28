// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#ifndef __IGAMEOBJECT_H__
#define __IGAMEOBJECT_H__

#pragma once

#include "IGameObjectSystem.h"

#define GAME_OBJECT_SUPPORTS_CUSTOM_USER_DATA 1

#include <Prey/CryEntitySystem/IComponent.h>

#include <Prey/CryNetwork/SerializeFwd.h>
#include "IActionMapManager.h"
//#include <Prey/CryMemory/PoolAllocator.h>
//#include <Prey/CryFlowGraph/IFlowSystem.h>

inline void GameWarning(const char*, ...) PRINTF_PARAMS(1, 2);

struct IGameObjectExtension;
struct IGameObjectView;
struct IActionListener;
struct IMovementController;
struct IGameObjectProfileManager;
struct IWorldQuery;

enum EEntityAspects
{
	eEA_All               = 0xFFFFFFFF,
	// 0x01u                       // aspect 0
	eEA_Script            = 0x02u, // aspect 1
	// 0x04u                       // aspect 2
	eEA_Physics           = 0x08u, // aspect 3
	eEA_GameClientStatic  = 0x10u, // aspect 4
	eEA_GameServerStatic  = 0x20u, // aspect 5
	eEA_GameClientDynamic = 0x40u, // aspect 6
	eEA_GameServerDynamic = 0x80u, // aspect 7
#if NUM_ASPECTS > 8
	eEA_GameClientA       = 0x0100u, // aspect 8
	eEA_GameServerA       = 0x0200u, // aspect 9
	eEA_GameClientB       = 0x0400u, // aspect 10
	eEA_GameServerB       = 0x0800u, // aspect 11
	eEA_GameClientC       = 0x1000u, // aspect 12
	eEA_GameServerC       = 0x2000u, // aspect 13
	eEA_GameClientD       = 0x4000u, // aspect 14
	eEA_GameClientE       = 0x8000u, // aspect 15
#endif
#if NUM_ASPECTS > 16
	eEA_GameClientF = 0x00010000u,       // aspect 16
	eEA_GameClientG = 0x00020000u,       // aspect 17
	eEA_GameClientH = 0x00040000u,       // aspect 18
	eEA_GameClientI = 0x00080000u,       // aspect 19
	eEA_GameClientJ = 0x00100000u,       // aspect 20
	eEA_GameServerD = 0x00200000u,       // aspect 21
	eEA_GameClientK = 0x00400000u,       // aspect 22
	eEA_GameClientL = 0x00800000u,       // aspect 23
	eEA_GameClientM = 0x01000000u,       // aspect 24
	eEA_GameClientN = 0x02000000u,       // aspect 25
	eEA_GameClientO = 0x04000000u,       // aspect 26
	eEA_GameClientP = 0x08000000u,       // aspect 27
	eEA_GameServerE = 0x10000000u,       // aspect 28
	eEA_Aspect29    = 0x20000000u,       // aspect 29
	eEA_Aspect30    = 0x40000000u,       // aspect 30
	eEA_Aspect31    = 0x80000000u,       // aspect 31
#endif
};

enum EEntityPhysicsEvents
{
	eEPE_OnCollisionLogged        = 1 << 0,   // Logged events on lower byte.
	eEPE_OnPostStepLogged         = 1 << 1,
	eEPE_OnStateChangeLogged      = 1 << 2,
	eEPE_OnCreateEntityPartLogged = 1 << 3,
	eEPE_OnUpdateMeshLogged       = 1 << 4,
	eEPE_AllLogged                = eEPE_OnCollisionLogged | eEPE_OnPostStepLogged |
	                                eEPE_OnStateChangeLogged | eEPE_OnCreateEntityPartLogged |
	                                eEPE_OnUpdateMeshLogged,

	eEPE_OnCollisionImmediate        = 1 << 8, // Immediate events on higher byte.
	eEPE_OnPostStepImmediate         = 1 << 9,
	eEPE_OnStateChangeImmediate      = 1 << 10,
	eEPE_OnCreateEntityPartImmediate = 1 << 11,
	eEPE_OnUpdateMeshImmediate       = 1 << 12,
	eEPE_AllImmediate                = eEPE_OnCollisionImmediate | eEPE_OnPostStepImmediate |
	                                   eEPE_OnStateChangeImmediate | eEPE_OnCreateEntityPartImmediate |
	                                   eEPE_OnUpdateMeshImmediate,
};

static const int MAX_UPDATE_SLOTS_PER_EXTENSION = 5;

enum ERMInvocation
{
	eRMI_ToClientChannel = 0x01,
	eRMI_ToOwnClient     = 0x02,
	eRMI_ToOtherClients  = 0x04,
	eRMI_ToAllClients    = 0x08,

	eRMI_ToServer        = 0x100,

	eRMI_NoLocalCalls    = 0x10000,
	eRMI_NoRemoteCalls   = 0x20000,

	eRMI_ToRemoteClients = eRMI_NoLocalCalls | eRMI_ToAllClients
};

enum EUpdateEnableCondition
{
	eUEC_Never,
	eUEC_Always,
	eUEC_Visible,
	eUEC_InRange,
	eUEC_VisibleAndInRange,
	eUEC_VisibleOrInRange,
	eUEC_VisibleOrInRangeIgnoreAI,
	eUEC_VisibleIgnoreAI,
	eUEC_WithoutAI,
};

enum EPrePhysicsUpdate
{
	ePPU_Never,
	ePPU_Always,
	ePPU_WhenAIActivated
};

enum EGameObjectAIActivationMode
{
	eGOAIAM_Never,
	eGOAIAM_Always,
	eGOAIAM_VisibleOrInRange,
	// Must be last.
	eGOAIAM_COUNT_STATES,
};

enum EAutoDisablePhysicsMode
{
	eADPM_Never,
	eADPM_WhenAIDeactivated,
	eADPM_WhenInvisibleAndFarAway,
	// Must be last.
	eADPM_COUNT_STATES,
};

enum EBindToNetworkMode
{
	eBTNM_Normal,
	eBTNM_Force,
	eBTNM_NowInitialized
};

class SmartScriptTable;

struct SGameObjectExtensionRMI
{
	void GetMemoryUsage(ICrySizer* pSizer) const {}
	typedef INetAtSyncItem* (* DecoderFunction)(TSerialize, EntityId*, INetChannel*);

	DecoderFunction       decoder;
	const char*           description;
	const void*           pBase;
	const SNetMessageDef* pMsgDef;
	ERMIAttachmentType    attach;
	bool                  isServerCall;
	bool                  lowDelay;
	ENetReliabilityType   reliability;
};

#if 0
template<size_t N>
class CRMIAllocator
{
public:
	static ILINE void* Allocate()
	{
		if (!m_pAllocator)
			m_pAllocator = new stl::PoolAllocator<N>;
		return m_pAllocator->Allocate();
	}
	static ILINE void Deallocate(void* p)
	{
		CRY_ASSERT(m_pAllocator);
		m_pAllocator->Deallocate(p);
	}

private:
	static stl::PoolAllocator<N>* m_pAllocator;
};
template<size_t N> stl::PoolAllocator<N>* CRMIAllocator<N>::m_pAllocator = 0;
#endif

// Summary
//   Interface used to interact with a game object
// See Also
//   IGameObjectExtension
struct IGameObject : public IActionListener
{
protected:
	class CRMIBody;
#if 0
	class CRMIBody : public IRMIMessageBody
	{
	public:
		CRMIBody(const SGameObjectExtensionRMI* method, EntityId id, IRMIListener* pListener, int userId, EntityId dependentId) :
			IRMIMessageBody(method->reliability, method->attach, id, method->pMsgDef, pListener, userId, dependentId)
		{
		}
	};

	template<class T>
	class CRMIBodyImpl : public CRMIBody
	{
	public:
		void SerializeWith(TSerialize ser)
		{
			m_params.SerializeWith(ser);
		}

		size_t GetSize()
		{
			return sizeof(*this);
		}

#if ENABLE_RMI_BENCHMARK
		virtual const SRMIBenchmarkParams* GetRMIBenchmarkParams()
		{
			return NetGetRMIBenchmarkParams<T>(m_params);
		}
#endif

		static CRMIBodyImpl* Create(const SGameObjectExtensionRMI* method, EntityId id, const T& params, IRMIListener* pListener, int userId, EntityId dependentId)
		{
			return new(CRMIAllocator<sizeof(CRMIBodyImpl)>::Allocate())CRMIBodyImpl(method, id, params, pListener, userId, dependentId);
		}

		void DeleteThis()
		{
			this->~CRMIBodyImpl();
			CRMIAllocator<sizeof(CRMIBodyImpl)>::Deallocate(this);
		}

	private:
		T m_params;

		CRMIBodyImpl(const SGameObjectExtensionRMI* method, EntityId id, const T& params, IRMIListener* pListener, int userId, EntityId dependentId) :
			CRMIBody(method, id, pListener, userId, dependentId),
			m_params(params)
		{
		}
	};
#endif

public:
	// bind this entity to the network system (it gets synchronized then...)
	virtual bool                  BindToNetwork(EBindToNetworkMode mode = eBTNM_Normal) = 0;
	// bind this entity to the network system, with a dependency on its parent
	virtual bool                  BindToNetworkWithParent(EBindToNetworkMode mode, EntityId parentId) = 0;
	// flag that we have changed the state of the game object aspect
	virtual void                  ChangedNetworkState(NetworkAspectType aspects) = 0;
	// enable/disable network aspects on game object
	virtual void                  EnableAspect(NetworkAspectType aspects, bool enable) = 0;
	// enable/disable delegatable aspects
	virtual void                  EnableDelegatableAspect(NetworkAspectType aspects, bool enable) = 0;
	// A one off call to never enable the physics aspect, this needs to be done *before* the BindToNetwork (typically in the GameObject's Init function)
	virtual void                  DontSyncPhysics() = 0;

	virtual IGameObjectSystem::ExtensionID GetExtensionId(const char *extension) = 0;
	// query extension. returns 0 if extension is not there.
	virtual IGameObjectExtension* QueryExtension(const char* extension) const = 0;
	virtual IGameObjectExtension* QueryExtension(IGameObjectSystem::ExtensionID id) const = 0;

	// set extension parameters
	virtual bool                  SetExtensionParams(const char* extension, SmartScriptTable params) = 0;
	// get extension parameters
	virtual bool                  GetExtensionParams(const char* extension, SmartScriptTable params) = 0;
	// send a game object event
	virtual void                  SendEvent(const SGameObjectEvent&) = 0;
	// force the object to update even if extensions' slots are "sleeping"...
	virtual void                  ForceUpdate(bool force) = 0;
	virtual void                  ForceUpdateExtension(IGameObjectExtension* pGOE, int slot) = 0;
	// get/set network channel
	virtual uint16                GetChannelId() const = 0;
	virtual void SetChannelId(uint16) = 0;
	virtual INetChannel*          GetNetChannel() const = 0;
	// serialize some aspects of the game object
	virtual void                  FullSerialize(TSerialize ser) = 0;
	virtual bool                  NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int pflags) = 0;
	// in case things have to be set after serialization
	virtual void                  PostSerialize() = 0;
	// is the game object probably visible?
	virtual bool                  IsProbablyVisible() = 0;
	virtual bool                  IsProbablyDistant() = 0;
	// change the profile of an aspect
	virtual bool                  SetAspectProfile(EEntityAspects aspect, uint8 profile, bool fromNetwork = false) = 0;
	virtual uint8                 GetAspectProfile(EEntityAspects aspect) = 0;
	virtual IGameObjectExtension* GetExtensionWithRMIBase(const void* pBase) = 0;
	virtual void                  EnablePrePhysicsUpdate(EPrePhysicsUpdate updateRule) = 0;
	virtual void                  SetNetworkParent(EntityId id) = 0;
	virtual void                  Pulse(uint32 pulse) = 0;
	virtual void                  RegisterAsPredicted() = 0;
	virtual void                  RegisterAsValidated(IGameObject* pGO, int predictionHandle) = 0;
	virtual int                   GetPredictionHandle() = 0;

	virtual void                  RegisterExtForEvents(IGameObjectExtension* piExtention, const int* pEvents, const int numEvents) = 0;
	virtual void                  UnRegisterExtForEvents(IGameObjectExtension* piExtention, const int* pEvents, const int numEvents) = 0;

	// enable/disable sending physics events to this game object
	virtual void EnablePhysicsEvent(bool enable, int events) = 0;
	virtual bool WantsPhysicsEvent(int events) = 0;
	//virtual void AttachDistanceChecker() = 0;

	// enable/disable AI activation flag
	virtual bool SetAIActivation(EGameObjectAIActivationMode mode) = 0;
	// enable/disable auto-disabling of physics
	virtual void SetAutoDisablePhysicsMode(EAutoDisablePhysicsMode mode) = 0;
	// for debugging updates
	virtual bool ShouldUpdate() = 0;

	virtual bool CheckShouldAIUpdate() = 0;
	virtual unsigned int GetAiActivationMode() = 0;
	virtual void SetCloseDistThreshold(float) = 0;
	virtual float GetCloseDistThresholdSq() = 0;
	virtual void SetCurrDistFromPlayerSq(float) = 0;

	// register a partial update in the netcode without actually serializing - useful only for working around other bugs
	virtual void RequestRemoteUpdate(NetworkAspectType aspectMask) = 0;

#if 0
	// WARNING: there *MUST* be at least one frame between spawning ent and using this function to send an RMI if
	// that RMI is _FAST, otherwise the dependent entity is ignored
	template<class MI, class T>
	void InvokeRMIWithDependentObject(const MI method, const T& params, unsigned where, EntityId ent, int channel = -1)
	{
		InvokeRMI_Primitive(method, params, where, 0, 0, channel, ent);
	}

	template<class MI, class T>
	void InvokeRMI(const MI method, const T& params, unsigned where, int channel = -1)
	{
		InvokeRMI_Primitive(method, params, where, 0, 0, channel, 0);
	}

	template<class MI, class T>
	void InvokeRMI_Primitive(const MI method, const T& params, unsigned where, IRMIListener* pListener, int userId, int channel, EntityId dependentId)
	{
		method.Verify(params);
		DoInvokeRMI(CRMIBodyImpl<T>::Create(method.pMethodInfo, GetEntityId(), params, pListener, userId, dependentId), where, channel);
	}
#endif

	// turn an extension on
	ILINE bool                  ActivateExtension(const char* extension)   { return ChangeExtension(extension, eCE_Activate) != 0; }
	// turn an extension off
	ILINE void                  DeactivateExtension(const char* extension) { ChangeExtension(extension, eCE_Deactivate); }
	// forcefully get a pointer to an extension (may instantiate if needed)
	ILINE IGameObjectExtension* AcquireExtension(const char* extension)    { return ChangeExtension(extension, eCE_Acquire); }
	// release a previously acquired extension
	ILINE void                  ReleaseExtension(const char* extension)    { ChangeExtension(extension, eCE_Release); }

	// retrieve the hosting entity
	ILINE IEntity* GetEntity() const
	{
		return m_pEntity;
	}

	ILINE EntityId GetEntityId() const
	{
		return m_entityId;
	}

	// for extensions to register for special things
	virtual bool                       CaptureView(IGameObjectView* pGOV) = 0;
	virtual void                       ReleaseView(IGameObjectView* pGOV) = 0;
	virtual bool                       CaptureActions(IActionListener* pAL) = 0;
	virtual void                       ReleaseActions(IActionListener* pAL) = 0;
	virtual bool                       CaptureProfileManager(IGameObjectProfileManager* pPH) = 0;
	virtual void                       ReleaseProfileManager(IGameObjectProfileManager* pPH) = 0;
	virtual void                       EnableUpdateSlot(IGameObjectExtension* pExtension, int slot) = 0;
	virtual void                       DisableUpdateSlot(IGameObjectExtension* pExtension, int slot) = 0;
	virtual uint8                      GetUpdateSlotEnables(IGameObjectExtension* pExtension, int slot) = 0;
	virtual void                       EnablePostUpdates(IGameObjectExtension* pExtension) = 0;
	virtual void                       DisablePostUpdates(IGameObjectExtension* pExtension) = 0;
	virtual void                       SetUpdateSlotEnableCondition(IGameObjectExtension* pExtension, int slot, EUpdateEnableCondition condition) = 0;
	virtual void                       PostUpdate(float frameTime) = 0;
	virtual IWorldQuery*               GetWorldQuery() = 0;

	virtual bool                       IsJustExchanging() = 0;

	ILINE void                         SetMovementController(IMovementController* pMC) { m_pMovementController = pMC; }
	virtual ILINE IMovementController* GetMovementController()                         { return m_pMovementController; }

	virtual void                       GetMemoryUsage(ICrySizer* pSizer) const         {};

#if GAME_OBJECT_SUPPORTS_CUSTOM_USER_DATA
	virtual void* GetUserData() const = 0;
	virtual void  SetUserData(void* ptr) = 0;
#endif

protected:
	enum EChangeExtension
	{
		eCE_Activate,
		eCE_Deactivate,
		eCE_Acquire,
		eCE_Release
	};

	IGameObject() : m_pEntity(0), m_entityId(0), m_pMovementController(0) {}
	EntityId             m_entityId;
	IMovementController* m_pMovementController;
	IEntity*             m_pEntity;

private:
	// change extension activation/reference somehow
	virtual IGameObjectExtension* ChangeExtension(const char* extension, EChangeExtension change) = 0;
	// invoke an RMI call
	virtual void                  DoInvokeRMI(_smart_ptr<CRMIBody> pBody, unsigned where, int channel) = 0;
};

#if 0
struct IRMIAtSyncItem : public INetAtSyncItem, public IRMICppLogger {};

template<class T, class Obj>
class CRMIAtSyncItem : public IRMIAtSyncItem
{
public:
	typedef bool (Obj::* CallbackFunc)(const T&, INetChannel*);

	// INetAtSyncItem
	// INetAtSyncItem

	static ILINE CRMIAtSyncItem* Create(const T& params, EntityId id, const SGameObjectExtensionRMI* pRMI, CallbackFunc callback, INetChannel* pChannel)
	{
		return new(CRMIAllocator<sizeof(CRMIAtSyncItem)>::Allocate())CRMIAtSyncItem(params, id, pRMI, callback, pChannel);
	}

	bool Sync()
	{
		bool ok = false;
		bool foundObject = false;
		char msg[256];
		msg[0] = 0;

		if (IGameObject* pGameObject = gEnv->pGame->GetIGameFramework()->GetGameObject(m_id))
		{
			INDENT_LOG_DURING_SCOPE(true, "During game object sync: %s %s", pGameObject->GetEntity()->GetEntityTextDescription().c_str(), m_pRMI->pMsgDef->description);

			if (Obj* pGameObjectExtension = (Obj*)pGameObject->GetExtensionWithRMIBase(m_pRMI->pBase))
			{
				ok = (pGameObjectExtension->*m_callback)(m_params, m_pChannel);
				foundObject = true;
			}
			else
			{
				cry_sprintf(msg, "Game object extension with base %.8x for entity %s for RMI %s not found", (uint32)(TRUNCATE_PTR)m_pRMI->pBase, pGameObject->GetEntity()->GetName(), m_pRMI->pMsgDef->description);
				GameWarning("%s", msg);
			}
		}
		else
		{
			cry_sprintf(msg, "Entity %u for RMI %s not found", m_id, m_pRMI->pMsgDef->description);
		}

		if (!ok)
		{
			GameWarning("Error handling RMI %s", m_pRMI->pMsgDef->description);

			if (!foundObject && !gEnv->bServer && !m_pChannel->IsInTransition())
			{
				CRY_ASSERT(msg[0]);
				m_pChannel->Disconnect(eDC_ContextCorruption, msg);
			}
			else
			{
				ok = true;
				// fake for singleplayer/multiplayer server
				// singleplayer - 'impossible' to get right during quick-load
				// multiplayer server - object can be deleted while the message is in flight
			}
		}

		if (!foundObject)
			return true; // for editor
		else
			return ok;
	}

	bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage)
	{
		return Sync();
	}

	void DeleteThis()
	{
		this->~CRMIAtSyncItem();
		CRMIAllocator<sizeof(CRMIAtSyncItem)>::Deallocate(this);
	}
	// ~INetAtSyncItem

	// IRMICppLogger
	virtual const char* GetName()
	{
		return m_pRMI->description;
	}
	virtual void SerializeParams(TSerialize ser)
	{
		m_params.SerializeWith(ser);
	}
	// ~IRMICppLogger

private:
	CRMIAtSyncItem(const T& params, EntityId id, const SGameObjectExtensionRMI* pRMI, CallbackFunc callback, INetChannel* pChannel) : m_params(params), m_id(id), m_pRMI(pRMI), m_callback(callback), m_pChannel(pChannel) {}

	T                              m_params;
	EntityId                       m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	CallbackFunc                   m_callback;
	INetChannel*                   m_pChannel;
};
#endif

struct IGameObject;
struct SViewParams;
class TFlowInputData;

template<class T_Derived, class T_Parent, size_t MAX_STATIC_MESSAGES = 64>
class CGameObjectExtensionHelper : public T_Parent
{
public:
	static void GetGameObjectExtensionRMIData(void** ppRMI, size_t* nCount)
	{
		*ppRMI = ms_statics.m_vMessages;
		*nCount = ms_statics.m_nMessages;
	}

	const void* GetRMIBase() const
	{
		return ms_statics.m_vMessages;
	}

	static void SetExtensionId(IGameObjectSystem::ExtensionID id) { ms_statics.m_extensionId = id; }

protected:
#if 0
	static T_Derived* QueryExtension(EntityId id)
	{
		IGameObject* pGO = gEnv->pGame->GetIGameFramework()->GetGameObject(id);
		if (pGO)
		{
			return static_cast<T_Derived*>(pGO->QueryExtension(T_Derived::ms_statics.m_extensionId));
		}

		return NULL;
	}

	static void ActivateOutputPort(EntityId id, int port, const TFlowInputData& data)
	{
		SEntityEvent evnt;
		evnt.event = ENTITY_EVENT_ACTIVATE_FLOW_NODE_OUTPUT;
		evnt.nParam[0] = port;
		evnt.nParam[1] = (INT_PTR)&data;

		IEntity* pEntity = gEnv->pEntitySystem->GetEntity(id);
		if (pEntity)
			pEntity->SendEvent(evnt);
	}
#endif

	static const SGameObjectExtensionRMI* Helper_AddMessage(SGameObjectExtensionRMI::DecoderFunction decoder, const char* description, ERMIAttachmentType attach, bool isServerCall, ENetReliabilityType reliability, bool lowDelay)
	{
		if (ms_statics.m_nMessages >= MAX_STATIC_MESSAGES)
		{
			// Assert or CryFatalError here uses gEnv, which is not yet initialized.
			__debugbreak();
			((void (*)())NULL)();
			return NULL;
		}
		SGameObjectExtensionRMI& rmi = ms_statics.m_vMessages[ms_statics.m_nMessages++];
		rmi.decoder = decoder;
		rmi.description = description;
		rmi.attach = attach;
		rmi.isServerCall = isServerCall;
		rmi.pBase = ms_statics.m_vMessages;
		rmi.reliability = reliability;
		rmi.pMsgDef = 0;
		rmi.lowDelay = lowDelay;
		return &rmi;
	}

private:
	struct Statics
	{
		size_t                         m_nMessages;
		SGameObjectExtensionRMI        m_vMessages[MAX_STATIC_MESSAGES];
		IGameObjectSystem::ExtensionID m_extensionId;
	};

	static Statics ms_statics;
};

#define DECLARE_RMI(name, params, reliability, attachment, isServer, lowDelay)                              \
  public:                                                                                                   \
    struct MethodInfo_ ## name                                                                              \
    {                                                                                                       \
      MethodInfo_ ## name(const SGameObjectExtensionRMI * pMethodInfo) { this->pMethodInfo = pMethodInfo; } \
      const SGameObjectExtensionRMI* pMethodInfo;                                                           \
      ILINE void Verify(const params &p) const                                                              \
      {                                                                                                     \
      }                                                                                                     \
    };                                                                                                      \
  private:                                                                                                  \
    static INetAtSyncItem* Decode_ ## name(TSerialize, EntityId*, INetChannel*);                            \
    bool Handle_ ## name(const params &, INetChannel*);                                                     \
    static const ERMIAttachmentType Attach_ ## name = attachment;                                           \
    static const bool ServerCall_ ## name = isServer;                                                       \
    static const ENetReliabilityType Reliability_ ## name = reliability;                                    \
    static const bool LowDelay_ ## name = lowDelay;                                                         \
    typedef params Params_ ## name;                                                                         \
    static MethodInfo_ ## name m_info ## name;                                                              \
  public:                                                                                                   \
    static const MethodInfo_ ## name& name() { return m_info ## name; }

#define DECLARE_INTERFACE_RMI(name, params, reliability, attachment, isServer, lowDelay)                    \
  protected:                                                                                                \
    static const ERMIAttachmentType Attach_ ## name = attachment;                                           \
    static const bool ServerCall_ ## name = isServer;                                                       \
    static const ENetReliabilityType Reliability_ ## name = reliability;                                    \
    static const bool LowDelay_ ## name = lowDelay;                                                         \
    typedef params Params_ ## name;                                                                         \
  public:                                                                                                   \
    struct MethodInfo_ ## name                                                                              \
    {                                                                                                       \
      MethodInfo_ ## name(const SGameObjectExtensionRMI * pMethodInfo) { this->pMethodInfo = pMethodInfo; } \
      const SGameObjectExtensionRMI* pMethodInfo;                                                           \
      ILINE void Verify(const params &p) const                                                              \
      {                                                                                                     \
      }                                                                                                     \
    };                                                                                                      \
    virtual const MethodInfo_ ## name& name() = 0

#define DECLARE_IMPLEMENTATION_RMI(name)                                  \
  private:                                                                \
    INetAtSyncItem * Decode_ ## name(TSerialize, EntityId, INetChannel*); \
    static bool Handle_ ## name(const Params_ ## name &, INetChannel*);   \
    static MethodInfo_ ## name m_info ## name;                            \
  public:                                                                 \
    const MethodInfo_ ## name& name() { return m_info ## name; }

#define IMPLEMENT_RMI(cls, name)                                                                                                                                                                                            \
  cls::MethodInfo_ ## name cls::m_info ## name = cls::Helper_AddMessage(&cls::Decode_ ## name, "RMI:" # cls ":" # name, cls::Attach_ ## name, cls::ServerCall_ ## name, cls::Reliability_ ## name, cls::LowDelay_ ## name); \
  INetAtSyncItem* cls::Decode_ ## name(TSerialize ser, EntityId * pID, INetChannel * pChannel)                                                                                                                              \
  {                                                                                                                                                                                                                         \
    CRY_ASSERT(pID);                                                                                                                                                                                                        \
    Params_ ## name params;                                                                                                                                                                                                 \
    params.SerializeWith(ser);                                                                                                                                                                                              \
    NetLogRMIReceived(params, pChannel);                                                                                                                                                                                    \
    return CRMIAtSyncItem<Params_ ## name, cls>::Create(params, *pID, m_info ## name.pMethodInfo, &cls::Handle_ ## name, pChannel);                                                                                         \
  }                                                                                                                                                                                                                         \
  ILINE bool cls::Handle_ ## name(const Params_ ## name & params, INetChannel * pNetChannel)

#define IMPLEMENT_INTERFACE_RMI(cls, name)                                                                                                                                                                                  \
  cls::MethodInfo_ ## name cls::m_info ## name = cls::Helper_AddMessage(&cls::Decode_ ## name, "RMI:" # cls ":" # name, cls::Attach_ ## name, cls::ServerCall_ ## name, cls::Reliability_ ## name, cls::LowDelay_ ## name); \
  INetAtSyncItem* cls::Decode_ ## name(TSerialize ser, INetChannel * pChannel)                                                                                                                                              \
  {                                                                                                                                                                                                                         \
    Params_ ## name params;                                                                                                                                                                                                 \
    params.SerializeWith(ser);                                                                                                                                                                                              \
    return CRMIAtSyncItem<Params_ ## name, cls>::Create(params, id, m_info ## name.pMethodInfo, &cls::Handle_ ## name, pChannel);                                                                                           \
  }                                                                                                                                                                                                                         \
  ILINE bool cls::Handle_ ## name(const Params_ ## name & params, INetChannel * pNetChannel)

/*
 * _FAST versions may send the RMI without waiting for the frame to end; be sure that consistency with the entity is not important!
 */

//
// PreAttach/PostAttach RMI's cannot have their reliability specified (see CGameObjectDispatch::RegisterInterface() for details)
#define DECLARE_SERVER_RMI_PREATTACH(name, params)             DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PreAttach, true, false)
#define DECLARE_CLIENT_RMI_PREATTACH(name, params)             DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PreAttach, false, false)
#define DECLARE_SERVER_RMI_POSTATTACH(name, params)            DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PostAttach, true, false)
#define DECLARE_CLIENT_RMI_POSTATTACH(name, params)            DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PostAttach, false, false)
#define DECLARE_SERVER_RMI_NOATTACH(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_NoAttach, true, false)
#define DECLARE_CLIENT_RMI_NOATTACH(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_NoAttach, false, false)

// PreAttach/PostAttach RMI's cannot have their reliability specified (see CGameObjectDispatch::RegisterInterface() for details)
#define DECLARE_SERVER_RMI_PREATTACH_FAST(name, params)             DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PreAttach, true, true)
#define DECLARE_CLIENT_RMI_PREATTACH_FAST(name, params)             DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PreAttach, false, true)
#define DECLARE_SERVER_RMI_POSTATTACH_FAST(name, params)            DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PostAttach, true, true)
#define DECLARE_CLIENT_RMI_POSTATTACH_FAST(name, params)            DECLARE_RMI(name, params, eNRT_UnreliableOrdered, eRAT_PostAttach, false, true)
#define DECLARE_SERVER_RMI_NOATTACH_FAST(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_NoAttach, true, true)
#define DECLARE_CLIENT_RMI_NOATTACH_FAST(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_NoAttach, false, true)

#if ENABLE_URGENT_RMIS
	#define DECLARE_SERVER_RMI_URGENT(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_Urgent, true, false)
	#define DECLARE_CLIENT_RMI_URGENT(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_Urgent, false, false)
#else
	#define DECLARE_SERVER_RMI_URGENT(name, params, reliability) DECLARE_SERVER_RMI_NOATTACH(name, params, reliability)
	#define DECLARE_CLIENT_RMI_URGENT(name, params, reliability) DECLARE_CLIENT_RMI_NOATTACH(name, params, reliability)
#endif // ENABLE_URGENT_RMIS

#if ENABLE_INDEPENDENT_RMIS
	#define DECLARE_SERVER_RMI_INDEPENDENT(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_Independent, true, false)
	#define DECLARE_CLIENT_RMI_INDEPENDENT(name, params, reliability) DECLARE_RMI(name, params, reliability, eRAT_Independent, false, false)
#else
	#define DECLARE_SERVER_RMI_INDEPENDENT(name, params, reliability) DECLARE_SERVER_RMI_NOATTACH(name, params, reliability)
	#define DECLARE_CLIENT_RMI_INDEPENDENT(name, params, reliability) DECLARE_CLIENT_RMI_NOATTACH(name, params, reliability)
#endif // ENABLE_INDEPENDENT_RMIS

/*
   // Todo:
   //		Temporary, until a good solution for sending noattach fast messages can be found
   #define DECLARE_SERVER_RMI_NOATTACH_FAST(a,b,c) DECLARE_SERVER_RMI_NOATTACH(a,b,c)
   #define DECLARE_CLIENT_RMI_NOATTACH_FAST(a,b,c) DECLARE_CLIENT_RMI_NOATTACH(a,b,c)
 */

//
#define DECLARE_INTERFACE_SERVER_RMI_PREATTACH(name, params, reliability)       DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PreAttach, true, false)
#define DECLARE_INTERFACE_CLIENT_RMI_PREATTACH(name, params, reliability)       DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PreAttach, false, false)
#define DECLARE_INTERFACE_SERVER_RMI_POSTATTACH(name, params, reliability)      DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PostAttach, true, false)
#define DECLARE_INTERFACE_CLIENT_RMI_POSTATTACH(name, params, reliability)      DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PostAttach, false, false)

#define DECLARE_INTERFACE_SERVER_RMI_PREATTACH_FAST(name, params, reliability)  DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PreAttach, true, true)
#define DECLARE_INTERFACE_CLIENT_RMI_PREATTACH_FAST(name, params, reliability)  DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PreAttach, false, true)
#define DECLARE_INTERFACE_SERVER_RMI_POSTATTACH_FAST(name, params, reliability) DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PostAttach, true, true)
#define DECLARE_INTERFACE_CLIENT_RMI_POSTATTACH_FAST(name, params, reliability) DECLARE_INTERFACE_RMI(name, params, reliability, eRAT_PostAttach, false, true)

template<class T, class U, size_t N>
typename CGameObjectExtensionHelper<T, U, N>::Statics CGameObjectExtensionHelper<T, U, N>::ms_statics;

struct IGameObjectView
{
	virtual ~IGameObjectView(){}
	virtual void UpdateView(SViewParams& params) = 0;
	virtual void PostUpdateView(SViewParams& params) = 0;
};

struct IGameObjectProfileManager
{
	virtual ~IGameObjectProfileManager(){}
	virtual bool  SetAspectProfile(EEntityAspects aspect, uint8 profile) = 0;
	virtual uint8 GetDefaultProfile(EEntityAspects aspect) = 0;
};

// Summary
//   Interface used to implement a game object extension
struct IGameObjectExtension : public IComponent
{
	virtual ~IGameObjectExtension(){}
	virtual void GetMemoryUsage(ICrySizer* pSizer) const = 0;

	IGameObjectExtension() : m_pGameObject(0), m_entityId(0), m_pEntity(0) {}

	// IComponent
	virtual ComponentEventPriority GetEventPriority(const int eventID) const { return(ENTITY_PROXY_LAST - ENTITY_PROXY_USER); }
	// ~IComponent

	// Summary
	//   Initialize the extension
	// Parameters
	//   pGameObject - a pointer to the game object which will use the extension
	// Remarks
	//   IMPORTANT: It's very important that the implementation of this function
	//   call the protected function SetGameObject() during the execution of the
	//   Init() function. Unexpected results would happen otherwise.
	virtual bool Init(IGameObject* pGameObject) = 0;

	// Summary
	//   Post-initialize the extension
	// Description
	//   During the post-initialization, the extension is now contained in the
	//   game object
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	virtual void PostInit(IGameObject* pGameObject) = 0;

	// Summary
	//   Initialize the extension (client only)
	// Description
	//   This initialization function should be use to initialize resource only
	//   used in the client
	// Parameters
	//   channelId - id of the server channel of the client to receive the
	//               initialization
	virtual void InitClient(int channelId) = 0;

	// Summary
	//   Post-initialize the extension (client only)
	// Description
	//   This initialization function should be use to initialize resource only
	//   used in the client. During the post-initialization, the extension is now
	//   contained in the game object
	// Parameters
	//   channelId - id of the server channel of the client to receive the
	//               initialization
	virtual void PostInitClient(int channelId) = 0;

	// Summary
	//   Reload the extension
	// Description
	//   Called when owning entity is reloaded
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	// Returns
	//   TRUE if the extension should be kept, FALSE if it should be removed
	// Remarks
	//   IMPORTANT: It's very important that the implementation of this function
	//   call the protected function ResetGameObject() during the execution of the
	//   ReloadExtension() function. Unexpected results would happen otherwise.
	virtual bool ReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params) = 0;

	// Summary
	//   Post-reload the extension
	// Description
	//   Called when owning entity is reloaded and all its extensions have either
	//   either been reloaded or destroyed
	// Parameters
	//   pGameObject - a pointer to the game object which owns the extension
	virtual void PostReloadExtension(IGameObject* pGameObject, const SEntitySpawnParams& params) = 0;

	// Summary
	//   Builds a signature to describe the dynamic hierarchy of the parent Entity container
	// Arguments:
	//    signature - the object to serialize with, forming the signature
	// Returns:
	//    true - If the signature is thus far valid
	// Note:
	//    It's the responsibility of the proxy to identify its internal state which may complicate the hierarchy
	//    of the parent Entity i.e., sub-proxies and which actually exist for this instantiation.
	virtual bool GetEntityPoolSignature(TSerialize signature) = 0;

	// Summary
	//   Releases the resources used by the object
	// Remarks
	//   This function should also take care of freeing the instance once the
	//   resource are freed.
	virtual void Release() = 0;

	// Summary
	//   Performs the serialization the extension
	// Parameters
	//   ser - object used to serialize values
	//   aspect - serialization aspect, used for network serialization
	//   profile - which profile to serialize; 255 == don't care
	//   flags - physics flags to be used for serialization
	// See Also
	//   ISerialize
	virtual void FullSerialize(TSerialize ser) = 0;
	virtual bool NetSerialize(TSerialize ser, EEntityAspects aspect, uint8 profile, int pflags) = 0;

	// Summary
	//   Return the aspects NetSerialize serializes.
	//   Overriding this to return only the aspects used will speed up the net bind of the object.
	virtual NetworkAspectType GetNetSerializeAspects() { return eEA_All; }

	// Summary
	//   Performs post serialization fixes
	virtual void PostSerialize() = 0;

	// Summary
	//   Performs the serialization of special spawn information
	// Parameters
	//   ser - object used to serialize values
	// See Also
	//   Serialize, ISerialize
	virtual void                 SerializeSpawnInfo(TSerialize ser) = 0;

	virtual ISerializableInfoPtr GetSpawnInfo() = 0;

	// Summary
	//   Performs frame dependent extension updates
	// Parameters
	//   ctx - Update context
	//   updateSlot - updateSlot
	// See Also
	//   PostUpdate, SEntityUpdateContext, IGameObject::EnableUpdateSlot
	virtual void Update(SEntityUpdateContext& ctx, int updateSlot) = 0;

	// Summary
	//   Processes game specific events
	// Parameters
	//   event - game event
	// See Also
	//   SGameObjectEvent
	virtual void HandleEvent(const SGameObjectEvent& event) = 0;

	// Summary
	//   Processes entity specific events
	// Parameters
	//   event - entity event, see SEntityEvent for more information
	virtual void ProcessEvent(SEntityEvent& event) = 0;

	virtual void SetChannelId(uint16 id) = 0;
	virtual void SetAuthority(bool auth) = 0;

	// Summary
	//   Retrieves the RMI Base pointer
	// Description
	//   Internal function used for RMI. It's usually implemented by
	//   CGameObjectExtensionHelper provides a way of checking who should
	//   receive some RMI call.
	virtual const void* GetRMIBase() const = 0;

	// Summary
	//   Performs an additional update
	// Parameters
	//   frameTime - time elapsed since the last frame update
	// See Also
	//   Update, IGameObject::EnablePostUpdates, IGameObject::DisablePostUpdates
	virtual void PostUpdate(float frameTime) = 0;

	// Summary
	virtual void PostRemoteSpawn() = 0;

	// Summary
	//   Retrieves the pointer to the game object
	// Returns
	//   A pointer to the game object which hold this extension
	ILINE IGameObject* GetGameObject() const { return m_pGameObject; }

	// Summary
	//   Retrieves the pointer to the entity
	// Returns
	//   A pointer to the entity which hold this game object extension
	ILINE IEntity* GetEntity() const { return m_pEntity; }

	// Summary
	//   Retrieves the EntityId
	// Returns
	//   An EntityId to the entity which hold this game object extension
	ILINE EntityId GetEntityId() const { return m_entityId; }

protected:
	void SetGameObject(IGameObject* pGameObject)
	{
		m_pGameObject = pGameObject;
		if (pGameObject)
		{
			m_pEntity = pGameObject->GetEntity();
			m_entityId = pGameObject->GetEntityId();
		}
	}

	void ResetGameObject()
	{
		m_pEntity = (m_pGameObject ? m_pGameObject->GetEntity() : 0);
		m_entityId = (m_pGameObject ? m_pGameObject->GetEntityId() : 0);
	}

private:
	IGameObject* m_pGameObject;
	EntityId     m_entityId;
	IEntity*     m_pEntity;
};

DECLARE_COMPONENT_POINTERS(IGameObjectExtension);

#define CHANGED_NETWORK_STATE(object, aspects)     do { /* IEntity * pEntity = object->GetGameObject()->GetEntity(); CryLogAlways("%s changed aspect %x (%s %d)", pEntity ? pEntity->GetName() : "NULL", aspects, __FILE__, __LINE__); */ object->GetGameObject()->ChangedNetworkState(aspects); } while (0)
#define CHANGED_NETWORK_STATE_GO(object, aspects)  do { /* IEntity * pEntity = object->GetEntity(); CryLogAlways("%s changed aspect %x (%s %d)", pEntity ? pEntity->GetName() : "NULL", aspects, __FILE__, __LINE__); */ object->ChangedNetworkState(aspects); } while (0)
#define CHANGED_NETWORK_STATE_REF(object, aspects) do { /* IEntity * pEntity = object.GetGameObject()->GetEntity(); CryLogAlways("%s changed aspect %x (%s %d)", pEntity ? pEntity->GetName() : "NULL", aspects, __FILE__, __LINE__); */ object.GetGameObject()->ChangedNetworkState(aspects); } while (0)

#endif
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryAction/IAnimatedCharacter.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryAction/IInteractor.h>
#include <Prey/CryAction/IItem.h>
#include <Prey/CryAction/IItemSystem.h>
#include <Prey/CryAction/IWorldQuery.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/CryActor.h>
#include <Prey/GameDll/GameRules.h>
#include <Prey/GameDll/Item.h>
#include <Prey/GameDll/Player.h>
#include <Prey/GameDll/ark/iface/IArkEmotionExtension.h>
#include <Prey/GameDll/ark/iface/IArkSpeakerExtension.h>
#include <_unknown/CActor.h>
#include <_unknown/IGameObject.h>
#include <_unknown/IRMIAtSyncItem.h>
#include <_unknown/SMicrowaveBeamParams.h>
#include <_unknown/SProjectileExplosionParams_Impact.h>

enum EDisconnectionCause;
enum ENetReliabilityType;
enum ERMIAttachmentType;
struct INetAtSyncItem;
struct INetChannel;
struct IRMIListener;

// CGameObjectExtensionHelper<ArkApexTentacleHead,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkApexTentacleHead,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkApexTentacleHead,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkApexTentacleHead, IGameObjectExtension>::Statics>(0x2D8A6B0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkApexTentacleHead, IGameObjectExtension>* const _this)>(0x182A410);
};

// CGameObjectExtensionHelper<ArkCystoid,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkCystoid,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkCystoid,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkCystoid, IGameObjectExtension>::Statics>(0x2D60460);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkCystoid, IGameObjectExtension>* const _this)>(0x1530A90);
};

// CGameObjectExtensionHelper<ArkDoor,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkDoor,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkDoor,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkDoor, IGameObjectExtension>::Statics>(0x2D610A0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkDoor, IGameObjectExtension>* const _this)>(0x153B8F0);
};

// CGameObjectExtensionHelper<ArkEmotionExtension,IArkEmotionExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkEmotionExtension,IArkEmotionExtension,64> : public IArkEmotionExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkEmotionExtension,IArkEmotionExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkEmotionExtension, IArkEmotionExtension>::Statics>(0x2D37240);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkEmotionExtension, IArkEmotionExtension>* const _this)>(0x11A8FC0);
};

// CGameObjectExtensionHelper<ArkEnvironmentalObject,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkEnvironmentalObject,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkEnvironmentalObject,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkEnvironmentalObject, IGameObjectExtension>::Statics>(0x2D3A9B0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkEnvironmentalObject, IGameObjectExtension>* const _this)>(0x11C92F0);
};

// CGameObjectExtensionHelper<ArkHealthExtension,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkHealthExtension,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkHealthExtension,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkHealthExtension, IGameObjectExtension>::Statics>(0x2D43FB0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkHealthExtension, IGameObjectExtension>* const _this)>(0x1262140);
};

// CGameObjectExtensionHelper<ArkInteractiveObject,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkInteractiveObject,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkInteractiveObject,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkInteractiveObject, IGameObjectExtension>::Statics>(0x2D3D0B0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkInteractiveObject, IGameObjectExtension>* const _this)>(0x11FFBD0);
};

// CGameObjectExtensionHelper<ArkInteractiveScreen,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkInteractiveScreen,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkInteractiveScreen,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkInteractiveScreen, IGameObjectExtension>::Statics>(0x2D37E60);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkInteractiveScreen, IGameObjectExtension>* const _this)>(0x11B0C20);
};

// CGameObjectExtensionHelper<ArkInventory,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkInventory,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkInventory,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkInventory, IGameObjectExtension>::Statics>(0x2D2B7B0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkInventory, IGameObjectExtension>* const _this)>(0x10DA300);
};

// CGameObjectExtensionHelper<ArkLaserTripline,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkLaserTripline,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkLaserTripline,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkLaserTripline, IGameObjectExtension>::Statics>(0x2D3DCC0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkLaserTripline, IGameObjectExtension>* const _this)>(0x1203010);
};

// CGameObjectExtensionHelper<ArkNpc,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkNpc,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkNpc,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkNpc, IGameObjectExtension>::Statics>(0x2D7B0F0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkNpc, IGameObjectExtension>* const _this)>(0x1613760);
};

// CGameObjectExtensionHelper<ArkPlayer,CActor,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkPlayer,CActor,64> : public CActor
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkPlayer,CActor,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkPlayer, CActor>::Statics>(0x2D7CCF0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkPlayer, CActor>* const _this)>(0x1674D90);
};

// CGameObjectExtensionHelper<ArkRecycleHelper,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkRecycleHelper,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkRecycleHelper,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkRecycleHelper, IGameObjectExtension>::Statics>(0x2D39D60);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkRecycleHelper, IGameObjectExtension>* const _this)>(0x11BF660);
};

// CGameObjectExtensionHelper<ArkRepairableObject,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkRepairableObject,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkRepairableObject,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkRepairableObject, IGameObjectExtension>::Statics>(0x2D49F60);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkRepairableObject, IGameObjectExtension>* const _this)>(0x12FB760);
};

// CGameObjectExtensionHelper<ArkSceneWindow,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkSceneWindow,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkSceneWindow,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkSceneWindow, IGameObjectExtension>::Statics>(0x2D3FCB0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkSceneWindow, IGameObjectExtension>* const _this)>(0x122BA40);
};

// CGameObjectExtensionHelper<ArkSearchHuntTarget,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkSearchHuntTarget,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkSearchHuntTarget,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkSearchHuntTarget, IGameObjectExtension>::Statics>(0x2D34770);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkSearchHuntTarget, IGameObjectExtension>* const _this)>(0x118E9A0);
};

// CGameObjectExtensionHelper<ArkSpeakerExtension,IArkSpeakerExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkSpeakerExtension,IArkSpeakerExtension,64> : public IArkSpeakerExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkSpeakerExtension,IArkSpeakerExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkSpeakerExtension, IArkSpeakerExtension>::Statics>(0x2D89AA0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkSpeakerExtension, IArkSpeakerExtension>* const _this)>(0x182A420);
};

// CGameObjectExtensionHelper<ArkSurfaceHazardLightManager,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkSurfaceHazardLightManager,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkSurfaceHazardLightManager,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkSurfaceHazardLightManager, IGameObjectExtension>::Statics>(0x2D8B2C0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkSurfaceHazardLightManager, IGameObjectExtension>* const _this)>(0x182A430);
};

// CGameObjectExtensionHelper<ArkTurret,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkTurret,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkTurret,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkTurret, IGameObjectExtension>::Statics>(0x2D7F400);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkTurret, IGameObjectExtension>* const _this)>(0x1707FC0);
};

// CGameObjectExtensionHelper<ArkTurretCountArea,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkTurretCountArea,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkTurretCountArea,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkTurretCountArea, IGameObjectExtension>::Statics>(0x2D408E0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkTurretCountArea, IGameObjectExtension>* const _this)>(0x122EA90);
};

// CGameObjectExtensionHelper<ArkTurretSpawner,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkTurretSpawner,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkTurretSpawner,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkTurretSpawner, IGameObjectExtension>::Statics>(0x2D52420);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkTurretSpawner, IGameObjectExtension>* const _this)>(0x13CE510);
};

// CGameObjectExtensionHelper<ArkTurretWeapon,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkTurretWeapon,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkTurretWeapon,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkTurretWeapon, IGameObjectExtension>::Statics>(0x2D53040);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkTurretWeapon, IGameObjectExtension>* const _this)>(0x13CF700);
};

// CGameObjectExtensionHelper<ArkWorldUI,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<ArkWorldUI,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<ArkWorldUI,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<ArkWorldUI, IGameObjectExtension>::Statics>(0x2D8CAE0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<ArkWorldUI, IGameObjectExtension>* const _this)>(0x182A440);
};

// CGameObjectExtensionHelper<CAICorpse,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CAICorpse,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CAICorpse,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CAICorpse, IGameObjectExtension>::Statics>(0x2D2A960);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CAICorpse, IGameObjectExtension>* const _this)>(0x10C1FA0);
};

// CGameObjectExtensionHelper<CAnimatedCharacter,IAnimatedCharacter,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CAnimatedCharacter,IAnimatedCharacter,64> : public IAnimatedCharacter
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CAnimatedCharacter,IAnimatedCharacter,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CAnimatedCharacter, IAnimatedCharacter>::Statics>(0x260C290);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CAnimatedCharacter, IAnimatedCharacter>* const _this)>(0x510740);
};

// CGameObjectExtensionHelper<CArkAngleRotationComponent,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkAngleRotationComponent,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkAngleRotationComponent,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkAngleRotationComponent, IGameObjectExtension>::Statics>(0x2D35430);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkAngleRotationComponent, IGameObjectExtension>* const _this)>(0x1190670);
};

// CGameObjectExtensionHelper<CArkAreaContainer,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkAreaContainer,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkAreaContainer,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkAreaContainer, IGameObjectExtension>::Statics>(0x2D59FA0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkAreaContainer, IGameObjectExtension>* const _this)>(0x14D6D00);
};

// CGameObjectExtensionHelper<CArkAttraction,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkAttraction,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkAttraction,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkAttraction, IGameObjectExtension>::Statics>(0x2D797B0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkAttraction, IGameObjectExtension>* const _this)>(0x1602FE0);
};

// CGameObjectExtensionHelper<CArkBreakable,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkBreakable,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkBreakable,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkBreakable, IGameObjectExtension>::Statics>(0x2D85240);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkBreakable, IGameObjectExtension>* const _this)>(0x182A450);
};

// CGameObjectExtensionHelper<CArkDistraction,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkDistraction,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkDistraction,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkDistraction, IGameObjectExtension>::Statics>(0x2D7A410);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkDistraction, IGameObjectExtension>* const _this)>(0x1606E60);
};

// CGameObjectExtensionHelper<CArkEthericFogEntity,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkEthericFogEntity,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkEthericFogEntity,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkEthericFogEntity, IGameObjectExtension>::Statics>(0x2D61CC0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkEthericFogEntity, IGameObjectExtension>* const _this)>(0x1541C70);
};

// CGameObjectExtensionHelper<CArkGravShaftEntity,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkGravShaftEntity,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkGravShaftEntity,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkGravShaftEntity, IGameObjectExtension>::Statics>(0x2D62DA0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkGravShaftEntity, IGameObjectExtension>* const _this)>(0x154FF20);
};

// CGameObjectExtensionHelper<CArkLight,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkLight,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkLight,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkLight, IGameObjectExtension>::Statics>(0x2D639E0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkLight, IGameObjectExtension>* const _this)>(0x155A420);
};

// CGameObjectExtensionHelper<CArkLurkPoint,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkLurkPoint,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkLurkPoint,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkLurkPoint, IGameObjectExtension>::Statics>(0x2D47190);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkLurkPoint, IGameObjectExtension>* const _this)>(0x12811F0);
};

// CGameObjectExtensionHelper<CArkMoonRockEntity,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkMoonRockEntity,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkMoonRockEntity,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkMoonRockEntity, IGameObjectExtension>::Statics>(0x2D39100);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkMoonRockEntity, IGameObjectExtension>* const _this)>(0x11B7E70);
};

// CGameObjectExtensionHelper<CArkNavIslandJumpLink,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkNavIslandJumpLink,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkNavIslandJumpLink,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkNavIslandJumpLink, IGameObjectExtension>::Statics>(0x2D5F790);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkNavIslandJumpLink, IGameObjectExtension>* const _this)>(0x152DF40);
};

// CGameObjectExtensionHelper<CArkNavLowGJumpLink,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkNavLowGJumpLink,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkNavLowGJumpLink,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkNavLowGJumpLink, IGameObjectExtension>::Statics>(0x2D3F010);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkNavLowGJumpLink, IGameObjectExtension>* const _this)>(0x121E910);
};

// CGameObjectExtensionHelper<CArkNpcSpawnCystoid,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkNpcSpawnCystoid,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkNpcSpawnCystoid,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkNpcSpawnCystoid, IGameObjectExtension>::Statics>(0x2D4DBE0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkNpcSpawnCystoid, IGameObjectExtension>* const _this)>(0x1333E80);
};

// CGameObjectExtensionHelper<CArkNpcSpawnGroup,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkNpcSpawnGroup,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkNpcSpawnGroup,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkNpcSpawnGroup, IGameObjectExtension>::Statics>(0x2D57960);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkNpcSpawnGroup, IGameObjectExtension>* const _this)>(0x1485DA0);
};

// CGameObjectExtensionHelper<CArkNpcSpawnTyphonNest,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkNpcSpawnTyphonNest,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkNpcSpawnTyphonNest,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkNpcSpawnTyphonNest, IGameObjectExtension>::Statics>(0x2D4E820);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkNpcSpawnTyphonNest, IGameObjectExtension>* const _this)>(0x1334880);
};

// CGameObjectExtensionHelper<CArkNpcSpawner,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkNpcSpawner,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkNpcSpawner,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkNpcSpawner, IGameObjectExtension>::Statics>(0x2D46500);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkNpcSpawner, IGameObjectExtension>* const _this)>(0x12803B0);
};

// CGameObjectExtensionHelper<CArkPhantomGravityWarp,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkPhantomGravityWarp,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkPhantomGravityWarp,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkPhantomGravityWarp, IGameObjectExtension>::Statics>(0x2D59370);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkPhantomGravityWarp, IGameObjectExtension>* const _this)>(0x14D5990);
};

// CGameObjectExtensionHelper<CArkRetreatPoint,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkRetreatPoint,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkRetreatPoint,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkRetreatPoint, IGameObjectExtension>::Statics>(0x2D8BED0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkRetreatPoint, IGameObjectExtension>* const _this)>(0x182A460);
};

// CGameObjectExtensionHelper<CArkSeededPickupSpawner,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CArkSeededPickupSpawner,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CArkSeededPickupSpawner,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CArkSeededPickupSpawner, IGameObjectExtension>::Statics>(0x2D88E90);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CArkSeededPickupSpawner, IGameObjectExtension>* const _this)>(0x182A470);
};

// CGameObjectExtensionHelper<CCryActor,CActor,40>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CCryActor,CActor,40> : public CActor
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CCryActor,CActor,40>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=1928 (0x788)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[40];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CCryActor,CActor,40>::Statics>(0x2D7C200);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CCryActor,CActor,40>* const _this)>(0x162BA50);
};

// CGameObjectExtensionHelper<CGameRules,IGameRules,53>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CGameRules,IGameRules,53> : public IGameRules
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CGameRules,IGameRules,53>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=2552 (0x9F8)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[53];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CGameRules,IGameRules,53>::Statics>(0x2D834D0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CGameRules,IGameRules,53>* const _this)>(0x183FFC0);
};

// CGameObjectExtensionHelper<CGameVolume_Water,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CGameVolume_Water,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CGameVolume_Water,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CGameVolume_Water, IGameObjectExtension>::Statics>(0x25ED520);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CGameVolume_Water, IGameObjectExtension>* const _this)>(0x369530);
};

// CGameObjectExtensionHelper<CInteractor,IInteractor,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CInteractor,IInteractor,64> : public IInteractor
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CInteractor,IInteractor,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CInteractor, IInteractor>::Statics>(0x260B5C0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CInteractor, IInteractor>* const _this)>(0x507100);
};

// CGameObjectExtensionHelper<CInventory,IInventory,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CInventory,IInventory,64> : public IInventory
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CInventory,IInventory,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CInventory, IInventory>::Statics>(0x25EF110);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CInventory, IInventory>* const _this)>(0x3FC850);
};

// CGameObjectExtensionHelper<CItem,IItem,39>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CItem,IItem,39> : public IItem
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CItem,IItem,39>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=1880 (0x758)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[39];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CItem,IItem,39>::Statics>(0x2D83ED0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CItem,IItem,39>* const _this)>(0x187C2D0);
};

// CGameObjectExtensionHelper<CLipSync_FacialInstance,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CLipSync_FacialInstance,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CLipSync_FacialInstance,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CLipSync_FacialInstance, IGameObjectExtension>::Statics>(0x260F740);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CLipSync_FacialInstance, IGameObjectExtension>* const _this)>(0x5D9910);
};

// CGameObjectExtensionHelper<CLipSync_TransitionQueue,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CLipSync_TransitionQueue,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CLipSync_TransitionQueue,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CLipSync_TransitionQueue, IGameObjectExtension>::Statics>(0x260EB30);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CLipSync_TransitionQueue, IGameObjectExtension>* const _this)>(0x5D9920);
};

// CGameObjectExtensionHelper<CMannequinObject,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CMannequinObject,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CMannequinObject,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CMannequinObject, IGameObjectExtension>::Statics>(0x25EBCF0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CMannequinObject, IGameObjectExtension>* const _this)>(0x3607C0);
};

// CGameObjectExtensionHelper<CRuntimeAreaObject,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CRuntimeAreaObject,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CRuntimeAreaObject,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CRuntimeAreaObject, IGameObjectExtension>::Statics>(0x25EC900);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CRuntimeAreaObject, IGameObjectExtension>* const _this)>(0x361560);
};

// CGameObjectExtensionHelper<CScriptControlledPhysics,IGameObjectExtension,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CScriptControlledPhysics,IGameObjectExtension,64> : public IGameObjectExtension
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CScriptControlledPhysics,IGameObjectExtension,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CScriptControlledPhysics, IGameObjectExtension>::Statics>(0x2D84630);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CScriptControlledPhysics, IGameObjectExtension>* const _this)>(0x1918B60);
};

// CGameObjectExtensionHelper<CWorldQuery,IWorldQuery,64>
// Header:  CryEngine/cryaction/igameobject.h
class CGameObjectExtensionHelper<CWorldQuery,IWorldQuery,64> : public IWorldQuery
{ // Size=64 (0x40)
public:
	// CGameObjectExtensionHelper<CWorldQuery,IWorldQuery,64>::Statics
	// Header:  CryEngine/cryaction/igameobject.h
	struct Statics
	{ // Size=3080 (0xC08)
		uint64_t m_nMessages;
		SGameObjectExtensionRMI m_vMessages[64];
	};

	static inline auto ms_statics = PreyGlobal<CGameObjectExtensionHelper<CWorldQuery, IWorldQuery>::Statics>(0x260A9B0);

	virtual const void* GetRMIBase() const;

#if 0
	static void GetGameObjectExtensionRMIData(void* * _arg0_, uint64_t* _arg1_);
	static const SGameObjectExtensionRMI* Helper_AddMessage(INetAtSyncItem* (*_arg0_)(TSerialize, unsigned*, INetChannel*), const char* _arg1_, ERMIAttachmentType _arg2_, bool _arg3_, ENetReliabilityType _arg4_, bool _arg5_);
#endif

	static inline auto FGetRMIBase = PreyFunction<const void* (const CGameObjectExtensionHelper<CWorldQuery, IWorldQuery>* const _this)>(0x50A680);
};

// CRMIAtSyncItem<CCryActor::AttachmentsParams,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::AttachmentsParams,CCryActor> : public IRMIAtSyncItem
{ // Size=200 (0xC8)
public:
	using CallbackFunc = bool (*)(const CCryActor::AttachmentsParams&, INetChannel*);

	CCryActor::AttachmentsParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::AttachmentsParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::AttachmentsParams,CCryActor>* Create(const CCryActor::AttachmentsParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::AttachmentsParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::AttachmentsParams,CCryActor>(const CCryActor::AttachmentsParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::AttachmentsParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::AttachmentsParams,CCryActor>* const _this)>(0x17D0ED0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::AttachmentsParams,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::AttachmentsParams,CCryActor>* const _this)>(0x17C2B00);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1812A0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CEB40);
};

// CRMIAtSyncItem<CCryActor::DropItemParams,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::DropItemParams,CCryActor> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CCryActor::DropItemParams&, INetChannel*);

	CCryActor::DropItemParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::DropItemParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::DropItemParams,CCryActor>* Create(const CCryActor::DropItemParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::DropItemParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::DropItemParams,CCryActor>(const CCryActor::DropItemParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::DropItemParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::DropItemParams,CCryActor>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::DropItemParams,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::DropItemParams,CCryActor>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CEB60);
};

// CRMIAtSyncItem<CCryActor::ExchangeItemParams,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::ExchangeItemParams,CCryActor> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CCryActor::ExchangeItemParams&, INetChannel*);

	CCryActor::ExchangeItemParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::ExchangeItemParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::ExchangeItemParams,CCryActor>* Create(const CCryActor::ExchangeItemParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::ExchangeItemParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::ExchangeItemParams,CCryActor>(const CCryActor::ExchangeItemParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::ExchangeItemParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::ExchangeItemParams,CCryActor>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::ExchangeItemParams,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::ExchangeItemParams,CCryActor>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CEBE0);
};

// CRMIAtSyncItem<CCryActor::ItemIdParam,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::ItemIdParam,CCryActor> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CCryActor::ItemIdParam&, INetChannel*);

	CCryActor::ItemIdParam m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::ItemIdParam&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::ItemIdParam,CCryActor>* Create(const CCryActor::ItemIdParam& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::ItemIdParam&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::ItemIdParam,CCryActor>(const CCryActor::ItemIdParam& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::ItemIdParam&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::ItemIdParam,CCryActor>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::ItemIdParam,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::ItemIdParam,CCryActor>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CEC40);
};

// CRMIAtSyncItem<CCryActor::KillCamFPData,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::KillCamFPData,CCryActor> : public IRMIAtSyncItem
{ // Size=120 (0x78)
public:
	using CallbackFunc = bool (*)(const CCryActor::KillCamFPData&, INetChannel*);

	CCryActor::KillCamFPData m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::KillCamFPData&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::KillCamFPData,CCryActor>* Create(const CCryActor::KillCamFPData& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::KillCamFPData&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::KillCamFPData,CCryActor>(const CCryActor::KillCamFPData& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::KillCamFPData&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::KillCamFPData,CCryActor>* const _this)>(0x17D1050);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::KillCamFPData,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::KillCamFPData,CCryActor>* const _this)>(0x17C2B30);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x17C41A0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CECC0);
};

// CRMIAtSyncItem<CCryActor::KillParams,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::KillParams,CCryActor> : public IRMIAtSyncItem
{ // Size=120 (0x78)
public:
	using CallbackFunc = bool (*)(const CCryActor::KillParams&, INetChannel*);

	CCryActor::KillParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::KillParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::KillParams,CCryActor>* Create(const CCryActor::KillParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::KillParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::KillParams,CCryActor>(const CCryActor::KillParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::KillParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::KillParams,CCryActor>* const _this)>(0x17D11B0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::KillParams,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::KillParams,CCryActor>* const _this)>(0x17C2B30);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x17C41A0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CECE0);
};

// CRMIAtSyncItem<CCryActor::MoveParams,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::MoveParams,CCryActor> : public IRMIAtSyncItem
{ // Size=80 (0x50)
public:
	using CallbackFunc = bool (*)(const CCryActor::MoveParams&, INetChannel*);

	CCryActor::MoveParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::MoveParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::MoveParams,CCryActor>* Create(const CCryActor::MoveParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::MoveParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::MoveParams,CCryActor>(const CCryActor::MoveParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::MoveParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::MoveParams,CCryActor>* const _this)>(0x17D1310);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::MoveParams,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::MoveParams,CCryActor>* const _this)>(0x17C2B60);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851620);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CED00);
};

// CRMIAtSyncItem<CCryActor::PickItemParams,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::PickItemParams,CCryActor> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CCryActor::PickItemParams&, INetChannel*);

	CCryActor::PickItemParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::PickItemParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::PickItemParams,CCryActor>* Create(const CCryActor::PickItemParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::PickItemParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::PickItemParams,CCryActor>(const CCryActor::PickItemParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::PickItemParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::PickItemParams,CCryActor>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::PickItemParams,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::PickItemParams,CCryActor>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CED60);
};

// CRMIAtSyncItem<CCryActor::ReviveParams,CCryActor>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CCryActor::ReviveParams,CCryActor> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CCryActor::ReviveParams&, INetChannel*);

	CCryActor::ReviveParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CCryActor::ReviveParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CCryActor::ReviveParams,CCryActor>* Create(const CCryActor::ReviveParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::ReviveParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CCryActor::ReviveParams,CCryActor>(const CCryActor::ReviveParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CCryActor::ReviveParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CCryActor::ReviveParams,CCryActor>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CCryActor::ReviveParams,CCryActor>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CCryActor::ReviveParams,CCryActor>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x17CEDF0);
};

// CRMIAtSyncItem<CGameRules::ActivateHitIndicatorParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::ActivateHitIndicatorParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::ActivateHitIndicatorParams&, INetChannel*);

	CGameRules::ActivateHitIndicatorParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::ActivateHitIndicatorParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::ActivateHitIndicatorParams,CGameRules>* Create(const CGameRules::ActivateHitIndicatorParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ActivateHitIndicatorParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::ActivateHitIndicatorParams,CGameRules>(const CGameRules::ActivateHitIndicatorParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ActivateHitIndicatorParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ActivateHitIndicatorParams,CGameRules>* const _this)>(0x1854E70);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ActivateHitIndicatorParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::ActivateHitIndicatorParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853250);
};

// CRMIAtSyncItem<CGameRules::ChangeTeamParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::ChangeTeamParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::ChangeTeamParams&, INetChannel*);

	CGameRules::ChangeTeamParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::ChangeTeamParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::ChangeTeamParams,CGameRules>* Create(const CGameRules::ChangeTeamParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ChangeTeamParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::ChangeTeamParams,CGameRules>(const CGameRules::ChangeTeamParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ChangeTeamParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ChangeTeamParams,CGameRules>* const _this)>(0x1854E70);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ChangeTeamParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::ChangeTeamParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853280);
};

// CRMIAtSyncItem<CGameRules::EquipmentLoadoutParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::EquipmentLoadoutParams,CGameRules> : public IRMIAtSyncItem
{ // Size=72 (0x48)
public:
	using CallbackFunc = bool (*)(const CGameRules::EquipmentLoadoutParams&, INetChannel*);

	CGameRules::EquipmentLoadoutParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::EquipmentLoadoutParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::EquipmentLoadoutParams,CGameRules>* Create(const CGameRules::EquipmentLoadoutParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::EquipmentLoadoutParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::EquipmentLoadoutParams,CGameRules>(const CGameRules::EquipmentLoadoutParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::EquipmentLoadoutParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::EquipmentLoadoutParams,CGameRules>* const _this)>(0x18559D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::EquipmentLoadoutParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::EquipmentLoadoutParams,CGameRules>* const _this)>(0x1884570);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x3874F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853330);
};

// CRMIAtSyncItem<CGameRules::NetConsoleCommandParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::NetConsoleCommandParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::NetConsoleCommandParams&, INetChannel*);

	CGameRules::NetConsoleCommandParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::NetConsoleCommandParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::NetConsoleCommandParams,CGameRules>* Create(const CGameRules::NetConsoleCommandParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::NetConsoleCommandParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::NetConsoleCommandParams,CGameRules>(const CGameRules::NetConsoleCommandParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::NetConsoleCommandParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::NetConsoleCommandParams,CGameRules>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::NetConsoleCommandParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::NetConsoleCommandParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853390);
};

// CRMIAtSyncItem<CGameRules::PostInitParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::PostInitParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::PostInitParams&, INetChannel*);

	CGameRules::PostInitParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::PostInitParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::PostInitParams,CGameRules>* Create(const CGameRules::PostInitParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::PostInitParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::PostInitParams,CGameRules>(const CGameRules::PostInitParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::PostInitParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::PostInitParams,CGameRules>* const _this)>(0x1854E70);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::PostInitParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::PostInitParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18533C0);
};

// CRMIAtSyncItem<CGameRules::ProcessHitParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::ProcessHitParams,CGameRules> : public IRMIAtSyncItem
{ // Size=80 (0x50)
public:
	using CallbackFunc = bool (*)(const CGameRules::ProcessHitParams&, INetChannel*);

	CGameRules::ProcessHitParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::ProcessHitParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::ProcessHitParams,CGameRules>* Create(const CGameRules::ProcessHitParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ProcessHitParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::ProcessHitParams,CGameRules>(const CGameRules::ProcessHitParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ProcessHitParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ProcessHitParams,CGameRules>* const _this)>(0x17D1310);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ProcessHitParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::ProcessHitParams,CGameRules>* const _this)>(0x17C2B60);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851620);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853440);
};

// CRMIAtSyncItem<CGameRules::RenameEntityParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::RenameEntityParams,CGameRules> : public IRMIAtSyncItem
{ // Size=72 (0x48)
public:
	using CallbackFunc = bool (*)(const CGameRules::RenameEntityParams&, INetChannel*);

	CGameRules::RenameEntityParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::RenameEntityParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::RenameEntityParams,CGameRules>* Create(const CGameRules::RenameEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::RenameEntityParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::RenameEntityParams,CGameRules>(const CGameRules::RenameEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::RenameEntityParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::RenameEntityParams,CGameRules>* const _this)>(0x18559D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::RenameEntityParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::RenameEntityParams,CGameRules>* const _this)>(0x1884570);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x3874F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853460);
};

// CRMIAtSyncItem<CGameRules::SHostMigrationClientRequestParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SHostMigrationClientRequestParams,CGameRules> : public IRMIAtSyncItem
{ // Size=96 (0x60)
public:
	using CallbackFunc = bool (*)(const CGameRules::SHostMigrationClientRequestParams&, INetChannel*);

	CGameRules::SHostMigrationClientRequestParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SHostMigrationClientRequestParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SHostMigrationClientRequestParams,CGameRules>* Create(const CGameRules::SHostMigrationClientRequestParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SHostMigrationClientRequestParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SHostMigrationClientRequestParams,CGameRules>(const CGameRules::SHostMigrationClientRequestParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SHostMigrationClientRequestParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SHostMigrationClientRequestParams,CGameRules>* const _this)>(0x18552D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SHostMigrationClientRequestParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SHostMigrationClientRequestParams,CGameRules>* const _this)>(0x1851390);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851630);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18534B0);
};

// CRMIAtSyncItem<CGameRules::SMidMigrationJoinParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SMidMigrationJoinParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::SMidMigrationJoinParams&, INetChannel*);

	CGameRules::SMidMigrationJoinParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SMidMigrationJoinParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SMidMigrationJoinParams,CGameRules>* Create(const CGameRules::SMidMigrationJoinParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SMidMigrationJoinParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SMidMigrationJoinParams,CGameRules>(const CGameRules::SMidMigrationJoinParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SMidMigrationJoinParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SMidMigrationJoinParams,CGameRules>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SMidMigrationJoinParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SMidMigrationJoinParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853540);
};

// CRMIAtSyncItem<CGameRules::SModuleRMIEntityParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SModuleRMIEntityParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::SModuleRMIEntityParams&, INetChannel*);

	CGameRules::SModuleRMIEntityParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SModuleRMIEntityParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SModuleRMIEntityParams,CGameRules>* Create(const CGameRules::SModuleRMIEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMIEntityParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SModuleRMIEntityParams,CGameRules>(const CGameRules::SModuleRMIEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMIEntityParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMIEntityParams,CGameRules>* const _this)>(0x1854E70);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMIEntityParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SModuleRMIEntityParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18535A0);
};

// CRMIAtSyncItem<CGameRules::SModuleRMIEntityTimeParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SModuleRMIEntityTimeParams,CGameRules> : public IRMIAtSyncItem
{ // Size=80 (0x50)
public:
	using CallbackFunc = bool (*)(const CGameRules::SModuleRMIEntityTimeParams&, INetChannel*);

	CGameRules::SModuleRMIEntityTimeParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SModuleRMIEntityTimeParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SModuleRMIEntityTimeParams,CGameRules>* Create(const CGameRules::SModuleRMIEntityTimeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMIEntityTimeParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SModuleRMIEntityTimeParams,CGameRules>(const CGameRules::SModuleRMIEntityTimeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMIEntityTimeParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMIEntityTimeParams,CGameRules>* const _this)>(0x1855430);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMIEntityTimeParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SModuleRMIEntityTimeParams,CGameRules>* const _this)>(0x17C2B60);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851620);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853620);
};

// CRMIAtSyncItem<CGameRules::SModuleRMISvClientActionParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SModuleRMISvClientActionParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::SModuleRMISvClientActionParams&, INetChannel*);

	CGameRules::SModuleRMISvClientActionParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SModuleRMISvClientActionParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SModuleRMISvClientActionParams,CGameRules>* Create(const CGameRules::SModuleRMISvClientActionParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMISvClientActionParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SModuleRMISvClientActionParams,CGameRules>(const CGameRules::SModuleRMISvClientActionParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMISvClientActionParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMISvClientActionParams,CGameRules>* const _this)>(0x1854E70);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMISvClientActionParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SModuleRMISvClientActionParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18536B0);
};

// CRMIAtSyncItem<CGameRules::SModuleRMITwoEntityParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SModuleRMITwoEntityParams,CGameRules> : public IRMIAtSyncItem
{ // Size=72 (0x48)
public:
	using CallbackFunc = bool (*)(const CGameRules::SModuleRMITwoEntityParams&, INetChannel*);

	CGameRules::SModuleRMITwoEntityParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SModuleRMITwoEntityParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SModuleRMITwoEntityParams,CGameRules>* Create(const CGameRules::SModuleRMITwoEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMITwoEntityParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SModuleRMITwoEntityParams,CGameRules>(const CGameRules::SModuleRMITwoEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SModuleRMITwoEntityParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMITwoEntityParams,CGameRules>* const _this)>(0x18559D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SModuleRMITwoEntityParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SModuleRMITwoEntityParams,CGameRules>* const _this)>(0x1884570);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x3874F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853740);
};

// CRMIAtSyncItem<CGameRules::SPredictionParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SPredictionParams,CGameRules> : public IRMIAtSyncItem
{ // Size=56 (0x38)
public:
	using CallbackFunc = bool (*)(const CGameRules::SPredictionParams&, INetChannel*);

	CGameRules::SPredictionParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SPredictionParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SPredictionParams,CGameRules>* Create(const CGameRules::SPredictionParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SPredictionParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SPredictionParams,CGameRules>(const CGameRules::SPredictionParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SPredictionParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SPredictionParams,CGameRules>* const _this)>(0x18CC3A0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SPredictionParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SPredictionParams,CGameRules>* const _this)>(0x18513F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851680);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18537F0);
};

// CRMIAtSyncItem<CGameRules::SRespawnUpdateParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SRespawnUpdateParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::SRespawnUpdateParams&, INetChannel*);

	CGameRules::SRespawnUpdateParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SRespawnUpdateParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SRespawnUpdateParams,CGameRules>* Create(const CGameRules::SRespawnUpdateParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SRespawnUpdateParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SRespawnUpdateParams,CGameRules>(const CGameRules::SRespawnUpdateParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SRespawnUpdateParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SRespawnUpdateParams,CGameRules>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SRespawnUpdateParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SRespawnUpdateParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18538D0);
};

// CRMIAtSyncItem<CGameRules::SSuccessfulFlashBangParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SSuccessfulFlashBangParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::SSuccessfulFlashBangParams&, INetChannel*);

	CGameRules::SSuccessfulFlashBangParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SSuccessfulFlashBangParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SSuccessfulFlashBangParams,CGameRules>* Create(const CGameRules::SSuccessfulFlashBangParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SSuccessfulFlashBangParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SSuccessfulFlashBangParams,CGameRules>(const CGameRules::SSuccessfulFlashBangParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SSuccessfulFlashBangParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SSuccessfulFlashBangParams,CGameRules>* const _this)>(0x1854E70);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SSuccessfulFlashBangParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SSuccessfulFlashBangParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853930);
};

// CRMIAtSyncItem<CGameRules::STrackViewParameters,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::STrackViewParameters,CGameRules> : public IRMIAtSyncItem
{ // Size=192 (0xC0)
public:
	using CallbackFunc = bool (*)(const CGameRules::STrackViewParameters&, INetChannel*);

	CGameRules::STrackViewParameters m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::STrackViewParameters&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::STrackViewParameters,CGameRules>* Create(const CGameRules::STrackViewParameters& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::STrackViewParameters&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::STrackViewParameters,CGameRules>(const CGameRules::STrackViewParameters& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::STrackViewParameters&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::STrackViewParameters,CGameRules>* const _this)>(0x1855850);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::STrackViewParameters,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::STrackViewParameters,CGameRules>* const _this)>(0x18BF030);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851660);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18539B0);
};

// CRMIAtSyncItem<CGameRules::STrackViewRequestParameters,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::STrackViewRequestParameters,CGameRules> : public IRMIAtSyncItem
{ // Size=56 (0x38)
public:
	using CallbackFunc = bool (*)(const CGameRules::STrackViewRequestParameters&, INetChannel*);

	CGameRules::STrackViewRequestParameters m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::STrackViewRequestParameters&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::STrackViewRequestParameters,CGameRules>* Create(const CGameRules::STrackViewRequestParameters& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::STrackViewRequestParameters&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::STrackViewRequestParameters,CGameRules>(const CGameRules::STrackViewRequestParameters& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::STrackViewRequestParameters&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::STrackViewRequestParameters,CGameRules>* const _this)>(0x18CC3A0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::STrackViewRequestParameters,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::STrackViewRequestParameters,CGameRules>* const _this)>(0x18513F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851680);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18539D0);
};

// CRMIAtSyncItem<CGameRules::ScoreChangeParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::ScoreChangeParams,CGameRules> : public IRMIAtSyncItem
{ // Size=72 (0x48)
public:
	using CallbackFunc = bool (*)(const CGameRules::ScoreChangeParams&, INetChannel*);

	CGameRules::ScoreChangeParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::ScoreChangeParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::ScoreChangeParams,CGameRules>* Create(const CGameRules::ScoreChangeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ScoreChangeParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::ScoreChangeParams,CGameRules>(const CGameRules::ScoreChangeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ScoreChangeParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ScoreChangeParams,CGameRules>* const _this)>(0x18559D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ScoreChangeParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::ScoreChangeParams,CGameRules>* const _this)>(0x1884570);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x3874F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853A00);
};

// CRMIAtSyncItem<CGameRules::ServerReviveParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::ServerReviveParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::ServerReviveParams&, INetChannel*);

	CGameRules::ServerReviveParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::ServerReviveParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::ServerReviveParams,CGameRules>* Create(const CGameRules::ServerReviveParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ServerReviveParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::ServerReviveParams,CGameRules>(const CGameRules::ServerReviveParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::ServerReviveParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ServerReviveParams,CGameRules>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::ServerReviveParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::ServerReviveParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853A20);
};

// CRMIAtSyncItem<CGameRules::SetGameTimeParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SetGameTimeParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::SetGameTimeParams&, INetChannel*);

	CGameRules::SetGameTimeParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SetGameTimeParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SetGameTimeParams,CGameRules>* Create(const CGameRules::SetGameTimeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SetGameTimeParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SetGameTimeParams,CGameRules>(const CGameRules::SetGameTimeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SetGameTimeParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SetGameTimeParams,CGameRules>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SetGameTimeParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SetGameTimeParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853A80);
};

// CRMIAtSyncItem<CGameRules::SetTeamParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SetTeamParams,CGameRules> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CGameRules::SetTeamParams&, INetChannel*);

	CGameRules::SetTeamParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SetTeamParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SetTeamParams,CGameRules>* Create(const CGameRules::SetTeamParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SetTeamParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SetTeamParams,CGameRules>(const CGameRules::SetTeamParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SetTeamParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SetTeamParams,CGameRules>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SetTeamParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SetTeamParams,CGameRules>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853AA0);
};

// CRMIAtSyncItem<CGameRules::SpectatorModeParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::SpectatorModeParams,CGameRules> : public IRMIAtSyncItem
{ // Size=72 (0x48)
public:
	using CallbackFunc = bool (*)(const CGameRules::SpectatorModeParams&, INetChannel*);

	CGameRules::SpectatorModeParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::SpectatorModeParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::SpectatorModeParams,CGameRules>* Create(const CGameRules::SpectatorModeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SpectatorModeParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::SpectatorModeParams,CGameRules>(const CGameRules::SpectatorModeParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::SpectatorModeParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SpectatorModeParams,CGameRules>* const _this)>(0x18559D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::SpectatorModeParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::SpectatorModeParams,CGameRules>* const _this)>(0x1884570);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x3874F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853B00);
};

// CRMIAtSyncItem<CGameRules::StartingPrematchCountDownParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::StartingPrematchCountDownParams,CGameRules> : public IRMIAtSyncItem
{ // Size=56 (0x38)
public:
	using CallbackFunc = bool (*)(const CGameRules::StartingPrematchCountDownParams&, INetChannel*);

	CGameRules::StartingPrematchCountDownParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::StartingPrematchCountDownParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::StartingPrematchCountDownParams,CGameRules>* Create(const CGameRules::StartingPrematchCountDownParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::StartingPrematchCountDownParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::StartingPrematchCountDownParams,CGameRules>(const CGameRules::StartingPrematchCountDownParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::StartingPrematchCountDownParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::StartingPrematchCountDownParams,CGameRules>* const _this)>(0x18CC3A0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::StartingPrematchCountDownParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::StartingPrematchCountDownParams,CGameRules>* const _this)>(0x18513F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851680);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853B20);
};

// CRMIAtSyncItem<CGameRules::TempRadarTaggingParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::TempRadarTaggingParams,CGameRules> : public IRMIAtSyncItem
{ // Size=72 (0x48)
public:
	using CallbackFunc = bool (*)(const CGameRules::TempRadarTaggingParams&, INetChannel*);

	CGameRules::TempRadarTaggingParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::TempRadarTaggingParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::TempRadarTaggingParams,CGameRules>* Create(const CGameRules::TempRadarTaggingParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::TempRadarTaggingParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::TempRadarTaggingParams,CGameRules>(const CGameRules::TempRadarTaggingParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::TempRadarTaggingParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::TempRadarTaggingParams,CGameRules>* const _this)>(0x18559D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::TempRadarTaggingParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::TempRadarTaggingParams,CGameRules>* const _this)>(0x1884570);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x3874F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853B50);
};

// CRMIAtSyncItem<CGameRules::TextMessageParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::TextMessageParams,CGameRules> : public IRMIAtSyncItem
{ // Size=112 (0x70)
public:
	using CallbackFunc = bool (*)(const CGameRules::TextMessageParams&, INetChannel*);

	CGameRules::TextMessageParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::TextMessageParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::TextMessageParams,CGameRules>* Create(const CGameRules::TextMessageParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::TextMessageParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::TextMessageParams,CGameRules>(const CGameRules::TextMessageParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::TextMessageParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::TextMessageParams,CGameRules>* const _this)>(0x1855B30);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::TextMessageParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::TextMessageParams,CGameRules>* const _this)>(0x1851420);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851670);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853BF0);
};

// CRMIAtSyncItem<CGameRules::UInt8Param,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::UInt8Param,CGameRules> : public IRMIAtSyncItem
{ // Size=56 (0x38)
public:
	using CallbackFunc = bool (*)(const CGameRules::UInt8Param&, INetChannel*);

	CGameRules::UInt8Param m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::UInt8Param&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::UInt8Param,CGameRules>* Create(const CGameRules::UInt8Param& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::UInt8Param&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::UInt8Param,CGameRules>(const CGameRules::UInt8Param& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::UInt8Param&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::UInt8Param,CGameRules>* const _this)>(0x18CC3A0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::UInt8Param,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::UInt8Param,CGameRules>* const _this)>(0x18513F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851680);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853C10);
};

// CRMIAtSyncItem<CGameRules::VictoryPlayerParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::VictoryPlayerParams,CGameRules> : public IRMIAtSyncItem
{ // Size=328 (0x148)
public:
	using CallbackFunc = bool (*)(const CGameRules::VictoryPlayerParams&, INetChannel*);

	CGameRules::VictoryPlayerParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::VictoryPlayerParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CGameRules::VictoryPlayerParams,CGameRules>* Create(const CGameRules::VictoryPlayerParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::VictoryPlayerParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CGameRules::VictoryPlayerParams,CGameRules>(const CGameRules::VictoryPlayerParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::VictoryPlayerParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::VictoryPlayerParams,CGameRules>* const _this)>(0x1855C90);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::VictoryPlayerParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::VictoryPlayerParams,CGameRules>* const _this)>(0x1851450);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851690);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853C40);
};

// CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules> : public IRMIAtSyncItem
{ // Size=520 (0x208)
public:
	using CallbackFunc = bool (*)(const CGameRules::VictoryTeamParams&, INetChannel*);

	CGameRules::VictoryTeamParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CGameRules::VictoryTeamParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);
	CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules>(const CGameRules::VictoryTeamParams& params, unsigned id, const SGameObjectExtensionRMI* pRMI, bool (*callback)(const CGameRules::VictoryTeamParams&, INetChannel*), INetChannel* pChannel);

#if 0
	static CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules>* Create(const CGameRules::VictoryTeamParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CGameRules::VictoryTeamParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules>* const _this)>(0x1855E10);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules>* const _this)>(0x1851480);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18516A0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853C60);
	static inline auto FCRMIAtSyncItemLessCGameRules::VictoryTeamParamsCommaCGameRulesGreaterOv2 = PreyFunction<void(CRMIAtSyncItem<CGameRules::VictoryTeamParams,CGameRules>* const _this, const CGameRules::VictoryTeamParams& params, unsigned id, const SGameObjectExtensionRMI* pRMI, bool (*callback)(const CGameRules::VictoryTeamParams&, INetChannel*), INetChannel* pChannel)>(0x184B500);
};

// CRMIAtSyncItem<CItem::AccessoryParams,CItem>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CItem::AccessoryParams,CItem> : public IRMIAtSyncItem
{ // Size=56 (0x38)
public:
	using CallbackFunc = bool (*)(const CItem::AccessoryParams&, INetChannel*);

	CItem::AccessoryParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CItem::AccessoryParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CItem::AccessoryParams,CItem>* Create(const CItem::AccessoryParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CItem::AccessoryParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CItem::AccessoryParams,CItem>(const CItem::AccessoryParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CItem::AccessoryParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CItem::AccessoryParams,CItem>* const _this)>(0x18CC3A0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CItem::AccessoryParams,CItem>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CItem::AccessoryParams,CItem>* const _this)>(0x18513F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851680);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1885650);
};

// CRMIAtSyncItem<CPlayer::SIntStatParams,CPlayer>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CPlayer::SIntStatParams,CPlayer> : public IRMIAtSyncItem
{ // Size=56 (0x38)
public:
	using CallbackFunc = bool (*)(const CPlayer::SIntStatParams&, INetChannel*);

	CPlayer::SIntStatParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CPlayer::SIntStatParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CPlayer::SIntStatParams,CPlayer>* Create(const CPlayer::SIntStatParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SIntStatParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CPlayer::SIntStatParams,CPlayer>(const CPlayer::SIntStatParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SIntStatParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SIntStatParams,CPlayer>* const _this)>(0x18CC3A0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SIntStatParams,CPlayer>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CPlayer::SIntStatParams,CPlayer>* const _this)>(0x18513F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851680);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18C8E00);
};

// CRMIAtSyncItem<CPlayer::SPlayerMeleeImpulseParams,CPlayer>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CPlayer::SPlayerMeleeImpulseParams,CPlayer> : public IRMIAtSyncItem
{ // Size=72 (0x48)
public:
	using CallbackFunc = bool (*)(const CPlayer::SPlayerMeleeImpulseParams&, INetChannel*);

	CPlayer::SPlayerMeleeImpulseParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CPlayer::SPlayerMeleeImpulseParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CPlayer::SPlayerMeleeImpulseParams,CPlayer>* Create(const CPlayer::SPlayerMeleeImpulseParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SPlayerMeleeImpulseParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CPlayer::SPlayerMeleeImpulseParams,CPlayer>(const CPlayer::SPlayerMeleeImpulseParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SPlayerMeleeImpulseParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SPlayerMeleeImpulseParams,CPlayer>* const _this)>(0x18559D0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SPlayerMeleeImpulseParams,CPlayer>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CPlayer::SPlayerMeleeImpulseParams,CPlayer>* const _this)>(0x1884570);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x3874F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18C8E90);
};

// CRMIAtSyncItem<CPlayer::SRequestLeaveLadderParams,CPlayer>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CPlayer::SRequestLeaveLadderParams,CPlayer> : public IRMIAtSyncItem
{ // Size=56 (0x38)
public:
	using CallbackFunc = bool (*)(const CPlayer::SRequestLeaveLadderParams&, INetChannel*);

	CPlayer::SRequestLeaveLadderParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CPlayer::SRequestLeaveLadderParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CPlayer::SRequestLeaveLadderParams,CPlayer>* Create(const CPlayer::SRequestLeaveLadderParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SRequestLeaveLadderParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CPlayer::SRequestLeaveLadderParams,CPlayer>(const CPlayer::SRequestLeaveLadderParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SRequestLeaveLadderParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SRequestLeaveLadderParams,CPlayer>* const _this)>(0x18CC3A0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SRequestLeaveLadderParams,CPlayer>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CPlayer::SRequestLeaveLadderParams,CPlayer>* const _this)>(0x18513F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851680);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18C8EF0);
};

// CRMIAtSyncItem<CPlayer::SRequestUseLadderParams,CPlayer>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CPlayer::SRequestUseLadderParams,CPlayer> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CPlayer::SRequestUseLadderParams&, INetChannel*);

	CPlayer::SRequestUseLadderParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CPlayer::SRequestUseLadderParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CPlayer::SRequestUseLadderParams,CPlayer>* Create(const CPlayer::SRequestUseLadderParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SRequestUseLadderParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CPlayer::SRequestUseLadderParams,CPlayer>(const CPlayer::SRequestUseLadderParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::SRequestUseLadderParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SRequestUseLadderParams,CPlayer>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CPlayer::SRequestUseLadderParams,CPlayer>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CPlayer::SRequestUseLadderParams,CPlayer>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18C8F30);
};

// CRMIAtSyncItem<CPlayer::TwoEntityParams,CPlayer>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<CPlayer::TwoEntityParams,CPlayer> : public IRMIAtSyncItem
{ // Size=64 (0x40)
public:
	using CallbackFunc = bool (*)(const CPlayer::TwoEntityParams&, INetChannel*);

	CPlayer::TwoEntityParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const CPlayer::TwoEntityParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<CPlayer::TwoEntityParams,CPlayer>* Create(const CPlayer::TwoEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::TwoEntityParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<CPlayer::TwoEntityParams,CPlayer>(const CPlayer::TwoEntityParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const CPlayer::TwoEntityParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<CPlayer::TwoEntityParams,CPlayer>* const _this)>(0x17D1470);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<CPlayer::TwoEntityParams,CPlayer>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<CPlayer::TwoEntityParams,CPlayer>* const _this)>(0x18BF000);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18515F0);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18C8FB0);
};

// CRMIAtSyncItem<ExplosionInfo,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<ExplosionInfo,CGameRules> : public IRMIAtSyncItem
{ // Size=224 (0xE0)
public:
	using CallbackFunc = bool (*)(const ExplosionInfo&, INetChannel*);

	ExplosionInfo m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const ExplosionInfo&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<ExplosionInfo,CGameRules>* Create(const ExplosionInfo& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const ExplosionInfo&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<ExplosionInfo,CGameRules>(const ExplosionInfo& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const ExplosionInfo&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<ExplosionInfo,CGameRules>* const _this)>(0x1854FD0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<ExplosionInfo,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<ExplosionInfo,CGameRules>* const _this)>(0x1851330);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851600);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853350);
};

// CRMIAtSyncItem<HitInfo,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<HitInfo,CGameRules> : public IRMIAtSyncItem
{ // Size=160 (0xA0)
public:
	using CallbackFunc = bool (*)(const HitInfo&, INetChannel*);

	HitInfo m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const HitInfo&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<HitInfo,CGameRules>* Create(const HitInfo& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const HitInfo&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<HitInfo,CGameRules>(const HitInfo& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const HitInfo&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<HitInfo,CGameRules>* const _this)>(0x1855150);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<HitInfo,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<HitInfo,CGameRules>* const _this)>(0x1851360);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851610);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853370);
};

// CRMIAtSyncItem<SMicrowaveBeamParams,CPlayer>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<SMicrowaveBeamParams,CPlayer> : public IRMIAtSyncItem
{ // Size=80 (0x50)
public:
	using CallbackFunc = bool (*)(const SMicrowaveBeamParams&, INetChannel*);

	SMicrowaveBeamParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const SMicrowaveBeamParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<SMicrowaveBeamParams,CPlayer>* Create(const SMicrowaveBeamParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SMicrowaveBeamParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<SMicrowaveBeamParams,CPlayer>(const SMicrowaveBeamParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SMicrowaveBeamParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<SMicrowaveBeamParams,CPlayer>* const _this)>(0x1855430);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<SMicrowaveBeamParams,CPlayer>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<SMicrowaveBeamParams,CPlayer>* const _this)>(0x17C2B60);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851620);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18C8E30);
};

// CRMIAtSyncItem<SPathFollowingAttachToPathParameters,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<SPathFollowingAttachToPathParameters,CGameRules> : public IRMIAtSyncItem
{ // Size=88 (0x58)
public:
	using CallbackFunc = bool (*)(const SPathFollowingAttachToPathParameters&, INetChannel*);

	SPathFollowingAttachToPathParameters m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const SPathFollowingAttachToPathParameters&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<SPathFollowingAttachToPathParameters,CGameRules>* Create(const SPathFollowingAttachToPathParameters& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SPathFollowingAttachToPathParameters&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<SPathFollowingAttachToPathParameters,CGameRules>(const SPathFollowingAttachToPathParameters& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SPathFollowingAttachToPathParameters&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<SPathFollowingAttachToPathParameters,CGameRules>* const _this)>(0x1855590);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<SPathFollowingAttachToPathParameters,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<SPathFollowingAttachToPathParameters,CGameRules>* const _this)>(0x18513C0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851640);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18537D0);
};

// CRMIAtSyncItem<SProjectileExplosionParams,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<SProjectileExplosionParams,CGameRules> : public IRMIAtSyncItem
{ // Size=136 (0x88)
public:
	using CallbackFunc = bool (*)(const SProjectileExplosionParams&, INetChannel*);

	SProjectileExplosionParams m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const SProjectileExplosionParams&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<SProjectileExplosionParams,CGameRules>* Create(const SProjectileExplosionParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SProjectileExplosionParams&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<SProjectileExplosionParams,CGameRules>(const SProjectileExplosionParams& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SProjectileExplosionParams&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<SProjectileExplosionParams,CGameRules>* const _this)>(0x18556F0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<SProjectileExplosionParams,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<SProjectileExplosionParams,CGameRules>* const _this)>(0x183F0F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851650);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853820);
};

// CRMIAtSyncItem<SProjectileExplosionParams_Impact,CGameRules>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<SProjectileExplosionParams_Impact,CGameRules> : public IRMIAtSyncItem
{ // Size=136 (0x88)
public:
	using CallbackFunc = bool (*)(const SProjectileExplosionParams_Impact&, INetChannel*);

	SProjectileExplosionParams_Impact m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const SProjectileExplosionParams_Impact&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<SProjectileExplosionParams_Impact,CGameRules>* Create(const SProjectileExplosionParams_Impact& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SProjectileExplosionParams_Impact&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<SProjectileExplosionParams_Impact,CGameRules>(const SProjectileExplosionParams_Impact& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SProjectileExplosionParams_Impact&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<SProjectileExplosionParams_Impact,CGameRules>* const _this)>(0x18556F0);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<SProjectileExplosionParams_Impact,CGameRules>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<SProjectileExplosionParams_Impact,CGameRules>* const _this)>(0x183F0F0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x1851650);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x1853840);
};

// CRMIAtSyncItem<SXPEvents,CPlayer>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIAtSyncItem<SXPEvents,CPlayer> : public IRMIAtSyncItem
{ // Size=176 (0xB0)
public:
	using CallbackFunc = bool (*)(const SXPEvents&, INetChannel*);

	SXPEvents m_params;
	unsigned m_id;
	const SGameObjectExtensionRMI* m_pRMI;
	bool (*m_callback)(const SXPEvents&, INetChannel*);
	INetChannel* m_pChannel;

	virtual bool Sync();
	virtual bool SyncWithError(EDisconnectionCause& disconnectCause, string& disconnectMessage);
	virtual void DeleteThis();
	virtual const char* GetName();
	virtual void SerializeParams(TSerialize ser);

#if 0
	static CRMIAtSyncItem<SXPEvents,CPlayer>* Create(const SXPEvents& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SXPEvents&, INetChannel*), INetChannel* _arg4_);
	CRMIAtSyncItem<SXPEvents,CPlayer>(const SXPEvents& _arg0_, unsigned _arg1_, const SGameObjectExtensionRMI* _arg2_, bool (*_arg3_)(const SXPEvents&, INetChannel*), INetChannel* _arg4_);
#endif

	static inline auto FSync = PreyFunction<bool(CRMIAtSyncItem<SXPEvents,CPlayer>* const _this)>(0x18CC500);
	static inline auto FSyncWithError = PreyFunction<bool(CRMIAtSyncItem<SXPEvents,CPlayer>* const _this, EDisconnectionCause& disconnectCause, string& disconnectMessage)>(0x1855F90);
	static inline auto FDeleteThis = PreyFunction<void(CRMIAtSyncItem<SXPEvents,CPlayer>* const _this)>(0x18BEFD0);
	static inline auto FGetName = PreyFunction<const char* (IRMICppLogger* const _this)>(0x18C1A50);
	static inline auto FSerializeParams = PreyFunction<void(IRMICppLogger* const _this, TSerialize ser)>(0x18C8F90);
};

// IGameObject::CRMIBodyImpl<CCryActor::DropItemParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CCryActor::DropItemParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CCryActor::DropItemParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CCryActor::DropItemParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CCryActor::DropItemParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CCryActor::DropItemParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CCryActor::DropItemParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::DropItemParams>* const _this, TSerialize ser)>(0x17CEE80);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CCryActor::DropItemParams>* const _this)>(0x17C42B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::DropItemParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CCryActor::ItemIdParam>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CCryActor::ItemIdParam> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CCryActor::ItemIdParam m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	static IGameObject::CRMIBodyImpl<CCryActor::ItemIdParam>* Create(const SGameObjectExtensionRMI* method, unsigned id, const CCryActor::ItemIdParam& params, IRMIListener* pListener, int userId, unsigned dependentId) { return FCreate(method, id, params, pListener, userId, dependentId); }
	virtual void DeleteThis();

#if 0
	CRMIBodyImpl<CCryActor::ItemIdParam>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CCryActor::ItemIdParam& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::ItemIdParam>* const _this, TSerialize ser)>(0x17CEF00);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CCryActor::ItemIdParam>* const _this)>(0x17C42B0);
	static inline auto FCreate = PreyFunction<IGameObject::CRMIBodyImpl<CCryActor::ItemIdParam>* (const SGameObjectExtensionRMI* method, unsigned id, const CCryActor::ItemIdParam& params, IRMIListener* pListener, int userId, unsigned dependentId)>(0x17C0B00);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::ItemIdParam>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CCryActor::KillParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CCryActor::KillParams> : public IGameObject::CRMIBody
{ // Size=136 (0x88)
public:
	CCryActor::KillParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CCryActor::KillParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CCryActor::KillParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CCryActor::KillParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CCryActor::KillParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::KillParams>* const _this, TSerialize ser)>(0x1847C80);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CCryActor::KillParams>* const _this)>(0xB9E9B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::KillParams>* const _this)>(0x183F0F0);
};

// IGameObject::CRMIBodyImpl<CCryActor::PickItemParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CCryActor::PickItemParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CCryActor::PickItemParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CCryActor::PickItemParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CCryActor::PickItemParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CCryActor::PickItemParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CCryActor::PickItemParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::PickItemParams>* const _this, TSerialize ser)>(0x1885680);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CCryActor::PickItemParams>* const _this)>(0x17C42B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CCryActor::PickItemParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CGameRules::EntityParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::EntityParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CGameRules::EntityParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::EntityParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::EntityParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::EntityParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::EntityParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::EntityParams>* const _this, TSerialize ser)>(0x1847C50);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::EntityParams>* const _this)>(0x17C42B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::EntityParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CGameRules::ProcessHitParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::ProcessHitParams> : public IGameObject::CRMIBody
{ // Size=96 (0x60)
public:
	CGameRules::ProcessHitParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::ProcessHitParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::ProcessHitParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::ProcessHitParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::ProcessHitParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::ProcessHitParams>* const _this, TSerialize ser)>(0x1912C10);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::ProcessHitParams>* const _this)>(0x190FEC0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::ProcessHitParams>* const _this)>(0x1851390);
};

// IGameObject::CRMIBodyImpl<CGameRules::RenameEntityParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::RenameEntityParams> : public IGameObject::CRMIBody
{ // Size=80 (0x50)
public:
	CGameRules::RenameEntityParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	static IGameObject::CRMIBodyImpl<CGameRules::RenameEntityParams>* Create(const SGameObjectExtensionRMI* method, unsigned id, const CGameRules::RenameEntityParams& params, IRMIListener* pListener, int userId, unsigned dependentId) { return FCreate(method, id, params, pListener, userId, dependentId); }
	virtual void DeleteThis();

#if 0
	CRMIBodyImpl<CGameRules::RenameEntityParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::RenameEntityParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::RenameEntityParams>* const _this, TSerialize ser)>(0x1847CA0);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::RenameEntityParams>* const _this)>(0x3DA250);
	static inline auto FCreate = PreyFunction<IGameObject::CRMIBodyImpl<CGameRules::RenameEntityParams>* (const SGameObjectExtensionRMI* method, unsigned id, const CGameRules::RenameEntityParams& params, IRMIListener* pListener, int userId, unsigned dependentId)>(0x183D600);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::RenameEntityParams>* const _this)>(0x17C2B60);
};

// IGameObject::CRMIBodyImpl<CGameRules::SMidMigrationJoinParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::SMidMigrationJoinParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CGameRules::SMidMigrationJoinParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::SMidMigrationJoinParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::SMidMigrationJoinParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::SMidMigrationJoinParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::SMidMigrationJoinParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SMidMigrationJoinParams>* const _this, TSerialize ser)>(0x1847CF0);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::SMidMigrationJoinParams>* const _this)>(0x17C42B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SMidMigrationJoinParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CGameRules::SRespawnUpdateParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::SRespawnUpdateParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CGameRules::SRespawnUpdateParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::SRespawnUpdateParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::SRespawnUpdateParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::SRespawnUpdateParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::SRespawnUpdateParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SRespawnUpdateParams>* const _this, TSerialize ser)>(0x1847D50);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::SRespawnUpdateParams>* const _this)>(0x17C42B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SRespawnUpdateParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CGameRules::ScoreChangeParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::ScoreChangeParams> : public IGameObject::CRMIBody
{ // Size=80 (0x50)
public:
	CGameRules::ScoreChangeParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::ScoreChangeParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::ScoreChangeParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::ScoreChangeParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::ScoreChangeParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::ScoreChangeParams>* const _this, TSerialize ser)>(0x1847DB0);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::ScoreChangeParams>* const _this)>(0x3DA250);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::ScoreChangeParams>* const _this)>(0x17C2B60);
};

// IGameObject::CRMIBodyImpl<CGameRules::SetGameTimeParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::SetGameTimeParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CGameRules::SetGameTimeParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	static IGameObject::CRMIBodyImpl<CGameRules::SetGameTimeParams>* Create(const SGameObjectExtensionRMI* method, unsigned id, const CGameRules::SetGameTimeParams& params, IRMIListener* pListener, int userId, unsigned dependentId) { return FCreate(method, id, params, pListener, userId, dependentId); }
	virtual void DeleteThis();

#if 0
	CRMIBodyImpl<CGameRules::SetGameTimeParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::SetGameTimeParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SetGameTimeParams>* const _this, TSerialize ser)>(0x1847E70);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::SetGameTimeParams>* const _this)>(0x17C42B0);
	static inline auto FCreate = PreyFunction<IGameObject::CRMIBodyImpl<CGameRules::SetGameTimeParams>* (const SGameObjectExtensionRMI* method, unsigned id, const CGameRules::SetGameTimeParams& params, IRMIListener* pListener, int userId, unsigned dependentId)>(0x183D780);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SetGameTimeParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CGameRules::SetTeamParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::SetTeamParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CGameRules::SetTeamParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::SetTeamParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::SetTeamParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::SetTeamParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::SetTeamParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SetTeamParams>* const _this, TSerialize ser)>(0x1847E90);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::SetTeamParams>* const _this)>(0x17C42B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::SetTeamParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CGameRules::StartingPrematchCountDownParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::StartingPrematchCountDownParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CGameRules::StartingPrematchCountDownParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::StartingPrematchCountDownParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::StartingPrematchCountDownParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::StartingPrematchCountDownParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::StartingPrematchCountDownParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::StartingPrematchCountDownParams>* const _this, TSerialize ser)>(0x1847EF0);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::StartingPrematchCountDownParams>* const _this)>(0x17C42B0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::StartingPrematchCountDownParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CGameRules::TempRadarTaggingParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::TempRadarTaggingParams> : public IGameObject::CRMIBody
{ // Size=80 (0x50)
public:
	CGameRules::TempRadarTaggingParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	static IGameObject::CRMIBodyImpl<CGameRules::TempRadarTaggingParams>* Create(const SGameObjectExtensionRMI* method, unsigned id, const CGameRules::TempRadarTaggingParams& params, IRMIListener* pListener, int userId, unsigned dependentId) { return FCreate(method, id, params, pListener, userId, dependentId); }
	virtual void DeleteThis();

#if 0
	CRMIBodyImpl<CGameRules::TempRadarTaggingParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::TempRadarTaggingParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::TempRadarTaggingParams>* const _this, TSerialize ser)>(0x1847F20);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::TempRadarTaggingParams>* const _this)>(0x3DA250);
	static inline auto FCreate = PreyFunction<IGameObject::CRMIBodyImpl<CGameRules::TempRadarTaggingParams>* (const SGameObjectExtensionRMI* method, unsigned id, const CGameRules::TempRadarTaggingParams& params, IRMIListener* pListener, int userId, unsigned dependentId)>(0x183D8E0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::TempRadarTaggingParams>* const _this)>(0x17C2B60);
};

// IGameObject::CRMIBodyImpl<CGameRules::TextMessageParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CGameRules::TextMessageParams> : public IGameObject::CRMIBody
{ // Size=120 (0x78)
public:
	CGameRules::TextMessageParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<CGameRules::TextMessageParams>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::TextMessageParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<CGameRules::TextMessageParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CGameRules::TextMessageParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::TextMessageParams>* const _this, TSerialize ser)>(0x1847FC0);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CGameRules::TextMessageParams>* const _this)>(0x1840050);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CGameRules::TextMessageParams>* const _this)>(0x17C2B30);
};

// IGameObject::CRMIBodyImpl<CItem::AccessoryParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CItem::AccessoryParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CItem::AccessoryParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	static IGameObject::CRMIBodyImpl<CItem::AccessoryParams>* Create(const SGameObjectExtensionRMI* method, unsigned id, const CItem::AccessoryParams& params, IRMIListener* pListener, int userId, unsigned dependentId) { return FCreate(method, id, params, pListener, userId, dependentId); }
	virtual void DeleteThis();

#if 0
	CRMIBodyImpl<CItem::AccessoryParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CItem::AccessoryParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CItem::AccessoryParams>* const _this, TSerialize ser)>(0x18831F0);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CItem::AccessoryParams>* const _this)>(0x17C42B0);
	static inline auto FCreate = PreyFunction<IGameObject::CRMIBodyImpl<CItem::AccessoryParams>* (const SGameObjectExtensionRMI* method, unsigned id, const CItem::AccessoryParams& params, IRMIListener* pListener, int userId, unsigned dependentId)>(0x1882090);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CItem::AccessoryParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams> : public IGameObject::CRMIBody
{ // Size=72 (0x48)
public:
	CPlayer::SRequestLeaveLadderParams m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	static IGameObject::CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams>* Create(const SGameObjectExtensionRMI* method, unsigned id, const CPlayer::SRequestLeaveLadderParams& params, IRMIListener* pListener, int userId, unsigned dependentId) { return FCreate(method, id, params, pListener, userId, dependentId); }
	virtual void DeleteThis();

#if 0
	CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const CPlayer::SRequestLeaveLadderParams& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams>* const _this, TSerialize ser)>(0x18C90D0);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams>* const _this)>(0x17C42B0);
	static inline auto FCreate = PreyFunction<IGameObject::CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams>* (const SGameObjectExtensionRMI* method, unsigned id, const CPlayer::SRequestLeaveLadderParams& params, IRMIListener* pListener, int userId, unsigned dependentId)>(0x18BDDB0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<CPlayer::SRequestLeaveLadderParams>* const _this)>(0x1884570);
};

// IGameObject::CRMIBodyImpl<HitInfo>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<HitInfo> : public IGameObject::CRMIBody
{ // Size=176 (0xB0)
public:
	HitInfo m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<HitInfo>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const HitInfo& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<HitInfo>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const HitInfo& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<HitInfo>* const _this, TSerialize ser)>(0x1853C80);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<HitInfo>* const _this)>(0xB62E70);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<HitInfo>* const _this)>(0x18BEFD0);
};

// IGameObject::CRMIBodyImpl<SXPEvents>
// Header:  CryEngine/cryaction/igameobject.h
class CRMIBodyImpl<SXPEvents> : public IGameObject::CRMIBody
{ // Size=192 (0xC0)
public:
	SXPEvents m_params;

	virtual void SerializeWith(TSerialize ser);
	virtual uint64_t GetSize();
	virtual void DeleteThis();

#if 0
	static IGameObject::CRMIBodyImpl<SXPEvents>* Create(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const SXPEvents& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
	CRMIBodyImpl<SXPEvents>(const SGameObjectExtensionRMI* _arg0_, unsigned _arg1_, const SXPEvents& _arg2_, IRMIListener* _arg3_, int _arg4_, unsigned _arg5_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(IGameObject::CRMIBodyImpl<SXPEvents>* const _this, TSerialize ser)>(0x18C9110);
	static inline auto FGetSize = PreyFunction<uint64_t(IGameObject::CRMIBodyImpl<SXPEvents>* const _this)>(0x18C1AE0);
	static inline auto FDeleteThis = PreyFunction<void(IGameObject::CRMIBodyImpl<SXPEvents>* const _this)>(0x18BF030);
};
#endif // !MOONCRASH
