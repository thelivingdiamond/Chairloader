// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/ArkModalDialogInGame.h>

struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/ArkModalDialogRepair.h
class ArkModalDialogRepair : public ArkModalDialogInGame // Id=801BA71 Size=232
{
public:
	int m_durability;
	
	virtual const char *GetTypeName() const;
	void SetDurability(int _durability) { FSetDurability(this,_durability); }
	virtual void SetContents() const;
	virtual void OnButtonPress(IUIElement *_pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual ~ArkModalDialogRepair();
	
#if 0
	static const char *GetTypeNameS();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkModalDialogRepair const *const _this)>(0x134AD90);
	static inline auto FSetDurability = PreyFunction<void(ArkModalDialogRepair *const _this, int _durability)>(0x134B0C0);
	static inline auto FSetContents = PreyFunction<void(ArkModalDialogRepair const *const _this)>(0x134AEB0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkModalDialogRepair *const _this, IUIElement *_pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x134ADA0);
};

