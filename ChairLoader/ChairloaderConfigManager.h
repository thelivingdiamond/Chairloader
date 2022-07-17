#pragma once
#include "ChairloaderGUILog.h"
#include <fstream>
#include <pugixml.hpp>
#include <boost/bimap.hpp>
#include <boost/variant.hpp>

class ChairloaderConfigManager {
private:
	pugi::xml_document configFile;
	const std::string configFilePath = "chairloader.xml";
	bool loadConfigFile();
	bool saveConfigFile();
	bool configDirty, configLoaded;
	void addModConfig(std::string modName);
	const char* rootNode = "config";
	const std::string modName = "Chairloader.ConfigManager";
public:
	enum class  parameterType {
		String,
		Bool,
		Int,
		Uint,
		Int64,
		Uint64,
		Float,
		XMLNode,
		Other
	};
	using ConfigParameterPair = boost::bimap<parameterType, std::string>::value_type ;
	boost::bimap<parameterType, std::string> parameterNameMap;
	using ConfigParameter = boost::variant<std::string, bool, int, unsigned int, int64, uint64, float>;
	ChairloaderConfigManager();
	~ChairloaderConfigManager();
	void Draw(bool* bShow);
	void Update();
	bool getConfig(std::string modName, pugi::xml_node* node);
	void writeConfig(std::string modName, pugi::xml_node* node);
	ConfigParameter ParseXmlTextToParameter(pugi::xml_text value);
	ConfigParameter getConfigValue(std::string modName, std::string parameterName);
	void setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type);
	bool config_dirty() const { return configDirty; }
	bool config_loaded() const { return configLoaded; }
};

