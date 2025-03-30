#ifndef CIPHER_H
#define CIPHER_H

#include "../../lib/lib.h"

class Cipher {
public:
    virtual ~Cipher() = default;
    virtual string encrypt(const string& text, const string& key) = 0;
    virtual string decrypt(const string& text, const string& key) = 0;
};

#endif