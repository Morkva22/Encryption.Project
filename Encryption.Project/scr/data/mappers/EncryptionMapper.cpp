    #include "EncryptionMapper.h"

        EncryptionData EncryptionMapper::toDTO(const EncryptedDocument& doc) {
        return {
            doc.getOriginalText(),
            doc.getEncryptedText(),
            doc.getKey(),
            doc.getCipherType()
        };
    }

    EncryptedDocument EncryptionMapper::toDomain(const EncryptionData& dto) {
        return EncryptedDocument(
            dto.text,
            dto.cipherType,
            dto.key,
            dto.encryptedText
        );
    }

    string EncryptionMapper::toStorageString(const EncryptionData& dto) {
        ostringstream oss;
        oss << dto.text << "|" << dto.encryptedText << "|"
            << dto.key << "|" << dto.cipherType;
        return oss.str();
    }

    EncryptionData EncryptionMapper::fromStorageString(const string& raw) {
        istringstream iss(raw);
        EncryptionData dto;
        string token;

        getline(iss, dto.text, '|');
        getline(iss, dto.encryptedText, '|');
        getline(iss, token, '|');
        dto.key = stoi(token);
        getline(iss, dto.cipherType, '|');

        return dto;
    }