#include "DecryptUseCase.h"

void DecryptUseCase::registerCipher(const string& name, shared_ptr<Cipher> cipher) {
    ciphers[name] = cipher;
}

string DecryptUseCase::execute(const string& encryptedText, const string& cipherType, int key) {
    auto it = ciphers.find(cipherType);
    if (it == ciphers.end()) {
        throw runtime_error("Unsupported cipher type: " + cipherType);
    }
    return it->second->decrypt(encryptedText, to_string(key));
}