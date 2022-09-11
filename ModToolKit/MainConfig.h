#pragma once

class MainConfig
{
public:
	fs::path gamePath;

	void LoadFromXML(fs::path path);
	void SaveToXML(fs::path path);
};
