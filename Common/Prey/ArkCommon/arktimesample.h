// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: Exact
// Prey/ArkCommon/arktimesample.h
template <typename T, size_t SIZE>
class ArkTimeSample // Id=8017975 Size=48
{
public:
	using ValueType = T;
	
	static constexpr const size_t k_sampleCount = SIZE;
	
	using SampleArray = std::array<float, k_sampleCount>;
	
	SampleArray m_sampleArray;
	float m_currentTime;
	float m_sampleTime;
	
#if 0
	float GetSampleTime() const;
	void AddSample(const float &arg0);
	void Advance(float arg0);
	float GetTotal() const;
	float GetDerivative() const;
	void Clear();
	void Reset(float arg0);
	void Serialize(TSerialize _serializer);
	void __dflt_ctor_closure();
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkTimeSample<float,10>
// Header:  Prey/ArkCommon/arktimesample.h
class ArkTimeSample<float,10>
{ // Size=48 (0x30)
public:
	using ValueType = float;
	using SampleArray = std::array<float, 10>;

	static constexpr const uint64_t k_sampleCount = 10;
	std::array<float, 10> m_sampleArray;
	float m_currentTime;
	float m_sampleTime;

	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }

#if 0
	ArkTimeSample<float,10>(float _arg0_);
	float GetSampleTime() const;
	void AddSample(const float& _arg0_);
	void Advance(float _arg0_);
	float GetTotal() const;
	float GetDerivative() const;
	void Clear();
	void Reset(float _arg0_);
	void SetSampleTime(float _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(ArkTimeSample<float,10>* const _this, TSerialize _serializer)>(0x1115330);
};

// ArkTimeSample<int,10>
// Header:  Prey/ArkCommon/arktimesample.h
class ArkTimeSample<int,10>
{ // Size=48 (0x30)
public:
	using ValueType = int;
	using SampleArray = std::array<int, 10>;

	static constexpr const uint64_t k_sampleCount = 10;
	std::array<int, 10> m_sampleArray;
	float m_currentTime;
	float m_sampleTime;

	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }

#if 0
	ArkTimeSample<int,10>(float _arg0_);
	float GetSampleTime() const;
	void AddSample(const int& _arg0_);
	void Advance(float _arg0_);
	int GetTotal() const;
	float GetDerivative() const;
	void Clear();
	void Reset(float _arg0_);
	void SetSampleTime(float _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(ArkTimeSample<int,10>* const _this, TSerialize _serializer)>(0x12A8590);
};
#endif // !MOONCRASH
