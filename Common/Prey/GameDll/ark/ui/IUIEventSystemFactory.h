// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IUIEventSystemFactory.h
struct IUIEventSystemFactory // Id=801766F Size=16
{
	IUIEventSystemFactory *m_pNext;
	static IUIEventSystemFactory *s_pFirst;
	static IUIEventSystemFactory *s_pLast;
	
	virtual ~IUIEventSystemFactory();
	virtual std::shared_ptr<IUIGameEventSystem> Create() = 0;
	
#if 0
	static IUIEventSystemFactory *GetFirst();
	IUIEventSystemFactory *GetNext() const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// IUIEventSystemFactory
// Header:  Prey/GameDll/ark/ui/IUIEventSystemFactory.h
struct IUIEventSystemFactory
{ // Size=16 (0x10)
	IUIEventSystemFactory* m_pNext;
	static inline auto s_pFirst = PreyGlobal<IUIEventSystemFactory*>(0x2D939B0);
	static inline auto s_pLast = PreyGlobal<IUIEventSystemFactory*>(0x2D939B8);

	virtual ~IUIEventSystemFactory();
	virtual std::shared_ptr<IUIGameEventSystem> Create() = 0;

#if 0
	IUIEventSystemFactory();
	static IUIEventSystemFactory* GetFirst();
	IUIEventSystemFactory* GetNext() const;
#endif
};
#endif // !MOONCRASH
