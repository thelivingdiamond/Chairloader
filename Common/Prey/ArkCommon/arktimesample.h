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

