#pragma once
#include <Preditor/Main/IPreditor.h>

struct IChairloaderToolsPreditor;

namespace Main
{

class PreditorUI;

class Preditor : public IPreditor
{
public:
    Preditor();
    ~Preditor();
    
    // IPreditor
    virtual void InitSystem() override;
    virtual void InitGame() override;
    virtual void ShutdownGame() override;
    virtual void ShutdownSystem() override;
    virtual void Update() override;
    virtual void ShowUI() override;

private:
    std::unique_ptr<IChairloaderToolsPreditor> m_pChairTools;
    std::unique_ptr<PreditorUI> m_pUI;
};

} // namespace
