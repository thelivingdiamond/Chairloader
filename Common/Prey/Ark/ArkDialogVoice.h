// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkdialogvoice.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

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

