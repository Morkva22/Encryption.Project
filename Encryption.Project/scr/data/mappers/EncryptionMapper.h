#ifndef _ENCRYPTIONMAPPER_H
#define _ENCRYPTIONMAPPER_H

#include "../../domain/Entities/EncryptionDocument.h"
#include "../../lib/lib.h"
#include "../DTO/EncryptionData.h"
class EncryptionMapper {
public:
    static EncryptionData toDTO(const EncryptedDocument& document);
    static EncryptedDocument toDomain(const EncryptionData& dto);
    static string toStorageString(const EncryptionData& dto);
    static EncryptionData fromStorageString(const string& raw);
};

#endif