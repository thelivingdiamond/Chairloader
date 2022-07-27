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

