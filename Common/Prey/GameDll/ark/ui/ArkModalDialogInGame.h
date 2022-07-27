// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/ArkModalDialogBase.h>

struct IUIElement;

// Header: Exact
// Prey/GameDll/ark/ui/ArkModalDialogInGame.h
class ArkModalDialogInGame : public ArkModalDialogBase // Id=801BA70 Size=224
{
public:
	virtual const char *GetTypeName() const;
	virtual IUIElement *GetUIElement() const;
	virtual const char *GetDialogClassName() const;
	virtual ~ArkModalDialogInGame();
	
#if 0
	static const char *GetTypeNameS();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkModalDialogInGame const *const _this)>(0x134AD80);
	static inline auto FGetUIElement = PreyFunction<IUIElement *(ArkModalDialogInGame const *const _this)>(0x1605260);
	static inline auto FGetDialogClassName = PreyFunction<const char *(ArkModalDialogInGame const *const _this)>(0x134AD80);
};

