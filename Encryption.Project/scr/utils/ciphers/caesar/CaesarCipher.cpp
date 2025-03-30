#include "CaesarCipher.h"

int CaesarCipher::parseKey(const string& key) const {
    if (key.empty()) {
        throw invalid_argument("Caesar cipher key cannot be empty");
    }
    
    try {
        return stoi(key);
    } catch (const exception&) {
        throw invalid_argument("Caesar cipher key must be a valid integer");
    }
}

char CaesarCipher::shiftChar(char c, int shift) const {
    if (!isalpha(c)) {
        return c;
    }
    
    shift %= 26;
    if (shift < 0) {
        shift += 26;
    }
    
    char base = isupper(c) ? 'A' : 'a';
    return (c - base + shift) % 26 + base;
}

string CaesarCipher::encrypt(const string& text, const string& key) {
    int shift = parseKey(key);
    
    if (text.empty()) {
        return "";
    }

    string result;
    result.reserve(text.size());
    
    for (char c : text) {
        result += shiftChar(c, shift);
    }
    
    return result;
}

string CaesarCipher::decrypt(const string& text, const string& key) {
    int shift = parseKey(key);
    return encrypt(text, to_string(-shift)); 
}