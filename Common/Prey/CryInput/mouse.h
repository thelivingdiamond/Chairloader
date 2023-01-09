// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/DXInputDevice.h>

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

