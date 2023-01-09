//
// Created by theli on 10/28/2022.
//

#include "AppModule.h"
#include "AppStage.h"
#include "Application.h"

AppModule::~AppModule() {

}

void AppModule::Init() {
    bIsInitialized = true;
}

void AppModule::Update() {
}

void AppModule::ShowUI() {
}

void AppModule::updateInternal() {
}

AppModule::AppModule() {
    updateInternal();
}
