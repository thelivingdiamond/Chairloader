// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkPetSkin
// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
class ArkPetSkin : public ArkReflectedObject
{ // Size=72 (0x48)
public:
	// ArkPetSkin::ArkIDProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPetSkin::ArkNameProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPetSkin::ArkLabelProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPetSkin::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPetSkin::ArkIconProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPetSkin::ArkAbilityProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkAbilityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAbilityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkAbilityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkAbilityProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkPetSkin::ArkMaterialProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkMaterialProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaterialProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkMaterialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkMaterialProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkPetSkin::ArkParticleProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkParticleProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkParticleProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkParticleProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkParticleProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkPetSkin::ArkMeshAttachmentProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkMeshAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMeshAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkin::ArkMeshAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkin::ArkMeshAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkPetSkin::ArkIDProperty>(0x2D49AD0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkPetSkin::ArkNameProperty>(0x2D49AF0);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkPetSkin::ArkLabelProperty>(0x2D49B10);
	string m_Label;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPetSkin::ArkDescriptionProperty>(0x2D49B30);
	string m_Description;
	static inline auto s_ArkIconProperty = PreyGlobal<ArkPetSkin::ArkIconProperty>(0x2D49B50);
	string m_Icon;
	static inline auto s_ArkAbilityProperty = PreyGlobal<ArkPetSkin::ArkAbilityProperty>(0x2D49B70);
	uint64_t m_Ability;
	static inline auto s_ArkMaterialProperty = PreyGlobal<ArkPetSkin::ArkMaterialProperty>(0x2D49B90);
	string m_Material;
	static inline auto s_ArkParticleProperty = PreyGlobal<ArkPetSkin::ArkParticleProperty>(0x2D49BB0);
	string m_Particle;
	static inline auto s_ArkMeshAttachmentProperty = PreyGlobal<ArkPetSkin::ArkMeshAttachmentProperty>(0x2D49BD0);
	string m_MeshAttachment;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkPetSkin();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetIcon(string _arg0_);
	const string& GetIcon() const;
	void SetAbility(uint64_t _arg0_);
	const uint64_t& GetAbility() const;
	void SetMaterial(string _arg0_);
	const string& GetMaterial() const;
	void SetParticle(string _arg0_);
	const string& GetParticle() const;
	void SetMeshAttachment(string _arg0_);
	const string& GetMeshAttachment() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12C9570);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12C9650);
};

// ArkPetSkinLibrary
// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
class ArkPetSkinLibrary : public ArkReflectedLibrary
{ // Size=40 (0x28)
public:
	// ArkPetSkinLibrary::ArkPetSkinsProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkPetSkinsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkPetSkinsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkinLibrary::ArkPetSkinsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8BA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkinLibrary::ArkPetSkinsProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C8BE0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPetSkinLibrary::ArkPetSkinsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPetSkinLibrary::ArkPetSkinsProperty* const _this, ArkReflectedObject* _pObject)>(0x12C8C20);
	};

	// ArkPetSkinLibrary::ArkUnlockGameTokenProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkUnlockGameTokenProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUnlockGameTokenProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkinLibrary::ArkUnlockGameTokenProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkinLibrary::ArkUnlockGameTokenProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1FF0);
	};

	// ArkPetSkinLibrary::ArkVersionProperty
	// Header:  Prey/GameDll/ark/player/ArkPetSkin.h
	class ArkVersionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVersionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPetSkinLibrary::ArkVersionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPetSkinLibrary::ArkVersionProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C8CB0);
	};

	static inline auto s_ArkPetSkinsProperty = PreyGlobal<ArkPetSkinLibrary::ArkPetSkinsProperty>(0x2D49BF0);
	std::vector<ArkPetSkin> m_PetSkins;
	static inline auto s_ArkUnlockGameTokenProperty = PreyGlobal<ArkPetSkinLibrary::ArkUnlockGameTokenProperty>(0x2D49C10);
	int m_UnlockGameToken;
	static inline auto s_ArkVersionProperty = PreyGlobal<ArkPetSkinLibrary::ArkVersionProperty>(0x2D49C30);
	unsigned m_Version;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	bool IsAbilityWithSkins(uint64_t _abilityId) const { return FIsAbilityWithSkins(this, _abilityId); }
	std::vector<const ArkPetSkin*> GetSkinsForAbility(uint64_t _abilityId) const { alignas(std::vector<const ArkPetSkin*>) std::byte _return_buf_[sizeof(std::vector<const ArkPetSkin*>)]; return *FGetSkinsForAbility(this, reinterpret_cast<std::vector<const ArkPetSkin*>*>(_return_buf_), _abilityId); }
	const ArkPetSkin* FindPetSkin(uint64_t _id) const { return FFindPetSkin(this, _id); }

#if 0
	std::vector<ArkPetSkin>& GetPetSkins();
	const std::vector<ArkPetSkin>& GetPetSkins() const;
	void SetUnlockGameToken(int _arg0_);
	const int& GetUnlockGameToken() const;
	void SetVersion(unsigned _arg0_);
	const unsigned& GetVersion() const;
	ArkPetSkinLibrary();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12C95C0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x12C96F0);
	static inline auto FInit = PreyFunction<bool(ArkPetSkinLibrary* const _this)>(0x12C9850);
	static inline auto FIsAbilityWithSkins = PreyFunction<bool(const ArkPetSkinLibrary* const _this, uint64_t _abilityId)>(0x12C9A20);
	static inline auto FGetSkinsForAbility = PreyFunction<std::vector<const ArkPetSkin*>*(const ArkPetSkinLibrary* const _this, std::vector<const ArkPetSkin*>* _return_value_, uint64_t _abilityId)>(0x12C97E0);
	static inline auto FFindPetSkin = PreyFunction<const ArkPetSkin* (const ArkPetSkinLibrary* const _this, uint64_t _id)>(0x12C9620);
};
#endif // MOONCRASH
