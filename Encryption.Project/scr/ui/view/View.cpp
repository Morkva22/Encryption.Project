#include "View.h"

#ifdef _WIN32
#endif

View::View(shared_ptr<Localization> localization) 
    : localization(move(localization)) {}

#ifdef _WIN32
void View::setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
#else
void View::setTextColor(const string& ansiCode) {
    cout << ansiCode;
}
#endif

void View::resetConsoleColor() {
    #ifdef _WIN32
    setConsoleColor(15);
    #else
    cout << "\033[0m";
    #endif
}

void View::showMainMenu() {
    #ifdef _WIN32
    setConsoleColor(9);
    #else
    setTextColor("\033[1;34m");
    #endif
    
    cout << localization->translate("main_menu") << "\n";
    
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    cout << localization->translate("encrypt_option") << "\n"
              << localization->translate("decrypt_option") << "\n"
              << localization->translate("exit_option") << "\n";
    
    resetConsoleColor();
    cout << localization->translate("choose_option");
}

void View::showLanguageMenu() {
    #ifdef _WIN32
    setConsoleColor(9);
    #else
    setTextColor("\033[1;34m");
    #endif
    
    cout << "\n=== " << localization->translate("language_selection") << " ===\n";
    
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    cout << "1. English\n"
              << "2. Українська\n"
              << "3. Русский\n";
    
    resetConsoleColor();
    cout << localization->translate("select_language");
}

int View::getUserChoice() {
    int choice;
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore(10000, '\n');  
        showError(localization->translate("invalid_input"));
    }
    cin.ignore(10000, '\n');
    return choice;
}

string View::getInputText() {
    cout << localization->translate("enter_text");
    string text;
    getline(cin, text);
    return text;
}

int View::getEncryptionKey() {
    cout << localization->translate("enter_key");
    int key;
    while (!(cin >> key)) {
        cin.clear();
        cin.ignore(10000, '\n');
        showError(localization->translate("invalid_input"));
    }
    cin.ignore(10000, '\n');
    return key;
}

string View::getCipherType() {
    cout << localization->translate("choose_cipher");
    string type;
    cin >> type;
    cin.ignore(10000, '\n');

    if (type != "caesar" && type != "xor") {
        showError(localization->translate("invalid_cipher"));
        throw invalid_argument("Invalid cipher type");
    }
    return type;
}

void View::showResult(const string& result) {
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    cout << localization->translate("result") << result << "\n";
    resetConsoleColor();
}

void View::showError(const string& message) {
    #ifdef _WIN32
    setConsoleColor(12);
    #else
    setTextColor("\033[1;31m");
    #endif
    
    cerr << localization->translate("error") << message << "\n";
    resetConsoleColor();
}

void View::setLanguage(const string& language) {
    localization->setLanguage(language);
    
    #ifdef _WIN32
    setConsoleColor(10);
    #else
    setTextColor("\033[1;32m");
    #endif
    
    cout << localization->translate("language_set") << "\n";
    resetConsoleColor();
}