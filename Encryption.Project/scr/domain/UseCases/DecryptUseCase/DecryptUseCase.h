#ifndef DECRYPT_USE_CASE_H
#define DECRYPT_USE_CASE_H

#include "../../../lib/lib.h"
#include "../../../Utils/Ciphers/Cipher.h"

class DecryptUseCase {
public:
    void registerCipher(const string& name, shared_ptr<Cipher> cipher);
    string execute(const string& encryptedText, const string& cipherType, int key);

private:
    map<string, shared_ptr<Cipher>> ciphers;
};

#endif 