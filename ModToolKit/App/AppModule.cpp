//
// Created by theli on 10/28/2022.
//

#include "AppModule.h"

AppModule::~AppModule() {

}

void AppModule::Init() {
}

void AppModule::Update() {
}

void AppModule::ShowUI() {
}

void AppModule::updateInternal() {
    if(!bIsInitialized) {
        Init();
        bIsInitialized = true;
    }

    Update();
}
