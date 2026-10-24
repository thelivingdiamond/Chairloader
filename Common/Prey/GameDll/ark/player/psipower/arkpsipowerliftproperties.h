// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPsiLiftProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiLiftProperties : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkPsiLiftProperties::ArkMaxHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMaxHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxHeightProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiLiftProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiLiftProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiLiftProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiLiftProperties::ArkMaxHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

	// ArkPsiLiftProperties::ArkDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationSecProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiLiftProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiLiftProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiLiftProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiLiftProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
	};

#ifndef MOONCRASH
	static inline auto s_ArkMaxHeightProperty = PreyGlobal<ArkPsiLiftProperties::ArkMaxHeightProperty>(0x2BD9CB0);
#else
	static inline auto s_ArkMaxHeightProperty = PreyGlobal<ArkPsiLiftProperties::ArkMaxHeightProperty>(0x2D514D0);
#endif
	float m_MaxHeight;
#ifndef MOONCRASH
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiLiftProperties::ArkDurationSecProperty>(0x2BD9C90);
#else
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiLiftProperties::ArkDurationSecProperty>(0x2D514B0);
#endif
	float m_DurationSec;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMaxHeight(float _arg0_);
	const float& GetMaxHeight() const;
	void SetDurationSec(float _arg0_);
	const float& GetDurationSec() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F6430);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F65E0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x165E150);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13BDA20);
#endif
};

// ArkPsiPowerLiftLevelProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiPowerLiftLevelProperties : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

	// ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

	// ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

	// ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkLiftPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLiftPropertiesProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12F5C80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
#endif
	};

#ifndef MOONCRASH
	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty>(0x2BD9F10);
#else
	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty>(0x2D51730);
#endif
	string m_DisplayName;
#ifndef MOONCRASH
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty>(0x2BD9F30);
#else
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty>(0x2D51750);
#endif
	string m_Description;
#ifndef MOONCRASH
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty>(0x2BD9F50);
#else
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty>(0x2D51770);
#endif
	float m_CooldownDurationSec;
#ifndef MOONCRASH
	static inline auto s_ArkLiftPropertiesProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty>(0x2BD9F70);
#else
	static inline auto s_ArkLiftPropertiesProperty = PreyGlobal<ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty>(0x2D51790);
#endif
	ArkPsiLiftProperties m_LiftProperties;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetLiftProperties(ArkPsiLiftProperties _arg0_);
	const ArkPsiLiftProperties& GetLiftProperties() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F6460);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F6680);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13BD8A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13BDAC0);
#endif
};

// ArkPsiPowerLiftUniqueProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiPowerLiftUniqueProperties : public ArkReflectedObject
{ // Size=104 (0x68)
public:
	// ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMinHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinHeightProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMaxRangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxRangeProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkMaxRangeZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxRangeZeroGProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRadiusProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkGravityProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkGravityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGravityProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkGravityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkGravityProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkGravityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkGravityProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkInwardLiftForceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInwardLiftForceProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkUpwardLiftForceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUpwardLiftForceProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkLiftForceZeroGProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLiftForceZeroGProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkHoverVelocityDampingProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoverVelocityDampingProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkHoverVelocityFalloffProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoverVelocityFalloffProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328510);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkHoverFalloffDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoverFalloffDistanceProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkParticleEffectProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkTargetingParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingParticleEffectProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkTargetingParticleEffectLightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingParticleEffectLightProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkPlayerPostEffectIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerPostEffectIdProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkPlayerEnterAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerEnterAudioTriggerProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkPlayerExitAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerExitAudioTriggerProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10860E0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
#endif
	};

	// ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkEnterLiftSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnterLiftSignalPackageIdProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1089080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7820);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
#endif
	};

#ifndef MOONCRASH
	static inline auto s_ArkMinHeightProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty>(0x2BD9CD0);
#else
	static inline auto s_ArkMinHeightProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMinHeightProperty>(0x2D514F0);
#endif
	float m_MinHeight;
#ifndef MOONCRASH
	static inline auto s_ArkMaxRangeProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty>(0x2BD9CF0);
#else
	static inline auto s_ArkMaxRangeProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMaxRangeProperty>(0x2D51510);
#endif
	float m_MaxRange;
#ifndef MOONCRASH
	static inline auto s_ArkMaxRangeZeroGProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty>(0x2BD9D10);
#else
	static inline auto s_ArkMaxRangeZeroGProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkMaxRangeZeroGProperty>(0x2D51530);
#endif
	float m_MaxRangeZeroG;
#ifndef MOONCRASH
	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty>(0x2BD9D30);
#else
	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkRadiusProperty>(0x2D51550);
#endif
	float m_Radius;
#ifndef MOONCRASH
	static inline auto s_ArkGravityProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkGravityProperty>(0x2BD9D50);
#else
	static inline auto s_ArkGravityProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkGravityProperty>(0x2D51570);
#endif
	float m_Gravity;
#ifndef MOONCRASH
	static inline auto s_ArkInwardLiftForceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty>(0x2BD9D70);
#else
	static inline auto s_ArkInwardLiftForceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkInwardLiftForceProperty>(0x2D51590);
#endif
	float m_InwardLiftForce;
#ifndef MOONCRASH
	static inline auto s_ArkUpwardLiftForceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty>(0x2BD9D90);
#else
	static inline auto s_ArkUpwardLiftForceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkUpwardLiftForceProperty>(0x2D515B0);
#endif
	float m_UpwardLiftForce;
#ifndef MOONCRASH
	static inline auto s_ArkLiftForceZeroGProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty>(0x2BD9DB0);
#else
	static inline auto s_ArkLiftForceZeroGProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkLiftForceZeroGProperty>(0x2D515D0);
#endif
	float m_LiftForceZeroG;
#ifndef MOONCRASH
	static inline auto s_ArkHoverVelocityDampingProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty>(0x2BD9DD0);
#else
	static inline auto s_ArkHoverVelocityDampingProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityDampingProperty>(0x2D515F0);
#endif
	float m_HoverVelocityDamping;
#ifndef MOONCRASH
	static inline auto s_ArkHoverVelocityFalloffProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty>(0x2BD9DF0);
#else
	static inline auto s_ArkHoverVelocityFalloffProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverVelocityFalloffProperty>(0x2D51610);
#endif
	float m_HoverVelocityFalloff;
#ifndef MOONCRASH
	static inline auto s_ArkHoverFalloffDistanceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty>(0x2BD9E10);
#else
	static inline auto s_ArkHoverFalloffDistanceProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkHoverFalloffDistanceProperty>(0x2D51630);
#endif
	float m_HoverFalloffDistance;
#ifndef MOONCRASH
	static inline auto s_ArkParticleEffectProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty>(0x2BD9E30);
#else
	static inline auto s_ArkParticleEffectProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkParticleEffectProperty>(0x2D51650);
#endif
	string m_ParticleEffect;
#ifndef MOONCRASH
	static inline auto s_ArkTargetingParticleEffectProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty>(0x2BD9E50);
#else
	static inline auto s_ArkTargetingParticleEffectProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectProperty>(0x2D51670);
#endif
	string m_TargetingParticleEffect;
#ifndef MOONCRASH
	static inline auto s_ArkTargetingParticleEffectLightProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty>(0x2BD9E70);
#else
	static inline auto s_ArkTargetingParticleEffectLightProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkTargetingParticleEffectLightProperty>(0x2D51690);
#endif
	string m_TargetingParticleEffectLight;
#ifndef MOONCRASH
	static inline auto s_ArkPlayerPostEffectIdProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty>(0x2BD9E90);
#else
	static inline auto s_ArkPlayerPostEffectIdProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerPostEffectIdProperty>(0x2D516B0);
#endif
	uint64_t m_PlayerPostEffectId;
#ifndef MOONCRASH
	static inline auto s_ArkPlayerEnterAudioTriggerProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty>(0x2BD9EB0);
#else
	static inline auto s_ArkPlayerEnterAudioTriggerProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerEnterAudioTriggerProperty>(0x2D516D0);
#endif
	string m_PlayerEnterAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkPlayerExitAudioTriggerProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty>(0x2BD9ED0);
#else
	static inline auto s_ArkPlayerExitAudioTriggerProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkPlayerExitAudioTriggerProperty>(0x2D516F0);
#endif
	string m_PlayerExitAudioTrigger;
#ifndef MOONCRASH
	static inline auto s_ArkEnterLiftSignalPackageIdProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty>(0x2BD9EF0);
#else
	static inline auto s_ArkEnterLiftSignalPackageIdProperty = PreyGlobal<ArkPsiPowerLiftUniqueProperties::ArkEnterLiftSignalPackageIdProperty>(0x2D51710);
#endif
	uint64_t m_EnterLiftSignalPackageId;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMinHeight(float _arg0_);
	const float& GetMinHeight() const;
	void SetMaxRange(float _arg0_);
	const float& GetMaxRange() const;
	void SetMaxRangeZeroG(float _arg0_);
	const float& GetMaxRangeZeroG() const;
	void SetRadius(float _arg0_);
	const float& GetRadius() const;
	void SetGravity(float _arg0_);
	const float& GetGravity() const;
	void SetInwardLiftForce(float _arg0_);
	const float& GetInwardLiftForce() const;
	void SetUpwardLiftForce(float _arg0_);
	const float& GetUpwardLiftForce() const;
	void SetLiftForceZeroG(float _arg0_);
	const float& GetLiftForceZeroG() const;
	void SetHoverVelocityDamping(float _arg0_);
	const float& GetHoverVelocityDamping() const;
	void SetHoverVelocityFalloff(float _arg0_);
	const float& GetHoverVelocityFalloff() const;
	void SetHoverFalloffDistance(float _arg0_);
	const float& GetHoverFalloffDistance() const;
	void SetParticleEffect(string _arg0_);
	const string& GetParticleEffect() const;
	void SetTargetingParticleEffect(string _arg0_);
	const string& GetTargetingParticleEffect() const;
	void SetTargetingParticleEffectLight(string _arg0_);
	const string& GetTargetingParticleEffectLight() const;
	void SetPlayerPostEffectId(uint64_t _arg0_);
	const uint64_t& GetPlayerPostEffectId() const;
	void SetPlayerEnterAudioTrigger(string _arg0_);
	const string& GetPlayerEnterAudioTrigger() const;
	void SetPlayerExitAudioTrigger(string _arg0_);
	const string& GetPlayerExitAudioTrigger() const;
	void SetEnterLiftSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetEnterLiftSignalPackageId() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F64A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F6720);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13BD8E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13BDB60);
#endif
};

// LiftPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class LiftPowerProperties : public ArkReflectedLibrary
{ // Size=344 (0x158)
public:
	// LiftPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
#else
		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
#endif
	};

	// LiftPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12F5C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
#else
		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
#endif
	};

	// LiftPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
	class ArkLevelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLevelsProperty();
	#endif

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12F5EA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F5F50);
		static inline auto FIsArray = PreyFunction<bool(const LiftPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x12F5FA0);
#else
		static inline auto FSetValue = PreyFunction<void(const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BD330);
		static inline auto FIsArray = PreyFunction<bool(const LiftPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const LiftPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x13BD380);
#endif
	};

	using LevelProperties = ArkPsiPowerLiftLevelProperties;
	using UniqueProperties = ArkPsiPowerLiftUniqueProperties;

#ifndef MOONCRASH
	static inline auto s_ArkCommonProperty = PreyGlobal<LiftPowerProperties::ArkCommonProperty>(0x2BD9F90);
#else
	static inline auto s_ArkCommonProperty = PreyGlobal<LiftPowerProperties::ArkCommonProperty>(0x2D517B0);
#endif
	ArkPsiPowerCommonProperties m_Common;
#ifndef MOONCRASH
	static inline auto s_ArkUniqueProperty = PreyGlobal<LiftPowerProperties::ArkUniqueProperty>(0x2BD9FB0);
#else
	static inline auto s_ArkUniqueProperty = PreyGlobal<LiftPowerProperties::ArkUniqueProperty>(0x2D517D0);
#endif
	ArkPsiPowerLiftUniqueProperties m_Unique;
#ifndef MOONCRASH
	static inline auto s_ArkLevelsProperty = PreyGlobal<LiftPowerProperties::ArkLevelsProperty>(0x2BD9FD0);
#else
	static inline auto s_ArkLevelsProperty = PreyGlobal<LiftPowerProperties::ArkLevelsProperty>(0x2D517F0);
#endif
	std::vector<ArkPsiPowerLiftLevelProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerLiftUniqueProperties _arg0_);
	const ArkPsiPowerLiftUniqueProperties& GetUnique() const;
	std::vector<ArkPsiPowerLiftLevelProperties>& GetLevels();
	const std::vector<ArkPsiPowerLiftLevelProperties>& GetLevels() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F64F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12F67C0);
	static inline auto FInit = PreyFunction<bool(LiftPowerProperties* const _this)>(0x12F68B0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13BD930);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13BDC00);
	static inline auto FInit = PreyFunction<bool(LiftPowerProperties* const _this)>(0x13BDCF0);
#endif
};
