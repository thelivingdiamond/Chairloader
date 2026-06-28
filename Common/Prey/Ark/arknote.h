// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>

class ArkClass;
class ArkNote;
class ArkReflectedObject;

// Header: Exact
// Prey/Ark/arknote.h
class ArkNotes : public ArkReflectedLibrary // Id=8016B2A Size=32
{
public:
	class ArkNotesProperty : public ArkProperty // Id=8016B2B Size=32
	{
	public:
		ArkNotesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkNotes::ArkNotesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1078890);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkNotes::ArkNotesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10789D0);
		static inline auto FIsArray = PreyFunction<bool(ArkNotes::ArkNotesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkNotes::ArkNotesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1078A10);
	};

	static ArkNotes::ArkNotesProperty s_ArkNotesProperty;
	std::vector<ArkNote> m_Notes;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkNotes();
	
#if 0
	std::vector<ArkNote> &GetNotes();
	std::vector<ArkNote> const &GetNotes() const;
	ArkNote const *FindNote(const uint64_t arg0) const;
	ArkNote const *FindNote(const char *arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1079490);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1079590);
	static inline auto FInit = PreyFunction<bool(ArkNotes *const _this)>(0x1079680);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkNote
// Header:  Prey/Ark/ArkNote.h
class ArkNote : public ArkReflectedObject
{ // Size=80 (0x50)
public:
	// ArkNote::ArkIDProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkNote::ArkNameProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkNote::ArkPlotCriticalProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkPlotCriticalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlotCriticalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkPlotCriticalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkPlotCriticalProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkNote::ArkSubjectProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkSubjectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSubjectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkSubjectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkSubjectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkNote::ArkContentProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkContentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkContentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkContentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkContentProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkNote::ArkKeyCodeProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkKeyCodeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkKeyCodeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkKeyCodeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkKeyCodeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkNote::ArkLocationProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkLocationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLocationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkNote::ArkPasswordProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkPasswordProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPasswordProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10AD1F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkPasswordProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	// ArkNote::ArkImageNameProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkImageNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkImageNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkImageNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8B40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkImageNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x119D010);
	};

	// ArkNote::ArkResetWithCharacterChangeProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkResetWithCharacterChangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkResetWithCharacterChangeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkNote::ArkResetWithCharacterChangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x109EE80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNote::ArkResetWithCharacterChangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EE90);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkNote::ArkIDProperty>(0x2D26A90);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkNote::ArkNameProperty>(0x2D26AB0);
	string m_Name;
	static inline auto s_ArkPlotCriticalProperty = PreyGlobal<ArkNote::ArkPlotCriticalProperty>(0x2D26AD0);
	bool m_PlotCritical;
	static inline auto s_ArkSubjectProperty = PreyGlobal<ArkNote::ArkSubjectProperty>(0x2D26AF0);
	string m_Subject;
	static inline auto s_ArkContentProperty = PreyGlobal<ArkNote::ArkContentProperty>(0x2D26B10);
	string m_Content;
	static inline auto s_ArkKeyCodeProperty = PreyGlobal<ArkNote::ArkKeyCodeProperty>(0x2D26B30);
	uint64_t m_KeyCode;
	static inline auto s_ArkLocationProperty = PreyGlobal<ArkNote::ArkLocationProperty>(0x2D26B50);
	uint64_t m_Location;
	static inline auto s_ArkPasswordProperty = PreyGlobal<ArkNote::ArkPasswordProperty>(0x2D26B70);
	uint64_t m_Password;
	static inline auto s_ArkImageNameProperty = PreyGlobal<ArkNote::ArkImageNameProperty>(0x2D26B90);
	string m_ImageName;
	static inline auto s_ArkResetWithCharacterChangeProperty = PreyGlobal<ArkNote::ArkResetWithCharacterChangeProperty>(0x2D26BB0);
	bool m_ResetWithCharacterChange;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkNote();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetPlotCritical(bool _arg0_);
	const bool& GetPlotCritical() const;
	void SetSubject(string _arg0_);
	const string& GetSubject() const;
	void SetContent(string _arg0_);
	const string& GetContent() const;
	void SetKeyCode(uint64_t _arg0_);
	const uint64_t& GetKeyCode() const;
	void SetLocation(uint64_t _arg0_);
	const uint64_t& GetLocation() const;
	void SetPassword(uint64_t _arg0_);
	const uint64_t& GetPassword() const;
	void SetImageName(string _arg0_);
	const string& GetImageName() const;
	void SetResetWithCharacterChange(bool _arg0_);
	const bool& GetResetWithCharacterChange() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109FA70);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109FB20);
};

// ArkNotes
// Header:  Prey/Ark/ArkNote.h
class ArkNotes : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkNotes::ArkNotesProperty
	// Header:  Prey/Ark/ArkNote.h
	class ArkNotesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkNotesProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkNotesPropertyOv2 = PreyFunction<void(ArkNotes::ArkNotesProperty* const _this)>(0x109F6F0);
		static inline auto FSetValue = PreyFunction<void(const ArkNotes::ArkNotesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x109EEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkNotes::ArkNotesProperty* const _this, ArkReflectedObject* const _pObject)>(0x109EFE0);
		static inline auto FIsArray = PreyFunction<bool(const ArkNotes::ArkNotesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkNotes::ArkNotesProperty* const _this, ArkReflectedObject* _pObject)>(0x109F020);
	};

	static inline auto s_ArkNotesProperty = PreyGlobal<ArkNotes::ArkNotesProperty>(0x2D26BD0);
	std::vector<ArkNote> m_Notes;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkNote>& GetNotes();
	const std::vector<ArkNote>& GetNotes() const;
	const ArkNote* FindNote(const uint64_t _arg0_) const;
	const ArkNote* FindNote(const char* _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109FAC0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109FBC0);
	static inline auto FInit = PreyFunction<bool(ArkNotes* const _this)>(0x109FCB0);
};
#endif // !MOONCRASH
