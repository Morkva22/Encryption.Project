#ifndef PARSER_INTERFACE_H
#define PARSER_INTERFACE_H

#include "../../lib/lib.h"
class ParserInterface {
public:
    virtual ~ParserInterface() = default;
    virtual string serialize(const class EncryptionData& data) = 0;
    virtual class EncryptionData deserialize(const string& serialized) = 0;
};

#endif 