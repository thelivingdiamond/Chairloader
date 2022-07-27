// Header file automatically created from a PDB.

#pragma once

struct IEntity;

// Header: Override
// Prey/Ark/ArkAudioUtil.h
class ArkAudioControl // Id=80020DC Size=4
{
public:
	unsigned m_controlId;
	
#if 0
	bool IsValid() const;
	void Invalidate();
	unsigned GetId() const;
	void SetName(const char *arg0);
#endif
};

// Header: Override
// Prey/Ark/ArkAudioUtil.h
class ArkAudioTrigger : public ArkAudioControl // Id=80020DB Size=4
{
public:
	bool Load(const char *_pName) { return FLoad(this,_pName); }
	void Execute(IEntity *_pEntity) const { FExecute(this,_pEntity); }
	void Stop(IEntity *_pEntity) const { FStop(this,_pEntity); }
	
	static inline auto FLoad = PreyFunction<bool(ArkAudioTrigger *const _this, const char *_pName)>(0x12086D0);
	static inline auto FExecute = PreyFunction<void(ArkAudioTrigger const *const _this, IEntity *_pEntity)>(0x10B19B0);
	static inline auto FStop = PreyFunction<void(ArkAudioTrigger const *const _this, IEntity *_pEntity)>(0x1236480);
};

// Header: Override
// Prey/Ark/ArkAudioUtil.h
class ArkAudioRtpc : public ArkAudioControl // Id=8005A03 Size=4
{
public:
	void SetValue(float _value, IEntity *_pEntity) const { FSetValue(this,_value,_pEntity); }
	
#if 0
	bool Load(const char *arg0);
#endif
	
	static inline auto FSetValue = PreyFunction<void(ArkAudioRtpc const *const _this, float _value, IEntity *_pEntity)>(0x12402B0);
};

