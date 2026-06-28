// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkReadyRoomInfo
// Header:  Prey/Ark/ArkPlayableCharacter.h
class ArkReadyRoomInfo : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkReadyRoomInfo::ArkLockedModelProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkLockedModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockedModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomInfo::ArkLockedModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomInfo::ArkLockedModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkReadyRoomInfo::ArkUnlockedModelProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkUnlockedModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUnlockedModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomInfo::ArkUnlockedModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomInfo::ArkUnlockedModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkLockedModelProperty = PreyGlobal<ArkReadyRoomInfo::ArkLockedModelProperty>(0x2D26D10);
	string m_LockedModel;
	static inline auto s_ArkUnlockedModelProperty = PreyGlobal<ArkReadyRoomInfo::ArkUnlockedModelProperty>(0x2D26D30);
	string m_UnlockedModel;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetLockedModel(string _arg0_);
	const string& GetLockedModel() const;
	void SetUnlockedModel(string _arg0_);
	const string& GetUnlockedModel() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10929D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A1D60);
};

// ArkReadyRoomCharacterInfo
// Header:  Prey/Ark/ArkPlayableCharacter.h
class ArkReadyRoomCharacterInfo : public ArkReadyRoomInfo
{ // Size=64 (0x40)
public:
	// ArkReadyRoomCharacterInfo::ArkADBProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkADBProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkADBProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomCharacterInfo::ArkADBProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomCharacterInfo::ArkADBProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkReadyRoomCharacterInfo::ArkControllerDefProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkControllerDefProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkControllerDefProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomCharacterInfo::ArkControllerDefProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomCharacterInfo::ArkControllerDefProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkReadyRoomCharacterInfo::ArkFragmentProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkFragmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFragmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomCharacterInfo::ArkFragmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomCharacterInfo::ArkFragmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkReadyRoomCharacterInfo::ArkIdleTagProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkIdleTagProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIdleTagProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomCharacterInfo::ArkIdleTagProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomCharacterInfo::ArkIdleTagProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkReadyRoomCharacterInfo::ArkLockedTagProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkLockedTagProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockedTagProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomCharacterInfo::ArkLockedTagProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomCharacterInfo::ArkLockedTagProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkReadyRoomCharacterInfo::ArkDeadTagProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkDeadTagProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDeadTagProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomCharacterInfo::ArkDeadTagProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomCharacterInfo::ArkDeadTagProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	static inline auto s_ArkADBProperty = PreyGlobal<ArkReadyRoomCharacterInfo::ArkADBProperty>(0x2D26DF0);
	string m_ADB;
	static inline auto s_ArkControllerDefProperty = PreyGlobal<ArkReadyRoomCharacterInfo::ArkControllerDefProperty>(0x2D26E10);
	string m_ControllerDef;
	static inline auto s_ArkFragmentProperty = PreyGlobal<ArkReadyRoomCharacterInfo::ArkFragmentProperty>(0x2D26E30);
	string m_Fragment;
	static inline auto s_ArkIdleTagProperty = PreyGlobal<ArkReadyRoomCharacterInfo::ArkIdleTagProperty>(0x2D26E50);
	string m_IdleTag;
	static inline auto s_ArkLockedTagProperty = PreyGlobal<ArkReadyRoomCharacterInfo::ArkLockedTagProperty>(0x2D26E70);
	string m_LockedTag;
	static inline auto s_ArkDeadTagProperty = PreyGlobal<ArkReadyRoomCharacterInfo::ArkDeadTagProperty>(0x2D26E90);
	string m_DeadTag;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetADB(string _arg0_);
	const string& GetADB() const;
	void SetControllerDef(string _arg0_);
	const string& GetControllerDef() const;
	void SetFragment(string _arg0_);
	const string& GetFragment() const;
	void SetIdleTag(string _arg0_);
	const string& GetIdleTag() const;
	void SetLockedTag(string _arg0_);
	const string& GetLockedTag() const;
	void SetDeadTag(string _arg0_);
	const string& GetDeadTag() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10B58D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A1CC0);
};

// ArkReadyRoomPropInfo
// Header:  Prey/Ark/ArkPlayableCharacter.h
class ArkReadyRoomPropInfo : public ArkReadyRoomInfo
{ // Size=56 (0x38)
public:
	// ArkReadyRoomPropInfo::ArkIdleIntroAnimProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkIdleIntroAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIdleIntroAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomPropInfo::ArkIdleIntroAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomPropInfo::ArkIdleIntroAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkReadyRoomPropInfo::ArkIdleLoopAnimProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkIdleLoopAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIdleLoopAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomPropInfo::ArkIdleLoopAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomPropInfo::ArkIdleLoopAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkReadyRoomPropInfo::ArkLockedAnimProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkLockedAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockedAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomPropInfo::ArkLockedAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomPropInfo::ArkLockedAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkReadyRoomPropInfo::ArkDeadAnimProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkDeadAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDeadAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomPropInfo::ArkDeadAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomPropInfo::ArkDeadAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkReadyRoomPropInfo::ArkEscapedAnimProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkEscapedAnimProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEscapedAnimProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkReadyRoomPropInfo::ArkEscapedAnimProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkReadyRoomPropInfo::ArkEscapedAnimProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	static inline auto s_ArkIdleIntroAnimProperty = PreyGlobal<ArkReadyRoomPropInfo::ArkIdleIntroAnimProperty>(0x2D26D50);
	string m_IdleIntroAnim;
	static inline auto s_ArkIdleLoopAnimProperty = PreyGlobal<ArkReadyRoomPropInfo::ArkIdleLoopAnimProperty>(0x2D26D70);
	string m_IdleLoopAnim;
	static inline auto s_ArkLockedAnimProperty = PreyGlobal<ArkReadyRoomPropInfo::ArkLockedAnimProperty>(0x2D26D90);
	string m_LockedAnim;
	static inline auto s_ArkDeadAnimProperty = PreyGlobal<ArkReadyRoomPropInfo::ArkDeadAnimProperty>(0x2D26DB0);
	string m_DeadAnim;
	static inline auto s_ArkEscapedAnimProperty = PreyGlobal<ArkReadyRoomPropInfo::ArkEscapedAnimProperty>(0x2D26DD0);
	string m_EscapedAnim;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetIdleIntroAnim(string _arg0_);
	const string& GetIdleIntroAnim() const;
	void SetIdleLoopAnim(string _arg0_);
	const string& GetIdleLoopAnim() const;
	void SetLockedAnim(string _arg0_);
	const string& GetLockedAnim() const;
	void SetDeadAnim(string _arg0_);
	const string& GetDeadAnim() const;
	void SetEscapedAnim(string _arg0_);
	const string& GetEscapedAnim() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A1AC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A1E00);
};

// ArkStartingItem
// Header:  Prey/Ark/ArkPlayableCharacter.h
class ArkStartingItem : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkStartingItem::ArkArchetypeProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStartingItem::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
	};

	// ArkStartingItem::ArkQuantityProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkQuantityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkQuantityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStartingItem::ArkQuantityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStartingItem::ArkQuantityProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkStartingItem::ArkShowOnCharacterSelectProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkShowOnCharacterSelectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkShowOnCharacterSelectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStartingItem::ArkShowOnCharacterSelectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A03C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStartingItem::ArkShowOnCharacterSelectProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkStartingItem::ArkArchetypeProperty>(0x2D26CB0);
	string m_Archetype;
	static inline auto s_ArkQuantityProperty = PreyGlobal<ArkStartingItem::ArkQuantityProperty>(0x2D26CD0);
	int m_Quantity;
	static inline auto s_ArkShowOnCharacterSelectProperty = PreyGlobal<ArkStartingItem::ArkShowOnCharacterSelectProperty>(0x2D26CF0);
	bool m_ShowOnCharacterSelect;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkStartingItem();
	ArkStartingItem(const string& _arg0_, int _arg1_);
	void SetArchetype(string _arg0_);
	uint64_t GetArchetype() const;
	const string& GetArchetypeString() const;
	void SetQuantity(int _arg0_);
	const int& GetQuantity() const;
	void SetShowOnCharacterSelect(bool _arg0_);
	const bool& GetShowOnCharacterSelect() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1087430);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A1EA0);
};

// ArkPlayableCharacter
// Header:  Prey/Ark/ArkPlayableCharacter.h
class ArkPlayableCharacter : public ArkReflectedObject
{ // Size=376 (0x178)
public:
	// ArkPlayableCharacter::ArkIDProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPlayableCharacter::ArkNameProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPlayableCharacter::ArkLabelProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPlayableCharacter::ArkPortraitImageProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkPortraitImageProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPortraitImageProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkPortraitImageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkPortraitImageProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPlayableCharacter::ArkClassLabelProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkClassLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkClassLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkClassLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkClassLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPlayableCharacter::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkPlayableCharacter::ArkLockedDescriptionProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkLockedDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockedDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkLockedDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkLockedDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkPlayableCharacter::ArkLockedObjectiveProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkLockedObjectiveProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLockedObjectiveProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkLockedObjectiveProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkLockedObjectiveProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkPlayableCharacter::ArkSpecialtiesProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkSpecialtiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSpecialtiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkSpecialtiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkSpecialtiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// ArkPlayableCharacter::ArkUnlockMethodProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkUnlockMethodProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUnlockMethodProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkUnlockMethodProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10917B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkUnlockMethodProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	// ArkPlayableCharacter::ArkModelProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkModelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkModelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkModelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkModelProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
	};

	// ArkPlayableCharacter::ArkArmsSkinProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkArmsSkinProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkArmsSkinProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkArmsSkinProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B1A70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkArmsSkinProperty* const _this, ArkReflectedObject* const _pObject)>(0x10844A0);
	};

	// ArkPlayableCharacter::ArkLegsSkinProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkLegsSkinProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLegsSkinProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkLegsSkinProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD500);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkLegsSkinProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B80);
	};

	// ArkPlayableCharacter::ArkReadyRoomCharacterProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkReadyRoomCharacterProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReadyRoomCharacterProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkReadyRoomCharacterProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A06E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkReadyRoomCharacterProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
	};

	// ArkPlayableCharacter::ArkReadyRoomHandPropProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkReadyRoomHandPropProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReadyRoomHandPropProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkReadyRoomHandPropProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0790);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkReadyRoomHandPropProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	// ArkPlayableCharacter::ArkReadyRoomEnvironmentPropProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkReadyRoomEnvironmentPropProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReadyRoomEnvironmentPropProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkReadyRoomEnvironmentPropProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A07D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkReadyRoomEnvironmentPropProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A0810);
	};

	// ArkPlayableCharacter::ArkStatModifierProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkStatModifierProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStatModifierProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkStatModifierProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkStatModifierProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A0160);
	};

	// ArkPlayableCharacter::ArkAbilityLayoutProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkAbilityLayoutProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAbilityLayoutProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkAbilityLayoutProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0170);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkAbilityLayoutProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B8610);
	};

	// ArkPlayableCharacter::ArkStartsUnlockedProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkStartsUnlockedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartsUnlockedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkStartsUnlockedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkStartsUnlockedProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A0190);
	};

	// ArkPlayableCharacter::ArkSkeletonKeyProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkSkeletonKeyProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSkeletonKeyProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkSkeletonKeyProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A01A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkSkeletonKeyProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A01B0);
	};

	// ArkPlayableCharacter::ArkCorpseProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkCorpseProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkCorpseProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkCorpseProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A01C0);
	};

	// ArkPlayableCharacter::ArkStartingAbilitiesProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkStartingAbilitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStartingAbilitiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkStartingAbilitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0220);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkStartingAbilitiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A0250);
		static inline auto FIsArray = PreyFunction<bool(const ArkPlayableCharacter::ArkStartingAbilitiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPlayableCharacter::ArkStartingAbilitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x10A0280);
	};

	// ArkPlayableCharacter::ArkStartingItemsProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkStartingItemsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStartingItemsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkStartingItemsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0290);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkStartingItemsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A0300);
		static inline auto FIsArray = PreyFunction<bool(const ArkPlayableCharacter::ArkStartingItemsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPlayableCharacter::ArkStartingItemsProperty* const _this, ArkReflectedObject* _pObject)>(0x10A0330);
	};

	// ArkPlayableCharacter::ArkSwitchStateProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkSwitchStateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSwitchStateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkSwitchStateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A03D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkSwitchStateProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A0430);
	};

	// ArkPlayableCharacter::ArkInitialObjectiveDescriptionProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkInitialObjectiveDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInitialObjectiveDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacter::ArkInitialObjectiveDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0440);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacter::ArkInitialObjectiveDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A04A0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkPlayableCharacter::ArkIDProperty>(0x2D26EB0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkPlayableCharacter::ArkNameProperty>(0x2D26ED0);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkPlayableCharacter::ArkLabelProperty>(0x2D26EF0);
	string m_Label;
	static inline auto s_ArkPortraitImageProperty = PreyGlobal<ArkPlayableCharacter::ArkPortraitImageProperty>(0x2D26F30);
	string m_PortraitImage;
	static inline auto s_ArkClassLabelProperty = PreyGlobal<ArkPlayableCharacter::ArkClassLabelProperty>(0x2D26F10);
	string m_ClassLabel;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPlayableCharacter::ArkDescriptionProperty>(0x2D26F50);
	string m_Description;
	static inline auto s_ArkLockedDescriptionProperty = PreyGlobal<ArkPlayableCharacter::ArkLockedDescriptionProperty>(0x2D26F70);
	string m_LockedDescription;
	static inline auto s_ArkLockedObjectiveProperty = PreyGlobal<ArkPlayableCharacter::ArkLockedObjectiveProperty>(0x2D26FB0);
	string m_LockedObjective;
	static inline auto s_ArkSpecialtiesProperty = PreyGlobal<ArkPlayableCharacter::ArkSpecialtiesProperty>(0x2D26F90);
	string m_Specialties;
	static inline auto s_ArkUnlockMethodProperty = PreyGlobal<ArkPlayableCharacter::ArkUnlockMethodProperty>(0x2D26FD0);
	string m_UnlockMethod;
	static inline auto s_ArkModelProperty = PreyGlobal<ArkPlayableCharacter::ArkModelProperty>(0x2D26FF0);
	string m_Model;
	static inline auto s_ArkArmsSkinProperty = PreyGlobal<ArkPlayableCharacter::ArkArmsSkinProperty>(0x2D27010);
	string m_ArmsSkin;
	static inline auto s_ArkLegsSkinProperty = PreyGlobal<ArkPlayableCharacter::ArkLegsSkinProperty>(0x2D27030);
	string m_LegsSkin;
	static inline auto s_ArkReadyRoomCharacterProperty = PreyGlobal<ArkPlayableCharacter::ArkReadyRoomCharacterProperty>(0x2D27050);
	ArkReadyRoomCharacterInfo m_ReadyRoomCharacter;
	static inline auto s_ArkReadyRoomHandPropProperty = PreyGlobal<ArkPlayableCharacter::ArkReadyRoomHandPropProperty>(0x2D27070);
	ArkReadyRoomPropInfo m_ReadyRoomHandProp;
	static inline auto s_ArkReadyRoomEnvironmentPropProperty = PreyGlobal<ArkPlayableCharacter::ArkReadyRoomEnvironmentPropProperty>(0x2D27090);
	ArkReadyRoomPropInfo m_ReadyRoomEnvironmentProp;
	static inline auto s_ArkStatModifierProperty = PreyGlobal<ArkPlayableCharacter::ArkStatModifierProperty>(0x2D270B0);
	uint64_t m_StatModifier;
	static inline auto s_ArkAbilityLayoutProperty = PreyGlobal<ArkPlayableCharacter::ArkAbilityLayoutProperty>(0x2D270D0);
	uint64_t m_AbilityLayout;
	static inline auto s_ArkStartsUnlockedProperty = PreyGlobal<ArkPlayableCharacter::ArkStartsUnlockedProperty>(0x2D27110);
	bool m_StartsUnlocked;
	static inline auto s_ArkSkeletonKeyProperty = PreyGlobal<ArkPlayableCharacter::ArkSkeletonKeyProperty>(0x2D27130);
	bool m_SkeletonKey;
	static inline auto s_ArkCorpseProperty = PreyGlobal<ArkPlayableCharacter::ArkCorpseProperty>(0x2D270F0);
	string m_Corpse;
	static inline auto s_ArkStartingAbilitiesProperty = PreyGlobal<ArkPlayableCharacter::ArkStartingAbilitiesProperty>(0x2D27150);
	std::vector<uint64_t> m_StartingAbilities;
	static inline auto s_ArkStartingItemsProperty = PreyGlobal<ArkPlayableCharacter::ArkStartingItemsProperty>(0x2D27170);
	std::vector<ArkStartingItem> m_StartingItems;
	static inline auto s_ArkSwitchStateProperty = PreyGlobal<ArkPlayableCharacter::ArkSwitchStateProperty>(0x2D27190);
	string m_SwitchState;
	static inline auto s_ArkInitialObjectiveDescriptionProperty = PreyGlobal<ArkPlayableCharacter::ArkInitialObjectiveDescriptionProperty>(0x2D271B0);
	string m_InitialObjectiveDescription;

	ArkPlayableCharacter();
	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetPortraitImage(string _arg0_);
	const string& GetPortraitImage() const;
	void SetClassLabel(string _arg0_);
	const string& GetClassLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetLockedDescription(string _arg0_);
	const string& GetLockedDescription() const;
	void SetLockedObjective(string _arg0_);
	const string& GetLockedObjective() const;
	void SetSpecialties(string _arg0_);
	const string& GetSpecialties() const;
	void SetUnlockMethod(string _arg0_);
	const string& GetUnlockMethod() const;
	void SetModel(string _arg0_);
	const string& GetModel() const;
	void SetArmsSkin(string _arg0_);
	const string& GetArmsSkin() const;
	void SetLegsSkin(string _arg0_);
	const string& GetLegsSkin() const;
	void SetReadyRoomCharacter(ArkReadyRoomCharacterInfo _arg0_);
	const ArkReadyRoomCharacterInfo& GetReadyRoomCharacter() const;
	void SetReadyRoomHandProp(ArkReadyRoomPropInfo _arg0_);
	const ArkReadyRoomPropInfo& GetReadyRoomHandProp() const;
	void SetReadyRoomEnvironmentProp(ArkReadyRoomPropInfo _arg0_);
	const ArkReadyRoomPropInfo& GetReadyRoomEnvironmentProp() const;
	void SetStatModifier(uint64_t _arg0_);
	const uint64_t& GetStatModifier() const;
	void SetAbilityLayout(uint64_t _arg0_);
	const uint64_t& GetAbilityLayout() const;
	void SetStartsUnlocked(bool _arg0_);
	const bool& GetStartsUnlocked() const;
	void SetSkeletonKey(bool _arg0_);
	const bool& GetSkeletonKey() const;
	void SetCorpse(string _arg0_);
	uint64_t GetCorpse() const;
	const string& GetCorpseString() const;
	std::vector<uint64_t>& GetStartingAbilities();
	const std::vector<uint64_t>& GetStartingAbilities() const;
	std::vector<ArkStartingItem>& GetStartingItems();
	const std::vector<ArkStartingItem>& GetStartingItems() const;
	void SetSwitchState(string _arg0_);
	const string& GetSwitchState() const;
	void SetInitialObjectiveDescription(string _arg0_);
	const string& GetInitialObjectiveDescription() const;
#endif

	static inline auto FArkPlayableCharacterOv2 = PreyFunction<void(ArkPlayableCharacter* const _this)>(0x10A1150);
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A1A30);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A1B30);
};

// ArkPlayableCharacterLibrary
// Header:  Prey/Ark/ArkPlayableCharacter.h
class ArkPlayableCharacterLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkPlayableCharacterLibrary::ArkPlayableCharactersProperty
	// Header:  Prey/Ark/ArkPlayableCharacter.h
	class ArkPlayableCharactersProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkPlayableCharactersProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkPlayableCharactersPropertyOv2 = PreyFunction<void(ArkPlayableCharacterLibrary::ArkPlayableCharactersProperty* const _this)>(0x10A1250);
		static inline auto FSetValue = PreyFunction<void(const ArkPlayableCharacterLibrary::ArkPlayableCharactersProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0570);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPlayableCharacterLibrary::ArkPlayableCharactersProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A05C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPlayableCharacterLibrary::ArkPlayableCharactersProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPlayableCharacterLibrary::ArkPlayableCharactersProperty* const _this, ArkReflectedObject* _pObject)>(0x10A0600);
	};

	static inline auto s_ArkPlayableCharactersProperty = PreyGlobal<ArkPlayableCharacterLibrary::ArkPlayableCharactersProperty>(0x2D271D0);
	std::vector<ArkPlayableCharacter> m_PlayableCharacters;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkPlayableCharacter* Find(const uint64_t _id) const { return FFind(this, _id); }
	uint64_t Lookup(const char* _name) const { return FLookup(this, _name); }
	virtual bool Init();

#if 0
	std::vector<ArkPlayableCharacter>& GetPlayableCharacters();
	const std::vector<ArkPlayableCharacter>& GetPlayableCharacters() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10A1A60);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10A1BD0);
	static inline auto FFind = PreyFunction<const ArkPlayableCharacter* (const ArkPlayableCharacterLibrary* const _this, const uint64_t _id)>(0x10A1B00);
	static inline auto FLookup = PreyFunction<uint64_t(const ArkPlayableCharacterLibrary* const _this, const char* _name)>(0x10A2110);
	static inline auto FInit = PreyFunction<bool(ArkPlayableCharacterLibrary* const _this)>(0x10A1F40);
};
#endif // MOONCRASH
