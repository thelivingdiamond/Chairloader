// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/ArkModalDialogBase.h>

struct IUIElement;

// Header: Exact
// Prey/GameDll/ark/ui/ArkModalDialogMetaGame.h
class ArkModalDialogMetaGame : public ArkModalDialogBase // Id=801B6FA Size=224
{
public:
	virtual const char *GetTypeName() const;
	virtual IUIElement *GetUIElement() const;
	virtual const char *GetDialogClassName() const;
	virtual ~ArkModalDialogMetaGame();
	
#if 0
	static const char *GetTypeNameS();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkModalDialogMetaGame const *const _this)>(0x1605470);
	static inline auto FGetUIElement = PreyFunction<IUIElement *(ArkModalDialogMetaGame const *const _this)>(0x1605450);
	static inline auto FGetDialogClassName = PreyFunction<const char *(ArkModalDialogMetaGame const *const _this)>(0x1605470);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/ArkModalDialogBase.h>

struct IUIElement;

// ArkModalDialogMetaGame
// Header:  Prey/GameDll/ark/ui/ArkModalDialogMetaGame.h
class ArkModalDialogMetaGame : public ArkModalDialogBase
{ // Size=224 (0xE0)
public:
	virtual const char* GetTypeName() const;
	virtual IUIElement* GetUIElement() const;
	virtual const char* GetDialogClassName() const;

#if 0
	static const char* GetTypeNameS();
#endif

	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x17266B0);
	static inline auto FGetUIElement = PreyFunction<IUIElement* (const ArkModalDialogMetaGame* const _this)>(0x1726690);
	static inline auto FGetDialogClassName = PreyFunction<const char* (const ArkModalDialogMetaGame* const _this)>(0x17266B0);
};
#endif // !MOONCRASH
