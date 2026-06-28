// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAISystem/IAgent.h>
#include <Prey/CryNetwork/ISerialize.h>

class SmartScriptTable;

// AISIGNAL
// Header:  CryEngine/cryaisystem/AISIGNAL.h
// Include: Prey/CryAISystem/IAgent.h
struct AISIGNAL
{ // Size=80 (0x50)
	int nSignal;
	unsigned m_nCrcText;
	unsigned senderID;
	IAISignalExtraData* pEData;
	static constexpr const int SIGNAL_STRING_LENGTH = 50;
	char strText[50];

	void Serialize(TSerialize ser) { FSerialize(this, ser); }

#if 0
	bool Compare(unsigned _arg0_) const;
	AISIGNAL();
#endif

	static inline auto FSerialize = PreyFunction<void(AISIGNAL* const _this, TSerialize ser)>(0x6DB440);
};

// AISignalExtraData
// Header:  CryEngine/cryaisystem/AISIGNAL.h
// Include: Prey/CryAISystem/AISignal.h
struct AISignalExtraData : public IAISignalExtraData
{ // Size=80 (0x50)
	using SignalExtraDataAlloc = stl::PoolAllocator<80,stl::PSyncNone,0>;

	char* sObjectName;
	static inline auto m_signalExtraDataAlloc = PreyGlobal<stl::PoolAllocator<80,stl::PSyncNone,0>>(0x261A060);

	static void CleanupPool() { FCleanupPool(); }
	AISignalExtraData();
	AISignalExtraData(const AISignalExtraData& other);
	virtual ~AISignalExtraData();
	virtual void Serialize(TSerialize ser);
	virtual const char* GetObjectName() const;
	virtual void SetObjectName(const char* objectName);
	virtual void ToScriptTable(SmartScriptTable& table) const;
	virtual void FromScriptTable(const SmartScriptTable& table);

#if 0
	AISignalExtraData& operator=(const AISignalExtraData& _arg0_);
	static void* operator new(uint64_t _arg0_);
	static void operator delete(void* _arg0_);
#endif

	static inline auto FCleanupPool = PreyFunction<void()>(0x6DB030);
	static inline auto FAISignalExtraDataOv1 = PreyFunction<void(AISignalExtraData* const _this)>(0x6DAED0);
	static inline auto FAISignalExtraDataOv0 = PreyFunction<void(AISignalExtraData* const _this, const AISignalExtraData& other)>(0x6E3D50);
	static inline auto FSerialize = PreyFunction<void(AISignalExtraData* const _this, TSerialize ser)>(0x6DB690);
	static inline auto FGetObjectName = PreyFunction<const char* (const AISignalExtraData* const _this)>(0x6DB420);
	static inline auto FSetObjectName = PreyFunction<void(AISignalExtraData* const _this, const char* objectName)>(0x6DBB70);
	static inline auto FToScriptTable = PreyFunction<void(const AISignalExtraData* const _this, SmartScriptTable& table)>(0x6DBBE0);
	static inline auto FFromScriptTable = PreyFunction<void(AISignalExtraData* const _this, const SmartScriptTable& table)>(0x6DB0A0);
};
#endif // !MOONCRASH
