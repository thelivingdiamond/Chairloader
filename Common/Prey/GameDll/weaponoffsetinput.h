// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/IInput.h>
#include <Prey/GameDll/weaponoffset.h>

struct SInputEvent;

// Header: FromCpp
// Prey/GameDll/weaponoffsetinput.h
class CWeaponOffsetInput : public IInputEventListener // Id=8016D22 Size=80
{
public:
	enum Mode
	{
		EMode_None = 0,
		EMode_PositionOffset = 1,
		EMode_RotationOffset = 2,
		EMode_ZAxisOffset = 3,
	};

	enum Sensibility
	{
		ESensibility_Slow = 0,
		ESensibility_Medium = 1,
		ESensibility_Fast = 2,
	};

	enum Hand
	{
		EHand_Right = 0,
		EHand_Left = 1,
	};

	using TWeaponOffsetInput = std::shared_ptr<CWeaponOffsetInput>;
	
	SWeaponOffset m_debugRightOffset;
	SWeaponOffset m_debugLeftOffset;
	Vec2 m_offset;
	CWeaponOffsetInput::Mode m_mode;
	CWeaponOffsetInput::Sensibility m_sensibility;
	CWeaponOffsetInput::Hand m_hand;
	
	virtual void Update();
	virtual bool OnInputEvent(SInputEvent const &inputEvent);
	static std::shared_ptr<CWeaponOffsetInput> Get() { return FGet(); }
	void SetRightDebugOffset(SWeaponOffset const &offset) { FSetRightDebugOffset(this,offset); }
	void SetLeftDebugOffset(SWeaponOffset const &offset) { FSetLeftDebugOffset(this,offset); }
	void AddOffset(Vec3 pos, Ang3 ang) { FAddOffset(this,pos,ang); }
	virtual ~CWeaponOffsetInput();
	
#if 0
	void AddRightDebugOffset(SWeaponOffset const &arg0);
	SWeaponOffset GetRightDebugOffset() const;
	void AddLeftDebugOffset(SWeaponOffset const &arg0);
	SWeaponOffset GetLeftDebugOffset() const;
#endif
	
	static inline auto FUpdate = PreyFunction<void(CWeaponOffsetInput *const _this)>(0x1803210);
	static inline auto FOnInputEvent = PreyFunction<bool(CWeaponOffsetInput *const _this, SInputEvent const &inputEvent)>(0x18030D0);
	static inline auto FGet = PreyFunction<std::shared_ptr<CWeaponOffsetInput>()>(0x1803040);
	static inline auto FSetRightDebugOffset = PreyFunction<void(CWeaponOffsetInput *const _this, SWeaponOffset const &offset)>(0x18031F0);
	static inline auto FSetLeftDebugOffset = PreyFunction<void(CWeaponOffsetInput *const _this, SWeaponOffset const &offset)>(0x18031D0);
	static inline auto FAddOffset = PreyFunction<void(CWeaponOffsetInput *const _this, Vec3 pos, Ang3 ang)>(0x1802F30);
};

