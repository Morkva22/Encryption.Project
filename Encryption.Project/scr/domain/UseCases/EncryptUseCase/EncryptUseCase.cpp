#include "EncryptUseCase.h"

void EncryptUseCase::registerCipher(const string& name, shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
}

string EncryptUseCase::execute(const string& text, const string& cipherType, int key) {
    auto it = ciphers.find(cipherType);
    if (it == ciphers.end()) {
        throw runtime_error("Unsupported cipher type: " + cipherType);
    }
    return it->second->encrypt(text, to_string(key));
}