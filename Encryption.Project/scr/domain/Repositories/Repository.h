#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "../Entities/EncryptionDocument.h"
#include "../../lib/lib.h"

class Repository {
public:
    virtual ~Repository() = default;
    virtual void save(const EncryptedDocument& document) = 0;
    virtual vector<EncryptedDocument> loadAll() = 0;
    virtual string getFilePath() const = 0;
};

#endif // REPOSITORY_H