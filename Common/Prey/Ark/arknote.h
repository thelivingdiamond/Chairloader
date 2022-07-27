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

