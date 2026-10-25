// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/ICryMannequinTagDefs.h>
#include <Prey/CryAction/ICryMannequinTagDefs.h>

class IAnimationDatabase;

// CFragmentVariationHelper
// Header:  Prey/GameDll/FragmentVariationHelper.h
class CFragmentVariationHelper
{ // Size=88 (0x58)
public:
	int m_currentFragmentId;
	int m_requestedFragmentId;
	SFragTagState m_currentTagState;
	SFragTagState m_requestedTagState;
	SFragTagState m_selectedTagState;
	unsigned m_selectedOptionIndex;
	bool m_reachedFragmentEnd;

	CFragmentVariationHelper();
	~CFragmentVariationHelper();
	void SetFragmentId(const int fragmentId) { FSetFragmentId(this, fragmentId); }
	void SetTagState(const SFragTagState& tagState) { FSetTagState(this, tagState); }
	bool Update(const IAnimationDatabase* pDatabase, const bool forceReevaluate) { return FUpdate(this, pDatabase, forceReevaluate); }
	void OnFragmentEnd() { FOnFragmentEnd(this); }
	int GetFragmentId() const { return FGetFragmentId(this); }
	STagState<12> GetFragmentTagState() const { alignas(STagState<12>) std::byte _return_buf_[sizeof(STagState<12>)]; return *FGetFragmentTagState(this, reinterpret_cast<STagState<12>*>(_return_buf_)); }
	unsigned GetOptionIndex() const { return FGetOptionIndex(this); }
	bool Reevaluate(const IAnimationDatabase* pDatabase, const bool forceReevaluate) { return FReevaluate(this, pDatabase, forceReevaluate); }

#if 0
	STagState<12> GetTagState() const;
#endif

#ifndef MOONCRASH
	static inline auto FCFragmentVariationHelper = PreyFunction<void(CFragmentVariationHelper* const _this)>(0x16C29D0);
	static inline auto FBitNotCFragmentVariationHelper = PreyFunction<void(CFragmentVariationHelper* const _this)>(0xA13080);
	static inline auto FSetFragmentId = PreyFunction<void(CFragmentVariationHelper* const _this, const int fragmentId)>(0x16C2C60);
	static inline auto FSetTagState = PreyFunction<void(CFragmentVariationHelper* const _this, const SFragTagState& tagState)>(0x18031D0);
	static inline auto FUpdate = PreyFunction<bool(CFragmentVariationHelper* const _this, const IAnimationDatabase* pDatabase, const bool forceReevaluate)>(0x16C2C70);
	static inline auto FOnFragmentEnd = PreyFunction<void(CFragmentVariationHelper* const _this)>(0x16C2A90);
	static inline auto FGetFragmentId = PreyFunction<int(const CFragmentVariationHelper* const _this)>(0x12114A0);
	static inline auto FGetFragmentTagState = PreyFunction<STagState<12>*(const CFragmentVariationHelper* const _this, STagState<12>* _return_value_)>(0x16C2A70);
	static inline auto FGetOptionIndex = PreyFunction<unsigned(const CFragmentVariationHelper* const _this)>(0xB46570);
	static inline auto FReevaluate = PreyFunction<bool(CFragmentVariationHelper* const _this, const IAnimationDatabase* pDatabase, const bool forceReevaluate)>(0x16C2AA0);
#else
	static inline auto FCFragmentVariationHelper = PreyFunction<void(CFragmentVariationHelper* const _this)>(0x17E5240);
	static inline auto FBitNotCFragmentVariationHelper = PreyFunction<void(CFragmentVariationHelper* const _this)>(0x1333E90);
	static inline auto FSetFragmentId = PreyFunction<void(CFragmentVariationHelper* const _this, const int fragmentId)>(0x17E54D0);
	static inline auto FSetTagState = PreyFunction<void(CFragmentVariationHelper* const _this, const SFragTagState& tagState)>(0x17E54E0);
	static inline auto FUpdate = PreyFunction<bool(CFragmentVariationHelper* const _this, const IAnimationDatabase* pDatabase, const bool forceReevaluate)>(0x17E5500);
	static inline auto FOnFragmentEnd = PreyFunction<void(CFragmentVariationHelper* const _this)>(0x17E5300);
	static inline auto FGetFragmentId = PreyFunction<int(const CFragmentVariationHelper* const _this)>(0x12A08E0);
	static inline auto FGetFragmentTagState = PreyFunction<STagState<12>*(const CFragmentVariationHelper* const _this, STagState<12>* _return_value_)>(0x17E52E0);
	static inline auto FGetOptionIndex = PreyFunction<unsigned(const CFragmentVariationHelper* const _this)>(0xB63D00);
	static inline auto FReevaluate = PreyFunction<bool(CFragmentVariationHelper* const _this, const IAnimationDatabase* pDatabase, const bool forceReevaluate)>(0x17E5310);
#endif
};

