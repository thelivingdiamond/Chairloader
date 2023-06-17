#pragma once
#include "Pin.h"
#include "UniqueID.h"
#include "ImGui/imgui.h"
#include "ImNodes/imnodes.h"
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
        UNKNOWN,
        COUNT,
    };
    using NodeClass = std::string;
    std::string Description;
    std::vector<PrototypePin> ProtoInputs;
    std::vector<PrototypePin> ProtoOutputs;
    NodeClass Class;
    nodeCategory Category = nodeCategory::NONE;
    unsigned mFlags = 0;

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

struct Node
{
    int64_t ID;
    std::string Name;
    std::shared_ptr<PrototypeNode> Proto;
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

    Node(std::string name, std::shared_ptr<PrototypeNode> proto, ImVec2 pos, int64_t id, IChairFlowgraph* flowgraph)
            : Name(name), Pos(pos), ParentFlowgraph(flowgraph) {
        ID = id;
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        Proto = proto;
//        mFlags = proto.mFlags;
//        m_bEntity_Node = proto.m_bEntity_Node;
//        ProtoInputs = proto.ProtoInputs;
//        ProtoOutputs = proto.ProtoOutputs;
//        Class = proto.Class;
//        Category = proto.Category;
//        Description = proto.Description;
    }
    Node(std::string name, std::shared_ptr<PrototypeNode> proto, ImVec2 pos, int64_t id, std::map<std::string, std::string> &defaultInputs, IChairFlowgraph* flowgraph)
            : Name(name), Pos(pos), ParentFlowgraph(flowgraph) {
        ID = id;
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        Proto = proto;
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
        if(Proto->m_bEntity_Node){
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
        for(auto &pin : Proto->ProtoInputs) {
            Pin newPin(pin, this, ParentFlowgraph->GetUniqueID());
            if(defaultInputs.find(newPin.Name) != defaultInputs.end()){
                newPin.value = defaultInputs[newPin.Name];
            }
            Inputs.emplace_back(newPin);
        }
        for(auto &pin : Proto->ProtoOutputs) {
            Pin newPin(pin, this, ParentFlowgraph->GetUniqueID());
            Outputs.emplace_back(newPin);
        }
    }

    void refreshPins(){
        // check through protoInputs and protoOutputs and see if any pins have been added or removed
        // iff a pin is not found in the current inputs or outputs, add it to the appropriate vector
        for(auto &pin : Proto->ProtoInputs) {
            bool found = false;
            for(auto &input : Inputs){
                if(input.Name == pin.Name){
                    found = true;
                    break;
                }
            }
            if(!found){
                Pin newPin(pin, this, ParentFlowgraph->GetUniqueID());
                Inputs.emplace_back(newPin);
                Inputs.back().Parent_Node = this;
                ParentFlowgraph->AddPin(newPin.ID, &Inputs.back());
            }
        }
        for(auto &pin : Proto->ProtoOutputs) {
            bool found = false;
            for(auto &output : Outputs) {
                if(output.Name == pin.Name){
                    found = true;
                    break;
                }
            }
            if(!found) {
                Pin newPin(pin, this, ParentFlowgraph->GetUniqueID());
                Outputs.emplace_back(newPin);
                Outputs.back().Parent_Node = this;
                ParentFlowgraph->AddPin(newPin.ID, &Outputs.back());
            }
        }
        for (auto &input : Inputs) {
            input.Parent_Node = this;
        }
        for (auto &output : Outputs) {
            output.Parent_Node = this;
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

    static inline std::map<PrototypeNode::nodeCategory, ImColor> CategoryColors {
            {PrototypeNode::nodeCategory::CHAIRLOADER_CUSTOM, ImColor::HSV(0.0f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::AI, ImColor::HSV(0.025f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::ACTOR, ImColor::HSV(0.05f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::ANIMATIONS, ImColor::HSV(0.075f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::ARK, ImColor::HSV(0.1f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::ARK_PLAYER, ImColor::HSV(0.125f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::AUDIO, ImColor::HSV(0.15f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::CAMERA, ImColor::HSV(0.175f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::CUSTOM_ACTION, ImColor::HSV(0.2f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::DEBUG, ImColor::HSV(0.225f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::EFFECTS, ImColor::HSV(0.25f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::ENGINE, ImColor::HSV(0.275f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::ENTITY, ImColor::HSV(0.3f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::ENVIRONMENT, ImColor::HSV(0.325f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::GAME, ImColor::HSV(0.35f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::IMAGE, ImColor::HSV(0.375f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::INPUT, ImColor::HSV(0.4f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::INTERPOL, ImColor::HSV(0.425f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::INVENTORY, ImColor::HSV(0.45f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::LOGIC, ImColor::HSV(0.475f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::MATERIAL, ImColor::HSV(0.5f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::MATERIALFX, ImColor::HSV(0.525f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::MATH, ImColor::HSV(0.55f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::MISSION, ImColor::HSV(0.575f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::MODULE, ImColor::HSV(0.6f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::MOVEMENT, ImColor::HSV(0.625f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::MULTIPLAYER, ImColor::HSV(0.65f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::PHYSICS, ImColor::HSV(0.675f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::PLAYER_PROFILE, ImColor::HSV(0.7f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::PREFAB, ImColor::HSV(0.725f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::STEREO, ImColor::HSV(0.75f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::STRING, ImColor::HSV(0.775f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::TIME, ImColor::HSV(0.9f, 0.6f,0.8f)},
            {PrototypeNode::nodeCategory::UI, ImColor::HSV(0.825f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::VEC3, ImColor::HSV(0.85f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::VIDEO, ImColor::HSV(0.875f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::XML, ImColor::HSV(0.9f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::NONE, ImColor::HSV(0.925f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::COMMENT, ImColor::HSV(0.95f,0.9f, 0.6f)},
            {PrototypeNode::nodeCategory::UNKNOWN, ImColor::HSV(0.0f,0.0f, 0.6f)},
    };

    static inline std::map<PrototypeNode::nodeCategory,const char *> CategoryIcons {
            {PrototypeNode::nodeCategory::CHAIRLOADER_CUSTOM, ICON_MD_SETTINGS},
            {PrototypeNode::nodeCategory::AI, ICON_MD_PSYCHOLOGY},
            {PrototypeNode::nodeCategory::ACTOR, ICON_MD_PERSON},
            {PrototypeNode::nodeCategory::ANIMATIONS, ICON_MD_THEATER_COMEDY},
            {PrototypeNode::nodeCategory::ARK, ICON_MD_STAR},
            {PrototypeNode::nodeCategory::ARK_PLAYER, ICON_MD_DIRECTIONS_RUN},
            {PrototypeNode::nodeCategory::AUDIO, ICON_MD_VOLUME_UP},
            {PrototypeNode::nodeCategory::CAMERA, ICON_MD_VIDEOCAM},
            {PrototypeNode::nodeCategory::CUSTOM_ACTION, ICON_MD_TUNE},
            {PrototypeNode::nodeCategory::DEBUG, ICON_MD_INFO_OUTLINE},
            {PrototypeNode::nodeCategory::EFFECTS, ICON_MD_GRAIN},
            {PrototypeNode::nodeCategory::ENGINE, ICON_MD_INTEGRATION_INSTRUCTIONS},
            {PrototypeNode::nodeCategory::ENTITY, ICON_MD_RECENT_ACTORS},
            {PrototypeNode::nodeCategory::ENVIRONMENT, ICON_MD_PUBLIC},
            {PrototypeNode::nodeCategory::GAME, ICON_MD_GAMES},
            {PrototypeNode::nodeCategory::IMAGE, ICON_MD_IMAGE},
            {PrototypeNode::nodeCategory::INPUT, ICON_MD_KEYBOARD},
            {PrototypeNode::nodeCategory::INTERPOL, ICON_MD_QUERY_STATS},
            {PrototypeNode::nodeCategory::INVENTORY, ICON_MD_INVENTORY},
            {PrototypeNode::nodeCategory::LOGIC, ICON_MD_DEVELOPER_BOARD},
            {PrototypeNode::nodeCategory::MATERIAL, ICON_MD_PANORAMA_PHOTOSPHERE},
            {PrototypeNode::nodeCategory::MATERIALFX, ICON_MD_PANORAMA_PHOTOSPHERE_SELECT},
            {PrototypeNode::nodeCategory::MATH, ICON_MD_CALCULATE},
            {PrototypeNode::nodeCategory::MISSION, ICON_MD_FORMAT_LIST_BULLETED},
            {PrototypeNode::nodeCategory::MODULE, ICON_MD_SPACE_DASHBOARD},
            {PrototypeNode::nodeCategory::MOVEMENT, ICON_MD_RUN_CIRCLE},
            {PrototypeNode::nodeCategory::MULTIPLAYER, ICON_MD_GROUP},
            {PrototypeNode::nodeCategory::PHYSICS, ICON_MD_SPORTS_BASKETBALL},
            {PrototypeNode::nodeCategory::PLAYER_PROFILE, ICON_MD_ACCOUNT_CIRCLE},
            {PrototypeNode::nodeCategory::PREFAB, ICON_MD_APARTMENT},
            {PrototypeNode::nodeCategory::STEREO, ICON_MD_SPEAKER},
            {PrototypeNode::nodeCategory::STRING, ICON_MD_PASSWORD},
            {PrototypeNode::nodeCategory::TIME, ICON_MD_SCHEDULE},
            {PrototypeNode::nodeCategory::UI, ICON_MD_CALL_TO_ACTION},
            {PrototypeNode::nodeCategory::VEC3, ICON_MD_CALL_TO_ACTION},
            {PrototypeNode::nodeCategory::VIDEO, ICON_MD_MOVIE},
            {PrototypeNode::nodeCategory::XML, ICON_MD_CODE},
            {PrototypeNode::nodeCategory::NONE, ICON_MD_CHECK_BOX_OUTLINE_BLANK},
            {PrototypeNode::nodeCategory::COMMENT, ICON_MD_COMMENT},
            {PrototypeNode::nodeCategory::UNKNOWN, ICON_MD_ERROR},
    };

    static inline std::map<PrototypeNode::nodeCategory,const char *> CategoryNames {
            {PrototypeNode::nodeCategory::CHAIRLOADER_CUSTOM, "Chairloader Custom"},
            {PrototypeNode::nodeCategory::AI, "AI"},
            {PrototypeNode::nodeCategory::ACTOR, "Actor"},
            {PrototypeNode::nodeCategory::ANIMATIONS, "Animations"},
            {PrototypeNode::nodeCategory::ARK, "Ark"},
            {PrototypeNode::nodeCategory::ARK_PLAYER, "Ark Player"},
            {PrototypeNode::nodeCategory::AUDIO, "Audio"},
            {PrototypeNode::nodeCategory::CAMERA, "Camera"},
            {PrototypeNode::nodeCategory::CUSTOM_ACTION, "Custom Action"},
            {PrototypeNode::nodeCategory::DEBUG, "Debug"},
            {PrototypeNode::nodeCategory::EFFECTS, "Effects"},
            {PrototypeNode::nodeCategory::ENGINE, "Engine"},
            {PrototypeNode::nodeCategory::ENTITY, "Entity"},
            {PrototypeNode::nodeCategory::ENVIRONMENT, "Environment"},
            {PrototypeNode::nodeCategory::GAME, "Game"},
            {PrototypeNode::nodeCategory::IMAGE, "Image"},
            {PrototypeNode::nodeCategory::INPUT, "Input"},
            {PrototypeNode::nodeCategory::INTERPOL, "Interpol"},
            {PrototypeNode::nodeCategory::INVENTORY, "Inventory"},
            {PrototypeNode::nodeCategory::LOGIC, "Logic"},
            {PrototypeNode::nodeCategory::MATERIAL, "Material"},
            {PrototypeNode::nodeCategory::MATERIALFX, "MaterialFX"},
            {PrototypeNode::nodeCategory::MATH, "Math"},
            {PrototypeNode::nodeCategory::MISSION, "Mission"},
            {PrototypeNode::nodeCategory::MODULE, "Module"},
            {PrototypeNode::nodeCategory::MOVEMENT, "Movement"},
            {PrototypeNode::nodeCategory::MULTIPLAYER, "Multiplayer"},
            {PrototypeNode::nodeCategory::PHYSICS, "Physics"},
            {PrototypeNode::nodeCategory::PLAYER_PROFILE, "Player Profile"},
            {PrototypeNode::nodeCategory::PREFAB, "Prefab"},
            {PrototypeNode::nodeCategory::STEREO, "Stereo"},
            {PrototypeNode::nodeCategory::STRING, "String"},
            {PrototypeNode::nodeCategory::TIME, "Time"},
            {PrototypeNode::nodeCategory::UI, "UI"},
            {PrototypeNode::nodeCategory::VEC3, "Vec3"},
            {PrototypeNode::nodeCategory::VIDEO, "Video"},
            {PrototypeNode::nodeCategory::XML, "XML"},
            {PrototypeNode::nodeCategory::NONE, "None"},
            {PrototypeNode::nodeCategory::COMMENT, "Comment"},
            {PrototypeNode::nodeCategory::UNKNOWN, "Unknown"},
    };
    static ImColor GetCategoryColor(PrototypeNode::nodeCategory category);
};

//struct commentBox : public Node{
//    std::string comment;
//    float textSize;
//    ImVec4 textColor;
//    commentBox(std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id, std::string comment, float textsize = 1, ImVec4 textcolor = {1.0,1.0,1.0,1.0})
//            : Node(name, proto, pos, id), textSize(textsize), textColor(textcolor) {}
//    void draw() override;
//};