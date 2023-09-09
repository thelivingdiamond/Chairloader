// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/GameDll/Ark/npc/desires/ArkNpcDesireManagerBase.h>
#include <boost/optional.hpp>

class ArkNpc;
class ArkNpcNoiseStateDesire;

// Header: FromCpp
// Prey/GameDll/ark/npc/desires/ArkNpcNoiseStateDesireManager.h
class ArkNpcNoiseStateDesireManager : public ArkNpcDesireManagerBase<ArkNpcNoiseStateDesireManager,ArkNpcNoiseStateDesire> // Id=801414A Size=80
{
public:
	ArkAudioTrigger m_audioTriggers[5];
	boost::optional<enum EArkNpcNoiseState> m_currentNoiseState;
	
	ArkNpcNoiseStateDesireManager(ArkNpc &_npc);
	void OnActiveDesireAdded(ArkNpcNoiseStateDesire const *_pPrevActiveDesire) const { FOnActiveDesireAdded(this,_pPrevActiveDesire); }
	void OnActiveDesireRemoved(ArkNpcNoiseStateDesire const &_prevActiveDesire) const { FOnActiveDesireRemoved(this,_prevActiveDesire); }
	void OnActiveParamsChanged() const { FOnActiveParamsChanged(this); }
	void Initialize(ArkNpc const &_npc) { FInitialize(this,_npc); }
	void Refresh() { FRefresh(this); }
	void ShutDown() { FShutDown(this); }
	
	static inline auto FOnActiveDesireAdded = PreyFunction<void(ArkNpcNoiseStateDesireManager const *const _this, ArkNpcNoiseStateDesire const *_pPrevActiveDesire)>(0xA13080);
	static inline auto FOnActiveDesireRemoved = PreyFunction<void(ArkNpcNoiseStateDesireManager const *const _this, ArkNpcNoiseStateDesire const &_prevActiveDesire)>(0xA13080);
	static inline auto FOnActiveParamsChanged = PreyFunction<void(ArkNpcNoiseStateDesireManager const *const _this)>(0xA13080);
	static inline auto FInitialize = PreyFunction<void(ArkNpcNoiseStateDesireManager *const _this, ArkNpc const &_npc)>(0x1212EF0);
	static inline auto FRefresh = PreyFunction<void(ArkNpcNoiseStateDesireManager *const _this)>(0x1212F40);
	static inline auto FShutDown = PreyFunction<void(ArkNpcNoiseStateDesireManager *const _this)>(0x1213150);
};

