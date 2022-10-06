#pragma once
#include "pch.h"
#include <ImGui/imgui.h>

struct Edge
{
    int64_t ID = 0;
    int64_t nodeOut = 0,
            nodeIn = 0;
    int64_t pinOut = 0,
            pinIn = 0;
    ImU32 Color = 0xFFFFFFFF;
    Edge() = default;
    Edge( int64_t id,  int64_t outPin, int64_t inPin, int64_t outNode, int64_t inNode)
            : ID(id), pinOut(outPin), pinIn(inPin), nodeOut(outNode), nodeIn(inNode) {}
};
