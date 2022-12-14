#include <WindowManager/ManagedWindow.h>
#include <WindowManager/WindowManager.h>

ManagedWindow::ManagedWindow()
{
	m_UniqueId = WindowManager::Get().NextUniqueId();
}

ManagedWindow::ManagedWindow(std::string_view title)
{
	SetTitle(title);
}

void ManagedWindow::SetTitle(std::string_view title)
{
	m_Title = title;
	UpdateFullTitle();
}

void ManagedWindow::SetPersistentID(std::string_view id)
{
	m_PersistentID = id;
	UpdateFullTitle();
}

void ManagedWindow::SetFlags(ImGuiWindowFlags flags)
{
	m_Flags = flags;
}

void ManagedWindow::SetCloseable(bool state)
{
	m_bCloseable = state;
}

void ManagedWindow::CloseWindow()
{
	m_bOpen = false;
}

bool ManagedWindow::UpdateWindow()
{
	if (m_bOpen)
	{
		assert(!m_PersistentID.empty() || (m_Flags & ImGuiWindowFlags_NoSavedSettings) != 0);

		if (m_bVisible)
		{
			PreUpdate();
			bool isVisible = ImGui::Begin(m_FullTitle.c_str(), m_bCloseable ? &m_bOpen : nullptr, m_Flags);
			Update(isVisible);
			if (isVisible)
				ShowContents();
			ImGui::End();
		}
		else
		{
			// Only update when invisible.
			Update(false);
		}
	}

	return m_bOpen;
}

void ManagedWindow::PreUpdate()
{

}

void ManagedWindow::Update(bool isVisible)
{

}

void ManagedWindow::UpdateFullTitle()
{
	if (m_PersistentID.empty())
		m_FullTitle = fmt::format("{}###Managed{}", m_Title, m_UniqueId);
	else
		m_FullTitle = fmt::format("{}###{}", m_Title, m_PersistentID);
}
