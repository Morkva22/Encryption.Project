#include "EncryptionDocument.h"

EncryptedDocument::EncryptedDocument(const string& originalText,
                                   const string& cipherType,
                                   int key,
                                   const string& encryptedText)
: originalText(originalText),
      encryptedText(encryptedText),
      cipherType(cipherType),
      key(key) {}

string EncryptedDocument::getOriginalText() const {
    return originalText;
}

string EncryptedDocument::getEncryptedText() const {
    return encryptedText;
}

string EncryptedDocument::getCipherType() const {
    return cipherType;
}

int EncryptedDocument::getKey() const {
    return key;
}

void EncryptedDocument::setEncryptedText(const string& encrypted_text) {
    this->encryptedText = encrypted_text;
}   