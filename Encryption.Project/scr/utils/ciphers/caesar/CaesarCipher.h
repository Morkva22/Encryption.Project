#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "../Cipher.h"
#include "../../..//lib/lib.h"

class CaesarCipher : public Cipher {
public:
    string encrypt(const string& text, const string& key) override;
    string decrypt(const string& text, const string& key) override;
    
private:
    int parseKey(const string& key) const;
    char shiftChar(char c, int shift) const;
};

#endif 