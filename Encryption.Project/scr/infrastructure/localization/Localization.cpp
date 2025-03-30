#include "Localization.h"

void createDefaultLocaleFile(const string& filePath, const string& lang) {
    ofstream file(filePath);
    if (!file) {
        throw runtime_error("Failed to create locale file: " + filePath);
    }

    if (lang == "uk") {
        file << R"({
  "main_menu": "=== Головне меню ===",
  "encrypt_option": "1. Шифрування",
  "decrypt_option": "2. Дешифрування",
  "exit_option": "3. Вихід",
  "language_set": "Мову встановлено на українську"
})";
    } else { 
        file << R"({
  "main_menu": "=== Main Menu ===",
  "encrypt_option": "1. Encrypt",
  "decrypt_option": "2. Decrypt",
  "exit_option": "3. Exit",
  "language_set": "Language set to English"
})";
    }
}

Localization::Localization(const string& basePath, const string& defaultLanguage)
    : basePath(basePath) {
    setLanguage(defaultLanguage);
}

shared_ptr<Localization> Localization::createWithFallback(
    const string& basePath,
    const string& preferredLang,
    const string& fallbackLang)
{
    try {
        string prefPath = basePath + preferredLang + ".json";
        ifstream test(prefPath);
        if (!test) {
            cerr << "Creating default " << preferredLang << " locale file..." << endl;
            createDefaultLocaleFile(prefPath, preferredLang);
        }

        auto loc = make_shared<Localization>(basePath, preferredLang);
        cout << loc->translate("language_set") << endl;
        return loc;
    } catch (const exception& e) {
        cerr << "Error with preferred language: " << e.what() << endl;

        try {
            string fallbackPath = basePath + fallbackLang + ".json";
            ifstream test(fallbackPath);
            if (!test) {
                cerr << "Creating default " << fallbackLang << " locale file..." << endl;
                createDefaultLocaleFile(fallbackPath, fallbackLang);
            }

            auto loc = make_shared<Localization>(basePath, fallbackLang);
            cerr << "Using fallback language: " << fallbackLang << endl;
            return loc;
        } catch (const exception& e) {
            throw runtime_error("All localization attempts failed: " + string(e.what()));
        }
    }
}

void Localization::setLanguage(const string& language) {
    currentLanguage = language;
    loadTranslations(language);
}

void Localization::loadTranslations(const string& language) {
    string filePath = basePath + language + ".json";
    ifstream file(filePath);

    if (!file) {
        throw runtime_error("Cannot open locale file: " + filePath);
    }

    string content((istreambuf_iterator<char>(file)),
                     istreambuf_iterator<char>());

    try {
        translations = parser.parse(content);
    } catch (const exception& e) {
        throw runtime_error("Invalid JSON in " + filePath + ": " + e.what());
    }
}

string Localization::translate(const string& key) const {
    auto it = translations.find(key);
    return it != translations.end() ? it->second : "[" + key + "]";
}