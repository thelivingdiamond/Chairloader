// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMovie/IMovieSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>

struct IAnimSequence;
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkCargoContainer.h
class ArkCargoContainer : public ArkEnvironmentalObject, public IMovieListener, public IEntityEventListener // Id=8019707 Size=184
{
public:
	EArkDockingState m_dockingState;
	EArkDockingBay m_dockingBay;
	string m_containerCode;
	unsigned m_dockingStation;
	unsigned m_frontDoor;
	unsigned m_backDoor;
	bool m_bOpeningFront;
	bool m_bOpeningBack;
	string m_confirmDoorOpenMessage;
	IAnimSequence *m_pCurrentSequence;
	string m_sequenceToCargoBay1;
	string m_sequenceToCargoBay2;
	string m_sequenceFromCargoBay1;
	string m_sequenceFromCargoBay2;
	
	ArkCargoContainer();
	virtual ~ArkCargoContainer();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void OnMovieEvent(IMovieListener::EMovieEvent event, IAnimSequence *pSequence);
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	float BeginDocking(EArkDockingBay _dockingBay, unsigned _dockingStation) { return FBeginDocking(this,_dockingBay,_dockingStation); }
	float BeginUndocking(unsigned _dockingStation) { return FBeginUndocking(this,_dockingStation); }
	void OpenDoors() { FOpenDoors(this); }
	bool AreDoorsOpen() const { return FAreDoorsOpen(this); }
	void UpdateSequences(const char *_toBay1, const char *_toBay2, const char *_fromBay1, const char *_fromBay2) { FUpdateSequences(this,_toBay1,_toBay2,_fromBay1,_fromBay2); }
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void HandleScriptEvent(const char *_pEvent, SEntityEvent &_event);
	bool StartTrackviewSequence(float &_sequenceDuration, EArkDockingBay _dockingBay, bool _bDocking) { return FStartTrackviewSequence(this,_sequenceDuration,_dockingBay,_bDocking); }
	void CleanupTrackviewSequence() { FCleanupTrackviewSequence(this); }
	void SetDockingState(EArkDockingState _state) { FSetDockingState(this,_state); }
	void UpdateDoorLocations() { FUpdateDoorLocations(this); }
	void CreateDoors() { FCreateDoors(this); }
	void OpenDoor(unsigned _doorId) const { FOpenDoor(this,_doorId); }
	
#if 0
	EArkDockingBay GetDockingBay() const;
	EArkDockingState GetDockingState() const;
	string const &GetConfirmDoorOpenMessage() const;
	string const &GetCode() const;
	IAnimSequence *GetTrackviewSequence(EArkDockingBay arg0, bool arg1) const;
	void CloseDoors();
#endif
	
	static inline auto FBitNotArkCargoContainer = PreyFunction<void(ArkCargoContainer *const _this)>(0x11B68D0);
	static inline auto FUpdate = PreyFunction<void(ArkCargoContainer *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x11B86C0);
	static inline auto FPostInit = PreyFunction<void(ArkCargoContainer *const _this, IGameObject *_pGameObject)>(0x11B81B0);
	static inline auto FFullSerialize = PreyFunction<void(ArkCargoContainer *const _this, TSerialize _ser)>(0x11B7500);
	static inline auto FPostSerialize = PreyFunction<void(ArkCargoContainer *const _this)>(0x11B81D0);
	static inline auto FProcessEvent = PreyFunction<void(ArkCargoContainer *const _this, SEntityEvent &_event)>(0x11B8300);
	static inline auto FOnMovieEvent = PreyFunction<void(ArkCargoContainer *const _this, IMovieListener::EMovieEvent event, IAnimSequence *pSequence)>(0x11B7FE0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkCargoContainer *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x11B7DD0);
	static inline auto FBeginDocking = PreyFunction<float(ArkCargoContainer *const _this, EArkDockingBay _dockingBay, unsigned _dockingStation)>(0x11B7230);
	static inline auto FBeginUndocking = PreyFunction<float(ArkCargoContainer *const _this, unsigned _dockingStation)>(0x11B72C0);
	static inline auto FOpenDoors = PreyFunction<void(ArkCargoContainer *const _this)>(0x11B8170);
	static inline auto FAreDoorsOpen = PreyFunction<bool(ArkCargoContainer const *const _this)>(0x11B7190);
	static inline auto FUpdateSequences = PreyFunction<void(ArkCargoContainer *const _this, const char *_toBay1, const char *_toBay2, const char *_fromBay1, const char *_fromBay2)>(0x11B8750);
	static inline auto FLoadProperties = PreyFunction<void(ArkCargoContainer *const _this)>(0x11B78E0);
	static inline auto FOnReset = PreyFunction<void(ArkCargoContainer *const _this, bool _bEnteringGameMode)>(0x11B8070);
	static inline auto FHandleScriptEvent = PreyFunction<void(ArkCargoContainer *const _this, const char *_pEvent, SEntityEvent &_event)>(0x11B7750);
	static inline auto FStartTrackviewSequence = PreyFunction<bool(ArkCargoContainer *const _this, float &_sequenceDuration, EArkDockingBay _dockingBay, bool _bDocking)>(0x11B8530);
	static inline auto FCleanupTrackviewSequence = PreyFunction<void(ArkCargoContainer *const _this)>(0x11B7350);
	static inline auto FSetDockingState = PreyFunction<void(ArkCargoContainer *const _this, EArkDockingState _state)>(0x11B84B0);
	static inline auto FUpdateDoorLocations = PreyFunction<void(ArkCargoContainer *const _this)>(0x11B86D0);
	static inline auto FCreateDoors = PreyFunction<void(ArkCargoContainer *const _this)>(0x11B73A0);
	static inline auto FOpenDoor = PreyFunction<void(ArkCargoContainer const *const _this, unsigned _doorId)>(0x11B80E0);
};

