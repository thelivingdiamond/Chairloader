// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAISystem/ITacticalPointSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ITacticalPointLanguageExtender.h>
#include <_unknown/ITacticalPointLanguageExtender__SExtenderParameters.h>

struct IAIObject;
struct ITacticalPoint;

// CTacticalPointLanguageExtender
// Header:  Prey/GameDll/ai/TacticalPointLanguageExtender.h
// Include: Prey/CryAISystem/FlyHelpers_TacticalPointLanguageExtender.h
class CTacticalPointLanguageExtender : public ITacticalPointLanguageExtender
{ // Size=16 (0x10)
public:
	unsigned m_battlefrontAIObject;

	CTacticalPointLanguageExtender();
	void Reset() { FReset(this); }
	void FullSerialize(TSerialize ser) { FFullSerialize(this, ser); }
	void Initialize() { FInitialize(this); }
	void Deinitialize() { FDeinitialize(this); }
	virtual bool GeneratePoints(ITacticalPointLanguageExtender::SExtenderParameters<ITacticalPointGenerateResult *>& parameters, ITacticalPointLanguageExtender::SGenerateDetails& details, IAIObject* const object, const Vec3& objectPos, IAIObject* const auxObject, const Vec3& auxObjectPos) const;
	virtual bool GetObject(ITacticalPointLanguageExtender::SExtenderParameters<IAIObject *>& parameters) const;
	virtual bool BoolTest(ITacticalPointLanguageExtender::SExtenderParameters<bool>& params, IAIObject* const pObject, const Vec3& objPos, const ITacticalPoint& point) const;

#if 0
	void RegisterWithTacticalPointSystem();
	void RegisterQueries();
	void UnregisterFromTacticalPointSystem();
	void UnregisterQueries();
	IAIObject* GetBattleFrontObject() const;
	void ReleaseBattleFrontObject();
#endif

	static inline auto FCTacticalPointLanguageExtenderOv2 = PreyFunction<void(CTacticalPointLanguageExtender* const _this)>(0x10CEE50);
	static inline auto FReset = PreyFunction<void(CTacticalPointLanguageExtender* const _this)>(0x10CF490);
	static inline auto FFullSerialize = PreyFunction<void(CTacticalPointLanguageExtender* const _this, TSerialize ser)>(0x10CEFC0);
	static inline auto FInitialize = PreyFunction<void(CTacticalPointLanguageExtender* const _this)>(0x10CF380);
	static inline auto FDeinitialize = PreyFunction<void(CTacticalPointLanguageExtender* const _this)>(0x10CEF50);
	static inline auto FGeneratePoints = PreyFunction<bool(const CTacticalPointLanguageExtender* const _this, ITacticalPointLanguageExtender::SExtenderParameters<ITacticalPointGenerateResult *>& parameters, ITacticalPointLanguageExtender::SGenerateDetails& details, IAIObject* const object, const Vec3& objectPos, IAIObject* const auxObject, const Vec3& auxObjectPos)>(0x10CEFE0);
	static inline auto FGetObject = PreyFunction<bool(const CTacticalPointLanguageExtender* const _this, ITacticalPointLanguageExtender::SExtenderParameters<IAIObject *>& parameters)>(0x10CF350);
	static inline auto FBoolTest = PreyFunction<bool(const CTacticalPointLanguageExtender* const _this, ITacticalPointLanguageExtender::SExtenderParameters<bool>& params, IAIObject* const pObject, const Vec3& objPos, const ITacticalPoint& point)>(0x10CEEA0);
};
#endif // MOONCRASH
