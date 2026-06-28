// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNpcSpawner.h>

class ArkNpc;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct SEntityEvent;
class SmartScriptTable;

// CArkHumanRandomSpawner
// Header:  Prey/GameDll/ark/npc/ArkHumanRandomSpawner.h
class CArkHumanRandomSpawner : public CArkNpcSpawner
{ // Size=152 (0x98)
public:
	enum class Gender : uint8_t
	{
		female = 0,
		male = 1,
		_count = 2,
	};

	enum class Job : uint8_t
	{
		mechanic = 0,
		scientist = 1,
		security = 2,
		_count = 3,
	};

	// CArkHumanRandomSpawner::HumanDefinition
	// Header:  Prey/GameDll/ark/npc/ArkHumanRandomSpawner.h
	struct HumanDefinition
	{ // Size=4 (0x4)
		CArkHumanRandomSpawner::Gender m_gender;
		CArkHumanRandomSpawner::Job m_job;
		uint8_t m_headIndex;
		uint8_t m_hairIndex;

	#if 0
		HumanDefinition();
	#endif
	};

	using SkinMaterialPair = std::pair<const char*, const char*>;

	CArkHumanRandomSpawner::HumanDefinition m_definition;
	std::vector<unsigned int> m_spawnedEntityIds;

	CArkHumanRandomSpawner();
	virtual ~CArkHumanRandomSpawner();
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void Release();
	virtual IEntityArchetype* GetEntityArchetype() const;
	virtual void InitializeNpc(ArkNpc& _npc);
	virtual void SetupSpawnedNpcCharacter();
	void InitializeEntity(IEntity& _entity) const { FInitializeEntity(this, _entity); }
	CArkHumanRandomSpawner::HumanDefinition GenerateRandomHumanDefinition() const { alignas(CArkHumanRandomSpawner::HumanDefinition) std::byte _return_buf_[sizeof(CArkHumanRandomSpawner::HumanDefinition)]; return *FGenerateRandomHumanDefinition(this, reinterpret_cast<CArkHumanRandomSpawner::HumanDefinition*>(_return_buf_)); }
	std::pair<const char*, const char*> GetBodySkin() const { alignas(std::pair<const char*, const char*>) std::byte _return_buf_[sizeof(std::pair<const char*, const char*>)]; return *FGetBodySkin(this, reinterpret_cast<std::pair<const char*, const char*>*>(_return_buf_)); }
	std::pair<const char*, const char*> GetHeadSkin() const { alignas(std::pair<const char*, const char*>) std::byte _return_buf_[sizeof(std::pair<const char*, const char*>)]; return *FGetHeadSkin(this, reinterpret_cast<std::pair<const char*, const char*>*>(_return_buf_)); }
	std::pair<const char*, const char*> GetHairSkin() const { alignas(std::pair<const char*, const char*>) std::byte _return_buf_[sizeof(std::pair<const char*, const char*>)]; return *FGetHairSkin(this, reinterpret_cast<std::pair<const char*, const char*>*>(_return_buf_)); }

#if 0
	CArkHumanRandomSpawner::Gender GenerateRandomGender() const;
	CArkHumanRandomSpawner::Job GenerateRandomJob() const;
	uint8_t GenerateRandomHead(SmartScriptTable _arg0_) const;
	uint8_t GenerateRandomHair(const SmartScriptTable _arg0_, const uint8_t _arg1_) const;
#endif

	static inline auto FCArkHumanRandomSpawner = PreyFunction<void(CArkHumanRandomSpawner* const _this)>(0x127F210);
	static inline auto FProcessEvent = PreyFunction<void(CArkHumanRandomSpawner* const _this, SEntityEvent& _event)>(0x12806C0);
	static inline auto FFullSerialize = PreyFunction<void(CArkHumanRandomSpawner* const _this, TSerialize _ser)>(0x127F790);
	static inline auto FPostSerialize = PreyFunction<void(CArkHumanRandomSpawner* const _this)>(0x1280530);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkHumanRandomSpawner* const _this, ICrySizer* _pSizer)>(0xCF0B20);
	static inline auto FRelease = PreyFunction<void(CArkHumanRandomSpawner* const _this)>(0x3E3960);
	static inline auto FGetEntityArchetype = PreyFunction<IEntityArchetype* (const CArkHumanRandomSpawner* const _this)>(0x127FE40);
	static inline auto FInitializeNpc = PreyFunction<void(CArkHumanRandomSpawner* const _this, ArkNpc& _npc)>(0x12804E0);
	static inline auto FSetupSpawnedNpcCharacter = PreyFunction<void(CArkHumanRandomSpawner* const _this)>(0x1280730);
	static inline auto FInitializeEntity = PreyFunction<void(const CArkHumanRandomSpawner* const _this, IEntity& _entity)>(0x12803C0);
	static inline auto FGenerateRandomHumanDefinition = PreyFunction<CArkHumanRandomSpawner::HumanDefinition*(const CArkHumanRandomSpawner* const _this, CArkHumanRandomSpawner::HumanDefinition* _return_value_)>(0x127F930);
	static inline auto FGetBodySkin = PreyFunction<std::pair<const char*, const char*>*(const CArkHumanRandomSpawner* const _this, std::pair<const char*, const char*>* _return_value_)>(0x127FCA0);
	static inline auto FGetHeadSkin = PreyFunction<std::pair<const char*, const char*>*(const CArkHumanRandomSpawner* const _this, std::pair<const char*, const char*>* _return_value_)>(0x1280140);
	static inline auto FGetHairSkin = PreyFunction<std::pair<const char*, const char*>*(const CArkHumanRandomSpawner* const _this, std::pair<const char*, const char*>* _return_value_)>(0x127FE80);
};
#endif // MOONCRASH
