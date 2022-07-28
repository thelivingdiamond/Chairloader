// Header file automatically created from a PDB.

#pragma once

class ICrySizer;
namespace SharedString
{
class CNameTable;
struct SNameEntry;
} // namespace SharedString

namespace SharedString
{

// Header: Exact
// Prey/GameDll/itemstring.h
class CSharedString // Id=8013D16 Size=8
{
public:
	const char *m_str;
	
	SharedString::CSharedString &operator=(SharedString::CSharedString const &n) { return FoperatorEqOv1(this,n); }
	SharedString::CSharedString &operator=(const char *s) { return FoperatorEqOv0(this,s); }
	void reset() { Freset(this); }
	void clear() { Fclear(this); }
	static SharedString::CNameTable *GetNameTable() { return FGetNameTable(); }
	
#if 0
	bool operator bool();
	bool operator bool() const;
	bool operator!();
	bool operator!() const;
	bool operator==(SharedString::CSharedString const &arg0) const;
	bool operator==(const char *arg0) const;
	bool operator!=(SharedString::CSharedString const &arg0) const;
	bool operator!=(const char *arg0) const;
	bool operator<(SharedString::CSharedString const &arg0) const;
	bool operator>(SharedString::CSharedString const &arg0) const;
	bool empty() const;
	const char *c_str() const;
	int length() const;
	static bool find(const char *arg0);
	static void DumpNameTable();
	void GetMemoryUsage(ICrySizer *arg0) const;
	int operator int();
	int operator int() const;
	SharedString::SNameEntry *_entry(const char *arg0) const;
	int _length() const;
	void _addref(const char *arg0);
	void _release(const char *arg0);
#endif
	
	static inline auto FoperatorEqOv1 = PreyFunction<SharedString::CSharedString &(SharedString::CSharedString *const _this, SharedString::CSharedString const &n)>(0x17609F0);
	static inline auto FoperatorEqOv0 = PreyFunction<SharedString::CSharedString &(SharedString::CSharedString *const _this, const char *s)>(0x169D060);
	static inline auto Freset = PreyFunction<void(SharedString::CSharedString *const _this)>(0x17634C0);
	static inline auto Fclear = PreyFunction<void(SharedString::CSharedString *const _this)>(0x17634C0);
	static inline auto FGetNameTable = PreyFunction<SharedString::CNameTable *()>(0x11CFF40);
};

} // namespace SharedString

