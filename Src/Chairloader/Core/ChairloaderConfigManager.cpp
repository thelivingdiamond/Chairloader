#include <Chairloader/IChairloaderDll.h>
#include "ChairloaderConfigManager.h"

#include "Config/ConfigNodeV1.h"


ChairloaderConfigManager::~ChairloaderConfigManager() {
	// save the files
	for (auto& modConfig : modConfigs) {
		ChairloaderConfigManager::saveModConfigFile(modConfig.first);
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

							auto node = ConfigNodeV1(parameter);
							// put text on imgui according to the type and value of the parameter
							auto value = node.GetValue();
							// convert the value to a string based on the type
							std::string valueText;
							if (!value) {
								valueText = "Error: Invalid Value";
							} else {
								switch (node.GetNodeType()) {
									case EConfigNodeType::String:
										valueText = std::get<std::string>(*value);
										break;
									case EConfigNodeType::Bool:
										valueText = std::to_string(std::get<bool>(*value));
										break;
									case EConfigNodeType::Int:
										valueText = std::to_string(std::get<int>(*value));
										break;
									case EConfigNodeType::Uint:
										valueText = std::to_string(std::get<unsigned int>(*value));
										break;
									case EConfigNodeType::Int64:
										valueText = std::to_string(std::get<int64_t>(*value));
										break;
									case EConfigNodeType::Uint64:
										valueText = std::to_string(std::get<uint64_t>(*value));
										break;
									case EConfigNodeType::Float:
										valueText = std::to_string(std::get<float>(*value));
										break;
									case EConfigNodeType::XmlNode:
										valueText = std::get<pugi::xml_node>(*value).name();
										break;
									default:
										valueText = "Error: Invalid Value";
										break;
								}
							}


							ImGui::PushID((entry.first + parameter.name()).c_str());

							static std::string popUpText;
							static bool selectedReadOnly;
							if(ImGui::Selectable(valueText.c_str(), selected == parameter, ImGuiSelectableFlags_SpanAllColumns)) {
								selected = parameter;

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
								switch (node.GetNodeType()) {
								case EConfigNodeType::String:
									ImGui::InputText("String Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterString);
									break;
								case EConfigNodeType::Bool:
									ImGui::InputText("Boolean Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterBool);
									break;
								case EConfigNodeType::Int:
									ImGui::InputText("Int Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case EConfigNodeType::Uint:
									ImGui::InputText("UInt Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case EConfigNodeType::Int64:
									ImGui::InputText("Int64 Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case EConfigNodeType::Uint64:
									ImGui::InputText("UInt64 Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterInt);
									break;
								case EConfigNodeType::Float:
									ImGui::InputText("Float Value", &popUpText, ImGuiInputTextFlags_CallbackCharFilter, filterFloat);
									break;
								case EConfigNodeType::XmlNode:
									ImGui::BeginDisabled();
									ImGui::InputText("XMLNode Value", &popUpText);
									ImGui::EndDisabled();
									break;
								case EConfigNodeType::Unknown:
									ImGui::InputText("Other Value", &popUpText);
									break;
								default:
									break;
								}
								if (selectedReadOnly)
									ImGui::BeginDisabled();
								ImGui::PushID((valueText + modName + selected.name() + "popup save button").c_str());
								if (ImGui::Button("Save To Config")) {
									node.GetXmlNode().text().set(popUpText.c_str());
									setConfigDirty(entry.first, true);
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

void ChairloaderConfigManager::setConfigDirty(std::string modName, bool bDirty) {
	if(modConfigsDirty.find(modName) != modConfigsDirty.end()) {
		modConfigsDirty.find(modName)->second = bDirty;
	}
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

ConfigNodeRef<IConfigNodeV1> ChairloaderConfigManager::getModConfig(std::string modName) {
	if (modConfigs.find(modName) != modConfigs.end()) {
		auto configFile = modConfigs.find(modName)->second;
		auto node = configFile->child(modName.c_str());
		return ConfigNodeRef<IConfigNodeV1>(std::make_unique<ConfigNodeV1>(node));
	}
	CryError("{}: config not found", modName);
	return ConfigNodeRef<IConfigNodeV1>(nullptr);
}

