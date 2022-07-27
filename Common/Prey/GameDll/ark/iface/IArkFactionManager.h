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

