//
// Created by theli on 1/6/2023.
//

#include "ChairGlobalModName.h"

static std::string ChairGlobalModName;

std::string& ChairGetGlobalModName() {
    return ChairGlobalModName;
}

void ChairSetGlobalModName(const std::string& name) {
    ChairGlobalModName = name;
}