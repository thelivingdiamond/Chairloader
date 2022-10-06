#pragma once
#include "pch.h"
#include "Pin.h"
#include "UniqueID.h"
#include "ImGui/imgui.h"

struct PrototypeNode{
    using NodeClass = std::string;
    std::string Description;
    std::vector<PrototypePin> ProtoInputs;
    std::vector<PrototypePin> ProtoOutputs;
    NodeClass Class;
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
};

struct Node : public PrototypeNode
{
    int64_t ID;
    std::string Name;
    // white
    ImU32 Color = 0xFFFFFFFF;
    ImVec2 Pos;
    std::vector<Pin> Inputs;
    std::vector<Pin> Outputs;
    std::string State;
    std::string SavedState;
    bool PosSet = false;
    float outputWidestText = 0.0f;
    float inputWidestText = 0.0f;
    using inputName = std::string;
    using inputValue = std::string;
    std::map<inputName, inputValue> defaultInputs;
    bool isHovered;


    Node() = default;
    // add a constructor to intialize from a PrototypeNode
    Node( std::string name, PrototypeNode &proto, ImVec2 pos)
            : Name(name), Pos(pos) {
        ID = GetUniqueID();
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        ProtoInputs = proto.ProtoInputs;
        ProtoOutputs = proto.ProtoOutputs;
        //TODO: initialize inputs and outputs from proto
        Class = proto.Class;
        Description = proto.Description;
    }

    Node( std::string name, PrototypeNode &proto, ImVec2 pos, int64_t id)
            : Name(name), Pos(pos) {
        ID = id;
//        Inputs = proto.ProtoInputs;
//        Outputs = proto.ProtoOutputs;
        ProtoInputs = proto.ProtoInputs;
        ProtoOutputs = proto.ProtoOutputs;
        //TODO: initialize inputs and outputs from proto
        Class = proto.Class;
        Description = proto.Description;
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
        for(auto &pin : ProtoInputs) {
            Pin newPin(pin, this);
            auto textSize = ImGui::CalcTextSize((newPin.Name + " ->").c_str());
            if(textSize.x > inputWidestText)
                inputWidestText = textSize.x;
            if(defaultInputs.find(newPin.Name) != defaultInputs.end()){
                newPin.value = defaultInputs[newPin.Name];
            }
            Inputs.emplace_back(newPin);
        }
        for(auto &pin : ProtoOutputs) {
            Pin newPin(pin, this);
            auto textSize = ImGui::CalcTextSize((newPin.Name + " ->").c_str());
            if(textSize.x > outputWidestText)
                outputWidestText = textSize.x;
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
};