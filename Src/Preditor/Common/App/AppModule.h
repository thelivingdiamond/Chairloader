//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_APPMODULE_H
#define CHAIRLOADER_APPMODULE_H


class AppModule {
public:
    AppModule();

    virtual ~AppModule();

    //! Called when the module is loaded
    virtual void Init();

    //! Updates the module. Called every frame.
    virtual void Update();

    //! Show's the module's UI. Called after Update.
    virtual void ShowUI();

    bool isInitialized() const { return bIsInitialized; }
    bool& isShown() { return bShowUI; }
    void setShown(bool show) { bShowUI = show; }

private:
    bool bIsInitialized = false;
    bool bShowUI = false;

    void updateInternal();

    friend class AppStage;
};


#endif //CHAIRLOADER_APPMODULE_H
