// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h>

class ArkClass;
class ArkReflectedObject;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
class ElectrostaticBurstPowerProperties : public ArkReflectedLibrary // Id=801C11E Size=248
{
public:
	using LevelProperties = ArkPsiPowerElectrostaticBurstProperties;
	using UniqueProperties = bool;
	
	class ArkCommonProperty : public ArkProperty // Id=801C11F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ElectrostaticBurstPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ElectrostaticBurstPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ElectrostaticBurstPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=801C120 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ElectrostaticBurstPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ElectrostaticBurstPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static ElectrostaticBurstPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	bool m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C121 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ElectrostaticBurstPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466C60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ElectrostaticBurstPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466D60);
		static inline auto FIsArray = PreyFunction<bool(ElectrostaticBurstPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ElectrostaticBurstPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1466DB0);
	};

	static ElectrostaticBurstPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerElectrostaticBurstProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(bool arg0);
	const bool &GetUnique() const;
	std::vector<ArkPsiPowerElectrostaticBurstProperties> &GetLevels();
	std::vector<ArkPsiPowerElectrostaticBurstProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1467630);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1467750);
	static inline auto FInit = PreyFunction<bool(ElectrostaticBurstPowerProperties *const _this)>(0x1467840);
};

