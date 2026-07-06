// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/ArkModalDialogInGame.h>

struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkModalDialogRepair
// Header:  Prey/GameDll/ark/ui/ArkModalDialogRepair.h
class ArkModalDialogRepair : public ArkModalDialogInGame
{ // Size=232 (0xE8)
public:
	int m_durability;

	virtual const char* GetTypeName() const;
	void SetDurability(int _durability) { FSetDurability(this, _durability); }
	virtual void SetContents() const;
	virtual void OnButtonPress(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);

#if 0
	static const char* GetTypeNameS();
	ArkModalDialogRepair();
#endif

	static inline auto FGetTypeName = PreyFunction<const char* (const IUIGameEventSystem* const _this)>(0x14291A0);
	static inline auto FSetDurability = PreyFunction<void(ArkModalDialogRepair* const _this, int _durability)>(0x14294D0);
	static inline auto FSetContents = PreyFunction<void(const ArkModalDialogRepair* const _this)>(0x14292C0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkModalDialogRepair* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14291B0);
};
#endif // !MOONCRASH
