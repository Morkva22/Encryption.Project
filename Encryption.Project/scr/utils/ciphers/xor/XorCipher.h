#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#include "../Cipher.h"
#include "../../../lib/lib.h"

class XorCipher : public Cipher {
public:
    string encrypt(const string& text, const string& key) override;
    string decrypt(const string& text, const string& key) override;
    
private:
    void validateKey(const string& key) const;
    string process(const string& text, const string& key) const;
};

#endif