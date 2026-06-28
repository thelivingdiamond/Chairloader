// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <_unknown/ArkCameraShakeChannel.h>

class ArkCameraShake;
class ArkClass;
enum class EArkCameraShakeType;
class IArkValueBase;

// ArkCameraShakeLibrary
// Header:  Prey/Ark/ArkCameraShake.h
class ArkCameraShakeLibrary : public ArkReflectedLibrary
{ // Size=56 (0x38)
public:
	// ArkCameraShakeLibrary::ArkCameraShakesProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkCameraShakesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkCameraShakesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShakeLibrary::ArkCameraShakesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B650);
		static inline auto FIsArray = PreyFunction<bool(const ArkCameraShakeLibrary::ArkCameraShakesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkCameraShakeLibrary::ArkCameraShakesProperty* const _this, ArkReflectedObject* _pObject)>(0x1444080);
	};

	// ArkCameraShakeLibrary::ArkChannelsProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkChannelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkChannelsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShakeLibrary::ArkChannelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B3A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShakeLibrary::ArkChannelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B410);
		static inline auto FIsArray = PreyFunction<bool(const ArkCameraShakeLibrary::ArkChannelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkCameraShakeLibrary::ArkChannelsProperty* const _this, ArkReflectedObject* _pObject)>(0x10AB170);
	};

	static inline auto s_ArkCameraShakesProperty = PreyGlobal<ArkCameraShakeLibrary::ArkCameraShakesProperty>(0x2D21D20);
	std::vector<std::shared_ptr<ArkCameraShake>> m_CameraShakes;
	static inline auto s_ArkChannelsProperty = PreyGlobal<ArkCameraShakeLibrary::ArkChannelsProperty>(0x2D21D40);
	std::vector<ArkCameraShakeChannel> m_Channels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkCameraShake* FindCameraShake(const uint64_t _id) const { return FFindCameraShake(this, _id); }
	virtual bool Init();

#if 0
	std::vector<std::shared_ptr<ArkCameraShake>>& GetCameraShakes();
	const std::vector<std::shared_ptr<ArkCameraShake>>& GetCameraShakes() const;
	std::vector<ArkCameraShakeChannel>& GetChannels();
	const std::vector<ArkCameraShakeChannel>& GetChannels() const;
	const ArkCameraShake* FindCameraShakeByName(const char* _arg0_) const;
	const ArkCameraShakeChannel* FindChannel(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107BE00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107C010);
	static inline auto FFindCameraShake = PreyFunction<const ArkCameraShake* (const ArkCameraShakeLibrary* const _this, const uint64_t _id)>(0x1194F50);
	static inline auto FInit = PreyFunction<bool(ArkCameraShakeLibrary* const _this)>(0x107C1A0);
};

// ArkCameraShake
// Header:  Prey/Ark/ArkCameraShake.h
class ArkCameraShake : public ArkReflectedObject
{ // Size=88 (0x58)
public:
	// ArkCameraShake::ArkIDProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ArkCameraShake::ArkNameProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108A000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9CA0);
	};

	// ArkCameraShake::ArkChannelProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkChannelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkChannelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkChannelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B450);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkChannelProperty* const _this, ArkReflectedObject* const _pObject)>(0x108A0C0);
	};

	// ArkCameraShake::ArkInnerRadiusProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkInnerRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkInnerRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkInnerRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkInnerRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1FF0);
	};

	// ArkCameraShake::ArkOuterRadiusProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkOuterRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOuterRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkOuterRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C8C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkOuterRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C8CB0);
	};

	// ArkCameraShake::ArkUIHorizontalAmplitudeProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkUIHorizontalAmplitudeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUIHorizontalAmplitudeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkUIHorizontalAmplitudeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108D310);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkUIHorizontalAmplitudeProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B470);
	};

	// ArkCameraShake::ArkUIVerticalAmplitudeProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkUIVerticalAmplitudeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUIVerticalAmplitudeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkUIVerticalAmplitudeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B490);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkUIVerticalAmplitudeProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B4B0);
	};

	// ArkCameraShake::ArkRampInDurationProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkRampInDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRampInDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkRampInDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B4D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkRampInDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089B40);
	};

	// ArkCameraShake::ArkHoldDurationProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkHoldDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHoldDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkHoldDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B4F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkHoldDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B510);
	};

	// ArkCameraShake::ArkRampOutDurationProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkRampOutDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRampOutDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkRampOutDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B530);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkRampOutDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1089B80);
	};

	// ArkCameraShake::ArkVerticalFrequencyProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkVerticalFrequencyProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkVerticalFrequencyProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkVerticalFrequencyProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkVerticalFrequencyProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B570);
	};

	// ArkCameraShake::ArkHorizontalFrequencyProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkHorizontalFrequencyProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHorizontalFrequencyProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkHorizontalFrequencyProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16C9E00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkHorizontalFrequencyProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C9E20);
	};

	// ArkCameraShake::ArkForceFeedbackProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkForceFeedbackProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkForceFeedbackProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkForceFeedbackProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C1AA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkForceFeedbackProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B590);
	};

	// ArkCameraShake::ArkAffectsForceFeedbackIntensityProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkAffectsForceFeedbackIntensityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAffectsForceFeedbackIntensityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake::ArkAffectsForceFeedbackIntensityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B5B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake::ArkAffectsForceFeedbackIntensityProperty* const _this, ArkReflectedObject* const _pObject)>(0x107B5D0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkCameraShake::ArkIDProperty>(0x2D21B00);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkCameraShake::ArkNameProperty>(0x2D21B20);
	string m_Name;
	static inline auto s_ArkChannelProperty = PreyGlobal<ArkCameraShake::ArkChannelProperty>(0x2D21B40);
	uint64_t m_Channel;
	static inline auto s_ArkInnerRadiusProperty = PreyGlobal<ArkCameraShake::ArkInnerRadiusProperty>(0x2D21B60);
	float m_InnerRadius;
	static inline auto s_ArkOuterRadiusProperty = PreyGlobal<ArkCameraShake::ArkOuterRadiusProperty>(0x2D21B80);
	float m_OuterRadius;
	static inline auto s_ArkUIHorizontalAmplitudeProperty = PreyGlobal<ArkCameraShake::ArkUIHorizontalAmplitudeProperty>(0x2D21BA0);
	float m_UIHorizontalAmplitude;
	static inline auto s_ArkUIVerticalAmplitudeProperty = PreyGlobal<ArkCameraShake::ArkUIVerticalAmplitudeProperty>(0x2D21BC0);
	float m_UIVerticalAmplitude;
	static inline auto s_ArkRampInDurationProperty = PreyGlobal<ArkCameraShake::ArkRampInDurationProperty>(0x2D21BE0);
	float m_RampInDuration;
	static inline auto s_ArkHoldDurationProperty = PreyGlobal<ArkCameraShake::ArkHoldDurationProperty>(0x2D21C00);
	float m_HoldDuration;
	static inline auto s_ArkRampOutDurationProperty = PreyGlobal<ArkCameraShake::ArkRampOutDurationProperty>(0x2D21C20);
	float m_RampOutDuration;
	static inline auto s_ArkVerticalFrequencyProperty = PreyGlobal<ArkCameraShake::ArkVerticalFrequencyProperty>(0x2D21C60);
	float m_VerticalFrequency;
	static inline auto s_ArkHorizontalFrequencyProperty = PreyGlobal<ArkCameraShake::ArkHorizontalFrequencyProperty>(0x2D21C40);
	float m_HorizontalFrequency;
	static inline auto s_ArkForceFeedbackProperty = PreyGlobal<ArkCameraShake::ArkForceFeedbackProperty>(0x2D21C80);
	string m_ForceFeedback;
	static inline auto s_ArkAffectsForceFeedbackIntensityProperty = PreyGlobal<ArkCameraShake::ArkAffectsForceFeedbackIntensityProperty>(0x2D21CA0);
	bool m_AffectsForceFeedbackIntensity;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual EArkCameraShakeType GetCameraShakeType() const;

#if 0
	ArkCameraShake();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetChannel(uint64_t _arg0_);
	const uint64_t& GetChannel() const;
	void SetInnerRadius(float _arg0_);
	const float& GetInnerRadius() const;
	void SetOuterRadius(float _arg0_);
	const float& GetOuterRadius() const;
	void SetUIHorizontalAmplitude(float _arg0_);
	const float& GetUIHorizontalAmplitude() const;
	void SetUIVerticalAmplitude(float _arg0_);
	const float& GetUIVerticalAmplitude() const;
	void SetRampInDuration(float _arg0_);
	const float& GetRampInDuration() const;
	void SetHoldDuration(float _arg0_);
	const float& GetHoldDuration() const;
	void SetRampOutDuration(float _arg0_);
	const float& GetRampOutDuration() const;
	void SetVerticalFrequency(float _arg0_);
	const float& GetVerticalFrequency() const;
	void SetHorizontalFrequency(float _arg0_);
	const float& GetHorizontalFrequency() const;
	void SetForceFeedback(string _arg0_);
	const string& GetForceFeedback() const;
	void SetAffectsForceFeedbackIntensity(bool _arg0_);
	const bool& GetAffectsForceFeedbackIntensity() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107BD80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107BF70);
	static inline auto FGetCameraShakeType = PreyFunction<EArkCameraShakeType(const ArkCameraShake* const _this)>(0x1CBB0B0);
};

// ArkCameraShake_Animated
// Header:  Prey/Ark/ArkCameraShake.h
class ArkCameraShake_Animated : public ArkCameraShake
{ // Size=96 (0x60)
public:
	// ArkCameraShake_Animated::ArkAnimationProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkAnimationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAnimationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake_Animated::ArkAnimationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12C1B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkCameraShake_Animated::ArkAnimationProperty* const _this, ArkReflectedObject* const _pObject)>(0x12C1BC0);
	};

	static inline auto s_ArkAnimationProperty = PreyGlobal<ArkCameraShake_Animated::ArkAnimationProperty>(0x2D21D00);
	string m_Animation;

	static ArkReflectedObject* Create() { return FCreate(); }
	virtual EArkCameraShakeType GetCameraShakeType() const;

#if 0
	static ArkClass* GetClass();
	void SetAnimation(string _arg0_);
	const string& GetAnimation() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107BE60);
	static inline auto FGetCameraShakeType = PreyFunction<EArkCameraShakeType(const ArkCameraShake_Animated* const _this)>(0x4FD7F0);
};

// ArkCameraShake_Procedural
// Header:  Prey/Ark/ArkCameraShake.h
class ArkCameraShake_Procedural : public ArkCameraShake
{ // Size=96 (0x60)
public:
	// ArkCameraShake_Procedural::ArkPitchAmplitudeProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkPitchAmplitudeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkPitchAmplitudeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake_Procedural::ArkPitchAmplitudeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B5F0);
	};

	// ArkCameraShake_Procedural::ArkYawAmplitudeProperty
	// Header:  Prey/Ark/ArkCameraShake.h
	class ArkYawAmplitudeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkYawAmplitudeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkCameraShake_Procedural::ArkYawAmplitudeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107B620);
	};

	static inline auto s_ArkPitchAmplitudeProperty = PreyGlobal<ArkCameraShake_Procedural::ArkPitchAmplitudeProperty>(0x2D21CC0);
	float m_PitchAmplitude;
	static inline auto s_ArkYawAmplitudeProperty = PreyGlobal<ArkCameraShake_Procedural::ArkYawAmplitudeProperty>(0x2D21CE0);
	float m_YawAmplitude;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual EArkCameraShakeType GetCameraShakeType() const;

#if 0
	ArkCameraShake_Procedural();
	void SetPitchAmplitude(float _arg0_);
	float GetPitchAmplitude() const;
	void SetYawAmplitude(float _arg0_);
	float GetYawAmplitude() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107BEF0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107C100);
	static inline auto FGetCameraShakeType = PreyFunction<EArkCameraShakeType(const ArkCameraShake_Procedural* const _this)>(0x1948930);
};
#endif // !MOONCRASH
