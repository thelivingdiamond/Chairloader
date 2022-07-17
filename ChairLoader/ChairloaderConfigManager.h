#pragma once
#include "ChairloaderGUILog.h"
#include <fstream>
#include <pugixml.hpp>
#include <filesystem>
#include <boost/bimap.hpp>
#include <boost/variant.hpp>

class ChairloaderConfigManager {
public:
	/* Protyotype configuration file
	 *
	 	<?xml version="1.0"?>
		<modName>
			<superImportantInformation type="string"></superImportantInformation>
			<NumberOfDecisions type="int">23</parameterName>
		</modName>
	 *
	 */

	// Enum for determining type of the parameter in a config parameter. Other will return the raw string.
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
	// Bimap for storing the parameter type and the corresponding string.
	using ConfigParameterPair = boost::bimap<parameterType, std::string>::value_type;
	boost::bimap<parameterType, std::string> parameterNameMap;
	using ConfigParameter = boost::variant<std::string, bool, int, unsigned int, int64, uint64, float, pugi::xml_node>;

	// store config files
	std::map<std::string, pugi::xml_document*> modConfigs;
	std::map<std::string, bool> modConfigsDirty;

	// Constructor and destructor
	ChairloaderConfigManager();
	~ChairloaderConfigManager();

	// Gui Element
	void Draw(bool* bShow);
	void Update();

	// retrieve the typed value of a parameter
	ConfigParameter ParseXmlTextToParameter(pugi::xml_node parameterNode);

	//TODO: change these to operate on mod specific configuration files
	// setting and getting configuration values
	ConfigParameter getConfigValue(std::string modName, std::string parameterName);
	bool setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type);


	// Returns the XML config file for a modName and stores it internally in the map
	// if the config is defined in Mods/config/ then it will return that file
	//    "Mods/config/modName.xml"
	// if the config is not found there, then it will check for the default config in the mod folder
	//    "Mods/modName/modName_default.xml"
	// Else, it will create a default file for you with only the root modName node. Good luck!
	//    "Mods/config/modName.xml"
	bool loadModConfigFile(std::string modName); 
	bool saveModConfigFile(std::string modName);
	bool copyDefaultModConfigFile(std::string modName);
	bool createDefaultModConfig(std::string modName); // someone was slacking so they don't get shit

	fs::path getConfigPath(std::string modName);
	fs::path getDefaultConfigPath(std::string modName);
	
	


	bool config_dirty() const { return configDirty; }
private:
	bool configDirty; // necessary?
	pugi::xml_document chairloaderConfigFile;
	const std::string chairloaderConfigFilePath = ".\\Mods\\config\\chairloader.xml";
	bool loadChairloaderConfigFile();
	bool saveChairloaderConfigFile();
	
	const char* rootNode = "config";
	const std::string modName = "Chairloader.ConfigManager";

};

