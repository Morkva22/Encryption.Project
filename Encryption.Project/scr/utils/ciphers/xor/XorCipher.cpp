#include "XorCipher.h"

void XorCipher::validateKey(const string& key) const {
    if (key.empty()) {
        throw invalid_argument("XOR key cannot be empty");
    }
    
    if (all_of(key.begin(), key.end(), [](char c) { 
        return c == '\0' || c == ' '; 
    })) {
        throw invalid_argument("XOR key cannot consist of only spaces or null characters");
    }
}

string XorCipher::process(const string& text, const string& key) const {
    validateKey(key);
    
    if (text.empty()) {
        return "";
    }

    string result;
    result.reserve(text.size());
    
    for (size_t i = 0; i < text.size(); ++i) {
        char encryptedChar = text[i] ^ key[i % key.size()];
        
        if (encryptedChar != ' ' && (encryptedChar < 32 || encryptedChar > 126)) {
            throw runtime_error(
                "XOR operation produced non-printable character (code: " + 
                to_string(static_cast<int>(encryptedChar)) + ")");
        }
        
        result += encryptedChar;
    }
    
    return result;
}

string XorCipher::encrypt(const string& text, const string& key) {
    return process(text, key);
}

string XorCipher::decrypt(const string& text, const string& key) {
    return process(text, key);
}