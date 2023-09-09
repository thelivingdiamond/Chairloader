#include <Chairloader/IChairloaderDll.h>
#include "ChairloaderConfigManager.h"

ChairloaderConfigManager::ChairloaderConfigManager() {

	parameterNameMap.insert(ConfigParameterPair(parameterType::String, "string"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Bool, "bool"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Int, "int"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Uint, "uint"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Int64, "int64"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Uint64, "uint64"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Float, "float"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::XMLNode, "xmlnode"));
	parameterNameMap.insert(ConfigParameterPair(parameterType::Other, "other"));
	//TODO: load mod configs (needs mod registration system)
	// something akin to for(list of mod names) {load mod config}
}
ChairloaderConfigManager::~ChairloaderConfigManager() {
	// save the files
	for (auto& modConfig : modConfigs) {
		saveModConfigFile(modConfig.first);
	}
}

int filterInt(ImGuiInputTextCallbackData * data) {
	if(data->EventFlag == ImGuiInputTextFlags_CallbackCharFilter) {
		if (data->EventChar < 512 && strchr("0123456789", (char)data->EventChar))
			return 0;
		return 1;
	}
	return 0;
}
int filterBool(ImGuiInputTextCallbackData* data) {
	if (data->EventFlag == ImGuiInputTextFlags_CallbackCharFilter) {
		if (data->EventChar < 512 && strchr("01", (char)data->EventChar))
			return 0;
		return 1;
	}
	return 0;
}

int filterFloat(ImGuiInputTextCallbackData* data) {
	if (data->EventFlag == ImGuiInputTextFlags_CallbackCharFilter) {
		if (data->EventChar < 512 && strchr("0123456789.", (char)data->EventChar))
			return 0;
		return 1;
	}
	return 0;
}

int filterString(ImGuiInputTextCallbackData* data) {
	if (data->EventFlag == ImGuiInputTextFlags_CallbackCharFilter) {
		if (data->EventChar < 512 && strchr("<>", (char)data->EventChar))
			return 1;
		return 0;
	}
	return 0;
}


void ChairloaderConfigManager::Draw(bool* bShow) {
	//TODO: figure out how to write to configs from menu (imgui limitation)
	if(ImGui::Begin("Config Menu", bShow)) {
		if (ImGui::BeginTabBar("configs")){
			static pugi::xml_node selected;
			for(auto & entry: modConfigs) {
				if(ImGui::BeginTabItem(entry.first.c_str())) {
					ImGui::Text("Config: %s", entry.first.c_str());
					if (ImGui::BeginTable(("ConfigTable" + entry.first).c_str(), 4, ImGuiTableFlags_SizingStretchProp | ImGuiTableFlags_Resizable | ImGuiTableFlags_Borders)) {
						// auto columnFlags = ImGuiTableColumnFlags;
						ImGui::TableSetupColumn("Parameter");
						ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("xmlnodesss ").x);
						ImGui::TableSetupColumn("Value");
						ImGui::TableSetupColumn("RO", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize(" RO ").x);
						ImGui::TableHeadersRow();
						for(auto& parameter: entry.second->child(entry.first.c_str())) {
							ImGui::TableNextRow();
							ImGui::TableSetColumnIndex(0);
							ImGui::Text("%s", parameter.name());
							ImGui::TableSetColumnIndex(1);
							ImGui::Text("%s", parameter.attribute("type").value());
							ImGui::TableSetColumnIndex(2);
							auto type = parameterNameMap.right.find((std::string) parameter.attribute("type").value())->second;
							auto value = ParseXmlTextToParameter(parameter);
							// put text on imgui according to the type and value of the parameter
							std::string valueText;
							switch (type) {
							case parameterType::String:
								valueText = boost::get<std::string>(value);
								break;
							case parameterType::Bool:
								valueText = std::to_string(boost::get<bool>(value));
								break;
							case parameterType::Int:
								valueText = std::to_string(boost::get<int>(value));
								break;
							case parameterType::Uint:
								valueText = std::to_string(boost::get<unsigned int>(value));
								break;
							case parameterType::Int64:
								valueText = std::to_string(boost::get<long long>(value));
								break;
							case parameterType::Uint64:
								valueText = std::to_string(boost::get<unsigned long long>(value));
								break;
							case parameterType::Float:
								valueText = std::to_string(boost::get<float>(value));
								break;
							case parameterType::XMLNode:
								valueText = boost::get<pugi::xml_node>(value).name();
								break;
							case parameterType::Other:
								valueText = boost::get<std::string>(value);
								break;
							default:
								break;
							}
							ImGui::PushID((entry.first + parameter.name()).c_str());
							static parameterType selectedType = parameterType::String;
							static std::string popUpText;
							static bool selectedReadOnly;
							if(ImGui::Selectable(valueText.c_str(), selected == parameter, ImGuiSelectableFlags_SpanAllColumns)) {
								selected = parameter;
								selectedType = type;
								if(parameter.attribute("readonly")) {
									selectedReadOnly = ((std::string)parameter.attribute("readonly").value() == std::string("1"));
								} else {
									selectedReadOnly = false;
								}
								ImGui::OpenPopup((valueText + modName + parameter.name() + "popup").c_str());
								popUpText = valueText;
							}
							if(ImGui::BeginPopup((valueText + modName + selected.name() + "popup").c_str())) {
								// oh boy here we go
								switch (type) {
								case parameterType::String:
									ImGui::InputText("String Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterString);
									break;
								case parameterType::Bool:
									ImGui::InputText("Boolean Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterBool);
									break;
								case parameterType::Int:
									ImGui::InputText("Int Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case parameterType::Uint:
									ImGui::InputText("UInt Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case parameterType::Int64:
									ImGui::InputText("Int64 Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case parameterType::Uint64:
									ImGui::InputText("UInt64 Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case parameterType::Float:
									ImGui::InputText("Float Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterFloat);
									break;
								case parameterType::XMLNode:
									ImGui::BeginDisabled();
									ImGui::InputText("XMLNode Value", &popUpText);
									ImGui::EndDisabled();
									break;
								case parameterType::Other:
									ImGui::InputText("Other Value", &popUpText);
									break;
								default:
									break;
								}
								if (selectedReadOnly)
									ImGui::BeginDisabled();
								ImGui::PushID((valueText + modName + selected.name() + "popup save button").c_str());
								if (ImGui::Button("Save To Config")) {
									setConfigValue(selected.parent().name(), selected.name(), popUpText, selectedType);
								}
								ImGui::PopID();
								if (selectedReadOnly)
									ImGui::EndDisabled();
								ImGui::EndPopup();
							}
							ImGui::PopID();
							ImGui::TableSetColumnIndex(3);
							if ((std::string)parameter.attribute("readonly").value() == std::string("1"))
								ImGui::Text("1");
						}
						ImGui::EndTable();
					}
					ImGui::EndTabItem();
				}
			}
			ImGui::EndTabBar();
		}
		// ImGui::Separator();
		// ConfigParameter daBoi;
		// daBoi = "yes";
		// daBoi = 2;
		// auto var = boost::get<int>(daBoi);
		// static std::string input = "In your mom";
//		if (ImGui::Button("Load Test Config File")) {
//			// loadConfigFile();
//			loadModConfigFile("ExampleMod");
//		}
		// if(ImGui::Button("Save Parameter 1")) {
		// 	setConfigValue("ExampleMod", "parameterName", "1", parameterType::Int);
		// }
		// ImGui::InputText("Config Save Location", &input);
		// if (ImGui::Button("Save Parameter 2")) {
		// 	setConfigValue("ExampleMod", "configSaveLocation", input.c_str(), parameterType::String);
		// }
		// if(ImGui::Button("Check filesystem shit")) {
		// 	if (fs::exists(getConfigPath("ExampleMod")))
		// 		CryLog("File exists yep");
		// 	else
		// 		CryLog("FUCK");
		// }
	}
	ImGui::End();
}


void ChairloaderConfigManager::Update() {
	for(auto &entry: modConfigsDirty) {
		if(entry.second) {
			saveModConfigFile(entry.first);
		}
	}

}

ChairloaderConfigManager::ConfigParameter ChairloaderConfigManager::ParseXmlTextToParameter(pugi::xml_node parameterNode) {
	std::string typeStr = parameterNode.attribute("type").value();
	// CryLog(typeStr.c_str());
	
	if (parameterNameMap.right.find(typeStr) != parameterNameMap.right.end()) {
		auto type = parameterNameMap.right.find(typeStr)->second;
		if (type == parameterType::String) {
			std::string val = parameterNode.text().as_string();
			return val;
		}
		else if (type == parameterType::Bool) {
			return parameterNode.text().as_bool();
		}
		else if (type == parameterType::Int) {
			return parameterNode.text().as_int();
		}
		else if (type == parameterType::Uint) {
			return parameterNode.text().as_uint();
		}
		else if (type == parameterType::Int64) {
			return parameterNode.text().as_llong();
		}
		else if (type == parameterType::Uint64) {
			return parameterNode.text().as_ullong();
		}
		else if (type == parameterType::Float) {
			return parameterNode.text().as_float();
		}
		else if (type == parameterType::XMLNode) {
			return parameterNode;
		}
		else if (type == parameterType::Other) {
			std::string val = parameterNode.text().as_string();
			return val;
		}
	}
	return boost::blank();
}



ChairloaderConfigManager::ConfigParameter ChairloaderConfigManager::getConfigValue(std::string modName, std::string parameterName) {
	if (modConfigs.find(modName) != modConfigs.end()) {
		auto configFile = modConfigs.find(modName)->second;
		if (configFile->child(modName.c_str()).child(parameterName.c_str())) {
			return ParseXmlTextToParameter(configFile->child(modName.c_str()).child(parameterName.c_str()));
		}
	}
	return boost::blank();
}

bool ChairloaderConfigManager::setConfigValue(std::string modName, std::string parameterName, std::string value, parameterType type) {
	if(modConfigs.find(modName) != modConfigs.end()) {
		auto configFile = modConfigs.find(modName)->second;
		auto modNode = configFile->child(modName.c_str());
		return setNodeConfigValue(modNode, parameterName, value, type);
	}
	CryError("{}: config not found", modName);
	return false;
}

pugi::xml_node ChairloaderConfigManager::getConfigNode(std::string modName) {
	if (modConfigs.find(modName) != modConfigs.end()) {
		auto configFile = modConfigs.find(modName)->second;
		auto node = configFile->child(modName.c_str());
		return node;
	}
	CryError("{}: config not found", modName);
	return pugi::xml_node();
}

ChairloaderConfigManager::ConfigParameter ChairloaderConfigManager::getNodeConfigValue(pugi::xml_node node, std::string parameterName) {
	if (node) {
		return ParseXmlTextToParameter(node.child(parameterName.c_str()));
	}
	return boost::blank();
}

void ChairloaderConfigManager::setConfigDirty(std::string modName, bool bDirty) {
	if(modConfigsDirty.find(modName) != modConfigsDirty.end()) {
		modConfigsDirty.find(modName)->second = bDirty;
	}
}

bool ChairloaderConfigManager::setNodeConfigValue(pugi::xml_node node, std::string parameterName, std::string value, parameterType type) {
	if (node) {
		auto parameterNode = node.child(parameterName.c_str());
		if (parameterNode) {
			parameterNode.text().set(value.c_str());
			parameterNode.attribute("type").set_value(parameterNameMap.left.find(type)->get_right().c_str());
		}
		else {
			node.append_child(parameterName.c_str()).text().set(value.c_str());
			node.child(parameterName.c_str()).append_attribute("type").set_value(parameterNameMap.left.find(type)->second.c_str());
		}
		setConfigDirty(node.name(), true);
		return true;
	}
	return false;
}


bool ChairloaderConfigManager::loadModConfigFile(std::string modName) {
	CRY_ASSERT(!modName.empty());
	fs::path configFilePath = getConfigPath(modName);
	fs::path defaultFilePath = getDefaultConfigPath(modName);



	pugi::xml_document* configFile;
	if(modConfigs.find(modName) != modConfigs.end()) {
		configFile = modConfigs.find(modName)->second;
		modConfigsDirty.find(modName)->second = false;
	} else {
		configFile = new pugi::xml_document;
		modConfigs.insert(std::pair{ modName, configFile});
		modConfigsDirty.insert(std::pair{ modName, false});
	}
	
	// load existing config file
	if (fs::exists(configFilePath)) {
		// continue on to load
	} else { // check for default config
		if(fs::exists(defaultFilePath)) {
			if (!copyDefaultModConfigFile(modName)) {
				CryError("{}: copying default mod config failed", modName);
				return false;
			}
		} else {
			// someone just gets the default config good luck and hope they handled null return values if they try and load
			if (!createDefaultModConfig(modName)) {
				CryError("{}: creating default mod config failed", modName);
				return false;
			}
		}
	}
	auto result = configFile->load_file(configFilePath.string().c_str());
	if (result.status == pugi::xml_parse_status::status_ok) {
		CryLog("{}: Config Loaded", modName);
		return true;
	}
	else {
		CryError("{}: Config Loading Failed, could not find config file at {} because {}", modName, configFilePath.string(), result.description());
		return false;
	}
}

bool ChairloaderConfigManager::saveModConfigFile(std::string modName) {
	if(modConfigs.find(modName) != modConfigs.end()) {
		modConfigsDirty.find(modName)->second = false;
		bool saved = modConfigs.find(modName)->second->save_file(getConfigPath(modName).string().c_str());
		if (saved)
			CryLog("{}: Config Saved", modName);
		else
			CryError("{}: Config Saving Failed", modName);
		return saved;
	}
	return false;
}

bool ChairloaderConfigManager::copyDefaultModConfigFile(std::string modName) {
	CryLog("{}: copying default mod config", modName);
	return fs::copy_file(getDefaultConfigPath(modName), getConfigPath(modName));
}

bool ChairloaderConfigManager::createDefaultModConfig(std::string modName) {
	CryWarning("{}: default not found, creating mod config", modName);
	pugi::xml_document newDocument;
	newDocument.append_child(modName.c_str());
	return newDocument.save_file(getConfigPath(modName).string().c_str());
}

fs::path ChairloaderConfigManager::getConfigPath(std::string modName) {
	return gChair->GetModsPath() / "config" / fs::u8path(modName + ".xml");
}

fs::path ChairloaderConfigManager::getDefaultConfigPath(std::string modName) {
	return gChair->GetModsPath() / fs::u8path(modName) / fs::u8path(modName + "_default.xml");
}

bool ChairloaderConfigManager::getConfigDirty(std::string modName) {
    if (modConfigsDirty.find(modName) != modConfigsDirty.end()) {
        return modConfigsDirty.find(modName)->second;
    }
    return false;
}

