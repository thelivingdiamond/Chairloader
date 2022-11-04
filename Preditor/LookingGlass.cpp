//
// Created by theli on 10/30/2022.
//

#include "LookingGlass.h"
static LookingGlass* m_pLookingGlass = nullptr;

LookingGlass::LookingGlass() {
    m_pLookingGlass = this;
}

LookingGlass::~LookingGlass() {
    m_pLookingGlass = nullptr;
}

void LookingGlass::Init() {
    AppModule::Init();
}

void LookingGlass::Update() {
    AppModule::Update();
}

void LookingGlass::ShowUI() {
    AppModule::ShowUI();
}

LookingGlass *LookingGlass::Get() {
    return m_pLookingGlass;
}

void LookingGlass::addXMLReference(XMLReference& reference) {
    m_References.push_back(std::make_shared<XMLReference>(reference));
    m_ReferencesByName[reference.getName()] = m_References.back();
    m_ReferencesByID32[reference.getId32()] = m_References.back();
    m_ReferencesByID64[reference.getGuid64()] = m_References.back();
    m_ReferencesByID128[reference.getGuid128()] = m_References.back();
    m_ReferencesByPath[reference.getPath()].push_back(m_References.back());
}

