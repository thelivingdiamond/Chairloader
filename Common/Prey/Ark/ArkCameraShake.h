// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkcamerashake.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkCameraShakeChannel;
class ArkClass;

// Header: Exact
// Prey/Ark/ArkCameraShake.h
class ArkCameraShake : public ArkReflectedObject // Id=801357D Size=80
{
public:
	class ArkIDProperty : public ArkProperty // Id=801357E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068B80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static ArkCameraShake::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=801357F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360380);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1068E60);
	};

	static ArkCameraShake::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkChannelProperty : public ArkProperty // Id=8013580 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkChannelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AD50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkChannelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A6360);
	};

	static ArkCameraShake::ArkChannelProperty s_ArkChannelProperty;
	uint64_t m_Channel;
	
	class ArkInnerRadiusProperty : public ArkProperty // Id=8013581 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkInnerRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A63A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkInnerRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1360170);
	};

	static ArkCameraShake::ArkInnerRadiusProperty s_ArkInnerRadiusProperty;
	float m_InnerRadius;
	
	class ArkOuterRadiusProperty : public ArkProperty // Id=8013582 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkOuterRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086230);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkOuterRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A63C0);
	};

	static ArkCameraShake::ArkOuterRadiusProperty s_ArkOuterRadiusProperty;
	float m_OuterRadius;
	
	class ArkUIHorizontalAmplitudeProperty : public ArkProperty // Id=8013583 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkUIHorizontalAmplitudeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1068AF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkUIHorizontalAmplitudeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221B60);
	};

	static ArkCameraShake::ArkUIHorizontalAmplitudeProperty s_ArkUIHorizontalAmplitudeProperty;
	float m_UIHorizontalAmplitude;
	
	class ArkUIVerticalAmplitudeProperty : public ArkProperty // Id=8013584 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkUIVerticalAmplitudeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AD70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkUIVerticalAmplitudeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AD90);
	};

	static ArkCameraShake::ArkUIVerticalAmplitudeProperty s_ArkUIVerticalAmplitudeProperty;
	float m_UIVerticalAmplitude;
	
	class ArkRampInDurationProperty : public ArkProperty // Id=8013585 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkRampInDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105A960);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkRampInDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105A980);
	};

	static ArkCameraShake::ArkRampInDurationProperty s_ArkRampInDurationProperty;
	float m_RampInDuration;
	
	class ArkHoldDurationProperty : public ArkProperty // Id=8013586 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkHoldDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105A9A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkHoldDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105A9C0);
	};

	static ArkCameraShake::ArkHoldDurationProperty s_ArkHoldDurationProperty;
	float m_HoldDuration;
	
	class ArkRampOutDurationProperty : public ArkProperty // Id=8013587 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkRampOutDurationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105A9E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkRampOutDurationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221C40);
	};

	static ArkCameraShake::ArkRampOutDurationProperty s_ArkRampOutDurationProperty;
	float m_RampOutDuration;
	
	class ArkVerticalFrequencyProperty : public ArkProperty // Id=8013588 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkVerticalFrequencyProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AA00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkVerticalFrequencyProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA20);
	};

	static ArkCameraShake::ArkVerticalFrequencyProperty s_ArkVerticalFrequencyProperty;
	float m_VerticalFrequency;
	
	class ArkHorizontalFrequencyProperty : public ArkProperty // Id=8013589 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkHorizontalFrequencyProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AA40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkHorizontalFrequencyProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA60);
	};

	static ArkCameraShake::ArkHorizontalFrequencyProperty s_ArkHorizontalFrequencyProperty;
	float m_HorizontalFrequency;
	
	class ArkForceFeedbackProperty : public ArkProperty // Id=801358A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake::ArkForceFeedbackProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1221CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake::ArkForceFeedbackProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AA80);
	};

	static ArkCameraShake::ArkForceFeedbackProperty s_ArkForceFeedbackProperty;
	string m_ForceFeedback;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual EArkCameraShakeType GetCameraShakeType() const;
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetChannel(uint64_t arg0);
	const uint64_t &GetChannel() const;
	void SetInnerRadius(float arg0);
	const float &GetInnerRadius() const;
	void SetOuterRadius(float arg0);
	const float &GetOuterRadius() const;
	void SetUIHorizontalAmplitude(float arg0);
	const float &GetUIHorizontalAmplitude() const;
	void SetUIVerticalAmplitude(float arg0);
	const float &GetUIVerticalAmplitude() const;
	void SetRampInDuration(float arg0);
	const float &GetRampInDuration() const;
	void SetHoldDuration(float arg0);
	const float &GetHoldDuration() const;
	void SetRampOutDuration(float arg0);
	const float &GetRampOutDuration() const;
	void SetVerticalFrequency(float arg0);
	const float &GetVerticalFrequency() const;
	void SetHorizontalFrequency(float arg0);
	const float &GetHorizontalFrequency() const;
	void SetForceFeedback(string arg0);
	string const &GetForceFeedback() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105B410);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105B5F0);
	static inline auto FGetCameraShakeType = PreyFunction<EArkCameraShakeType(ArkCameraShake const *const _this)>(0x158AEF0);
};

// Header: Exact
// Prey/Ark/arkcamerashake.h
class ArkCameraShake_Procedural : public ArkCameraShake // Id=801358B Size=88
{
public:
	class ArkPitchAmplitudeProperty : public ArkProperty // Id=801358C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake_Procedural::ArkPitchAmplitudeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AAA0);
	};

	static ArkCameraShake_Procedural::ArkPitchAmplitudeProperty s_ArkPitchAmplitudeProperty;
	float m_PitchAmplitude;
	
	class ArkYawAmplitudeProperty : public ArkProperty // Id=801358D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake_Procedural::ArkYawAmplitudeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AAD0);
	};

	static ArkCameraShake_Procedural::ArkYawAmplitudeProperty s_ArkYawAmplitudeProperty;
	float m_YawAmplitude;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual EArkCameraShakeType GetCameraShakeType() const;
	
#if 0
	void SetPitchAmplitude(float arg0);
	float GetPitchAmplitude() const;
	void SetYawAmplitude(float arg0);
	float GetYawAmplitude() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105B570);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105B780);
	static inline auto FGetCameraShakeType = PreyFunction<EArkCameraShakeType(ArkCameraShake_Procedural const *const _this)>(0x1B1DEA0);
};

// Header: Exact
// Prey/Ark/arkcamerashake.h
class ArkCameraShake_Animated : public ArkCameraShake // Id=801358E Size=88
{
public:
	class ArkAnimationProperty : public ArkProperty // Id=801358F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShake_Animated::ArkAnimationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AB00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShake_Animated::ArkAnimationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1221D20);
	};

	static ArkCameraShake_Animated::ArkAnimationProperty s_ArkAnimationProperty;
	string m_Animation;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	virtual EArkCameraShakeType GetCameraShakeType() const;
	
#if 0
	static ArkClass *GetClass();
	void SetAnimation(string arg0);
	string const &GetAnimation() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105B4E0);
	static inline auto FGetCameraShakeType = PreyFunction<EArkCameraShakeType(ArkCameraShake_Animated const *const _this)>(0x1A42CE0);
};

// Header: Exact
// Prey/Ark/arkcamerashake.h
class ArkCameraShakeLibrary : public ArkReflectedLibrary // Id=80135A0 Size=56
{
public:
	class ArkCameraShakesProperty : public ArkProperty // Id=80135A1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShakeLibrary::ArkCameraShakesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AB60);
		static inline auto FIsArray = PreyFunction<bool(ArkCameraShakeLibrary::ArkCameraShakesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkCameraShakeLibrary::ArkCameraShakesProperty const *const _this, ArkReflectedObject *_pObject)>(0x135FE00);
	};

	static ArkCameraShakeLibrary::ArkCameraShakesProperty s_ArkCameraShakesProperty;
	std::vector<std::shared_ptr<ArkCameraShake>> m_CameraShakes;
	
	class ArkChannelsProperty : public ArkProperty // Id=80135A2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkCameraShakeLibrary::ArkChannelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x105AC20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkCameraShakeLibrary::ArkChannelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x105AC90);
		static inline auto FIsArray = PreyFunction<bool(ArkCameraShakeLibrary::ArkChannelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkCameraShakeLibrary::ArkChannelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x105ACD0);
	};

	static ArkCameraShakeLibrary::ArkChannelsProperty s_ArkChannelsProperty;
	std::vector<ArkCameraShakeChannel> m_Channels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	ArkCameraShake const *FindCameraShake(const uint64_t _id) const { return FFindCameraShake(this,_id); }
	virtual bool Init();
	virtual ~ArkCameraShakeLibrary();
	
#if 0
	std::vector<std::shared_ptr<ArkCameraShake>> &GetCameraShakes();
	std::vector<std::shared_ptr<ArkCameraShake>> const &GetCameraShakes() const;
	std::vector<ArkCameraShakeChannel> &GetChannels();
	std::vector<ArkCameraShakeChannel> const &GetChannels() const;
	ArkCameraShake const *FindCameraShakeByName(const char *arg0) const;
	ArkCameraShakeChannel const *FindChannel(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x105B480);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x105B690);
	static inline auto FFindCameraShake = PreyFunction<ArkCameraShake const *(ArkCameraShakeLibrary const *const _this, const uint64_t _id)>(0x114DCE0);
	static inline auto FInit = PreyFunction<bool(ArkCameraShakeLibrary *const _this)>(0x105B820);
};

