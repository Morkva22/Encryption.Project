#include "ConsoleUtils.h"

#ifdef _WIN32
#endif

void ConsoleUtils::initialize() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); 
#endif
}

void ConsoleUtils::showError(const string& message) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cerr << message << endl;
    SetConsoleTextAttribute(hConsole, 15); 
#else
    cerr << "\033[1;31m" << message << "\033[0m" << endl;
#endif
}