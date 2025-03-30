#ifndef ENCRYPT_USE_CASE_H
#define ENCRYPT_USE_CASE_H

#include "../../../lib/lib.h"
#include "../../../Utils/Ciphers/Cipher.h"

class EncryptUseCase {
public:
    void registerCipher(const string& name, shared_ptr<Cipher> cipher);
    string execute(const string& text, const string& cipherType, int key);

private:
    map<string, shared_ptr<Cipher>> ciphers;
};

#endif 