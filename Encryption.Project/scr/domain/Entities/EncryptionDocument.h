#ifndef ENCRYPTED_DOCUMENT_H
#define ENCRYPTED_DOCUMENT_H

#include "../../lib/lib.h"

class EncryptedDocument {
public:
    EncryptedDocument(const string& originalText,
                     const string& cipherType,
                     int key,
                     const string& encryptedText = "");
    
    string getOriginalText() const;
    string getEncryptedText() const;
    string getCipherType() const;
    int getKey() const;
    
    void setEncryptedText(const string& encrypted_text);

private:
    string originalText;
    string encryptedText;
    string cipherType;
    int key;
};

#endif 