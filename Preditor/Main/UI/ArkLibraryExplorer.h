#pragma once
#include <WindowManager/ManagedWindow.h>

class ArkClass;
class ArkReflectedObject;
class ArkGameDataManager;

namespace Main
{

class ArkLibraryExplorer : public ManagedWindow
{
public:
    ArkLibraryExplorer();
    ~ArkLibraryExplorer();

protected:
    // ManagedWindow
    virtual void ShowContents() override;

private:
    ArkGameDataManager* m_pMgr = nullptr;

    //! Shows a node for an object.
    void ShowObjectNode(const ArkClass* pClass, ArkReflectedObject* pObject, const char* name);
    void ShowObjectNode(const char* className, ArkReflectedObject* pObject, const char* name);
};

} // namespace Main
