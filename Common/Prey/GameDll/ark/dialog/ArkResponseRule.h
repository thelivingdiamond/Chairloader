// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/dialog/ArkResponseRule.h>
#include <Prey/GameDll/ark/dialog/arkresponsetypes.h>

class XmlNodeRef;

using EArkWritebackType = EArkConversationType;

class ArkWritebackFact // Id=801368B Size=32
{
public:
	uint64_t m_id;
	ArkResponseValue m_value;
	EArkWritebackType m_type;
	float m_timeout;

#if 0
	bool IsValid() const;
	uint64_t GetId() const;
	ArkResponseValue const& GetValue() const;
	EArkWritebackType GetType() const;
	float GetTimeout() const;
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/dialog/arkresponserule.h
class ArkResponseCriterion // Id=801368A Size=40
{
public:
	uint64_t m_id;
	ArkResponseValue m_value;
	EArkResponseCompareType m_ctype;
	EArkCriterionKeyType m_keyType;
	bool m_bPassIfMissing;
	
	ArkResponseCriterion(XmlNodeRef _root);
	bool Compare(const double _x) const { return FCompare(this,_x); }
	
#if 0
	bool IsValid() const;
	uint64_t GetId() const;
	ArkResponseValue const &GetValue() const;
	bool CanPassIfMissing() const;
	EArkResponseCompareType GetCompareType() const;
	string const &GetStringValue() const;
	EArkCriterionKeyType GetKeyType() const;
#endif
	
	static inline auto FCompare = PreyFunction<bool(ArkResponseCriterion const *const _this, const double _x)>(0x1498280);
};

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkResponseRule.h
class ArkResponseRule // Id=801368C Size=96
{
public:
	using TCriteria = std::vector<ArkResponseCriterion>;
	using TWriteback = std::vector<ArkWritebackFact>;
	
	std::vector<ArkWritebackFact> m_writeback;
	std::vector<ArkResponseCriterion> m_criteria;
	uint64_t m_responseId;
	uint64_t m_id;
	float m_cooldown;
	bool m_bConversation;
	bool m_bDebug;
	EArkConversationPriority m_priority;
	CCryName m_name;
	CCryName m_file;
	
	ArkResponseRule(XmlNodeRef _root, CCryName const &_filename);
	static boost::optional<float> GetNumber(const char *_input) { return FGetNumber(_input); }
	
#if 0
	std::vector<ArkResponseCriterion> const &GetCriteria() const;
	uint64_t GetResponse() const;
	std::vector<ArkWritebackFact> const &GetWriteback() const;
	float GetCooldown() const;
	bool IsValid() const;
	uint64_t GetID() const;
	bool IsConversation() const;
	const char *GetName() const;
	const char *GetFilename() const;
	void SetDebug(const bool arg0);
	bool IsDebug() const;
	EArkConversationPriority GetPriority();
	bool IsAvailable(const float arg0, const float arg1) const;
#endif
	
	static inline auto FGetNumber = PreyFunction<boost::optional<float>(const char *_input)>(0x1498300);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/dialog/arkresponsetypes.h>

class XmlNodeRef;

// ArkResponseCriterion
// Header:  Prey/GameDll/ark/dialog/ArkResponseRule.h
class ArkResponseCriterion
{ // Size=40 (0x28)
public:
	uint64_t m_id;
	ArkResponseValue m_value;
	EArkResponseCompareType m_ctype;
	EArkCriterionKeyType m_keyType;
	bool m_bPassIfMissing;

	ArkResponseCriterion(XmlNodeRef _root);
	bool Compare(const double _x) const { return FCompare(this, _x); }

#if 0
	ArkResponseCriterion(uint64_t _arg0_, int _arg1_, EArkResponseCompareType _arg2_);
	bool IsValid() const;
	uint64_t GetId() const;
	const ArkResponseValue& GetValue() const;
	bool CanPassIfMissing() const;
	EArkResponseCompareType GetCompareType() const;
	const string& GetStringValue() const;
	EArkCriterionKeyType GetKeyType() const;
#endif

	static inline auto FArkResponseCriterionOv3 = PreyFunction<void(ArkResponseCriterion* const _this, XmlNodeRef _root)>(0x15AF4D0);
	static inline auto FCompare = PreyFunction<bool(const ArkResponseCriterion* const _this, const double _x)>(0x15AFD50);
};

// ArkWritebackFact
// Header:  Prey/GameDll/ark/dialog/ArkResponseRule.h
class ArkWritebackFact
{ // Size=32 (0x20)
public:
	uint64_t m_id;
	ArkResponseValue m_value;
	EArkWritebackType m_type;
	float m_timeout;

#if 0
	ArkWritebackFact(XmlNodeRef _arg0_);
	bool IsValid() const;
	uint64_t GetId() const;
	const ArkResponseValue& GetValue() const;
	const EArkWritebackType GetType() const;
	float GetTimeout() const;
#endif
};

// ArkResponseRule
// Header:  Prey/GameDll/ark/dialog/ArkResponseRule.h
class ArkResponseRule
{ // Size=96 (0x60)
public:
	using TCriteria = std::vector<ArkResponseCriterion>;
	using TWriteback = std::vector<ArkWritebackFact>;

	std::vector<ArkWritebackFact> m_writeback;
	std::vector<ArkResponseCriterion> m_criteria;
	uint64_t m_responseId;
	uint64_t m_id;
	float m_cooldown;
	bool m_bConversation;
	bool m_bDebug;
	EArkConversationPriority m_priority;
	CCryName m_name;
	CCryName m_file;

	ArkResponseRule(XmlNodeRef _root, const CCryName& _filename);
	static boost::optional<float> GetNumber(const char* _input) { return FGetNumber(_input); }

#if 0
	const std::vector<ArkResponseCriterion>& GetCriteria() const;
	uint64_t GetResponse() const;
	const std::vector<ArkWritebackFact>& GetWriteback() const;
	float GetCooldown() const;
	bool IsValid() const;
	uint64_t GetID() const;
	bool IsConversation() const;
	const char* GetName() const;
	const char* GetFilename() const;
	void SetDebug(const bool _arg0_);
	bool IsDebug() const;
	EArkConversationPriority GetPriority() const;
	bool IsAvailable(const float _arg0_, const float _arg1_) const;
#endif

	static inline auto FArkResponseRuleOv2 = PreyFunction<void(ArkResponseRule* const _this, XmlNodeRef _root, const CCryName& _filename)>(0x15AF720);
	static inline auto FGetNumber = PreyFunction<boost::optional<float>(const char* _input)>(0x15AFDD0);
};
#endif // !MOONCRASH
