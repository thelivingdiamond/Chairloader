// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkCameraShakeChannel
// Header:  _unknown/ArkCameraShakeChannel.h
class ArkCameraShakeChannel : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkCameraShakeChannel::ArkIDProperty
	// Header:  _unknown/ArkCameraShakeChannel.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _arg0_, const IArkValueBase* _arg1_) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _arg0_) const;

	#if 0
		ArkIDProperty();
	#endif
	};

	// ArkCameraShakeChannel::ArkNameProperty
	// Header:  _unknown/ArkCameraShakeChannel.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _arg0_, const IArkValueBase* _arg1_) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _arg0_) const;

	#if 0
		ArkNameProperty();
	#endif
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkCameraShakeChannel::ArkIDProperty>(0x0);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkCameraShakeChannel::ArkNameProperty>(0x0);
	string m_Name;

#if 0
	static ArkReflectedObject* Create();
	static ArkClass* GetClass();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
#endif
};

