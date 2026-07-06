// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryRenderer/IColorGradingController.h>

struct IColorGradingController;

namespace Graphics
{

// Graphics::CColorGradientManager
// Header:  Prey/GameDll/graphics/ColorGradientManager.h
class CColorGradientManager
{ // Size=48 (0x30)
public:
	// Graphics::CColorGradientManager::LoadedColorGradient
	// Header:  Prey/GameDll/graphics/ColorGradientManager.h
	class LoadedColorGradient
	{ // Size=32 (0x20)
	public:
		SColorChartLayer m_layer;
		string m_filePath;
		float m_fadeInTimeInSeconds;
		float m_elapsedTime;
		float m_maximumBlendAmount;

	#if 0
		LoadedColorGradient(const string& _arg0_, const SColorChartLayer& _arg1_, const float _arg2_);
		void FadeIn(const float _arg0_);
		void FadeOut(const float _arg0_);
		void FreezeMaximumBlendAmount();
	#endif
	};

	// Graphics::CColorGradientManager::LoadingColorGradient
	// Header:  Prey/GameDll/graphics/ColorGradientManager.h
	class LoadingColorGradient
	{ // Size=16 (0x10)
	public:
		string m_filePath;
		float m_fadeInTimeInSeconds;

	#if 0
		LoadingColorGradient(const string& _arg0_, const float _arg1_);
		Graphics::CColorGradientManager::LoadedColorGradient Load(IColorGradingController& _arg0_) const;
	#endif
	};

	std::vector<Graphics::CColorGradientManager::LoadingColorGradient> m_colorGradientsToLoad;
	std::vector<Graphics::CColorGradientManager::LoadedColorGradient> m_currentGradients;

	CColorGradientManager();
	void TriggerFadingColorGradient(const string& filePath, const float fadeInTimeInSeconds) { FTriggerFadingColorGradient(this, filePath, fadeInTimeInSeconds); }
	void UpdateForThisFrame(const float frameTimeInSeconds) { FUpdateForThisFrame(this, frameTimeInSeconds); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize serializer) { FSerialize(this, serializer); }
	void RemoveZeroWeightedLayers() { FRemoveZeroWeightedLayers(this); }

#if 0
	void FadeInLastLayer(const float _arg0_);
	void FadeOutCurrentLayers();
	void SetLayersForThisFrame();
	void LoadGradients();
	IColorGradingController& GetColorGradingController();
#endif

	static inline auto FCColorGradientManagerOv2 = PreyFunction<void(Graphics::CColorGradientManager* const _this)>(0xD48F00);
	static inline auto FTriggerFadingColorGradient = PreyFunction<void(Graphics::CColorGradientManager* const _this, const string& filePath, const float fadeInTimeInSeconds)>(0x1863800);
	static inline auto FUpdateForThisFrame = PreyFunction<void(Graphics::CColorGradientManager* const _this, const float frameTimeInSeconds)>(0x1863900);
	static inline auto FReset = PreyFunction<void(Graphics::CColorGradientManager* const _this)>(0x1863360);
	static inline auto FSerialize = PreyFunction<void(Graphics::CColorGradientManager* const _this, TSerialize serializer)>(0x1863400);
	static inline auto FRemoveZeroWeightedLayers = PreyFunction<void(Graphics::CColorGradientManager* const _this)>(0x1863200);
};


} // namespace Graphics
#endif // MOONCRASH
