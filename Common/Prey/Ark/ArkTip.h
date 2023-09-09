// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkTip.h
class ArkTip : public ArkReflectedObject // Id=8016918 Size=64
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016919 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTip::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTip::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkTip::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=801691A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTip::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTip::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkTip::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkContentProperty : public ArkProperty // Id=801691B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTip::ArkContentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTip::ArkContentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkTip::ArkContentProperty s_ArkContentProperty;
	string m_Content;
	
	class ArkLocksProperty : public ArkProperty // Id=801691C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTip::ArkLocksProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107FE10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTip::ArkLocksProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107FE30);
		static inline auto FIsArray = PreyFunction<bool(ArkTip::ArkLocksProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTip::ArkLocksProperty const *const _this, ArkReflectedObject *_pObject)>(0x107FE50);
	};

	static ArkTip::ArkLocksProperty s_ArkLocksProperty;
	std::vector<unsigned __int64> m_Locks;
	
	class ArkSequenceProperty : public ArkProperty // Id=801691D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTip::ArkSequenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105B9D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTip::ArkSequenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkTip::ArkSequenceProperty s_ArkSequenceProperty;
	uint64_t m_Sequence;
	
	class ArkHideOnDeathScreenProperty : public ArkProperty // Id=801691E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTip::ArkHideOnDeathScreenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107FE60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTip::ArkHideOnDeathScreenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkTip::ArkHideOnDeathScreenProperty s_ArkHideOnDeathScreenProperty;
	bool m_HideOnDeathScreen;
	unsigned m_sequenceIdx;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetContent(string arg0);
	string const &GetContent() const;
	std::vector<unsigned __int64> &GetLocks();
	std::vector<unsigned __int64> const &GetLocks() const;
	void SetSequence(uint64_t arg0);
	const uint64_t &GetSequence() const;
	void SetHideOnDeathScreen(bool arg0);
	const bool &GetHideOnDeathScreen() const;
	unsigned GetSequenceIndex() const;
	void SetSequenceIndex(unsigned arg0);
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1081180);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1081280);
};

// Header: Exact
// Prey/Ark/arktip.h
class ArkTipLock : public ArkReflectedObject // Id=8016C64 Size=16
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016C65 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTipLock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTipLock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkTipLock::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016C66 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTipLock::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTipLock::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkTipLock::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1081250);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1081410);
};

// Header: Exact
// Prey/Ark/arktip.h
class ArkTipSequence : public ArkReflectedObject // Id=8016C67 Size=16
{
public:
	class ArkIDProperty : public ArkProperty // Id=8016C68 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTipSequence::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTipSequence::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkTipSequence::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8016C69 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTipSequence::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTipSequence::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkTipSequence::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1081250);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10814B0);
};

// Header: Exact
// Prey/Ark/arktip.h
class ArkTipLibrary : public ArkReflectedLibrary // Id=8016C77 Size=80
{
public:
	class ArkTipsProperty : public ArkProperty // Id=8016C78 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTipLibrary::ArkTipsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107FE70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTipLibrary::ArkTipsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x107FF50);
		static inline auto FIsArray = PreyFunction<bool(ArkTipLibrary::ArkTipsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTipLibrary::ArkTipsProperty const *const _this, ArkReflectedObject *_pObject)>(0x107FF90);
	};

	static ArkTipLibrary::ArkTipsProperty s_ArkTipsProperty;
	std::vector<ArkTip> m_Tips;
	
	class ArkLocksProperty : public ArkProperty // Id=8016C79 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTipLibrary::ArkLocksProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107FFD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTipLibrary::ArkLocksProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1080040);
		static inline auto FIsArray = PreyFunction<bool(ArkTipLibrary::ArkLocksProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTipLibrary::ArkLocksProperty const *const _this, ArkReflectedObject *_pObject)>(0x105ACD0);
	};

	static ArkTipLibrary::ArkLocksProperty s_ArkLocksProperty;
	std::vector<ArkTipLock> m_Locks;
	
	class ArkSequencesProperty : public ArkProperty // Id=8016C87 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkTipLibrary::ArkSequencesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1080080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkTipLibrary::ArkSequencesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10800F0);
		static inline auto FIsArray = PreyFunction<bool(ArkTipLibrary::ArkSequencesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkTipLibrary::ArkSequencesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1080130);
	};

	static ArkTipLibrary::ArkSequencesProperty s_ArkSequencesProperty;
	std::vector<ArkTipSequence> m_Sequences;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkTipLibrary();
	
#if 0
	std::vector<ArkTip> &GetTips();
	std::vector<ArkTip> const &GetTips() const;
	std::vector<ArkTipLock> &GetLocks();
	std::vector<ArkTipLock> const &GetLocks() const;
	std::vector<ArkTipSequence> &GetSequences();
	std::vector<ArkTipSequence> const &GetSequences() const;
	ArkTip const *FindTip(const uint64_t arg0) const;
	ArkTipLock const *FindLock(const uint64_t arg0) const;
	ArkTipSequence const *FindSequence(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10811D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1081320);
	static inline auto FInit = PreyFunction<bool(ArkTipLibrary *const _this)>(0x1081550);
};

