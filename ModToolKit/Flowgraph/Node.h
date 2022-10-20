#pragma once
#include "pch.h"
#include "Pin.h"
#include "UniqueID.h"
#include "ImGui/imgui.h"
#include "ImNodes/imnodes.h"
#include <IconsMaterialDesign.h>
#include "IChairFlowgraph.h"
#include <pugixml.hpp>

struct PrototypeNode{
    enum class nodeCategory {
        NONE,
        CHAIRLOADER_CUSTOM,
        COMMENT,
        AI,
        ACTOR,
        ANIMATIONS,
        ARK,
        ARK_PLAYER,
        AUDIO,
        CAMERA,
        CUSTOM_ACTION,
        DEBUG,
        EFFECTS,
        ENGINE,
        ENTITY,
        ENVIRONMENT,
        GAME,
        IMAGE,
        INPUT,
        INTERPOL,
        INVENTORY,
        LOGIC,
        MATERIAL,
        MATERIALFX,
        MATH,
        MISSION,
        MODULE,
        MOVEMENT,
        MULTIPLAYER,
        PHYSICS,
        PLAYER_PROFILE,
        PREFAB,
        STEREO,
        STRING,
        TIME,
        UI,
        VEC3,
        VIDEO,
        XML,
        COUNT,
    };
    using NodeClass = std::string;
    std::string Description;
    std::vector<PrototypePin> ProtoInputs;
    std::vector<PrototypePin> ProtoOutputs;
    NodeClass Class;
    nodeCategory Category = nodeCategory::NONE;
    unsigned mFlags;

    // used to determine if the node has entity inputs
    bool m_bEntity_Node = false, m_bDefault_Entity_node;

    // == operator based on Class
    bool operator==(const PrototypeNode& other) const
    {
        return Class == other.Class;
    }
    // == operator based on std::string
    bool operator==(const std::string& other) const
    {
        return Class == other;
    }
    void setCategory();
};

struct Node : public PrototypeNode
{
    int64_t ID;
    std::string Name;
    IChairFlowgraph* ParentFlowgraph;

    ImVec2 Pos;

    std::vector<Pin> Inputs;
    std::vector<Pin> Outputs;

    std::string comment;

    bool PosSet = false;

    using inputName = std::string;
    using inputValue = std::string;
    std::map<inputName, inputValue> defaultInputs;
    pugi::xml_node xmlNode;

    bool isHovered;


    std::string entityGUID, entityGUID64;


    void SetCategoryColor();
    void ClearCategoryColor();
    Node() = default;
    // add a constructor to intialize from a PrototypeNode

    Node(std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id, IChairFlowgraph* flowgraph)
            : Name(name), Pos(pos), ParentFlowgraph(flowgraph) {
        ID = id;
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        mFlags = proto.mFlags;
        m_bEntity_Node = proto.m_bEntity_Node;
        ProtoInputs = proto.ProtoInputs;
        ProtoOutputs = proto.ProtoOutputs;
        Class = proto.Class;
        Category = proto.Category;
        Description = proto.Description;
    }
    Node(std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id, std::map<std::string, std::string> &defaultInputs, IChairFlowgraph* flowgraph)
            : Name(name), Pos(pos), ParentFlowgraph(flowgraph) {
        ID = id;
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        mFlags = proto.mFlags;
        m_bEntity_Node = proto.m_bEntity_Node;
        ProtoInputs = proto.ProtoInputs;
        ProtoOutputs = proto.ProtoOutputs;
        Category = proto.Category;
        Class = proto.Class;
        Description = proto.Description;
        this->defaultInputs = defaultInputs;
    }
    //! OPERATORS
    // == operator
    bool operator==(const Node& other) const
    {
        return ID == other.ID;
    }
    // != operator
    bool operator!=(const Node& other) const
    {
        return ID != other.ID;
    }
    // < operator
    bool operator<(const Node& other) const
    {
        return  ID < other.ID;
    }
    // > operator
    bool operator>(const Node& other) const
    {
        return ID > other.ID;
    }
    // <= operator
    bool operator<=(const Node& other) const
    {
        return ID <= other.ID;
    }
    // >= operator
    bool operator>=(const Node& other) const
    {
        return ID >= other.ID;
    }
    // operator that returns true if the id is not zero
    operator bool() const { return ID != 0; }

    void initializePins(){
        Inputs.clear();
        Outputs.clear();
        if(m_bEntity_Node){
            Pin entityPin;
            entityPin.Name = "entityId";
            entityPin.HumanName = "Entity ID";
            entityPin.Description = "An inherent entity ID specified by the xml file";
            entityPin.Kind = PinKind::Input;
//            entityPin.sUIConfig = "";
            entityPin.Type = 0;
            entityPin.ID = ParentFlowgraph->GetUniqueID();
            entityPin.Parent_Node = this;
            entityPin.value = entityGUID64;
            Inputs.emplace_back(entityPin);

        }
        for(auto &pin : ProtoInputs) {
            Pin newPin(pin, this, ParentFlowgraph->GetUniqueID());
            if(defaultInputs.find(newPin.Name) != defaultInputs.end()){
                newPin.value = defaultInputs[newPin.Name];
            }
            Inputs.emplace_back(newPin);
        }
        for(auto &pin : ProtoOutputs) {
            Pin newPin(pin, this, ParentFlowgraph->GetUniqueID());
            Outputs.emplace_back(newPin);
        }
    }
    Pin* getPin(int64_t id){
        for(auto &pin : Inputs){
            if(pin.ID == id)
                return &pin;
        }
        for(auto &pin : Outputs) {
            if (pin.ID == id)
                return &pin;
        }
        return nullptr;
    }
    Pin* getPin(std::string name){
        for(auto &pin : Inputs){
            if(pin.Name == name)
                return &pin;
        }
        for(auto &pin : Outputs){
            if(pin.Name == name)
                return &pin;
        }
        return nullptr;
    }
    Pin* getInputPin(std::string name){
        for(auto &pin : Inputs){
            if(pin.Name == name)
                return &pin;
        }
        return nullptr;
    }
    Pin* getOutputPin(std::string name){
        for(auto &pin : Outputs){
            if(pin.Name == name)
                return &pin;
        }
        return nullptr;
    }
    virtual void draw();

    static inline std::map<nodeCategory, ImColor> CategoryColors {
            {nodeCategory::CHAIRLOADER_CUSTOM, ImColor::HSV(0.0f,0.9f, 0.6f)},
            {nodeCategory::AI, ImColor::HSV(0.025f,0.9f, 0.6f)},
            {nodeCategory::ACTOR, ImColor::HSV(0.05f,0.9f, 0.6f)},
            {nodeCategory::ANIMATIONS, ImColor::HSV(0.075f,0.9f, 0.6f)},
            {nodeCategory::ARK, ImColor::HSV(0.1f,0.9f, 0.6f)},
            {nodeCategory::ARK_PLAYER, ImColor::HSV(0.125f,0.9f, 0.6f)},
            {nodeCategory::AUDIO, ImColor::HSV(0.15f,0.9f, 0.6f)},
            {nodeCategory::CAMERA, ImColor::HSV(0.175f,0.9f, 0.6f)},
            {nodeCategory::CUSTOM_ACTION, ImColor::HSV(0.2f,0.9f, 0.6f)},
            {nodeCategory::DEBUG, ImColor::HSV(0.225f,0.9f, 0.6f)},
            {nodeCategory::EFFECTS, ImColor::HSV(0.25f,0.9f, 0.6f)},
            {nodeCategory::ENGINE, ImColor::HSV(0.275f,0.9f, 0.6f)},
            {nodeCategory::ENTITY, ImColor::HSV(0.3f,0.9f, 0.6f)},
            {nodeCategory::ENVIRONMENT, ImColor::HSV(0.325f,0.9f, 0.6f)},
            {nodeCategory::GAME, ImColor::HSV(0.35f,0.9f, 0.6f)},
            {nodeCategory::IMAGE, ImColor::HSV(0.375f,0.9f, 0.6f)},
            {nodeCategory::INPUT, ImColor::HSV(0.4f,0.9f, 0.6f)},
            {nodeCategory::INTERPOL, ImColor::HSV(0.425f,0.9f, 0.6f)},
            {nodeCategory::INVENTORY, ImColor::HSV(0.45f,0.9f, 0.6f)},
            {nodeCategory::LOGIC, ImColor::HSV(0.475f,0.9f, 0.6f)},
            {nodeCategory::MATERIAL, ImColor::HSV(0.5f,0.9f, 0.6f)},
            {nodeCategory::MATERIALFX, ImColor::HSV(0.525f,0.9f, 0.6f)},
            {nodeCategory::MATH, ImColor::HSV(0.55f,0.9f, 0.6f)},
            {nodeCategory::MISSION, ImColor::HSV(0.575f,0.9f, 0.6f)},
            {nodeCategory::MODULE, ImColor::HSV(0.6f,0.9f, 0.6f)},
            {nodeCategory::MOVEMENT, ImColor::HSV(0.625f,0.9f, 0.6f)},
            {nodeCategory::MULTIPLAYER, ImColor::HSV(0.65f,0.9f, 0.6f)},
            {nodeCategory::PHYSICS, ImColor::HSV(0.675f,0.9f, 0.6f)},
            {nodeCategory::PLAYER_PROFILE, ImColor::HSV(0.7f,0.9f, 0.6f)},
            {nodeCategory::PREFAB, ImColor::HSV(0.725f,0.9f, 0.6f)},
            {nodeCategory::STEREO, ImColor::HSV(0.75f,0.9f, 0.6f)},
            {nodeCategory::STRING, ImColor::HSV(0.775f,0.9f, 0.6f)},
            {nodeCategory::TIME, ImColor::HSV(0.9f, 0.6f,0.8f)},
            {nodeCategory::UI, ImColor::HSV(0.825f,0.9f, 0.6f)},
            {nodeCategory::VEC3, ImColor::HSV(0.85f,0.9f, 0.6f)},
            {nodeCategory::VIDEO, ImColor::HSV(0.875f,0.9f, 0.6f)},
            {nodeCategory::XML, ImColor::HSV(0.9f,0.9f, 0.6f)},
            {nodeCategory::NONE, ImColor::HSV(0.925f,0.9f, 0.6f)},
            {nodeCategory::COMMENT, ImColor::HSV(0.95f,0.9f, 0.6f)},
    };

    static inline std::map<nodeCategory,const char *> CategoryIcons {
            {nodeCategory::CHAIRLOADER_CUSTOM, ICON_MD_SETTINGS},
            {nodeCategory::AI, ICON_MD_PSYCHOLOGY},
            {nodeCategory::ACTOR, ICON_MD_PERSON},
            {nodeCategory::ANIMATIONS, ICON_MD_THEATER_COMEDY},
            {nodeCategory::ARK, ICON_MD_STAR},
            {nodeCategory::ARK_PLAYER, ICON_MD_DIRECTIONS_RUN},
            {nodeCategory::AUDIO, ICON_MD_VOLUME_UP},
            {nodeCategory::CAMERA, ICON_MD_VIDEOCAM},
            {nodeCategory::CUSTOM_ACTION, ICON_MD_TUNE},
            {nodeCategory::DEBUG, ICON_MD_INFO_OUTLINE},
            {nodeCategory::EFFECTS, ICON_MD_GRAIN},
            {nodeCategory::ENGINE, ICON_MD_INTEGRATION_INSTRUCTIONS},
            {nodeCategory::ENTITY, ICON_MD_RECENT_ACTORS},
            {nodeCategory::ENVIRONMENT, ICON_MD_PUBLIC},
            {nodeCategory::GAME, ICON_MD_GAMES},
            {nodeCategory::IMAGE, ICON_MD_IMAGE},
            {nodeCategory::INPUT, ICON_MD_KEYBOARD},
            {nodeCategory::INTERPOL, ICON_MD_QUERY_STATS},
            {nodeCategory::INVENTORY, ICON_MD_INVENTORY},
            {nodeCategory::LOGIC, ICON_MD_DEVELOPER_BOARD},
            {nodeCategory::MATERIAL, ICON_MD_PANORAMA_PHOTOSPHERE},
            {nodeCategory::MATERIALFX, ICON_MD_PANORAMA_PHOTOSPHERE_SELECT},
            {nodeCategory::MATH, ICON_MD_CALCULATE},
            {nodeCategory::MISSION, ICON_MD_FORMAT_LIST_BULLETED},
            {nodeCategory::MODULE, ICON_MD_SPACE_DASHBOARD},
            {nodeCategory::MOVEMENT, ICON_MD_RUN_CIRCLE},
            {nodeCategory::MULTIPLAYER, ICON_MD_GROUP},
            {nodeCategory::PHYSICS, ICON_MD_SPORTS_BASKETBALL},
            {nodeCategory::PLAYER_PROFILE, ICON_MD_ACCOUNT_CIRCLE},
            {nodeCategory::PREFAB, ICON_MD_APARTMENT},
            {nodeCategory::STEREO, ICON_MD_SPEAKER},
            {nodeCategory::STRING, ICON_MD_PASSWORD},
            {nodeCategory::TIME, ICON_MD_SCHEDULE},
            {nodeCategory::UI, ICON_MD_CALL_TO_ACTION},
            {nodeCategory::VEC3, ICON_MD_CALL_TO_ACTION},
            {nodeCategory::VIDEO, ICON_MD_MOVIE},
            {nodeCategory::XML, ICON_MD_CODE},
            {nodeCategory::NONE, ICON_MD_CHECK_BOX_OUTLINE_BLANK},
            {nodeCategory::COMMENT, ICON_MD_COMMENT},
    };

    static inline std::map<nodeCategory,const char *> CategoryNames {
            {nodeCategory::CHAIRLOADER_CUSTOM, "Chairloader Custom"},
            {nodeCategory::AI, "AI"},
            {nodeCategory::ACTOR, "Actor"},
            {nodeCategory::ANIMATIONS, "Animations"},
            {nodeCategory::ARK, "Ark"},
            {nodeCategory::ARK_PLAYER, "Ark Player"},
            {nodeCategory::AUDIO, "Audio"},
            {nodeCategory::CAMERA, "Camera"},
            {nodeCategory::CUSTOM_ACTION, "Custom Action"},
            {nodeCategory::DEBUG, "Debug"},
            {nodeCategory::EFFECTS, "Effects"},
            {nodeCategory::ENGINE, "Engine"},
            {nodeCategory::ENTITY, "Entity"},
            {nodeCategory::ENVIRONMENT, "Environment"},
            {nodeCategory::GAME, "Game"},
            {nodeCategory::IMAGE, "Image"},
            {nodeCategory::INPUT, "Input"},
            {nodeCategory::INTERPOL, "Interpol"},
            {nodeCategory::INVENTORY, "Inventory"},
            {nodeCategory::LOGIC, "Logic"},
            {nodeCategory::MATERIAL, "Material"},
            {nodeCategory::MATERIALFX, "MaterialFX"},
            {nodeCategory::MATH, "Math"},
            {nodeCategory::MISSION, "Mission"},
            {nodeCategory::MODULE, "Module"},
            {nodeCategory::MOVEMENT, "Movement"},
            {nodeCategory::MULTIPLAYER, "Multiplayer"},
            {nodeCategory::PHYSICS, "Physics"},
            {nodeCategory::PLAYER_PROFILE, "Player Profile"},
            {nodeCategory::PREFAB, "Prefab"},
            {nodeCategory::STEREO, "Stereo"},
            {nodeCategory::STRING, "String"},
            {nodeCategory::TIME, "Time"},
            {nodeCategory::UI, "UI"},
            {nodeCategory::VEC3, "Vec3"},
            {nodeCategory::VIDEO, "Video"},
            {nodeCategory::XML, "XML"},
            {nodeCategory::NONE, "None"},
            {nodeCategory::COMMENT, "Comment"},
    };
    static ImColor GetCategoryColor(nodeCategory category);
};

//struct commentBox : public Node{
//    std::string comment;
//    float textSize;
//    ImVec4 textColor;
//    commentBox(std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id, std::string comment, float textsize = 1, ImVec4 textcolor = {1.0,1.0,1.0,1.0})
//            : Node(name, proto, pos, id), textSize(textsize), textColor(textcolor) {}
//    void draw() override;
//};