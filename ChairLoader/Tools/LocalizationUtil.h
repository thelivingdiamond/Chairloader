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
    int m_CurrentTextItem = 0;
    int m_CurrentAudioItem = 0;
    const std::vector<const char*> items = {"English", "French", "Italian", "German", "Spanish", "Latin American Spanish", "Brazilian Portuguese", "Russian", "Polish", "Japanese", "Traditional Chinese", "Simplified Chinese"};
    const std::vector<const char*> items_internal = {"english", "french", "italian", "german", "spanish", "latin_american_spanish", "brazilian_portuguese", "russian", "polish", "japanese", "chineset", "chineses"};
};


#endif //CHAIRLOADER_LOCALIZATIONUTIL_H
