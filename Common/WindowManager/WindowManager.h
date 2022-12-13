#pragma once
#include <WindowManager/IManagedWindow.h>

//! Manages a number of windows (IManagedWindow).
//! Windows can have any titles, they use numeric IDs to prevent name conflicts.
//! Each window internally is stored as a shared pointer to IManagedWindow.
//! It's recommended to keep std::weak_ptrs to windows that can be closed by the user.
//! That way you'll know if the window was closed without keeping the window constructed.
class WindowManager
{
public:
	using WindowPtr = std::shared_ptr<IManagedWindow>;
	using WindowWeakPtr = std::shared_ptr<IManagedWindow>;

	//! @returns the singleton instance.
	static WindowManager& Get() { return m_sInstance; }

	//! Adds a window to the internal list.
	void AddWindow(WindowPtr window);

	//! Constructs a window of type T and adds it to the internal list.
	//! @tparam	T			Type of the window.
	//! @tparam	ArgTypes	Types of constructor parameters.
	template <typename T, typename ... ArgTypes>
	std::shared_ptr<T> Create(ArgTypes... args)
	{
		std::shared_ptr<T> ptr = std::make_shared<T>(args...);
		AddWindow(ptr);
		return ptr;
	}

	//! Updates and shows all windows.
	void Update();

	//! @returns a new Unique ID.
	unsigned NextUniqueId();

private:
	std::list<WindowPtr> m_Windows;
	unsigned m_NextUniqueId = 0;

	static WindowManager m_sInstance;
};
