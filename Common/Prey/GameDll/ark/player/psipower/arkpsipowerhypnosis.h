// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h>

class ArkClass;
class ArkReflectedObject;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
class HypnosisPowerProperties : public ArkReflectedLibrary // Id=801C136 Size=248
{
public:
	using LevelProperties = ArkPsiPowerHypnosisProperties;
	using UniqueProperties = ArkPsiPowerFactionProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=801C137 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(HypnosisPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(HypnosisPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static HypnosisPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkFactionProperty : public ArkProperty // Id=801C138 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(HypnosisPowerProperties::ArkFactionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14660B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(HypnosisPowerProperties::ArkFactionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static HypnosisPowerProperties::ArkFactionProperty s_ArkFactionProperty;
	ArkPsiPowerFactionProperties m_Faction;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C139 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(HypnosisPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(HypnosisPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1467C40);
		static inline auto FIsArray = PreyFunction<bool(HypnosisPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(HypnosisPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1466240);
	};

	static HypnosisPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerHypnosisProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetFaction(ArkPsiPowerFactionProperties arg0);
	ArkPsiPowerFactionProperties const &GetFaction() const;
	std::vector<ArkPsiPowerHypnosisProperties> &GetLevels();
	std::vector<ArkPsiPowerHypnosisProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x14681B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1468320);
	static inline auto FInit = PreyFunction<bool(HypnosisPowerProperties *const _this)>(0x1468410);
};

