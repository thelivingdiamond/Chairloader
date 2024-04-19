//
// Created by theli on 10/30/2022.
//

#include <boost/algorithm/string/predicate.hpp>
#include "LookingGlass.h"
#include "ImGui/imgui_stdlib.h"
#include "Preditor.h"
static LookingGlass* m_pLookingGlass = nullptr;

pugi::xml_node noCaseChild(pugi::xml_node& node, std::string name) {
    for(auto &child : node.children()){
        if(boost::iequals(child.name(), name)){
            return child;
        }
    }
    return {};
}

LookingGlass::LookingGlass() {
    m_pLookingGlass = this;
}

LookingGlass::~LookingGlass() {
    m_pLookingGlass = nullptr;
}

void LookingGlass::Init() {
    fs::path policyPath = gPreditor->pConfig->GetPreditorRoot() / "Preditor/LookingGlassReferenceLibrary.xml";
    m_PolicyDocument.load_file(policyPath.c_str());
    m_PolicyNode = m_PolicyDocument.first_child();
    AppModule::Init();
}

void LookingGlass::Update() {
    AppModule::Update();
}

void LookingGlass::ShowUI() {
    static std::string search = "Ark\\SignalSystem\\Signals.xml";
    static LookingGlassFilePolicy policy;
    static ImGuiTextFilter filter;

    if(ImGui::Begin("Looking Glass")){
        if(ImGui::InputText("Search", &search)){
            policy = getPolicyForFile(search);
        }
        ImGui::Text("Policy: %s", policy.bValid ? "Valid" : "Invalid");
        if(policy.bValid){
            ImGui::Text("Relative Path: %s", policy.m_RelativePath.string().c_str());
            ImGui::Text("Node Structure: %s", policy.m_NodeStructure.name());
        }
        if(ImGui::Button("Load References")){
            loadReferences();
        }
        static std::string testString;
        ImGui::LookingGlassInputText("Test", &testString);
        ImGui::Text("Context");
        ImGui::RadioButton("None", (int*)&m_Context, (int)LookingGlassContext::None); ImGui::SameLine();
        ImGui::RadioButton("Level", (int*)&m_Context, (int)LookingGlassContext::Level); ImGui::SameLine();
        ImGui::RadioButton("Global", (int*)&m_Context, (int)LookingGlassContext::Global);
        auto pContextStr =  m_ContextPath.u8string();
        if(ImGui::InputText("Context Path", &pContextStr)){
            m_ContextPath = pContextStr;
        }
        ImGui::RadioButton("Default", (int*)&m_Mode, (int)LookingGlassMode::Default); ImGui::SameLine();
        ImGui::RadioButton("ID", (int*)&m_Mode, (int)LookingGlassMode::ID); ImGui::SameLine();
        ImGui::RadioButton("Name", (int*)&m_Mode, (int)LookingGlassMode::Name);
        if(ImGui::CollapsingHeader("References")) {
            filter.Draw();
            ImGui::Text("References: %llu", m_References.size());
            bool empty = std::string(filter.InputBuf).empty();
            for (auto &reference: m_References) {
                if (empty) {
                    ImGui::Text("%s: %llu", reference->getName().c_str(), reference->getId32());
                } else if (filter.PassFilter(reference->getName().c_str())) {
                    ImGui::Text("%s: %llu", reference->getName().c_str(), reference->getId32());
                }
            }
        }
    }

    ImGui::End();
    AppModule::ShowUI();
}
LookingGlass *LookingGlass::Get() {
    return m_pLookingGlass;
}

void LookingGlass::addXMLReference(XMLReference reference) {
    m_References.push_back(std::make_shared<XMLReference>(reference));
    if(!reference.getName().empty()) {
        m_ReferencesByName[reference.getName()].push_back(m_References.back());
    }
    if(reference.getId32() != 0) {
        m_ReferencesByID[reference.getId32()].push_back(m_References.back());
    }
    if(reference.getGuid64() != 0) {
        if(!m_GUIDReferencesByContext[reference.getPath()].insert({reference.getGuid64(), m_References.back()}).second){
            CryError("Duplicate GUID64: %llu btwn %s(%s) and %s(%s)", reference.getGuid64(), reference.getName().c_str(), reference.getPath().u8string().c_str(), m_ReferencesByGUID64[reference.getGuid64()]->getName().c_str(), m_ReferencesByGUID64[reference.getGuid64()]->getPath().u8string().c_str());
            if(reference.getPath() == m_ReferencesByGUID64[reference.getGuid64()]->getPath()) {
                CryWarning("Duplicate in same file WHAT THE FUCK");
            }
        }

    }

    m_ReferencesByGUID128[reference.getGuid128()] = m_References.back();
    m_ReferencesByPath[reference.getPath()].push_back(m_References.back());
}

LookingGlass::LookingGlassFilePolicy LookingGlass::getPolicyForFile(fs::path relativePath) {
    LookingGlassFilePolicy policy;
    auto currentNode = m_PolicyNode;
    fs::path currentPath;
    for (auto &directory : relativePath){
        if(!fs::exists(gPreditor->pConfig->GetPreyFiles() / currentPath / directory)){
            break;
        }
        currentPath /= directory;
        currentNode = noCaseChild(currentNode, directory.u8string());
        if(!currentNode){
            continue;
        } else {
            if(currentNode.child("nodeStructure")){
                policy.m_NodeStructure = currentNode.child("nodeStructure");
                policy.bValid = true;
                policy.m_RelativePath = currentPath;
            }
        }
    }
    return policy;
}

void LookingGlass::loadReferencesFromFile(fs::path path) {
    auto policy = getPolicyForFile(path);
    if(!policy.bValid){
        return;
    }
    pugi::xml_document document;
    document.load_file((gPreditor->pConfig->GetPreyFiles() / path).string().c_str());
    collectReferences(document.first_child(), policy.m_NodeStructure.first_child(), path);

}

void LookingGlass::loadReferences() {
    recursiveReferenceLoad(gPreditor->pConfig->GetPreyFiles());
}

//Ark\AI\AiDistractors\ArkAutomaticDistractors.xml
//Ark\SignalSystem\Signals.xml
void LookingGlass::collectReferences(pugi::xml_node dataNode, pugi::xml_node structureNode, fs::path path) {
    if(!dataNode || !structureNode){
        return;
    }
    bool continueToChildrenIfMatched = false;
    if(structureNode.attribute("match_node").as_bool()){
        auto reference = getReferenceForNode(dataNode, structureNode);
        reference.setPath(path);
        addXMLReference(reference);
    }
    if(structureNode.attribute("match_children").as_bool()){
        for(auto& child : dataNode.children()){
            auto reference = getReferenceForNode(child, structureNode);
            reference.setPath(path);
            addXMLReference(reference);
        }
        if(!structureNode.attribute("continue").as_bool()){
            return;
        } else {
            //TODO: support merging children of merge children for objectives
//            pugi::xml_node childStructureNode;
//            for(auto& child : structureNode.child("Children").children()){
//                for(auto& dataChild : dataNode.children()){
//                    newStructureNode.set_name(dataChild.name());
//                    collectReferences(dataChild, newStructureNode, path);
//                }
//            }
        }
    }
    for(auto & node: structureNode){
        collectReferences(dataNode.child(node.name()), node, path);
    }
}

XMLReference LookingGlass::getReferenceForNode(pugi::xml_node dataNode, pugi::xml_node structureNode) {
    auto reference = XMLReference();
    std::string ID32attr, ID64attr, ID128attr, nameAttr;
    if(structureNode.child("ID32")){
        ID32attr = structureNode.child("ID32").attribute("attribute").as_string();
    }
    if(structureNode.child("GUID64")){
        ID64attr = structureNode.child("GUID64").attribute("attribute").as_string();
    }
    if(structureNode.child("GUID128")){
        ID128attr = structureNode.child("GUID128").attribute("attribute").as_string();
    }
    if(structureNode.child("Name")){
        nameAttr = structureNode.child("Name").attribute("attribute").as_string();
    }
    if(!ID32attr.empty()){
        reference.setId32(dataNode.attribute(ID32attr.c_str()).as_ullong());
    }
    if(!ID64attr.empty()){
        std::string guid = dataNode.attribute(ID64attr.c_str()).as_string();
        uint64_t guid64 = 0;
        try {
            guid64 = std::stoull(guid, nullptr, 16);
        } catch (std::invalid_argument &e) {
            guid64 = 0;
        } catch (std::out_of_range &e) {
            guid64 = 0;
        } catch (std::exception &e) {
            guid64 = 0;
        }
        reference.setGuid64(guid64);
    }
    if(!ID128attr.empty()){
        //TODO: 128 bit GUIDs
    }
    if(!nameAttr.empty()){
        reference.setName(dataNode.attribute(nameAttr.c_str()).as_string());
    }
    return reference;
}

void LookingGlass::recursiveReferenceLoad(fs::path path) {
    if(fs::is_directory(path)){
        for(auto& entry : fs::directory_iterator(path)){
            recursiveReferenceLoad(entry.path());
        }
    } else if (path.filename().extension() == ".xml"){
        fs::path relativePath = fs::relative(path, gPreditor->pConfig->GetPreyFiles());
        loadReferencesFromFile(relativePath);
    }
}

bool ImGui::LookingGlassInputText(const char *label, std::string *str, ImGuiInputTextFlags flags,
                                  ImGuiInputTextCallback callback, void *user_data) {
    std::vector<std::shared_ptr<XMLReference>>* references = nullptr;
    references = LookingGlass::Get()->getReferences(*str);
    std::shared_ptr<XMLReference> GUIDReference = nullptr;
    bool stringMatch = (references != nullptr);
    bool IDMatch = false, GUIDMatch = false;
    bool match = false;
    assert(str != nullptr);
    uint64_t id, guid;
    try{
        id = std::stoull(*str);
        auto idReferences = LookingGlass::Get()->getReferences(id);
        if(idReferences) {
            if (!references) {
                references = idReferences;
            } else {
                for(auto& reference : *idReferences){
                    references->push_back(reference);
                }
            }
        }
        IDMatch = (idReferences != nullptr);
    } catch(std::invalid_argument& e){
        IDMatch = false;
    } catch(std::out_of_range& e){
        IDMatch = false;
    } catch(std::exception& e){
        IDMatch = false;
    }
    // GUID
    try {
        guid = std::stoull(*str, nullptr, 16);
        GUIDReference = LookingGlass::Get()->getReferenceFromCurrentContext(guid);
        GUIDMatch = (GUIDReference != nullptr);
    } catch(std::invalid_argument& e){
        GUIDMatch = false;
    } catch(std::out_of_range& e){
        GUIDMatch = false;
    } catch(std::exception& e){
        GUIDMatch = false;
    }
    match = stringMatch || IDMatch || GUIDMatch;
    bool inputReturn;
    if(match) {

        // todo: add looking glass features like automatic replacement of id with name
        if (LookingGlass::Get()->getMode() == LookingGlass::LookingGlassMode::Default) {
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
            inputReturn = ImGui::InputText(label, str, flags, callback, user_data);
            ImGui::PopStyleColor();
        } else if (LookingGlass::Get()->getMode() == LookingGlass::LookingGlassMode::Name) {
            if (GUIDMatch) {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 0.8f));
                auto referenceString = GUIDReference->getName();
                inputReturn = ImGui::InputText(label, &referenceString, flags & ImGuiInputTextFlags_ReadOnly, callback, user_data);
                ImGui::PopStyleColor();
            } else if (IDMatch && references->size() == 1) {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 0.8f));
                auto referenceString = references->at(0)->getName();
                inputReturn = ImGui::InputText(label, &referenceString, flags & ImGuiInputTextFlags_ReadOnly, callback, user_data);
                ImGui::PopStyleColor();
            } else {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.8f, 0.8f, 0.2f, 1.0f));
                inputReturn = ImGui::InputText(label, str, flags, callback, user_data);
                ImGui::PopStyleColor();
            }
        } else if (LookingGlass::Get()->getMode() == LookingGlass::LookingGlassMode::ID) {
            if (stringMatch && references->size() == 1) {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 0.8f));
                auto referenceString = std::to_string(references->at(0)->getId32());
                inputReturn = ImGui::InputText(label, &referenceString, flags & ImGuiInputTextFlags_ReadOnly, callback, user_data);
                ImGui::PopStyleColor();
            } else {
                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.8f, 0.8f, 0.2f, 1.0f));
                inputReturn = ImGui::InputText(label, str, flags, callback, user_data);
                ImGui::PopStyleColor();
            }
        } else {
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.8f, 0.8f, 0.2f, 1.0f));
            inputReturn = ImGui::InputText(label, str, flags, callback, user_data);
            ImGui::PopStyleColor();
        }
    } else {
        inputReturn = ImGui::InputText(label, str, flags, callback, user_data);
    }
//    if(ImGui::IsItemClicked(ImGuiMouseButton_Right)){
//        ImGui::OpenPopup();
//    }
    ImGui::OpenPopupOnItemClick((std::string("##lookingGlassPopup") + "##" + label).c_str());
    if(ImGui::IsItemHovered() && match){
        ImGui::BeginTooltip();
        if(stringMatch){
            ImGui::Text("String match");
            ImGui::Separator();
            if(ImGui::BeginTable("##stringMatchTable", 1, ImGuiTableFlags_SizingFixedFit)){
                int i = 0;
                for(auto& reference : *references){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    if(i >= 20){
                        ImGui::Text("...");
                        break;
                    }
                    ImGui::Text("%llu", reference->getId32());
                    i++;
                }
                ImGui::EndTable();
            }

        }
        else if (GUIDMatch){
            ImGui::Text("GUID match");
            ImGui::Separator();
            ImGui::Text("%s", GUIDReference->getName().c_str());
        }
        else if(IDMatch){
            ImGui::Text("ID match");
            ImGui::Separator();
            if(ImGui::BeginTable("##idMatchTable", 1, ImGuiTableFlags_SizingFixedFit)){
                int i = 0;
                for(auto& reference : *references){
                    ImGui::TableNextRow();
                    ImGui::TableNextColumn();
                    if(i >= 20){
                        ImGui::Text("...");
                        break;
                    }
                    ImGui::Text("%s", reference->getName().c_str());
                    i++;
                }
                ImGui::EndTable();
            }
        }
        ImGui::EndTooltip();
    }
    if(ImGui::BeginPopup((std::string("##lookingGlassPopup") + "##" + label).c_str())){
        ImGui::Text("Looking Glass");
        if(ImGui::BeginTable("##lookingGlassTable", 2, ImGuiTableFlags_SizingFixedFit)){
            if(stringMatch){
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("String match");
                ImGui::TableNextColumn();
                ImGui::Text("%llu", references->size());
                for(auto& reference : *references){
                    if(reference->getName() == *str) {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("%s", reference->getName().c_str());
                        ImGui::TableNextColumn();
                        ImGui::Text("%llu", reference->getId32());
                    }
                }
            }
            if(IDMatch){
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("ID match");
                ImGui::TableNextColumn();
                ImGui::Text("%llu", references->size());
                for(auto& reference : *references){
                    if(reference->getId32() == id) {
                        ImGui::TableNextRow();
                        ImGui::TableNextColumn();
                        ImGui::Text("%s", reference->getName().c_str());
                        ImGui::TableNextColumn();
                        ImGui::Text("%llu", reference->getId32());
                    }
                }
            }
            if(GUIDMatch){
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("GUID match");
                ImGui::TableNextColumn();
                ImGui::Text("%s", GUIDReference->getName().c_str());
            }
            ImGui::EndTable();
        }
        ImGui::EndPopup();
    }
    return inputReturn;
}
