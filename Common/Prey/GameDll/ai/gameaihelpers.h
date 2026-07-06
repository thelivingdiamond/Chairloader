// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <_unknown/IGameAIModule.h>
#include <_unknown/InstanceInitContext.h>

namespace HazardSystem
{
struct HazardModuleInstance;
} // namespace HazardSystem
struct InstanceID;
class RadioChatterInstance;
class RangeContainer;
struct StalkerInstance;

// AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>
// Header:  Prey/GameDll/ai/gameaihelpers.h
class AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8> : public IGameAIModule
{ // Size=56 (0x38)
public:
	using BaseClass = AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>;
	using InstanceType = HazardSystem::HazardModuleInstance;
	using Instances = std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >;
	using FreeInstances = std::deque<InstanceID,std::allocator<InstanceID> >;
	using InstancePool = std::vector<char>;

	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_running;
	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_paused;
	std::unique_ptr<std::deque<InstanceID, std::allocator<InstanceID>>> m_free;
	std::vector<char> m_pool;

	virtual void EntityEnter(unsigned entityID);
	virtual void EntityLeave(unsigned entityID);
	virtual void EntityPause(unsigned entityID);
	virtual void EntityResume(unsigned entityID);
	virtual void Reset(bool bUnload);
	InstanceID AllocateInstance(unsigned entityID, HazardSystem::HazardModuleInstance* * instanceOut) { alignas(InstanceID) std::byte _return_buf_[sizeof(InstanceID)]; return *FAllocateInstance(this, reinterpret_cast<InstanceID*>(_return_buf_), entityID, instanceOut); }
	void DeallocateInstance(InstanceID instanceID) { FDeallocateInstance(this, instanceID); }
	virtual void InitializeInstance(const InstanceInitContext<HazardSystem::HazardModuleInstance>& context);
	virtual void DeinitializeInstance(InstanceID instanceID);
	void EntityLeaveFrom(std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID) { FEntityLeaveFrom(this, instances, entityID); }
	void LeaveAllInstances() { FLeaveAllInstances(this); }

#if 0
	AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>();
	AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>(const AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>& _arg0_);
	HazardSystem::HazardModuleInstance* GetRunningInstance(unsigned _arg0_);
	HazardSystem::HazardModuleInstance* GetInstanceFromID(InstanceID _arg0_);
	AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>& operator=(const AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>& _arg0_);
#endif

	static inline auto FEntityEnter = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, unsigned entityID)>(0x10C8F90);
	static inline auto FEntityLeave = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, unsigned entityID)>(0x10C90A0);
	static inline auto FEntityPause = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, unsigned entityID)>(0x10C6740);
	static inline auto FEntityResume = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, unsigned entityID)>(0x10C91E0);
	static inline auto FReset = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, bool bUnload)>(0x10C98A0);
	static inline auto FAllocateInstance = PreyFunction<InstanceID*(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, InstanceID* _return_value_, unsigned entityID, HazardSystem::HazardModuleInstance* * instanceOut)>(0x10C8C60);
	static inline auto FDeallocateInstance = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, InstanceID instanceID)>(0x10C8E90);
	static inline auto FInitializeInstance = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, const InstanceInitContext<HazardSystem::HazardModuleInstance>& context)>(0x10C68E0);
	static inline auto FDeinitializeInstance = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, InstanceID instanceID)>(0x1333E90);
	static inline auto FEntityLeaveFrom = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this, std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID)>(0x10C90E0);
	static inline auto FLeaveAllInstances = PreyFunction<void(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>* const _this)>(0x10C92D0);
};

// AIModule<RadioChatterModule,RadioChatterInstance,12,1>
// Header:  Prey/GameDll/ai/gameaihelpers.h
class AIModule<RadioChatterModule,RadioChatterInstance,12,1> : public IGameAIModule
{ // Size=56 (0x38)
public:
	using BaseClass = AIModule<RadioChatterModule,RadioChatterInstance,12,1>;
	using InstanceType = RadioChatterInstance;
	using Instances = std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >;
	using FreeInstances = std::deque<InstanceID,std::allocator<InstanceID> >;
	using InstancePool = std::vector<char>;

	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_running;
	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_paused;
	std::unique_ptr<std::deque<InstanceID, std::allocator<InstanceID>>> m_free;
	std::vector<char> m_pool;

	virtual void EntityEnter(unsigned entityID);
	virtual void EntityLeave(unsigned entityID);
	virtual void EntityPause(unsigned entityID);
	virtual void EntityResume(unsigned entityID);
	virtual void Reset(bool bUnload);
	InstanceID AllocateInstance(unsigned entityID, RadioChatterInstance* * instanceOut) { alignas(InstanceID) std::byte _return_buf_[sizeof(InstanceID)]; return *FAllocateInstance(this, reinterpret_cast<InstanceID*>(_return_buf_), entityID, instanceOut); }
	virtual void InitializeInstance(const InstanceInitContext<RadioChatterInstance>& context);
	virtual void DeinitializeInstance(InstanceID instanceID);
	void EntityLeaveFrom(std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID) { FEntityLeaveFrom(this, instances, entityID); }
	void LeaveAllInstances() { FLeaveAllInstances(this); }

#if 0
	AIModule<RadioChatterModule,RadioChatterInstance,12,1>();
	AIModule<RadioChatterModule,RadioChatterInstance,12,1>(const AIModule<RadioChatterModule,RadioChatterInstance,12,1>& _arg0_);
	RadioChatterInstance* GetRunningInstance(unsigned _arg0_);
	RadioChatterInstance* GetInstanceFromID(InstanceID _arg0_);
	AIModule<RadioChatterModule,RadioChatterInstance,12,1>& operator=(const AIModule<RadioChatterModule,RadioChatterInstance,12,1>& _arg0_);
	void DeallocateInstance(InstanceID _arg0_);
#endif

	static inline auto FEntityEnter = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, unsigned entityID)>(0x10C5FE0);
	static inline auto FEntityLeave = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, unsigned entityID)>(0x10C6310);
	static inline auto FEntityPause = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, unsigned entityID)>(0x10C6740);
	static inline auto FEntityResume = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, unsigned entityID)>(0x10C91E0);
	static inline auto FReset = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, bool bUnload)>(0x10C7060);
	static inline auto FAllocateInstance = PreyFunction<InstanceID*(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, InstanceID* _return_value_, unsigned entityID, RadioChatterInstance* * instanceOut)>(0x10C5820);
	static inline auto FInitializeInstance = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, const InstanceInitContext<RadioChatterInstance>& context)>(0x10C68E0);
	static inline auto FDeinitializeInstance = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, InstanceID instanceID)>(0x1333E90);
	static inline auto FEntityLeaveFrom = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this, std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID)>(0x10C63D0);
	static inline auto FLeaveAllInstances = PreyFunction<void(AIModule<RadioChatterModule,RadioChatterInstance,12,1>* const _this)>(0x10C6970);
};

// AIModule<RangeModule,RangeContainer,16,8>
// Header:  Prey/GameDll/ai/gameaihelpers.h
class AIModule<RangeModule,RangeContainer,16,8> : public IGameAIModule
{ // Size=56 (0x38)
public:
	using BaseClass = AIModule<RangeModule,RangeContainer,16,8>;
	using InstanceType = RangeContainer;
	using Instances = std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >;
	using FreeInstances = std::deque<InstanceID,std::allocator<InstanceID> >;
	using InstancePool = std::vector<char>;

	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_running;
	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_paused;
	std::unique_ptr<std::deque<InstanceID, std::allocator<InstanceID>>> m_free;
	std::vector<char> m_pool;

	virtual void EntityEnter(unsigned entityID);
	virtual void EntityLeave(unsigned entityID);
	virtual void EntityPause(unsigned entityID);
	virtual void EntityResume(unsigned entityID);
	virtual void Reset(bool bUnload);
	RangeContainer* GetRunningInstance(unsigned entityID) { return FGetRunningInstance(this, entityID); }
	InstanceID AllocateInstance(unsigned entityID, RangeContainer* * instanceOut) { alignas(InstanceID) std::byte _return_buf_[sizeof(InstanceID)]; return *FAllocateInstance(this, reinterpret_cast<InstanceID*>(_return_buf_), entityID, instanceOut); }
	virtual void InitializeInstance(const InstanceInitContext<RangeContainer>& context);
	virtual void DeinitializeInstance(InstanceID instanceID);
	void EntityLeaveFrom(std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID) { FEntityLeaveFrom(this, instances, entityID); }
	void LeaveAllInstances() { FLeaveAllInstances(this); }

#if 0
	AIModule<RangeModule,RangeContainer,16,8>();
	AIModule<RangeModule,RangeContainer,16,8>(const AIModule<RangeModule,RangeContainer,16,8>& _arg0_);
	RangeContainer* GetInstanceFromID(InstanceID _arg0_);
	AIModule<RangeModule,RangeContainer,16,8>& operator=(const AIModule<RangeModule,RangeContainer,16,8>& _arg0_);
	void DeallocateInstance(InstanceID _arg0_);
#endif

	static inline auto FEntityEnter = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, unsigned entityID)>(0x10C60F0);
	static inline auto FEntityLeave = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, unsigned entityID)>(0x10C6350);
	static inline auto FEntityPause = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, unsigned entityID)>(0x10C6740);
	static inline auto FEntityResume = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, unsigned entityID)>(0x10C91E0);
	static inline auto FReset = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, bool bUnload)>(0x10C71B0);
	static inline auto FGetRunningInstance = PreyFunction<RangeContainer* (AIModule<RangeModule,RangeContainer,16,8>* const _this, unsigned entityID)>(0x10CD820);
	static inline auto FAllocateInstance = PreyFunction<InstanceID*(AIModule<RangeModule,RangeContainer,16,8>* const _this, InstanceID* _return_value_, unsigned entityID, RangeContainer* * instanceOut)>(0x10C5A50);
	static inline auto FInitializeInstance = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, const InstanceInitContext<RangeContainer>& context)>(0x10C6910);
	static inline auto FDeinitializeInstance = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, InstanceID instanceID)>(0x1333E90);
	static inline auto FEntityLeaveFrom = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this, std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID)>(0x10C64F0);
	static inline auto FLeaveAllInstances = PreyFunction<void(AIModule<RangeModule,RangeContainer,16,8>* const _this)>(0x10C6B00);
};

// AIModuleWithInstanceUpdate<RangeModule,RangeContainer,16,8>
// Header:  Prey/GameDll/ai/gameaihelpers.h
class AIModuleWithInstanceUpdate<RangeModule,RangeContainer,16,8> : public AIModule<RangeModule,RangeContainer,16,8>
{ // Size=56 (0x38)
public:
	using BaseClass = AIModule<RangeModule,RangeContainer,16,8>;
	using Instances = std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >;

	virtual void UpdateInstance(RangeContainer& instance, float frameTime);
	virtual void Update(float frameTime);

	static inline auto FUpdateInstance = PreyFunction<void(AIModuleWithInstanceUpdate<RangeModule,RangeContainer,16,8>* const _this, RangeContainer& instance, float frameTime)>(0x10C78A0);
	static inline auto FUpdate = PreyFunction<void(AIModuleWithInstanceUpdate<RangeModule,RangeContainer,16,8>* const _this, float frameTime)>(0x10C76E0);
};

// AIModule<StalkerModule,StalkerInstance,4,4>
// Header:  Prey/GameDll/ai/gameaihelpers.h
class AIModule<StalkerModule,StalkerInstance,4,4> : public IGameAIModule
{ // Size=56 (0x38)
public:
	using BaseClass = AIModule<StalkerModule,StalkerInstance,4,4>;
	using InstanceType = StalkerInstance;
	using Instances = std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >;
	using FreeInstances = std::deque<InstanceID,std::allocator<InstanceID> >;
	using InstancePool = std::vector<char>;

	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_running;
	std::unique_ptr<std::unordered_map<unsigned int, InstanceID, stl::hash_uint32, std::equal_to<unsigned int>, std::allocator<std::pair<const unsigned int, InstanceID>>>> m_paused;
	std::unique_ptr<std::deque<InstanceID, std::allocator<InstanceID>>> m_free;
	std::vector<char> m_pool;

	virtual void EntityEnter(unsigned entityID);
	virtual void EntityLeave(unsigned entityID);
	virtual void EntityPause(unsigned entityID);
	virtual void EntityResume(unsigned entityID);
	virtual void Reset(bool bUnload);
	InstanceID AllocateInstance(unsigned entityID, StalkerInstance* * instanceOut) { alignas(InstanceID) std::byte _return_buf_[sizeof(InstanceID)]; return *FAllocateInstance(this, reinterpret_cast<InstanceID*>(_return_buf_), entityID, instanceOut); }
	virtual void InitializeInstance(const InstanceInitContext<StalkerInstance>& context);
	virtual void DeinitializeInstance(InstanceID instanceID);
	void EntityLeaveFrom(std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID) { FEntityLeaveFrom(this, instances, entityID); }
	void LeaveAllInstances() { FLeaveAllInstances(this); }

#if 0
	AIModule<StalkerModule,StalkerInstance,4,4>();
	AIModule<StalkerModule,StalkerInstance,4,4>(const AIModule<StalkerModule,StalkerInstance,4,4>& _arg0_);
	StalkerInstance* GetRunningInstance(unsigned _arg0_);
	StalkerInstance* GetInstanceFromID(InstanceID _arg0_);
	AIModule<StalkerModule,StalkerInstance,4,4>& operator=(const AIModule<StalkerModule,StalkerInstance,4,4>& _arg0_);
	void DeallocateInstance(InstanceID _arg0_);
#endif

	static inline auto FEntityEnter = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, unsigned entityID)>(0x10C6200);
	static inline auto FEntityLeave = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, unsigned entityID)>(0x10C6390);
	static inline auto FEntityPause = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, unsigned entityID)>(0x10C6740);
	static inline auto FEntityResume = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, unsigned entityID)>(0x10C91E0);
	static inline auto FReset = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, bool bUnload)>(0x10C7300);
	static inline auto FAllocateInstance = PreyFunction<InstanceID*(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, InstanceID* _return_value_, unsigned entityID, StalkerInstance* * instanceOut)>(0x10C5CC0);
	static inline auto FInitializeInstance = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, const InstanceInitContext<StalkerInstance>& context)>(0x10C6940);
	static inline auto FDeinitializeInstance = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, InstanceID instanceID)>(0x1333E90);
	static inline auto FEntityLeaveFrom = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this, std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >& instances, unsigned entityID)>(0x10C6620);
	static inline auto FLeaveAllInstances = PreyFunction<void(AIModule<StalkerModule,StalkerInstance,4,4>* const _this)>(0x10C6CB0);
};

// AIModuleWithInstanceUpdate<StalkerModule,StalkerInstance,4,4>
// Header:  Prey/GameDll/ai/gameaihelpers.h
class AIModuleWithInstanceUpdate<StalkerModule,StalkerInstance,4,4> : public AIModule<StalkerModule,StalkerInstance,4,4>
{ // Size=56 (0x38)
public:
	using BaseClass = AIModule<StalkerModule,StalkerInstance,4,4>;
	using Instances = std::unordered_map<unsigned int,InstanceID,stl::hash_uint32,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,InstanceID> > >;

	virtual void UpdateInstance(StalkerInstance& _arg0_, float _arg1_);
	virtual void Update(float frameTime);

	static inline auto FUpdate = PreyFunction<void(AIModuleWithInstanceUpdate<StalkerModule,StalkerInstance,4,4>* const _this, float frameTime)>(0x10C7760);
};
#endif // MOONCRASH
