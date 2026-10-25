// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/ui/IUIEventSystemFactory.h
struct IUIEventSystemFactory // Id=801766F Size=16
{
	IUIEventSystemFactory *m_pNext;
#ifndef MOONCRASH
	static IUIEventSystemFactory *s_pFirst;
#else
	static inline auto s_pFirst = PreyGlobal<IUIEventSystemFactory*>(0x2D939B0);
#endif
#ifndef MOONCRASH
	static IUIEventSystemFactory *s_pLast;
#else
	static inline auto s_pLast = PreyGlobal<IUIEventSystemFactory*>(0x2D939B8);
#endif
	
	virtual ~IUIEventSystemFactory();
	virtual std::shared_ptr<IUIGameEventSystem> Create() = 0;
	
#if 0
	static IUIEventSystemFactory *GetFirst();
	IUIEventSystemFactory *GetNext() const;
#endif
};
