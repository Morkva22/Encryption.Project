#ifndef VIEW_H
#define VIEW_H

#include "../../lib/lib.h"
#include "../../Infrastructure/Localization/Localization.h"

class View {
public:
    explicit View(shared_ptr<Localization> localization);
    
    void showMainMenu();
    int getUserChoice();
    string getInputText();
    int getEncryptionKey();
    string getCipherType();
    void showResult(const string& result);
    void showError(const string& message);
    void showLanguageMenu();
    void setLanguage(const string& language);

private:
    shared_ptr<Localization> localization;

#ifdef _WIN32
    void setConsoleColor(int color);
#else
    void setTextColor(const string& ansiCode);
#endif
    
    void resetConsoleColor();
};

#endif 