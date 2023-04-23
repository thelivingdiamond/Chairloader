#include <Preditor/Project/Project.h>
//
// Created by theli on 10/28/2022.
//

Project::Project(const fs::path& path, bool loadExisting)
{
	assert(fs::is_directory(path));
	m_ProjectPath = fs::absolute(path); // Absolute to not cause problems on workdir change
	m_ProjectName = m_ProjectPath.filename().u8string();
	ConstructPaths();

	if (loadExisting)
	{
		LoadProject();
	}
	else
	{
		SaveProject();
	}
}

void Project::SaveProject()
{
	// TODO: Serialize to XML
	std::ofstream file(m_ProjectFilePath);
	file << "lol\n";
}

void Project::ConstructPaths()
{
	m_ProjectFilePath = m_ProjectPath / PROJECT_FILE_NAME;
	m_ProjectRuntimePath = m_ProjectPath / RUNTIME_PATH;
	fs::create_directory(m_ProjectRuntimePath);
}

void Project::LoadProject()
{
	// TODO: Load from XML
}
