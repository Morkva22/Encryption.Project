#ifndef LOCALIZATION_H
#define LOCALIZATION_H

#include "LocalizationInterface.h"
#include "../../Data/Parsers/JsonParser.h"
#include "../../lib/lib.h"
class Localization : public LocalizationInterface {
public:
    Localization(const string& basePath, const string& defaultLanguage);
    
    static shared_ptr<Localization> createWithFallback(
        const string& basePath,
        const string& preferredLang,
        const string& fallbackLang = "en"
    );
    
    void setLanguage(const string& language);
    string translate(const string& key) const override;

private:
    void loadTranslations(const string& language);
    string getlocalefilepath(const string& language) const;

    string basePath;
    unordered_map<std::string, string> translations;
    string currentLanguage;
    JsonParser parser;
};

#endif 