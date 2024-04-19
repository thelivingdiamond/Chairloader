//
// Created by theli on 12/26/2022.
//

#ifndef CHAIRLOADER_LOCALIZATIONUTIL_H
#define CHAIRLOADER_LOCALIZATIONUTIL_H


class LocalizationUtil {
public:
    LocalizationUtil();


    void InitGame();
    void drawMenu();
    void draw();
    bool m_bDraw = false;
private:
    //! Use default language. Don't change it on startup.
    static constexpr int DEFAULT_LANG_IDX = 0;

    int m_CurrentTextItem = 0; // 0 is special, 1+ - language id
    int m_CurrentAudioItem = 0; // 0 is special, 1+ - language id
    std::vector<const char*> items = {nullptr, "English", "French", "Italian", "German", "Spanish", "Latin American Spanish", "Brazilian Portuguese", "Russian", "Polish", "Japanese", "Traditional Chinese", "Simplified Chinese"};
    const std::vector<const char*> items_internal = {"default", "english", "french", "italian", "german", "spanish", "latin_american_spanish", "brazilian_portuguese", "russian", "polish", "japanese", "chineset", "chineses"};

    void SetLangCVar(const char* cvarName, int selectedItemIdx);
    void ShowLanguageComboBox(const char* label, const char* cvarName, int* pSelectedItemIdx);
};


#endif //CHAIRLOADER_LOCALIZATIONUTIL_H
