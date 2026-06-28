// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

struct ICVar;

// ArkRandomValueManager
// Header:  Prey/GameDll/ark/ArkRandomValueManager.h
class ArkRandomValueManager
{ // Size=136 (0x88)
public:
	std::unordered_map<uint64_t, std::vector<int>> m_shuffledValues;
	std::unordered_map<uint64_t, int> m_values;
	bool m_bSeedLocked;
	int m_seed;
	static inline auto m_pOverrideProfileCvar = PreyGlobal<ICVar*>(0x2D3FC58);

	static int GenerateValue(const uint64_t _id, const int _max) { return FGenerateValueOv1(_id, _max); }
	int GenerateValue(const int _seed, const uint64_t _id, const int _max) const { return FGenerateValueOv0(this, _seed, _id, _max); }
	static void RegisterCVars() { FRegisterCVars(); }
	int GenerateDesignerLibValues(int _seed) { return FGenerateDesignerLibValues(this, _seed); }
	int GetDesignerLibValue(const uint64_t _id) const { return FGetDesignerLibValue(this, _id); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	int GetShuffledValueFromList(uint64_t _listId, int _index, bool& _bOutOfBounds) const { return FGetShuffledValueFromList(this, _listId, _index, _bOutOfBounds); }
	void LoadDesignerLibOverrideProfile(const char* const _name) { FLoadDesignerLibOverrideProfile(this, _name); }
	void OverrideValue(const uint64_t _id, const int _value, const int _min, const int _max, const char* const _name) { FOverrideValue(this, _id, _value, _min, _max, _name); }
	void OverrideShuffledList(const uint64_t _listId, const std::vector<int>& _newValues) { FOverrideShuffledList(this, _listId, _newValues); }
	void ShuffleLists(int _seed) { FShuffleLists(this, _seed); }

#if 0
	ArkRandomValueManager();
	void SetSeedLocked(const bool _arg0_);
	bool IsSeedLocked() const;
	int GetSeed() const;
	void SaveDesignerLibOverrideProfile(const char* const _arg0_);
	void OverrideDesignerLibValue(const uint64_t _arg0_, const int _arg1_);
	void OverrideDoorValues(const uint64_t _arg0_, const int _arg1_, const int _arg2_);
	int GenerateSeed() const;
#endif

	static inline auto FGenerateValueOv1 = PreyFunction<int(const uint64_t _id, const int _max)>(0x1228BA0);
	static inline auto FGenerateValueOv0 = PreyFunction<int(const ArkRandomValueManager* const _this, const int _seed, const uint64_t _id, const int _max)>(0x12289D0);
	static inline auto FRegisterCVars = PreyFunction<void()>(0x1229630);
	static inline auto FGenerateDesignerLibValues = PreyFunction<int(ArkRandomValueManager* const _this, int _seed)>(0x12286D0);
	static inline auto FGetDesignerLibValue = PreyFunction<int(const ArkRandomValueManager* const _this, const uint64_t _id)>(0x1228BE0);
	static inline auto FReset = PreyFunction<void(ArkRandomValueManager* const _this)>(0x12297F0);
	static inline auto FSerialize = PreyFunction<void(ArkRandomValueManager* const _this, TSerialize _ser)>(0x1229870);
	static inline auto FGetShuffledValueFromList = PreyFunction<int(const ArkRandomValueManager* const _this, uint64_t _listId, int _index, bool& _bOutOfBounds)>(0x1228D00);
	static inline auto FLoadDesignerLibOverrideProfile = PreyFunction<void(ArkRandomValueManager* const _this, const char* const _name)>(0x1228E80);
	static inline auto FOverrideValue = PreyFunction<void(ArkRandomValueManager* const _this, const uint64_t _id, const int _value, const int _min, const int _max, const char* const _name)>(0x1229580);
	static inline auto FOverrideShuffledList = PreyFunction<void(ArkRandomValueManager* const _this, const uint64_t _listId, const std::vector<int>& _newValues)>(0x12293C0);
	static inline auto FShuffleLists = PreyFunction<void(ArkRandomValueManager* const _this, int _seed)>(0x1229910);
};
#endif // MOONCRASH
