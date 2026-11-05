// Based on CryEngine 5.2 ParticleParams.h (TStorageTraits, TCurve) and ParticleParams_TypeInfo.h (CCustomInfo).
// TCurve<TRangedType<float, MIN, MAX, 0>> for (INT_MIN, INT_MAX), (0, 1), (0, 180), (0, INT_MAX), (0, 360) - Size=8,
// CCustomInfo Size=32, T = float, TMod = TFixed<uint8, 1, 255, 0> (UnitFloat8) in every instantiation.
// The instantiations share folded code, so the addresses are valid for all of them.
#pragma once
#include <Prey/CryCore/CryCustomTypes.h>
#include <Prey/CryCore/CryTypeInfo.h>
#include <Prey/CryMath/Cry_Math.h>
#include <Prey/CryMath/FinalizingSpline.h>

class ICrySizer;

//! Storage traits of a particle parameter type (only the primary template is needed here).
template<class S>
struct TStorageTraits
{
	typedef float                     TValue;
	typedef UnitFloat8                TMod;
	typedef TRangedType<float, 0, 1>  TRandom; // UnitFloat
};

template<class S>
class TCurve : public spline::OptSpline<typename TStorageTraits<S>::TValue>
{ // Size=8 (0x8)
public:
	struct CCustomInfo : public CTypeInfo
	{ // Size=32 (0x20)
		using TIndirectSpline = spline::FinalizingSpline<typename TCurve<S>::source_spline, TCurve<S>>;

		virtual string ToString(const void* data, ::FToString flags, const void* def_data) const;
		virtual bool FromString(void* data, const char* str, ::FFromString flags) const;
		virtual bool ToValue(const void* data, void* value, const CTypeInfo& typeVal) const;
		virtual bool FromValue(void* data, const void* value, const CTypeInfo& typeVal) const;
		virtual bool ValueEqual(const void* data, const void* def_data) const;
		virtual void GetMemoryUsage(ICrySizer* pSizer, const void* data) const;

#if 0
		CCustomInfo();
#endif

#ifndef MOONCRASH
		static inline auto FToString = PreyFunction<string*(const CCustomInfo* const _this, string* _return_value_, const void* data, ::FToString flags, const void* def_data)>(0x1876F0);
		static inline auto FFromString = PreyFunction<bool(const CCustomInfo* const _this, void* data, const char* str, ::FFromString flags)>(0x1813F0);
		static inline auto FToValue = PreyFunction<bool(const CCustomInfo* const _this, const void* data, void* value, const CTypeInfo& typeVal)>(0x187FB0);
		static inline auto FFromValue = PreyFunction<bool(const CCustomInfo* const _this, void* data, const void* value, const CTypeInfo& typeVal)>(0x181E10);
		static inline auto FValueEqual = PreyFunction<bool(const CCustomInfo* const _this, const void* data, const void* def_data)>(0x18FEB0);
		static inline auto FGetMemoryUsage = PreyFunction<void(const CCustomInfo* const _this, ICrySizer* pSizer, const void* data)>(0x1835C0);
#else
		static inline auto FToString = PreyFunction<string*(const CCustomInfo* const _this, string* _return_value_, const void* data, ::FToString flags, const void* def_data)>(0x19F5B0);
		static inline auto FFromString = PreyFunction<bool(const CCustomInfo* const _this, void* data, const char* str, ::FFromString flags)>(0x1993D0);
		static inline auto FToValue = PreyFunction<bool(const CCustomInfo* const _this, const void* data, void* value, const CTypeInfo& typeVal)>(0x19FE70);
		static inline auto FFromValue = PreyFunction<bool(const CCustomInfo* const _this, void* data, const void* value, const CTypeInfo& typeVal)>(0x199DF0);
		static inline auto FValueEqual = PreyFunction<bool(const CCustomInfo* const _this, const void* data, const void* def_data)>(0x1A7DC0);
		static inline auto FGetMemoryUsage = PreyFunction<void(const CCustomInfo* const _this, ICrySizer* pSizer, const void* data)>(0x19B3C0);
#endif
	};

	using TThis = TCurve<S>;
	using T = typename TStorageTraits<S>::TValue;
	using TMod = typename TStorageTraits<S>::TMod;
	using super_type = spline::OptSpline<T>;
	using source_spline = typename super_type::source_spline;
	using key_type = typename super_type::key_type;

	bool FromString(const char* str_in, ::FFromString flags) { return FFromString(this, str_in, flags); }
	T operator()(type_min _min) const { return FoperatorRBLRBROv0(this, _min); }

#if 0
	string ToString(::FToString) const;
	T operator()(float) const;
	T operator()(type_max) const;
	const CTypeInfo& TypeInfo() const;
#endif

#ifndef MOONCRASH
	static inline auto FFromString = PreyFunction<bool(TCurve<S>* const _this, const char* str_in, ::FFromString flags)>(0x180490);
	static inline auto FoperatorRBLRBROv0 = PreyFunction<T(const TCurve<S>* const _this, type_min __unnamed1)>(0x17DAB0);
#else
	static inline auto FFromString = PreyFunction<bool(TCurve<S>* const _this, const char* str_in, ::FFromString flags)>(0x198470);
	static inline auto FoperatorRBLRBROv0 = PreyFunction<T(const TCurve<S>* const _this, type_min __unnamed1)>(0x195980);
#endif
};
