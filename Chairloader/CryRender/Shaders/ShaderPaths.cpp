#include <boost/algorithm/string.hpp>
#include "ShaderPaths.h"

class CCryPak;

namespace RenderDll::Shaders
{

static ShaderPaths g_ShaderPaths;

auto g_CCryPak_AdjustFileName = PreyFunction<const char* (CCryPak* const _this, const char* src, char* dst, unsigned nFlags)>(0xD6B9D0);
auto g_CCryPak_AdjustFileName_Hook = g_CCryPak_AdjustFileName.MakeHook();

const char* CCryPak_AdjustFileName_Hook(CCryPak* const _this, const char* src, char* dst, unsigned nFlags)
{
	if (!strnicmp(src, "Shaders/", 8))
	{
		char convSrc[ICryPak::g_nMaxPath];
		g_ShaderPaths.AdjustFileName(src, convSrc, nFlags);
		return g_CCryPak_AdjustFileName_Hook.InvokeOrig(_this, convSrc, dst, nFlags);
	}
	else
	{
		return g_CCryPak_AdjustFileName_Hook.InvokeOrig(_this, src, dst, nFlags);
	}
}

void FixUpPath(std::string& str)
{
	for (char& c : str)
	{
		if (c == '\\')
			c = '/';
		else if (c >= 'A' && c <= 'Z')
			c = (int)c - 'A' + 'a';
	}
}

} // namespace RenderDll::Shaders

RenderDll::Shaders::ShaderPaths& RenderDll::Shaders::ShaderPaths::Get()
{
	return g_ShaderPaths;
}

void RenderDll::Shaders::ShaderPaths::Init()
{
	g_CCryPak_AdjustFileName_Hook.SetHookFunc(&CCryPak_AdjustFileName_Hook);
}

bool RenderDll::Shaders::ShaderPaths::HasAnyFiles() const
{
	std::shared_lock lock(m_Mutex);
	return !m_FilePaths.empty();
}

void RenderDll::Shaders::ShaderPaths::AddShadersDir(const fs::path& path)
{
	std::scoped_lock lock(m_Mutex);
	m_ShaderDirs.push_back(path);
}

void RenderDll::Shaders::ShaderPaths::RefreshFileList()
{
	std::scoped_lock lock(m_Mutex);
	m_FilePaths.clear();

	for (const fs::path& shaderDir : m_ShaderDirs)
	{
		TraverseDir(shaderDir, "");
	}
}

void RenderDll::Shaders::ShaderPaths::AdjustFileName(const char* src, char dst[ICryPak::g_nMaxPath], unsigned nFlags) const
{
	std::shared_lock lock(m_Mutex);
	std::string stdsrc = src + 8; // strlen("Shaders/")
	FixUpPath(stdsrc);

	//if (strstr(src, "CommonZPass.cfi") || strstr(src, "commonzpass.cfi"))
	//	__debugbreak();

	auto it = m_FilePaths.find(stdsrc);
	if (it != m_FilePaths.end())
	{
		// Override the path
		cry_strcpy(dst, ICryPak::g_nMaxPath, it->second.c_str());
	}
	else
	{
		// Leave as is
		cry_strcpy(dst, ICryPak::g_nMaxPath, src);
	}
}

void RenderDll::Shaders::ShaderPaths::TraverseDir(const fs::path& dir, const std::string& prefix)
{
	for (const fs::directory_entry& entry : fs::directory_iterator(dir))
	{
		std::string name = entry.path().filename().string(); // CryPak uses ANSI
		FixUpPath(name);
		std::string localPath = prefix + name;

		if (entry.is_regular_file())
		{
			// Add full path to the map
			m_FilePaths[localPath] = entry.path().string();
		}
		else if (entry.is_directory())
		{
			// Recurse
			TraverseDir(entry.path(), localPath + "/");
		}
		else
		{
			CryWarning("ShaderPaths: unknown file type at path {}", entry.path().u8string());
		}
	}
}
