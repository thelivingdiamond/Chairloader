// Header file automatically created from a PDB.

#pragma once

namespace ArkSignalSystem
{

// Header: Exact
// Prey/Ark/arksignalsystemdata.h
class Data // Id=801377A Size=96
{
public:
	template <typename T>
	class SortableData // Id=801377C Size=8
	{
	public:
		uint64_t m_id;

#if 0
		void SortableData();
		bool operator<(T const& arg0) const;
		uint64_t operator unsigned __int64() const;
		uint64_t GetId() const;
#endif
	};

	class SignalGroupData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::SignalGroupData> // Id=801377B Size=40
	{
	public:
		string m_name;
		std::vector<unsigned __int64> m_signals;
		
		bool HasSignal(const uint64_t _id) const { return FHasSignal(this,_id); }
		void LoadParamters(XmlNodeRef _node) { FLoadParamters(this,_node); }
		
#if 0
		string const &GetName() const;
		std::vector<unsigned __int64> const &GetSignals() const;
#endif
		
		static inline auto FHasSignal = PreyFunction<bool(ArkSignalSystem::Data::SignalGroupData const *const _this, const uint64_t _id)>(0x13FA450);
		static inline auto FLoadParamters = PreyFunction<void(ArkSignalSystem::Data::SignalGroupData *const _this, XmlNodeRef _node)>(0x15DA250);
	};

	class PackageData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::PackageData> // Id=801377D Size=40
	{
	public:
		class SignalValueData // Id=80136C4 Size=16
		{
		public:
			uint64_t m_signalId;
			float m_value;
			
#if 0
			uint64_t GetSignalId() const;
			float GetValue() const;
#endif
		};

		std::vector<ArkSignalSystem::Data::PackageData::SignalValueData> m_values;
		string m_name;
		
#if 0
		string const &GetName() const;
		std::vector<ArkSignalSystem::Data::PackageData::SignalValueData> const &GetValues() const;
#endif
	};

	class SignalData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::SignalData> // Id=801377F Size=16
	{
	public:
		string m_name;
		
#if 0
		string const &GetName() const;
#endif
	};

	class ModifierData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::ModifierData> // Id=8013781 Size=40
	{
	public:
		class RuleData // Id=8013783 Size=72
		{
		public:
			class FactorData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::ModifierData::RuleData::FactorData> // Id=80136AC Size=16
			{
			public:
				float m_factor;
				
#if 0
				float GetFactor() const;
#endif
			};

			std::vector<unsigned __int64> m_signalFilter;
			std::vector<unsigned __int64> m_groupFilter;
			std::vector<ArkSignalSystem::Data::ModifierData::RuleData::FactorData> m_factors;
			
			RuleData(XmlNodeRef _root);
			
#if 0
			std::vector<unsigned __int64> const &GetGroupFilter() const;
			bool IsMatchingSignal(const uint64_t arg0) const;
			ArkSignalSystem::Data::ModifierData::RuleData::FactorData const *FindFactor(const uint64_t arg0) const;
			std::vector<ArkSignalSystem::Data::ModifierData::RuleData::FactorData> const &GetFactorData() const;
#endif
		};

		string m_name;
		std::vector<ArkSignalSystem::Data::ModifierData::RuleData> m_rules;
		
#if 0
		std::vector<ArkSignalSystem::Data::ModifierData::RuleData> const &GetRules() const;
		string const &GetName() const;
#endif
	};

	std::vector<ArkSignalSystem::Data::PackageData> m_packages;
	std::vector<ArkSignalSystem::Data::SignalData> m_signals;
	std::vector<ArkSignalSystem::Data::ModifierData> m_modifiers;
	std::vector<ArkSignalSystem::Data::SignalGroupData> m_signalGroups;
	
	void Scan() { FScan(this); }
	ArkSignalSystem::Data::ModifierData const *FindModifier(const uint64_t _id) const { return FFindModifier(this,_id); }
	ArkSignalSystem::Data::PackageData const *FindPackage(const uint64_t _id) const { return FFindPackage(this,_id); }
	
#if 0
	ArkSignalSystem::Data::SignalData const *FindSignal(const uint64_t arg0) const;
	ArkSignalSystem::Data::SignalGroupData const *FindSignalGroup(const uint64_t arg0) const;
	std::vector<ArkSignalSystem::Data::PackageData> const &GetPackageItems() const;
	std::vector<ArkSignalSystem::Data::SignalData> const &GetSignalItems() const;
	std::vector<ArkSignalSystem::Data::ModifierData> const &GetModifierItems() const;
	std::vector<ArkSignalSystem::Data::SignalGroupData> const &GetSignalGroupItems() const;
	const char *GetPackageName(const char *const arg0) const;
	const char *GetSignalName(const char *const arg0) const;
	const char *GetModifierName(const char *const arg0) const;
	const char *GetSignalGroupName(const char *const arg0) const;
	string GetPackageIdAsString(const char *const arg0) const;
	uint64_t GetPackageId(const char *const arg0) const;
	string GetSignalIdAsString(const char *const arg0) const;
	string GetModifierIdAsString(const char *const arg0) const;
	string GetSignalGroupIdAsString(const char *const arg0) const;
#endif
	
	static inline auto FScan = PreyFunction<void(ArkSignalSystem::Data *const _this)>(0x15DAEF0);
	static inline auto FFindModifier = PreyFunction<ArkSignalSystem::Data::ModifierData const *(ArkSignalSystem::Data const *const _this, const uint64_t _id)>(0x15D9D70);
	static inline auto FFindPackage = PreyFunction<ArkSignalSystem::Data::PackageData const *(ArkSignalSystem::Data const *const _this, const uint64_t _id)>(0x15D9E00);
};

} // namespace ArkSignalSystem

