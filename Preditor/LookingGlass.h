//
// Created by theli on 10/30/2022.
//

#ifndef CHAIRLOADER_LOOKINGGLASS_H
#define CHAIRLOADER_LOOKINGGLASS_H
#pragma once

#include "pch.h"
#include "App/AppModule.h"
#include "ImGui/imgui.h"
//#include "ImGui/imgui_stdlib.h"
#include "LookingGlass/XMLReference.h"

class LookingGlass : public AppModule {
public:
    LookingGlass();

    ~LookingGlass() override;

    void Init() override;

    void Update() override;
 
    void ShowUI() override;

    static LookingGlass* Get();

    void addXMLReference(XMLReference reference);

    enum class LookingGlassMode {
        Default,
        ID,
        Name,
        Error,
    };
    enum class LookingGlassContext {
        None,
        Global,
        Level,
        Error,
    };

    void setMode(LookingGlassMode mode){
        m_Mode = mode;
    }
    LookingGlassMode getMode(){
        return m_Mode;
    }
    void setContext(LookingGlassContext context){
        m_Context = context;
    }
    void setContextPath(fs::path path){
        m_ContextPath = path;
    }

    std::vector<std::shared_ptr<XMLReference>>& getReferences(){ return m_References; }

    std::vector<std::shared_ptr<XMLReference>>* getReferences(std::string& name){
        if(m_ReferencesByName.find(name) != m_ReferencesByName.end()){
            return &m_ReferencesByName[name];
        }
        return nullptr;
    }
    std::vector<std::shared_ptr<XMLReference>>* getReferences(uint64_t ID){
        if(m_ReferencesByID.find(ID) != m_ReferencesByID.end()){
            return &m_ReferencesByID[ID];
        }
        return nullptr;
    }
    std::shared_ptr<XMLReference> getReference(uint64_t GUID){
        if(m_ReferencesByGUID64.find(GUID) != m_ReferencesByGUID64.end()){
            return m_ReferencesByGUID64[GUID];
        }
        return nullptr;
    }
    std::shared_ptr<XMLReference> getReferenceFromCurrentContext(uint64_t GUID){
        if(m_GUIDReferencesByContext.find(m_ContextPath) != m_GUIDReferencesByContext.end()){
            if(m_GUIDReferencesByContext[m_ContextPath].find(GUID) != m_GUIDReferencesByContext[m_ContextPath].end()){
                return m_GUIDReferencesByContext[m_ContextPath][GUID];
            }
        }
        return nullptr;
    }
private:
    LookingGlassMode m_Mode = LookingGlassMode::Default;
    LookingGlassContext m_Context = LookingGlassContext::None;
    fs::path m_ContextPath;

    std::vector<std::shared_ptr<XMLReference>> m_References;
    std::map<uint64_t, std::vector<std::shared_ptr<XMLReference>>> m_ReferencesByID;
    std::map<std::string, std::vector<std::shared_ptr<XMLReference>>> m_ReferencesByName;
    std::map<fs::path, std::map<uint64_t, std::shared_ptr<XMLReference>>> m_GUIDReferencesByContext;
    std::map<uint64_t, std::shared_ptr<XMLReference>> m_ReferencesByGUID64;
    std::map<CryGUID, std::shared_ptr<XMLReference>> m_ReferencesByGUID128;
    std::map<fs::path, std::vector<std::shared_ptr<XMLReference>>> m_ReferencesByPath;

    struct LookingGlassFilePolicy {
        bool bValid = false;
        pugi::xml_node m_NodeStructure;
        fs::path m_RelativePath;
    };

    pugi::xml_document m_PolicyDocument;
    pugi::xml_node m_PolicyNode;
    LookingGlassFilePolicy getPolicyForFile(fs::path relativePath);
    void loadReferences();
    void recursiveReferenceLoad(fs::path path);
    XMLReference getReferenceForNode(pugi::xml_node dataNode, pugi::xml_node structureNode);
    void collectReferences(pugi::xml_node dataNode, pugi::xml_node structureNode, fs::path path);
    void loadReferencesFromFile(fs::path path);
};


#endif //CHAIRLOADER_LOOKINGGLASS_H


namespace ImGui {
    bool LookingGlassInputText(const char* label, std::string* str, ImGuiInputTextFlags flags = 0, ImGuiInputTextCallback callback = NULL, void* user_data = NULL);
}