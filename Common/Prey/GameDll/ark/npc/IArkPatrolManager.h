// Header file automatically created from a PDB.
#pragma once

// IArkPatrolManager
// Header:  _unknown/IArkPatrolManager.h
class IArkPatrolManager
{ // Size=8 (0x8)
public:
	virtual unsigned GetPatrolIndex(const char* const _pName) const = 0;
	virtual unsigned GetPatrolIndex(const uint64_t& _id) const = 0;
	virtual const string& GetPatrolName(unsigned _patrolIndex) const = 0;
	virtual uint64_t GetPatrolId(unsigned _patrolIndex) const = 0;
	virtual const std::unordered_map<string, unsigned int>& GetNameMap() const = 0;
	virtual const std::unordered_map<uint64_t, unsigned int>& GetIdMap() const = 0;
	virtual void LoadFromFile(const char* _pLevelName) = 0;
};

