// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/AISignal.h>
#include <Prey/CryAISystem/IAgent.h>
#include <Prey/CryNetwork/ISerialize.h>

class SmartScriptTable;
class IAISignalExtraData;

// Header: FromCpp
// CryEngine/cryaisystem/AISIGNAL.h
struct AISIGNAL // Id=8000FB0 Size=80
{
	int nSignal;
	unsigned m_nCrcText;
	unsigned senderID;
	IAISignalExtraData *pEData;
	static constexpr const int SIGNAL_STRING_LENGTH = 50;
	char strText[50];
	
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	
#if 0
	bool Compare(unsigned arg0) const;
#endif
	
	static inline auto FSerialize = PreyFunction<void(AISIGNAL *const _this, TSerialize ser)>(0x6BF660);
};

#if 0
// Header: Exact
// CryEngine/cryaisystem/aisignal.h
struct AISignalExtraData : public IAISignalExtraData // Id=800A9F5 Size=80
{
	char *sObjectName;
	
	using SignalExtraDataAlloc = stl::PoolAllocator<80,stl::PSyncNone,0>;
	
	static stl::PoolAllocator<80,stl::PSyncNone,0> m_signalExtraDataAlloc;
	
	static void CleanupPool() { FCleanupPool(); }
	AISignalExtraData();
	AISignalExtraData(AISignalExtraData const &other);
	virtual ~AISignalExtraData();
	virtual void Serialize(TSerialize ser);
	virtual const char *GetObjectName() const;
	virtual void SetObjectName(const char *objectName);
	virtual void ToScriptTable(SmartScriptTable &table) const;
	virtual void FromScriptTable(SmartScriptTable const &table);

	static void *operator new(uint64_t arg0);
	static void operator delete(void *arg0);
	
	static inline auto FCleanupPool = PreyFunction<void()>(0x6BF250);
	static inline auto FSerialize = PreyFunction<void(AISignalExtraData *const _this, TSerialize ser)>(0x6BF8B0);
	static inline auto FGetObjectName = PreyFunction<const char *(AISignalExtraData const *const _this)>(0x6BF640);
	static inline auto FSetObjectName = PreyFunction<void(AISignalExtraData *const _this, const char *objectName)>(0x6BFD90);
	static inline auto FToScriptTable = PreyFunction<void(AISignalExtraData const *const _this, SmartScriptTable &table)>(0x6BFE00);
	static inline auto FFromScriptTable = PreyFunction<void(AISignalExtraData *const _this, SmartScriptTable const &table)>(0x6BF2C0);
};

#endif