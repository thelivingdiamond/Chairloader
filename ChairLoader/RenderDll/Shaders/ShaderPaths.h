#pragma once
#include <shared_mutex>

namespace RenderDll::Shaders
{

class ShaderPaths
{
public:
	static ShaderPaths& Get();

	void Init();

	//! Adds a directory to the list.
	//! @param	path	Path to Mods/mod.name/Shaders
	void AddShadersDir(const fs::path& path);

	//! Updates the list of all files. Call when files may have changed.
	void RefreshFileList();

	//! Converts the shader path.
	//! @param	src		Source path
	//! @param	dst		Output converted path
	//! @param	nFlags	File flags
	void AdjustFileName(const char* src, char dst[ICryPak::g_nMaxPath], unsigned nFlags) const;

private:
	mutable std::shared_mutex m_Mutex;
	std::vector<fs::path> m_ShaderDirs; //!< Paths to Mods/mod.name/Shaders
	std::unordered_map<std::string, std::string> m_FilePaths; //!< Map from file name after "Shaders/" to full path

	//! Recursively adds all files in a directory. Prefix must end with / unless it's root
	void TraverseDir(const fs::path& dir, const std::string& prefix);
};

} // namespace RenderDll::Shaders
