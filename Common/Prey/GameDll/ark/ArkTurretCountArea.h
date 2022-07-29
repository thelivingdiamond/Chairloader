// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkGameObjectExtension.h>

struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/ArkTurretCountArea.h
class ArkTurretCountArea : public CArkGameObjectExtension<ArkTurretCountArea> // Id=80195C4 Size=128
{
public:
	enum class EArkTurretState
	{
		invalid = 0,
		good = 1,
		broken = 2,
		undeployed = 3,
	};

	class TurretEntry // Id=80195C8 Size=8
	{
	public:
		unsigned m_turret;
		ArkTurretCountArea::EArkTurretState m_state;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(unsigned arg0) const;
#endif
	};

	bool m_bEnabled;
	std::vector<ArkTurretCountArea::TurretEntry> m_turrets;
	int m_goodTurrets;
	int m_brokenTurrets;
	int m_undeployedTurrets;
	Vec3 m_area;
	bool m_bStartsEnabled;
	
	ArkTurretCountArea();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void Release();
	virtual void ProcessEvent(SEntityEvent &_event);
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	void TestAndAddTarget(unsigned _target, bool _bSendOutputs) { FTestAndAddTarget(this,_target,_bSendOutputs); }
	void LoadProperties() { FLoadProperties(this); }
	ArkTurretCountArea::EArkTurretState GetTurretState(unsigned _turret) const { return FGetTurretState(this,_turret); }
	virtual ~ArkTurretCountArea();
	
#if 0
	void RemoveTarget(unsigned arg0);
	void OnReset(bool arg0);
#endif
	
	static inline auto FInit = PreyFunction<bool(ArkTurretCountArea *const _this, IGameObject *_pGameObject)>(0x11B15D0);
	static inline auto FPostInit = PreyFunction<void(ArkTurretCountArea *const _this, IGameObject *_pGameObject)>(0x11B1A40);
	static inline auto FFullSerialize = PreyFunction<void(ArkTurretCountArea *const _this, TSerialize _ser)>(0x11B13A0);
	static inline auto FUpdate = PreyFunction<void(ArkTurretCountArea *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x11B1DB0);
	static inline auto FRelease = PreyFunction<void(ArkTurretCountArea *const _this)>(0xA97D40);
	static inline auto FProcessEvent = PreyFunction<void(ArkTurretCountArea *const _this, SEntityEvent &_event)>(0x11B1AA0);
	static inline auto FEnable = PreyFunction<void(ArkTurretCountArea *const _this)>(0x11B1110);
	static inline auto FDisable = PreyFunction<void(ArkTurretCountArea *const _this)>(0x11B10C0);
	static inline auto FTestAndAddTarget = PreyFunction<void(ArkTurretCountArea *const _this, unsigned _target, bool _bSendOutputs)>(0x11B1CB0);
	static inline auto FLoadProperties = PreyFunction<void(ArkTurretCountArea *const _this)>(0x11B16D0);
	static inline auto FGetTurretState = PreyFunction<ArkTurretCountArea::EArkTurretState(ArkTurretCountArea const *const _this, unsigned _turret)>(0x11B14B0);
};

