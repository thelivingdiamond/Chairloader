#include <WindowManager/WindowManager.h>

WindowManager WindowManager::m_sInstance;

void WindowManager::AddWindow(WindowPtr window)
{
	m_Windows.push_back(std::move(window));
}

void WindowManager::Update()
{
	auto it = m_Windows.begin();

	while (it != m_Windows.end())
	{
		bool isOpen = (*it)->UpdateWindow();

		if (!isOpen)
		{
			// Remove the window and go to the next one
			it = m_Windows.erase(it);
		}
		else
		{
			// Go to the next window
			++it;
		}
	}
}

unsigned WindowManager::NextUniqueId()
{
	return m_NextUniqueId++;
}
