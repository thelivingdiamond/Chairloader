//
// Created by theli on 10/6/2022.
//
#pragma once
#include "pch.h"

static int64_t uniqueID = 0;
static int64_t GetUniqueID() {
    return uniqueID++;
}