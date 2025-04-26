#pragma once
#include <boost/bimap.hpp>
#include <boost/variant.hpp>
#include "ConfigNode.h"

struct IChairloaderConfigManager {
    virtual ConfigNode getModConfig(std::string modName) = 0;

	virtual void setConfigDirty(std::string modName, bool bDirty) = 0;
    virtual bool getConfigDirty(std::string modName) = 0;


	// Returns the XML config file for a modName and stores it internally in the map
	// if the config is defined in Mods/config/ then it will return that file
	//    "Mods/config/modName.xml"
	// if the config is not found there, then it will check for the default config in the mod folder
	//    "Mods/modName/modName_default.xml"
	// Else, it will create a default file for you with only the root modName node. Good luck!
	//    "Mods/config/modName.xml"
	virtual bool loadModConfigFile(std::string modName) = 0;

	// saves the config file to disk for a modName
	virtual bool saveModConfigFile(std::string modName) = 0;

	// intialize mod configs

	// retrive config file path
	virtual fs::path getConfigPath(std::string modName) = 0;
	virtual fs::path getDefaultConfigPath(std::string modName) = 0;

};