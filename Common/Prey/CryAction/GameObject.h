#pragma once
#include <Prey/CryThreading/CryThread.h>
#include "IGameObject.h"

struct SEntitySchedulingProfiles;

class CGameObject : public IEntityProxy, public IGameObject {
public:
	struct SExtension
	{
		SExtension();

		uint64 eventReg;
		IGameObjectExtensionPtr pExtension;
		IGameObjectSystem::ExtensionID id;
		uint8 refCount;
		uint8 updateEnables[MAX_UPDATE_SLOTS_PER_EXTENSION];
		uint8 forceEnables[MAX_UPDATE_SLOTS_PER_EXTENSION];
		uint8 flagUpdateWhenVisible : MAX_UPDATE_SLOTS_PER_EXTENSION;
		uint8 flagUpdateWhenInRange : MAX_UPDATE_SLOTS_PER_EXTENSION;
		uint8 flagUpdateCombineOr : MAX_UPDATE_SLOTS_PER_EXTENSION;
		uint8 flagDisableWithAI : MAX_UPDATE_SLOTS_PER_EXTENSION;
		uint8 flagNeverUpdate : MAX_UPDATE_SLOTS_PER_EXTENSION;
		bool activated : 1;
		bool sticky : 1;
		bool postUpdate : 1;
	};

	typedef std::vector<SExtension> TExtensions;

	IActionListener *m_pActionDelegate;
	IGameObjectView *m_pViewDelegate;
	IGameObjectProfileManager *m_pProfileManager;
	uint8 m_profiles[NUM_ASPECTS];
	void *m_pUserData;
	CryMutex m_mutex;
	TExtensions m_extensions;
	uint16 m_channelId;
	NetworkAspectType m_enabledAspects;
	NetworkAspectType m_delegatableAspects;
	bool m_inRange : 1;
	bool m_isBoundToNetwork : 1;
	bool m_justExchanging : 1;
	bool m_bVisible : 1;
	bool m_bPrePhysicsEnabled : 1;
	bool m_bPhysicsDisabled : 1;
	bool m_bNoSyncPhysics : 1;
	bool m_bNeedsNetworkRebind : 1;
	uint m_updateState : 3;
	uint m_aiMode : 2;
	uint m_physDisableMode : 2;
	IGameObjectExtensionPtr m_pGameObjectExtensionCachedKey;
	SExtension *m_pGameObjectExtensionCachedValue;
	float m_updateTimer;
	float m_currDistFromPlayerSq;
	float m_closeDistThresholdSq;
	int m_enabledPhysicsEvents;
	int m_forceUpdate;
	int m_predictionHandle;
	EPrePhysicsUpdate m_prePhysicsUpdateRule;
	const SEntitySchedulingProfiles *m_pSchedulingProfiles;
	unsigned int m_currentSchedulingProfile;
	unsigned int m_cachedParentId;

	CGameObject();
};
