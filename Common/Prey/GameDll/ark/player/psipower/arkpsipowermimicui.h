// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>

struct IUIEventSystem;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowermimicui.h
class CArkPsiPowerMimicUI : public IUIGameEventSystem // Id=80197A2 Size=32
{
public:
	IUIEventSystem *m_pUIEventSystem;
	unsigned m_systemStartMorphInEventId;
	unsigned m_systemFinishMorphInEventId;
	unsigned m_systemStartMimickingEventId;
	unsigned m_systemStopMimickingEventId;
	
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	void SendStartMorphInEvent(const unsigned &_targetedEntityId) const { FSendStartMorphInEvent(this,_targetedEntityId); }
	void SendStartMimickingEvent(const unsigned &_targetedEntityId, const unsigned &_spawnedEntityId) const { FSendStartMimickingEvent(this,_targetedEntityId,_spawnedEntityId); }
	void SendStopMimickingEvent(const unsigned &_targetedEntityId, const unsigned &_spawnedEntityId) const { FSendStopMimickingEvent(this,_targetedEntityId,_spawnedEntityId); }
	
#if 0
	static const char *GetTypeNameS();
	void SendFinishMorphInEvent(const unsigned &arg0, const unsigned &arg1) const;
	unsigned GetStartMorphInEventId() const;
	unsigned GetFinishMorphInEventId() const;
	unsigned GetStartMimickingEventId() const;
	unsigned GetStopMimickingEventId() const;
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(CArkPsiPowerMimicUI const *const _this)>(0x159E890);
	static inline auto FInitEventSystem = PreyFunction<void(CArkPsiPowerMimicUI *const _this)>(0x159E8A0);
	static inline auto FUnloadEventSystem = PreyFunction<void(CArkPsiPowerMimicUI *const _this)>(0xA13080);
	static inline auto FSendStartMorphInEvent = PreyFunction<void(CArkPsiPowerMimicUI const *const _this, const unsigned &_targetedEntityId)>(0x159ED10);
	static inline auto FSendStartMimickingEvent = PreyFunction<void(CArkPsiPowerMimicUI const *const _this, const unsigned &_targetedEntityId, const unsigned &_spawnedEntityId)>(0x159EB00);
	static inline auto FSendStopMimickingEvent = PreyFunction<void(CArkPsiPowerMimicUI const *const _this, const unsigned &_targetedEntityId, const unsigned &_spawnedEntityId)>(0x159EF00);
};

