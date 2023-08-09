// Header file automatically created from a PDB.

#pragma once
#include "ChairLoader/PreyFunction.h"

namespace Serialization
{
struct ICallback;
class IContainer;
class IKeyValue;
class IPointer;
class IString;
class IWString;
struct SBlackBox;
struct SContextLink;
struct SStruct;
class TypeID;
} // namespace Serialization

namespace Serialization
{

// Header: Exact
// CryEngine/crycommon/serialization/IArchive.h
class IArchive // Id=8000F86 Size=24
{
public:
	enum ArchiveCaps
	{
		INPUT = 1,
		OUTPUT = 2,
		TEXT = 4,
		BINARY = 8,
		EDIT = 16,
		INPLACE = 32,
		NO_EMPTY_NAMES = 64,
		VALIDATION = 128,
		DOCUMENTATION = 256,
	};

	int caps_;
	int filter_;
	Serialization::SContextLink *innerContext_;
	
	virtual ~IArchive();
	virtual void InPlacePointer(void **pointer, uint64_t offset);
	virtual bool operator()(bool &value, const char *name, const char *label);
	virtual bool operator()(char &value, const char *name, const char *label);
	virtual bool operator()(uint8_t &value, const char *name, const char *label);
	virtual bool operator()(int8_t &value, const char *name, const char *label);
	virtual bool operator()(int16_t &value, const char *name, const char *label);
	virtual bool operator()(uint16_t &value, const char *name, const char *label);
	virtual bool operator()(int &value, const char *name, const char *label);
	virtual bool operator()(unsigned &value, const char *name, const char *label);
	virtual bool operator()(int64_t &value, const char *name, const char *label);
	virtual bool operator()(uint64_t &value, const char *name, const char *label);
	virtual bool operator()(float &value, const char *name, const char *label);
	virtual bool operator()(double &value, const char *name, const char *label);
	virtual bool operator()(Serialization::IString &value, const char *name, const char *label);
	virtual bool operator()(Serialization::IWString &value, const char *name, const char *label);
	virtual bool operator()(Serialization::SStruct const &ser, const char *name, const char *label);
	virtual bool operator()(Serialization::IContainer &ser, const char *name, const char *label);
	virtual bool operator()(Serialization::IPointer &ptr, const char *name, const char *label);
	virtual bool operator()(Serialization::IKeyValue &keyValue, const char *name, const char *label);
	virtual bool operator()(Serialization::SBlackBox const &blackBox, const char *name, const char *label);
	virtual bool operator()(Serialization::ICallback &callback, const char *name, const char *label);
	virtual bool OpenBlock(const char *name, const char *label);
	virtual void CloseBlock();
	virtual void ValidatorMessage(bool error, const void *handle, Serialization::TypeID const &type, const char *message);
	virtual void DocumentLastField(const char *text);
	
#if 0
	bool IsInput() const;
	bool IsOutput() const;
	bool IsEdit() const;
	bool IsInPlace() const;
	bool GetCaps(int arg0) const;
	void SetFilter(int arg0);
	int GetFilter() const;
	bool Filter(int arg0) const;
	void Error(const void *arg0, Serialization::TypeID const &arg1, const char *arg2, ... arg3);
	void Doc(const char *arg0);
	void *FindContextByType(Serialization::TypeID const &arg0) const;
	Serialization::SContextLink *SetInnerContext(Serialization::SContextLink *arg0);
	Serialization::SContextLink *GetInnerContext() const;
	void notImplemented();
#endif
	
	static inline auto FInPlacePointer = PreyFunction<void(Serialization::IArchive *const _this, void **pointer, uint64_t offset)>(0xA13080);
	static inline auto FoperatorRBLRBROv19 = PreyFunction<bool(Serialization::IArchive *const _this, bool &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv18 = PreyFunction<bool(Serialization::IArchive *const _this, char &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv17 = PreyFunction<bool(Serialization::IArchive *const _this, uint8_t &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv16 = PreyFunction<bool(Serialization::IArchive *const _this, int8_t &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv15 = PreyFunction<bool(Serialization::IArchive *const _this, int16_t &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv14 = PreyFunction<bool(Serialization::IArchive *const _this, uint16_t &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv13 = PreyFunction<bool(Serialization::IArchive *const _this, int &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv12 = PreyFunction<bool(Serialization::IArchive *const _this, unsigned &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv11 = PreyFunction<bool(Serialization::IArchive *const _this, int64_t &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv10 = PreyFunction<bool(Serialization::IArchive *const _this, uint64_t &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv9 = PreyFunction<bool(Serialization::IArchive *const _this, float &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv8 = PreyFunction<bool(Serialization::IArchive *const _this, double &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv7 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::IString &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv6 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::IWString &value, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv5 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::SStruct const &ser, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv4 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::IContainer &ser, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv3 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::IPointer &ptr, const char *name, const char *label)>(0xD92070);
	static inline auto FoperatorRBLRBROv2 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::IKeyValue &keyValue, const char *name, const char *label)>(0xD91EE0);
	static inline auto FoperatorRBLRBROv1 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::SBlackBox const &blackBox, const char *name, const char *label)>(0xDD23F0);
	static inline auto FoperatorRBLRBROv0 = PreyFunction<bool(Serialization::IArchive *const _this, Serialization::ICallback &callback, const char *name, const char *label)>(0xDD23F0);
	static inline auto FOpenBlock = PreyFunction<bool(Serialization::IArchive *const _this, const char *name, const char *label)>(0x1B933B0);
	static inline auto FCloseBlock = PreyFunction<void(Serialization::IArchive *const _this)>(0xA13080);
	static inline auto FValidatorMessage = PreyFunction<void(Serialization::IArchive *const _this, bool error, const void *handle, Serialization::TypeID const &type, const char *message)>(0xA13080);
	static inline auto FDocumentLastField = PreyFunction<void(Serialization::IArchive *const _this, const char *text)>(0xA13080);
};

} // namespace Serialization

