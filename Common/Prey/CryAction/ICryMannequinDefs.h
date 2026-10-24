// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.
// Based on CRYENGINE 5.2 CryAction/ICryMannequinDefs.h, adapted to Prey.
#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Prey/CryCore/CryCrc32.h>
#include <Prey/CryCore/Containers/CryArray.h>
#include <Prey/CryString/CryName.h>
#include <Chairloader/PreyFunction.h>

// Prey (release build): tag and animation-name strings are stored, scope and procedural clip strings are not.
// Implied by the game's sizes: SAnimationEntry=48, SScopeDef=28, SProceduralEntry=48.
#define STORE_TAG_STRINGS      1
#define STORE_ANIMNAME_STRINGS 1
#define STORE_PROCCLIP_STRINGS 0
#define STORE_SCOPE_STRINGS    0

typedef int32 TagID; // should be uint32, but it's too scary because we regularly check (tagID >= 0) instead of (tagID != TAG_ID_INVALID)
static const TagID TAG_ID_INVALID = ~TagID(0);

typedef int32 TagGroupID; // should be uint32, but it's too scary because we regularly check (tagGroupID >= 0) instead of (tagGroupID != TAG_ID_INVALID)
static const TagGroupID GROUP_ID_NONE = ~TagGroupID(0);

typedef TagID FragmentID; // should be uint32, but it's too scary because we regularly check (fragmentID >= 0) instead of (fragmentID != TAG_ID_INVALID)
static const FragmentID FRAGMENT_ID_INVALID = TAG_ID_INVALID;

static const TagID SCOPE_ID_INVALID = TAG_ID_INVALID;

typedef uint32 AnimCRC; // CRC of the name of the animation
static const AnimCRC ANIM_CRC_INVALID = AnimCRC(0);

static const uint32 OPTION_IDX_RANDOM = 0xfffffffe;
static const uint32 OPTION_IDX_INVALID = 0xffffffff;

static const uint32 TAG_SET_IDX_INVALID = ~uint32(0);

typedef uint32 ActionScopes;
static const ActionScopes ACTION_SCOPES_ALL = ~ActionScopes(0);
static const ActionScopes ACTION_SCOPES_NONE = ActionScopes(0);

//suggestion: typedef uint32 ScopeContextId;
static const TagID SCOPE_CONTEXT_ID_INVALID = TAG_ID_INVALID;

// SCRCRefHash_CRC32Lowercase
// Header:  CryEngine/cryaction/icrymannequindefs.h
struct SCRCRefHash_CRC32Lowercase
{ // Size=1 (0x1)
	typedef uint32 TInt;
	static const TInt INVALID = 0;

	static TInt CalculateHash(const char* const s)
	{
		assert(s);
		assert(s[0]);

		const TInt crc = CCrc32::ComputeLowercase(s);
		if (crc == INVALID)
		{
			CryWarning("Congratulations, you hit the jackpot! The string '{}' has a lowercase CRC32 equal to {}. Unfortunately this number is reserved for errors, so please rename and try again...", s, INVALID);
		}
		return crc;
	}
};

// SCRCRefHash_CRC32
// Header:  _unknown/SCRCRefHash_CRC32.h
struct SCRCRefHash_CRC32
{ // Size=1 (0x1)
	typedef uint32 TInt;
	static const TInt INVALID = 0;

	static TInt CalculateHash(const char* const s)
	{
		assert(s);
		assert(s[0]);

		const TInt crc = CCrc32::Compute(s);
		if (crc == INVALID)
		{
			CryWarning("Congratulations, you hit the jackpot! The string '{}' has a CRC32 equal to {}. Unfortunately this number is reserved for errors, so please rename and try again...", s, INVALID);
		}
		return crc;
	}
};

template<uint32 StoreStrings, typename THash = SCRCRefHash_CRC32Lowercase>
struct SCRCRef
{
};

template<typename THash>
struct SCRCRef<0, THash>
{ // Size=4 (0x4)
	typedef typename THash::TInt TInt;
	static const TInt INVALID = THash::INVALID;

	SCRCRef()
		: crc(INVALID)
	{
	}

	explicit SCRCRef(const char* const nameString)
	{
		SetByString(nameString);
	}

	void SetByString(const char* const nameString)
	{
		if (nameString && (nameString[0] != '\0'))
		{
			crc = THash::CalculateHash(nameString);
		}
		else
		{
			crc = INVALID;
		}
	}

	ILINE bool IsEmpty() const
	{
		return (crc == INVALID);
	}

	ILINE const char* c_str() const
	{
		if (crc == INVALID)
		{
			return "";
		}
		return "STRIPPED_CRC_NAMES";
	}

	ILINE SCRCRef<0, THash>& operator=(const char* const s)
	{
		SetByString(s);
		return *this;
	}

	template<uint32 StoreStringsRhs>
	ILINE bool operator==(const SCRCRef<StoreStringsRhs, THash>& rhs) const
	{
		return (crc == rhs.crc);
	}

	template<uint32 StoreStringsRhs>
	ILINE bool operator!=(const SCRCRef<StoreStringsRhs, THash>& rhs) const
	{
		return (crc != rhs.crc);
	}

	template<uint32 StoreStringsRhs>
	ILINE bool operator<(const SCRCRef<StoreStringsRhs, THash>& rhs) const
	{
		return (crc < rhs.crc);
	}

	ILINE uint32 ToUInt32() const
	{
		return static_cast<uint32>(crc);
	}

	TInt crc;
};

namespace mannequin_detail
{
// Prey's SCRCRef<1>::SetByString is out-of-line in the game (only the CRC32Lowercase instantiation exists).
#ifndef MOONCRASH
static inline auto FSCRCRef1_SetByString = PreyFunction<void(void* const _this, const char* const nameString)>(0x368440);
#else
static inline auto FSCRCRef1_SetByString = PreyFunction<void(void* const _this, const char* const nameString)>(0x382920);
#endif
} // namespace mannequin_detail

// Prey stores the string as a raw heap-allocated char* (CE 5.2 uses DynArray<char>).
// SetByString is forwarded to the game so the buffer is owned by the game's allocator.
template<typename THash>
struct SCRCRef<1, THash>
{ // Size=16 (0x10)
	typedef typename THash::TInt TInt;
	static const TInt INVALID = THash::INVALID;

	SCRCRef()
		: crc(INVALID)
		, stringValue(nullptr)
	{
	}

	explicit SCRCRef(const char* const nameString)
		: crc(INVALID)
		, stringValue(nullptr)
	{
		SetByString(nameString);
	}

	SCRCRef(const SCRCRef<1, THash>& other)
		: crc(INVALID)
		, stringValue(nullptr)
	{
		SetByString(other.c_str());
	}

	// The game's destructor has no address; the buffer is not freed (the game's allocator owns it).

	SCRCRef<1, THash>& operator=(const SCRCRef<1, THash>& other)
	{
		if (&other != this)
		{
			SetByString(other.c_str());
		}
		return *this;
	}

	void SetByString(const char* const nameString)
	{
		static_assert(std::is_same_v<THash, SCRCRefHash_CRC32Lowercase>, "Prey only has SCRCRef<1, SCRCRefHash_CRC32Lowercase>");
		mannequin_detail::FSCRCRef1_SetByString(this, nameString);
	}

	ILINE bool IsEmpty() const
	{
		return (crc == INVALID);
	}

	ILINE const char* c_str() const
	{
		return stringValue ? stringValue : "";
	}

	ILINE SCRCRef<1, THash>& operator=(const char* const s)
	{
		SetByString(s);
		return *this;
	}

	template<uint32 StoreStringsRhs>
	ILINE bool operator==(const SCRCRef<StoreStringsRhs, THash>& rhs) const
	{
		return (crc == rhs.crc);
	}

	template<uint32 StoreStringsRhs>
	ILINE bool operator!=(const SCRCRef<StoreStringsRhs, THash>& rhs) const
	{
		return (crc != rhs.crc);
	}

	template<uint32 StoreStringsRhs>
	ILINE bool operator<(const SCRCRef<StoreStringsRhs, THash>& rhs) const
	{
		return (crc < rhs.crc);
	}

	ILINE uint32 ToUInt32() const
	{
		return static_cast<uint32>(crc);
	}

	TInt crc;
	char* stringValue;
};

typedef SCRCRef<STORE_TAG_STRINGS>      STagRef;
typedef SCRCRef<STORE_ANIMNAME_STRINGS> SAnimRef;
typedef SCRCRef<STORE_SCOPE_STRINGS>    SScopeRef;

const uint32 DEF_PATH_LENGTH = 512;
typedef SCRCRef<1>                      TDefPathString;

typedef SCRCRef<STORE_PROCCLIP_STRINGS> SProcDataCRC;

typedef SCRCRef<1>                      TProcClipTypeName;

typedef CCryName                        TProcClipString;

enum eSequenceFlags
{
	eSF_Fragment        = BIT(0),
	eSF_TransitionOutro = BIT(1),
	eSF_Transition      = BIT(2)
};

// SWeightData
// Header:  _unknown/SWeightData.h
struct SWeightData
{ // Size=16 (0x10)
	enum { MAX_WEIGHTS = 4 };

	SWeightData() { memset(&weights, 0, MAX_WEIGHTS * sizeof(weights[0])); }

	float weights[MAX_WEIGHTS];
};
