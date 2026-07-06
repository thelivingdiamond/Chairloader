// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/iface/IArkFactionManager.h
class IArkFactionManager // Id=800208A Size=8
{
public:
	virtual unsigned GetFactionIndex(const char *const arg0) const = 0;
	virtual unsigned GetFactionIndex(const uint64_t &arg0) const = 0;
	virtual string const &GetFactionName(unsigned arg0) const = 0;
	virtual string const &GetFactionName(uint64_t arg0) const = 0;
	virtual uint64_t GetFactionId(const char *const arg0) const = 0;
	virtual uint64_t GetFactionId(unsigned arg0) const = 0;
	virtual unsigned GetEntityFaction(unsigned arg0) const = 0;
	virtual void SetEntityDispositionToEntity(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3) = 0;
	virtual void SetFactionDispositionToEntity(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3) = 0;
	virtual void SetFactionDispositionToFaction(unsigned arg0, unsigned arg1, EArkDisposition arg2, bool arg3) = 0;
	virtual EArkDisposition GetEffectiveFactionDispositionToEntity(unsigned arg0, unsigned arg1) const = 0;
	virtual EArkDisposition GetEffectiveEntityDispositionToEntity(unsigned arg0, unsigned arg1) const = 0;
	virtual void ReloadFactions() = 0;
	virtual std::unordered_map<unsigned __int64,unsigned int> const &GetGuidMap() const = 0;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

enum class EArkDisposition;

// IArkFactionManager
// Header:  Prey/GameDll/ark/iface/IArkFactionManager.h
class IArkFactionManager
{ // Size=8 (0x8)
public:
	virtual unsigned GetFactionIndex(const char* const _pFactionName) const = 0;
	virtual unsigned GetFactionIndex(const uint64_t& _factionGuid) const = 0;
	virtual const string& GetFactionName(unsigned _factionIndex) const = 0;
	virtual const string& GetFactionName(uint64_t _factionId) const = 0;
	virtual uint64_t GetFactionId(const char* const _pFactionName) const = 0;
	virtual uint64_t GetFactionId(unsigned _factionIndex) const = 0;
	virtual unsigned GetEntityFaction(unsigned _entityId) const = 0;
	virtual void SetEntityDispositionToEntity(unsigned _arg0_, unsigned _arg1_, EArkDisposition _arg2_, bool _arg3_) = 0;
	virtual void SetFactionDispositionToEntity(unsigned _arg0_, unsigned _arg1_, EArkDisposition _arg2_, bool _arg3_) = 0;
	virtual void SetFactionDispositionToFaction(unsigned _arg0_, unsigned _arg1_, EArkDisposition _arg2_, bool _arg3_) = 0;
	virtual EArkDisposition GetEffectiveFactionDispositionToEntity(unsigned _fromFactionIndex, unsigned _toEntityId) const = 0;
	virtual EArkDisposition GetEffectiveEntityDispositionToEntity(unsigned _fromEntityId, unsigned _toEntityId) const = 0;
	virtual void ReloadFactions() = 0;
	virtual const std::unordered_map<uint64_t, unsigned int>& GetGuidMap() const = 0;

#if 0
	IArkFactionManager();
	~IArkFactionManager();
#endif
};
#endif // !MOONCRASH
