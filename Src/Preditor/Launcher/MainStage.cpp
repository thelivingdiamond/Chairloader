#include <Preditor/Main/IPreditor.h>
#include "MainStage.h"

void MainStage::Update()
{
    gPreditor->pMain->Update();
}

void MainStage::ShowUI(bool* bOpen)
{
    gPreditor->pMain->ShowUI();
}
