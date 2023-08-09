#include "Project/UserProjectSettings.h"

Main::UserProjectSettings::UserProjectSettings(const fs::path& path)
{
	m_FilePath = path;
	if (fs::exists(path))
		LoadFile();
}

Main::UserProjectSettings::~UserProjectSettings()
{
	// Save if need to
	Update();
}

void Main::UserProjectSettings::MarkDirty()
{
	if (!m_bDirty)
	{
		m_bDirty = true;
		m_NextSaveTime = std::chrono::steady_clock::now() + std::chrono::milliseconds(SAVE_DELAY_MS);
	}
}

void Main::UserProjectSettings::LoadFile()
{
	m_bDirty = false;
	m_Xml = pugi::xml_document();
	m_Xml.load_file(m_FilePath.c_str());

	pugi::xml_node node = m_Xml.child("UserProjectSettings");

	m_WindowRestPos.x = node.attribute("m_WindowRestPos_x").as_int(INVALID_SIZE);
	m_WindowRestPos.y = node.attribute("m_WindowRestPos_y").as_int(INVALID_SIZE);
	m_WindowRestSize.x = node.attribute("m_WindowRestSize_x").as_int(INVALID_SIZE);
	m_WindowRestSize.y = node.attribute("m_WindowRestSize_y").as_int(INVALID_SIZE);

	m_bWindowMaximized = node.attribute("m_bWindowMaximized").as_bool(false);
}

void Main::UserProjectSettings::SaveFile()
{
	m_bDirty = false;

	if (!m_Xml.child("UserProjectSettings"))
		m_Xml.append_child("UserProjectSettings");
	pugi::xml_node node = m_Xml.child("UserProjectSettings");

	EnsureAttribute(node, "m_WindowRestPos_x").set_value(m_WindowRestPos.x);
	EnsureAttribute(node, "m_WindowRestPos_y").set_value(m_WindowRestPos.y);
	EnsureAttribute(node, "m_WindowRestSize_x").set_value(m_WindowRestSize.x);
	EnsureAttribute(node, "m_WindowRestSize_y").set_value(m_WindowRestSize.y);

	EnsureAttribute(node, "m_bWindowMaximized").set_value(m_bWindowMaximized);

	std::ofstream file(m_FilePath);
	m_Xml.save(file);
}

void Main::UserProjectSettings::Update()
{
	if (m_bDirty && std::chrono::steady_clock::now() >= m_NextSaveTime)
	{
		SaveFile();
	}
}

void Main::UserProjectSettings::SetWindowRestoredPos(const Vec2i& val)
{
	UpdateValue(m_WindowRestPos, val);
}

void Main::UserProjectSettings::SetWindowRestoredSize(const Vec2i& val)
{
	UpdateValue(m_WindowRestSize, val);
}

void Main::UserProjectSettings::SetWindowMaximized(bool val)
{
	UpdateValue(m_bWindowMaximized, val);
}

pugi::xml_attribute Main::UserProjectSettings::EnsureAttribute(pugi::xml_node& node, const char* name)
{
	pugi::xml_attribute attr = node.attribute(name);
	if (attr)
		return attr;
	else
		return node.append_attribute(name);
}
