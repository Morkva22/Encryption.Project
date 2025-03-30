#include "KeyProvider.h"

using namespace std;

KeyProvider::KeyProvider(const string& filename) 
    : filename(filename) {}

void KeyProvider::saveKey(const string& cipherName, int key) {
    ofstream file(filename, ios::app);
    if (!file) {
        throw runtime_error("Failed to open key file for writing");
    }
    file << cipherName << ":" << key << "\n";
}

int KeyProvider::loadKey(const string& cipherName) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Failed to open key file for reading");
    }

    string line;
    while (getline(file, line)) {
        size_t delimiterPos = line.find(':');
        if (delimiterPos != string::npos) {
            string currentCipher = line.substr(0, delimiterPos);
            if (currentCipher == cipherName) {
                try {
                    return stoi(line.substr(delimiterPos + 1));
                } catch (...) {
                    throw runtime_error("Invalid key format in file");
                }
            }
        }
    }
    
    throw runtime_error("Key not found for cipher: " + cipherName);
}