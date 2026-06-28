// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/dxinputdevice.h>

class CDXInput;
struct SInputSymbol;

// Header: FromCpp
// CryEngine/cryinput/mouse.h
class CMouse : public CDXInputDevice // Id=800D0AB Size=184
{
public:
	Vec2 m_deltas;
	Vec2 m_oldDeltas;
	Vec2 m_deltasInertia;
	float m_mouseWheel;
	static constexpr const int MAX_MOUSE_SYMBOLS = 15;
	static inline auto Symbol = PreyGlobal<SInputSymbol *[15]>(0x2767D70);
	
	CMouse(CDXInput &input);
	virtual int GetDeviceIndex() const;
	virtual bool Init();
	virtual void Update(bool bFocus);
	virtual bool SetExclusiveMode(bool value);
	void PostEvent(SInputSymbol *pSymbol) { FPostEvent(this,pSymbol); }
	void SmoothDeltas(float accel, float decel) { FSmoothDeltas(this,accel,decel); }
	virtual ~CMouse();
	
#if 0
	void PostOnlyIfChanged(SInputSymbol *arg0, EInputState arg1);
	void CapDeltas(float arg0);
#endif
	
	static inline auto FGetDeviceIndex = PreyFunction<int(CMouse const *const _this)>(0x158AEF0);
	static inline auto FInit = PreyFunction<bool(CMouse *const _this)>(0x9D3160);
	static inline auto FUpdate = PreyFunction<void(CMouse *const _this, bool bFocus)>(0x9D3820);
	static inline auto FSetExclusiveMode = PreyFunction<bool(CMouse *const _this, bool value)>(0x9D3580);
	static inline auto FPostEvent = PreyFunction<void(CMouse *const _this, SInputSymbol *pSymbol)>(0x9D34D0);
	static inline auto FSmoothDeltas = PreyFunction<void(CMouse *const _this, float accel, float decel)>(0x9D3630);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryInput/DXInputDevice.h>

class CDXInput;
enum EInputState;
struct SInputSymbol;

// CMouse
// Header:  CryEngine/cryinput/Mouse.h
// Include: Prey/CryInput/Mouse.h
class CMouse : public CDXInputDevice
{ // Size=184 (0xB8)
public:
	Vec2 m_deltas;
	Vec2 m_oldDeltas;
	Vec2 m_deltasInertia;
	float m_mouseWheel;
	static constexpr const int MAX_MOUSE_SYMBOLS = 15;
	static inline auto Symbol = PreyGlobal<SInputSymbol* [15]>(0x28D7000);

	CMouse(CDXInput& input);
	virtual int GetDeviceIndex() const;
	virtual bool Init();
	virtual void Update(bool bFocus);
	virtual bool SetExclusiveMode(bool value);
	void PostEvent(SInputSymbol* pSymbol) { FPostEvent(this, pSymbol); }
	void SmoothDeltas(float accel, float decel) { FSmoothDeltas(this, accel, decel); }

#if 0
	void PostOnlyIfChanged(SInputSymbol* _arg0_, EInputState _arg1_);
	void CapDeltas(float _arg0_);
#endif

	static inline auto FCMouseOv2 = PreyFunction<void(CMouse* const _this, CDXInput& input)>(0x9F0470);
	static inline auto FGetDeviceIndex = PreyFunction<int(const CMouse* const _this)>(0x1CBB0B0);
	static inline auto FInit = PreyFunction<bool(CMouse* const _this)>(0x9F04F0);
	static inline auto FUpdate = PreyFunction<void(CMouse* const _this, bool bFocus)>(0x9F0BB0);
	static inline auto FSetExclusiveMode = PreyFunction<bool(CMouse* const _this, bool value)>(0x9F0910);
	static inline auto FPostEvent = PreyFunction<void(CMouse* const _this, SInputSymbol* pSymbol)>(0x9F0860);
	static inline auto FSmoothDeltas = PreyFunction<void(CMouse* const _this, float accel, float decel)>(0x9F09C0);
};
#endif // !MOONCRASH
