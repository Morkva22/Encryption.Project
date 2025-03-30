#ifndef KEY_PROVIDER_H
#define KEY_PROVIDER_H

#include "../../../lib/lib.h"

class KeyProvider {
public:
    explicit KeyProvider(const string& filename);
    void saveKey(const string& cipherName, int key);
    int loadKey(const string& cipherName);

private:
    string filename;
};

#endif