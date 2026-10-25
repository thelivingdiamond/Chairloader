// SPrediction_tpl and its sample types, from CryEngine 5.2 GameSDK CornerSmoother.cpp (no debug turnRadius).
#pragma once

namespace CornerSmoothing
{

// CornerSmoothing::SSimpleSample
// Header:  _unknown/CornerSmoothing__SSimpleSample.h
struct SSimpleSample
{ // Size=8 (0x8)
	Vec2 pos;
};

// CornerSmoothing::SSplineSample
// Header:  _unknown/CornerSmoothing__SSplineSample.h
struct SSplineSample
{ // Size=20 (0x14)
	Vec2 pos;
	float alpha;
	float distance;
	float maximumSpeedSq;
};

//! Predicted 2D trajectory. When numSamples == 0 the prediction is empty (invalid).
template<class SampleType>
struct SPrediction_tpl
{
	static constexpr int SHOOTOUT_PREDICTION_MAX_SAMPLES = 25;

	int numSamples;
	SampleType samples[SHOOTOUT_PREDICTION_MAX_SAMPLES];

#if 0
	SPrediction_tpl();
	void Reset();
#endif
};

typedef SPrediction_tpl<SSimpleSample> SSimplifiedPrediction;
typedef SPrediction_tpl<SSplineSample> SSplinePrediction;

} // namespace CornerSmoothing
