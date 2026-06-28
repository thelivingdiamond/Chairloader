// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/IArkDoomClockManager.h>

class ArkClass;
class IArkValueBase;

// ArkDoomClockGlobalData_ProfileElem
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockGlobalData_ProfileElem : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkDoomClockGlobalData_ProfileElem::ArkDurationProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData_ProfileElem::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData_ProfileElem::ArkDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDoomClockGlobalData_ProfileElem::ArkPreIncrementProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkPreIncrementProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPreIncrementProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData_ProfileElem::ArkPreIncrementProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData_ProfileElem::ArkPreIncrementProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkDoomClockGlobalData_ProfileElem::ArkMaxSummonedPhantomsProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkMaxSummonedPhantomsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxSummonedPhantomsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData_ProfileElem::ArkMaxSummonedPhantomsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData_ProfileElem::ArkMaxSummonedPhantomsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkDoomClockGlobalData_ProfileElem::ArkLabelProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData_ProfileElem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData_ProfileElem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkDoomClockGlobalData_ProfileElem::ArkCryptoMultiplierProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkCryptoMultiplierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCryptoMultiplierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData_ProfileElem::ArkCryptoMultiplierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData_ProfileElem::ArkCryptoMultiplierProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	static inline auto s_ArkDurationProperty = PreyGlobal<ArkDoomClockGlobalData_ProfileElem::ArkDurationProperty>(0x2D360A0);
	float m_Duration;
	static inline auto s_ArkPreIncrementProperty = PreyGlobal<ArkDoomClockGlobalData_ProfileElem::ArkPreIncrementProperty>(0x2D360C0);
	float m_PreIncrement;
	static inline auto s_ArkMaxSummonedPhantomsProperty = PreyGlobal<ArkDoomClockGlobalData_ProfileElem::ArkMaxSummonedPhantomsProperty>(0x2D360E0);
	int m_MaxSummonedPhantoms;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkDoomClockGlobalData_ProfileElem::ArkLabelProperty>(0x2D36100);
	string m_Label;
	static inline auto s_ArkCryptoMultiplierProperty = PreyGlobal<ArkDoomClockGlobalData_ProfileElem::ArkCryptoMultiplierProperty>(0x2D36120);
	float m_CryptoMultiplier;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDuration(float _arg0_);
	const float& GetDuration() const;
	void SetPreIncrement(float _arg0_);
	const float& GetPreIncrement() const;
	void SetMaxSummonedPhantoms(int _arg0_);
	const int& GetMaxSummonedPhantoms() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetCryptoMultiplier(float _arg0_);
	const float& GetCryptoMultiplier() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x119EF40);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x119F4A0);
};

// ArkDoomClockEntityData_Level
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockEntityData_Level : public ArkReflectedObject
{ // Size=8 (0x8)
public:
	// ArkDoomClockEntityData_Level::ArkHealthModifierProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkHealthModifierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHealthModifierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockEntityData_Level::ArkHealthModifierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockEntityData_Level::ArkHealthModifierProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDoomClockEntityData_Level::ArkDamageModifierProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkDamageModifierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDamageModifierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockEntityData_Level::ArkDamageModifierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockEntityData_Level::ArkDamageModifierProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	static inline auto s_ArkHealthModifierProperty = PreyGlobal<ArkDoomClockEntityData_Level::ArkHealthModifierProperty>(0x2D36220);
	float m_HealthModifier;
	static inline auto s_ArkDamageModifierProperty = PreyGlobal<ArkDoomClockEntityData_Level::ArkDamageModifierProperty>(0x2D36240);
	float m_DamageModifier;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetHealthModifier(float _arg0_);
	const float& GetHealthModifier() const;
	void SetDamageModifier(float _arg0_);
	const float& GetDamageModifier() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x165E150);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x119F2C0);
};

// ArkDoomClockGlobalData_Profile
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockGlobalData_Profile : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkDoomClockGlobalData_Profile::ArkNameProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData_Profile::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData_Profile::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDoomClockGlobalData_Profile::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
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

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData_Profile::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CF00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData_Profile::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x119CF80);
		static inline auto FIsArray = PreyFunction<bool(const ArkDoomClockGlobalData_Profile::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDoomClockGlobalData_Profile::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x119CFA0);
	};

	static inline auto s_ArkNameProperty = PreyGlobal<ArkDoomClockGlobalData_Profile::ArkNameProperty>(0x2D36140);
	string m_Name;
	static inline auto s_ArkLevelsProperty = PreyGlobal<ArkDoomClockGlobalData_Profile::ArkLevelsProperty>(0x2D36160);
	std::vector<ArkDoomClockGlobalData_ProfileElem> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetName(string _arg0_);
	const string& GetName() const;
	std::vector<ArkDoomClockGlobalData_ProfileElem>& GetLevels();
	const std::vector<ArkDoomClockGlobalData_ProfileElem>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x119EF00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x119F400);
};

// ArkDoomClockLevelFanfare
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockLevelFanfare : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkDoomClockLevelFanfare::ArkVFXProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkVFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockLevelFanfare::ArkVFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockLevelFanfare::ArkVFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDoomClockLevelFanfare::ArkSFXProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkSFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockLevelFanfare::ArkSFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockLevelFanfare::ArkSFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkDoomClockLevelFanfare::ArkPostFXProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkPostFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPostFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockLevelFanfare::ArkPostFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockLevelFanfare::ArkPostFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkVFXProperty = PreyGlobal<ArkDoomClockLevelFanfare::ArkVFXProperty>(0x2D36040);
	string m_VFX;
	static inline auto s_ArkSFXProperty = PreyGlobal<ArkDoomClockLevelFanfare::ArkSFXProperty>(0x2D36060);
	string m_SFX;
	static inline auto s_ArkPostFXProperty = PreyGlobal<ArkDoomClockLevelFanfare::ArkPostFXProperty>(0x2D36080);
	uint64_t m_PostFX;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetVFX(string _arg0_);
	const string& GetVFX() const;
	void SetSFX(string _arg0_);
	const string& GetSFX() const;
	void SetPostFX(uint64_t _arg0_);
	const uint64_t& GetPostFX() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x119EF80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x119F540);
};

// ArkDoomClockEntityData
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockEntityData : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkDoomClockEntityData::ArkNameProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockEntityData::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockEntityData::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDoomClockEntityData::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
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

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockEntityData::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119D020);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockEntityData::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D040);
		static inline auto FIsArray = PreyFunction<bool(const ArkDoomClockEntityData::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDoomClockEntityData::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x139EF00);
	};

	static inline auto s_ArkNameProperty = PreyGlobal<ArkDoomClockEntityData::ArkNameProperty>(0x2D36260);
	string m_Name;
	static inline auto s_ArkLevelsProperty = PreyGlobal<ArkDoomClockEntityData::ArkLevelsProperty>(0x2D36280);
	std::vector<ArkDoomClockEntityData_Level> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetName(string _arg0_);
	const string& GetName() const;
	std::vector<ArkDoomClockEntityData_Level>& GetLevels();
	const std::vector<ArkDoomClockEntityData_Level>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x119EF00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x119F220);
};

// ArkDoomClockGlobalData
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockGlobalData : public ArkReflectedObject
{ // Size=72 (0x48)
public:
	// ArkDoomClockGlobalData::ArkMaxLevelProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkMaxLevelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxLevelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData::ArkMaxLevelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData::ArkMaxLevelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDoomClockGlobalData::ArkProfileProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkProfileProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkProfileProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData::ArkProfileProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119D060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData::ArkProfileProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D0E0);
		static inline auto FIsArray = PreyFunction<bool(const ArkDoomClockGlobalData::ArkProfileProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDoomClockGlobalData::ArkProfileProperty* const _this, ArkReflectedObject* _pObject)>(0x119D100);
	};

	// ArkDoomClockGlobalData::ArkLevelFanfareProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkLevelFanfareProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLevelFanfareProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData::ArkLevelFanfareProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CC90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData::ArkLevelFanfareProperty* const _this, ArkReflectedObject* const _pObject)>(0x119CD30);
		static inline auto FIsArray = PreyFunction<bool(const ArkDoomClockGlobalData::ArkLevelFanfareProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDoomClockGlobalData::ArkLevelFanfareProperty* const _this, ArkReflectedObject* _pObject)>(0x119CDD0);
	};

	// ArkDoomClockGlobalData::ArkPreIncrementPostFXProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkPreIncrementPostFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPreIncrementPostFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData::ArkPreIncrementPostFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData::ArkPreIncrementPostFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkDoomClockGlobalData::ArkPreIncrementVFXProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkPreIncrementVFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPreIncrementVFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockGlobalData::ArkPreIncrementVFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockGlobalData::ArkPreIncrementVFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	static inline auto s_ArkMaxLevelProperty = PreyGlobal<ArkDoomClockGlobalData::ArkMaxLevelProperty>(0x2D36180);
	int m_MaxLevel;
	static inline auto s_ArkProfileProperty = PreyGlobal<ArkDoomClockGlobalData::ArkProfileProperty>(0x2D361A0);
	std::vector<ArkDoomClockGlobalData_Profile> m_Profile;
	static inline auto s_ArkLevelFanfareProperty = PreyGlobal<ArkDoomClockGlobalData::ArkLevelFanfareProperty>(0x2D361C0);
	std::vector<ArkDoomClockLevelFanfare> m_LevelFanfare;
	static inline auto s_ArkPreIncrementPostFXProperty = PreyGlobal<ArkDoomClockGlobalData::ArkPreIncrementPostFXProperty>(0x2D361E0);
	uint64_t m_PreIncrementPostFX;
	static inline auto s_ArkPreIncrementVFXProperty = PreyGlobal<ArkDoomClockGlobalData::ArkPreIncrementVFXProperty>(0x2D36200);
	string m_PreIncrementVFX;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMaxLevel(int _arg0_);
	const int& GetMaxLevel() const;
	std::vector<ArkDoomClockGlobalData_Profile>& GetProfile();
	const std::vector<ArkDoomClockGlobalData_Profile>& GetProfile() const;
	std::vector<ArkDoomClockLevelFanfare>& GetLevelFanfare();
	const std::vector<ArkDoomClockLevelFanfare>& GetLevelFanfare() const;
	void SetPreIncrementPostFX(uint64_t _arg0_);
	const uint64_t& GetPreIncrementPostFX() const;
	void SetPreIncrementVFX(string _arg0_);
	const string& GetPreIncrementVFX() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x119EEB0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x119F360);
};

// ArkDoomClockData
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockData : public ArkReflectedObject
{ // Size=96 (0x60)
public:
	// ArkDoomClockData::ArkGlobalDataProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkGlobalDataProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGlobalDataProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockData::ArkGlobalDataProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CB90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockData::ArkGlobalDataProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDoomClockData::ArkEntityDataProperty
	// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
	class ArkEntityDataProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkEntityDataProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDoomClockData::ArkEntityDataProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CD50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDoomClockData::ArkEntityDataProperty* const _this, ArkReflectedObject* const _pObject)>(0x119CE00);
		static inline auto FIsArray = PreyFunction<bool(const ArkDoomClockData::ArkEntityDataProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDoomClockData::ArkEntityDataProperty* const _this, ArkReflectedObject* _pObject)>(0x119CE20);
	};

	static inline auto s_ArkGlobalDataProperty = PreyGlobal<ArkDoomClockData::ArkGlobalDataProperty>(0x2D362A0);
	ArkDoomClockGlobalData m_GlobalData;
	static inline auto s_ArkEntityDataProperty = PreyGlobal<ArkDoomClockData::ArkEntityDataProperty>(0x2D362C0);
	std::vector<ArkDoomClockEntityData> m_EntityData;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetGlobalData(ArkDoomClockGlobalData _arg0_);
	const ArkDoomClockGlobalData& GetGlobalData() const;
	std::vector<ArkDoomClockEntityData>& GetEntityData();
	const std::vector<ArkDoomClockEntityData>& GetEntityData() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x119EE40);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x119F180);
};

// ArkDoomClockManager
// Header:  Prey/GameDll/ark/ArkDoomClockManager.h
class ArkDoomClockManager : public IArkDoomClockManager
{ // Size=144 (0x90)
public:
	bool m_bEnabled;
	float m_fAccumulatedTime;
	int m_iDoomClockLevel;
	ArkDoomClockData m_data;
	bool m_bInPreIncrement;
	float m_fDuration;
	float m_fPreIncrement;
	int m_iMaxSummonedPhantoms;
	string m_globalDataProfileName;

	ArkDoomClockManager();
	~ArkDoomClockManager();
	void OnNewGame() { FOnNewGame(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	void FullSerialize(TSerialize _serializer) { FFullSerialize(this, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void Enable() { FEnable(this); }
	void Disable() { FDisable(this); }
	bool IsEnabled() const { return FIsEnabled(this); }
	void SetProfile(const char* _globalprofileName) { FSetProfile(this, _globalprofileName); }
	void SetDoomClockLevel(int _level) { FSetDoomClockLevel(this, _level); }
	const char* GetDoomClockLevelLabel() const { return FGetDoomClockLevelLabel(this); }
	int GetNumLevelsForCurrentProfile() const { return FGetNumLevelsForCurrentProfile(this); }
	float GetCurrentCryptoMultiplier() const { return FGetCurrentCryptoMultiplier(this); }
	float GetHealthModifier(const char* _entityProfileName, int _level) { return FGetHealthModifier(this, _entityProfileName, _level); }
	float GetDamageModifier(const char* _entityProfileName, int _level) { return FGetDamageModifier(this, _entityProfileName, _level); }
	void SetAccumulatedTime(float _val) { FSetAccumulatedTime(this, _val); }
	void IncrementLevel() { FIncrementLevel(this); }
	void DecrementLevel() { FDecrementLevel(this); }
	void SendEnabledEvent(bool _bEnabled) { FSendEnabledEvent(this, _bEnabled); }
	void SendIncrementEvent() { FSendIncrementEvent(this); }
	virtual std::vector<string> GetGlobalProfileNames() const;
	void LoadXml() { FLoadXml(this); }
	const ArkDoomClockEntityData_Level* GetEntityDataForLevel(const char* _name, const int _level) const { return FGetEntityDataForLevel(this, _name, _level); }
	const ArkDoomClockGlobalData_ProfileElem* GetCurrentProfileElement() const { return FGetCurrentProfileElement(this); }
	void UpdateCache() { FUpdateCache(this); }

#if 0
	int GetDoomClockLevel() const;
	float GetDuration() const;
	float GetAccumulatedTime() const;
	int GetMaxSummonedPhantoms() const;
	void SendPreIncrementEvent();
	float GetNormalizedTimeRemaining() const;
	float GetDuration_Internal();
	float GetPreIncrement_Internal();
	int GetMaxSummonedPhantoms_Internal();
#endif

	static inline auto FArkDoomClockManagerOv1 = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119EBE0);
	static inline auto FBitNotArkDoomClockManager = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119EDD0);
	static inline auto FOnNewGame = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119FCF0);
	static inline auto FReset = PreyFunction<void(ArkDoomClockManager* const _this, bool _bEnteringGameMode)>(0x119FD50);
	static inline auto FUpdate = PreyFunction<void(ArkDoomClockManager* const _this, float _frameTime)>(0x119FFB0);
	static inline auto FFullSerialize = PreyFunction<void(ArkDoomClockManager* const _this, TSerialize _serializer)>(0x119F070);
	static inline auto FPostSerialize = PreyFunction<void(ArkDoomClockManager* const _this)>(0x1333E90);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkDoomClockManager* const _this)>(0x1333E90);
	static inline auto FEnable = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119F020);
	static inline auto FDisable = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119F010);
	static inline auto FIsEnabled = PreyFunction<bool(const ArkDoomClockManager* const _this)>(0x119FB50);
	static inline auto FSetProfile = PreyFunction<void(ArkDoomClockManager* const _this, const char* _globalprofileName)>(0x119FF60);
	static inline auto FSetDoomClockLevel = PreyFunction<void(ArkDoomClockManager* const _this, int _level)>(0x119FF20);
	static inline auto FGetDoomClockLevelLabel = PreyFunction<const char* (const ArkDoomClockManager* const _this)>(0x119F6B0);
	static inline auto FGetNumLevelsForCurrentProfile = PreyFunction<int(const ArkDoomClockManager* const _this)>(0x119F7E0);
	static inline auto FGetCurrentCryptoMultiplier = PreyFunction<float(const ArkDoomClockManager* const _this)>(0x119F5E0);
	static inline auto FGetHealthModifier = PreyFunction<float(ArkDoomClockManager* const _this, const char* _entityProfileName, int _level)>(0x119F7C0);
	static inline auto FGetDamageModifier = PreyFunction<float(ArkDoomClockManager* const _this, const char* _entityProfileName, int _level)>(0x119F690);
	static inline auto FSetAccumulatedTime = PreyFunction<void(ArkDoomClockManager* const _this, float _val)>(0x119FEF0);
	static inline auto FIncrementLevel = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119F850);
	static inline auto FDecrementLevel = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119EFC0);
	static inline auto FSendEnabledEvent = PreyFunction<void(ArkDoomClockManager* const _this, bool _bEnabled)>(0x119FDB0);
	static inline auto FSendIncrementEvent = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119FE30);
	static inline auto FGetGlobalProfileNames = PreyFunction<std::vector<string>*(const ArkDoomClockManager* const _this, std::vector<string>* _return_value_)>(0x119F760);
	static inline auto FLoadXml = PreyFunction<void(ArkDoomClockManager* const _this)>(0x119FB60);
	static inline auto FGetEntityDataForLevel = PreyFunction<const ArkDoomClockEntityData_Level* (const ArkDoomClockManager* const _this, const char* _name, const int _level)>(0x119F6D0);
	static inline auto FGetCurrentProfileElement = PreyFunction<const ArkDoomClockGlobalData_ProfileElem* (const ArkDoomClockManager* const _this)>(0x119F600);
	static inline auto FUpdateCache = PreyFunction<void(ArkDoomClockManager* const _this)>(0x11A01D0);
};
#endif // MOONCRASH
