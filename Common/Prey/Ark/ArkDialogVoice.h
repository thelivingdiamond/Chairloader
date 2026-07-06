// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkDialogVoice.h
class ArkDialogVoice : public ArkReflectedObject // Id=8013A45 Size=80
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013A46 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkDialogVoice::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013A47 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkDialogVoice::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkDescriptionProperty : public ArkProperty // Id=8013A48 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkDialogVoice::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkAbstractProperty : public ArkProperty // Id=8013A49 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkAbstractProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10821A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkAbstractProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkDialogVoice::ArkAbstractProperty s_ArkAbstractProperty;
	bool m_Abstract;
	
	class ArkFaceFXProperty : public ArkProperty // Id=8013A4A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkFaceFXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1061640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkFaceFXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1061650);
	};

	static ArkDialogVoice::ArkFaceFXProperty s_ArkFaceFXProperty;
	bool m_FaceFX;
	
	class ArkSexProperty : public ArkProperty // Id=8013A4B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkSexProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkSexProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkDialogVoice::ArkSexProperty s_ArkSexProperty;
	string m_Sex;
	
	class ArkEffectProperty : public ArkProperty // Id=8013A4C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkDialogVoice::ArkEffectProperty s_ArkEffectProperty;
	string m_Effect;
	
	class ArkVoicesProperty : public ArkProperty // Id=8013A4D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoice::ArkVoicesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105FB00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoice::ArkVoicesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105FBB0);
		static inline auto FIsArray = PreyFunction<bool(ArkDialogVoice::ArkVoicesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkDialogVoice::ArkVoicesProperty const *const _this, ArkReflectedObject *_pObject)>(0x105FBD0);
	};

	static ArkDialogVoice::ArkVoicesProperty s_ArkVoicesProperty;
	std::vector<ArkDialogVoice> m_Voices;
	ArkDialogVoice const *m_pParent;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetAbstract(bool arg0);
	const bool &GetAbstract() const;
	void SetFaceFX(bool arg0);
	const bool &GetFaceFX() const;
	void SetSex(string arg0);
	string const &GetSex() const;
	void SetEffect(string arg0);
	string const &GetEffect() const;
	std::vector<ArkDialogVoice> &GetVoices();
	std::vector<ArkDialogVoice> const &GetVoices() const;
	ArkDialogVoice const *GetParent() const;
	void SetParent(ArkDialogVoice const *const arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10609C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1060BC0);
};

// Header: Exact
// Prey/Ark/arkdialogvoice.h
class ArkDialogVoices : public ArkReflectedLibrary // Id=8013A60 Size=96
{
public:
	class ArkVoicesProperty : public ArkProperty // Id=8013A61 Size=32
	{
	public:
		ArkVoicesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkDialogVoices::ArkVoicesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105F990);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkDialogVoices::ArkVoicesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105FA50);
		static inline auto FIsArray = PreyFunction<bool(ArkDialogVoices::ArkVoicesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkDialogVoices::ArkVoicesProperty const *const _this, ArkReflectedObject *_pObject)>(0x105FA90);
	};

	static ArkDialogVoices::ArkVoicesProperty s_ArkVoicesProperty;
	std::vector<ArkDialogVoice> m_Voices;
	std::unordered_map<unsigned __int64,ArkDialogVoice *> m_voiceMap;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkDialogVoice const *Find(const uint64_t _id) const { return FFindOv1(this,_id); }
	virtual ~ArkDialogVoices();
	
#if 0
	std::vector<ArkDialogVoice> &GetVoices();
	std::vector<ArkDialogVoice> const &GetVoices() const;
	ArkDialogVoice const *Find(string const &arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1060A10);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1060C60);
	static inline auto FInit = PreyFunction<bool(ArkDialogVoices *const _this)>(0x1060D50);
	static inline auto FFindOv1 = PreyFunction<ArkDialogVoice const *(ArkDialogVoices const *const _this, const uint64_t _id)>(0x1060AC0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkDialogVoice
// Header:  Prey/Ark/ArkDialogVoice.h
class ArkDialogVoice : public ArkReflectedObject
{ // Size=80 (0x50)
public:
	// ArkDialogVoice::ArkIDProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDialogVoice::ArkNameProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkDialogVoice::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkDialogVoice::ArkAbstractProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkAbstractProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAbstractProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkAbstractProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkAbstractProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkDialogVoice::ArkFaceFXProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkFaceFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFaceFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkFaceFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7BE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkFaceFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x10827A0);
	};

	// ArkDialogVoice::ArkAudioProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkAudioProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAudioProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkAudioProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10827B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkAudioProperty* const _this, ArkReflectedObject* const _pObject)>(0x10827C0);
	};

	// ArkDialogVoice::ArkSexProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkSexProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSexProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkSexProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkSexProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkDialogVoice::ArkEffectProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkDialogVoice::ArkVoicesProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkVoicesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkVoicesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoice::ArkVoicesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10827D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoice::ArkVoicesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082880);
		static inline auto FIsArray = PreyFunction<bool(const ArkDialogVoice::ArkVoicesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDialogVoice::ArkVoicesProperty* const _this, ArkReflectedObject* _pObject)>(0x10828A0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkDialogVoice::ArkIDProperty>(0x2D22AE0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkDialogVoice::ArkNameProperty>(0x2D22B00);
	string m_Name;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkDialogVoice::ArkDescriptionProperty>(0x2D22B20);
	string m_Description;
	static inline auto s_ArkAbstractProperty = PreyGlobal<ArkDialogVoice::ArkAbstractProperty>(0x2D22B40);
	bool m_Abstract;
	static inline auto s_ArkFaceFXProperty = PreyGlobal<ArkDialogVoice::ArkFaceFXProperty>(0x2D22B60);
	bool m_FaceFX;
	static inline auto s_ArkAudioProperty = PreyGlobal<ArkDialogVoice::ArkAudioProperty>(0x2D22B80);
	bool m_Audio;
	static inline auto s_ArkSexProperty = PreyGlobal<ArkDialogVoice::ArkSexProperty>(0x2D22BA0);
	string m_Sex;
	static inline auto s_ArkEffectProperty = PreyGlobal<ArkDialogVoice::ArkEffectProperty>(0x2D22BC0);
	string m_Effect;
	static inline auto s_ArkVoicesProperty = PreyGlobal<ArkDialogVoice::ArkVoicesProperty>(0x2D22BE0);
	std::vector<ArkDialogVoice> m_Voices;
	const ArkDialogVoice* m_pParent;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkDialogVoice();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetAbstract(bool _arg0_);
	const bool& GetAbstract() const;
	void SetFaceFX(bool _arg0_);
	const bool& GetFaceFX() const;
	void SetAudio(bool _arg0_);
	const bool& GetAudio() const;
	void SetSex(string _arg0_);
	const string& GetSex() const;
	void SetEffect(string _arg0_);
	const string& GetEffect() const;
	std::vector<ArkDialogVoice>& GetVoices();
	const std::vector<ArkDialogVoice>& GetVoices() const;
	const ArkDialogVoice* GetParent() const;
	void SetParent(const ArkDialogVoice* const _arg0_);
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1083820);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1083A30);
};

// ArkDialogVoices
// Header:  Prey/Ark/ArkDialogVoice.h
class ArkDialogVoices : public ArkReflectedLibrary
{ // Size=96 (0x60)
public:
	// ArkDialogVoices::ArkVoicesProperty
	// Header:  Prey/Ark/ArkDialogVoice.h
	class ArkVoicesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkVoicesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkVoicesPropertyOv2 = PreyFunction<void(ArkDialogVoices::ArkVoicesProperty* const _this)>(0x10832B0);
		static inline auto FSetValue = PreyFunction<void(const ArkDialogVoices::ArkVoicesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1082900);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDialogVoices::ArkVoicesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10829C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkDialogVoices::ArkVoicesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkDialogVoices::ArkVoicesProperty* const _this, ArkReflectedObject* _pObject)>(0x1082A00);
	};

	static inline auto s_ArkVoicesProperty = PreyGlobal<ArkDialogVoices::ArkVoicesProperty>(0x2D22C00);
	std::vector<ArkDialogVoice> m_Voices;
	std::unordered_map<uint64_t, ArkDialogVoice*> m_voiceMap;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkDialogVoice* Find(const uint64_t _id) const { return FFindOv1(this, _id); }

#if 0
	std::vector<ArkDialogVoice>& GetVoices();
	const std::vector<ArkDialogVoice>& GetVoices() const;
	const ArkDialogVoice* Find(const string& _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1083880);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1083AD0);
	static inline auto FInit = PreyFunction<bool(ArkDialogVoices* const _this)>(0x1083BC0);
	static inline auto FFindOv1 = PreyFunction<const ArkDialogVoice* (const ArkDialogVoices* const _this, const uint64_t _id)>(0x1083930);
};
#endif // !MOONCRASH
