// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <_unknown/ArkSignalSystem__Data__SortableData.h>

class XmlNodeRef;

namespace ArkSignalSystem
{

// ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::SignalGroupData>
// Header:  Prey/Ark/arksignalsystemdata.h
class SortableData<ArkSignalSystem::Data::SignalGroupData>
{ // Size=8 (0x8)
public:
	uint64_t m_id;

#if 0
	SortableData<ArkSignalSystem::Data::SignalGroupData>();
	bool operator<(const ArkSignalSystem::Data::SignalGroupData& _arg0_) const;
	uint64_t operator unsigned __int64() const;
	uint64_t GetId() const;
#endif
};

// ArkSignalSystem::Data
// Header:  Prey/Ark/arksignalsystemdata.h
class Data
{ // Size=120 (0x78)
public:
	// ArkSignalSystem::Data::SignalGroupData
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SignalGroupData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::SignalGroupData>
	{ // Size=40 (0x28)
	public:
		string m_name;
		std::vector<uint64_t> m_signals;

		bool HasSignal(const uint64_t _id) const { return FHasSignal(this, _id); }
		void LoadParamters(const XmlNodeRef _node) { FLoadParamters(this, _node); }

	#if 0
		SignalGroupData();
		SignalGroupData(const XmlNodeRef _arg0_);
		const string& GetName() const;
		const std::vector<uint64_t>& GetSignals() const;
	#endif

		static inline auto FHasSignal = PreyFunction<bool(const ArkSignalSystem::Data::SignalGroupData* const _this, const uint64_t _id)>(0x150C620);
		static inline auto FLoadParamters = PreyFunction<void(ArkSignalSystem::Data::SignalGroupData* const _this, const XmlNodeRef _node)>(0x1702370);
	};

	// ArkSignalSystem::Data::SortableData<class ArkSignalSystem::Data::SignalGroupData>
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SortableData<class ArkSignalSystem::Data::SignalGroupData>
	{ // Size=8 (0x8)
	public:
		uint64_t m_id;

	#if 0
		void SortableData<ArkSignalSystem::Data::SignalGroupData>();
		bool operator<(const ArkSignalSystem::Data::SignalGroupData& _arg0_) const;
		uint64_t operator unsigned __int64() const;
		uint64_t GetId() const;
	#endif
	};

	// ArkSignalSystem::Data::PackageData
	// Header:  Prey/Ark/arksignalsystemdata.h
	class PackageData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::PackageData>
	{ // Size=40 (0x28)
	public:
		// ArkSignalSystem::Data::PackageData::SignalValueData
		// Header:  Prey/Ark/arksignalsystemdata.h
		class SignalValueData
		{ // Size=16 (0x10)
		public:
			uint64_t m_signalId;
			float m_value;

		#if 0
			SignalValueData(const XmlNodeRef _arg0_);
			uint64_t GetSignalId() const;
			float GetValue() const;
		#endif
		};

		std::vector<ArkSignalSystem::Data::PackageData::SignalValueData> m_values;
		string m_name;

	#if 0
		PackageData(const XmlNodeRef _arg0_);
		const string& GetName() const;
		const std::vector<ArkSignalSystem::Data::PackageData::SignalValueData>& GetValues() const;
	#endif
	};

	// ArkSignalSystem::Data::SortableData<class ArkSignalSystem::Data::PackageData>
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SortableData<class ArkSignalSystem::Data::PackageData>
	{ // Size=8 (0x8)
	public:
		uint64_t m_id;

	#if 0
		void SortableData<ArkSignalSystem::Data::PackageData>();
		bool operator<(const ArkSignalSystem::Data::PackageData& _arg0_) const;
		uint64_t operator unsigned __int64() const;
		uint64_t GetId() const;
	#endif
	};

	// ArkSignalSystem::Data::SignalData
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SignalData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::SignalData>
	{ // Size=16 (0x10)
	public:
		string m_name;

	#if 0
		SignalData(const XmlNodeRef _arg0_);
		const string& GetName() const;
	#endif
	};

	// ArkSignalSystem::Data::SortableData<class ArkSignalSystem::Data::SignalData>
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SortableData<class ArkSignalSystem::Data::SignalData>
	{ // Size=8 (0x8)
	public:
		uint64_t m_id;

	#if 0
		void SortableData<ArkSignalSystem::Data::SignalData>();
		bool operator<(const ArkSignalSystem::Data::SignalData& _arg0_) const;
		uint64_t operator unsigned __int64() const;
		uint64_t GetId() const;
	#endif
	};

	// ArkSignalSystem::Data::ModifierData
	// Header:  Prey/Ark/arksignalsystemdata.h
	class ModifierData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::ModifierData>
	{ // Size=40 (0x28)
	public:
		// ArkSignalSystem::Data::ModifierData::RuleData
		// Header:  Prey/Ark/arksignalsystemdata.h
		class RuleData
		{ // Size=72 (0x48)
		public:
			// ArkSignalSystem::Data::ModifierData::RuleData::FactorData
			// Header:  Prey/Ark/arksignalsystemdata.h
			class FactorData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::ModifierData::RuleData::FactorData>
			{ // Size=16 (0x10)
			public:
				float m_factor;
				bool m_bIsAdditive;

			#if 0
				FactorData(const XmlNodeRef _arg0_);
				float GetFactor() const;
				bool IsAdditive() const;
			#endif
			};

			std::vector<uint64_t> m_signalFilter;
			std::vector<uint64_t> m_groupFilter;
			std::vector<ArkSignalSystem::Data::ModifierData::RuleData::FactorData> m_factors;

			RuleData(const XmlNodeRef _root);

		#if 0
			const std::vector<uint64_t>& GetGroupFilter() const;
			bool IsMatchingSignal(const uint64_t _arg0_) const;
			const ArkSignalSystem::Data::ModifierData::RuleData::FactorData* FindFactor(const uint64_t _arg0_) const;
			const std::vector<ArkSignalSystem::Data::ModifierData::RuleData::FactorData>& GetFactorData() const;
		#endif

			static inline auto FRuleDataOv2 = PreyFunction<void(ArkSignalSystem::Data::ModifierData::RuleData* const _this, const XmlNodeRef _root)>(0x17004C0);
		};

		string m_name;
		std::vector<ArkSignalSystem::Data::ModifierData::RuleData> m_rules;

	#if 0
		ModifierData(const XmlNodeRef _arg0_);
		const std::vector<ArkSignalSystem::Data::ModifierData::RuleData>& GetRules() const;
		const string& GetName() const;
	#endif
	};

	// ArkSignalSystem::Data::SortableData<class ArkSignalSystem::Data::ModifierData>
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SortableData<class ArkSignalSystem::Data::ModifierData>
	{ // Size=8 (0x8)
	public:
		uint64_t m_id;

	#if 0
		void SortableData<ArkSignalSystem::Data::ModifierData>();
		bool operator<(const ArkSignalSystem::Data::ModifierData& _arg0_) const;
		uint64_t operator unsigned __int64() const;
		uint64_t GetId() const;
	#endif
	};

	// ArkSignalSystem::Data::SortableData<class ArkSignalSystem::Data::ModifierData::RuleData::FactorData>
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SortableData<class ArkSignalSystem::Data::ModifierData::RuleData::FactorData>
	{ // Size=8 (0x8)
	public:
		uint64_t m_id;

	#if 0
		void SortableData<ArkSignalSystem::Data::ModifierData::RuleData::FactorData>();
		bool operator<(const ArkSignalSystem::Data::ModifierData::RuleData::FactorData& _arg0_) const;
		uint64_t operator unsigned __int64() const;
		uint64_t GetId() const;
	#endif
	};

	// ArkSignalSystem::Data::DamageSignalData
	// Header:  Prey/Ark/arksignalsystemdata.h
	class DamageSignalData : public ArkSignalSystem::Data::SortableData<ArkSignalSystem::Data::DamageSignalData>
	{ // Size=8 (0x8)
	public:
	#if 0
		DamageSignalData(const XmlNodeRef _arg0_);
	#endif
	};

	// ArkSignalSystem::Data::SortableData<class ArkSignalSystem::Data::DamageSignalData>
	// Header:  Prey/Ark/arksignalsystemdata.h
	class SortableData<class ArkSignalSystem::Data::DamageSignalData>
	{ // Size=8 (0x8)
	public:
		uint64_t m_id;

	#if 0
		void SortableData<ArkSignalSystem::Data::DamageSignalData>();
		bool operator<(const ArkSignalSystem::Data::DamageSignalData& _arg0_) const;
		uint64_t operator unsigned __int64() const;
		uint64_t GetId() const;
	#endif
	};

	std::vector<ArkSignalSystem::Data::PackageData> m_packages;
	std::vector<ArkSignalSystem::Data::SignalData> m_signals;
	std::vector<ArkSignalSystem::Data::ModifierData> m_modifiers;
	std::vector<ArkSignalSystem::Data::SignalGroupData> m_signalGroups;
	std::vector<ArkSignalSystem::Data::DamageSignalData> m_damageSignals;

	void Scan() { FScan(this); }
	const ArkSignalSystem::Data::ModifierData* FindModifier(const uint64_t _id) const { return FFindModifier(this, _id); }
	const ArkSignalSystem::Data::PackageData* FindPackage(const uint64_t _id) const { return FFindPackage(this, _id); }

#if 0
	const ArkSignalSystem::Data::SignalData* FindSignal(const uint64_t _arg0_) const;
	const ArkSignalSystem::Data::SignalGroupData* FindSignalGroup(const uint64_t _arg0_) const;
	const ArkSignalSystem::Data::DamageSignalData* FindDamageSignalData(const uint64_t _arg0_) const;
	const std::vector<ArkSignalSystem::Data::PackageData>& GetPackageItems() const;
	const std::vector<ArkSignalSystem::Data::SignalData>& GetSignalItems() const;
	const std::vector<ArkSignalSystem::Data::ModifierData>& GetModifierItems() const;
	const std::vector<ArkSignalSystem::Data::SignalGroupData>& GetSignalGroupItems() const;
	const char* GetPackageName(const char* const _arg0_) const;
	const char* GetSignalName(const char* const _arg0_) const;
	const char* GetModifierName(const char* const _arg0_) const;
	const char* GetSignalGroupName(const char* const _arg0_) const;
	string GetPackageIdAsString(const char* const _arg0_) const;
	uint64_t GetPackageId(const char* const _arg0_) const;
	string GetSignalIdAsString(const char* const _arg0_) const;
	string GetModifierIdAsString(const char* const _arg0_) const;
	string GetSignalGroupIdAsString(const char* const _arg0_) const;
#endif

	static inline auto FScan = PreyFunction<void(ArkSignalSystem::Data* const _this)>(0x1702FE0);
	static inline auto FFindModifier = PreyFunction<const ArkSignalSystem::Data::ModifierData* (const ArkSignalSystem::Data* const _this, const uint64_t _id)>(0x1701E20);
	static inline auto FFindPackage = PreyFunction<const ArkSignalSystem::Data::PackageData* (const ArkSignalSystem::Data* const _this, const uint64_t _id)>(0x1701EB0);
};


} // namespace ArkSignalSystem
#endif // !MOONCRASH
