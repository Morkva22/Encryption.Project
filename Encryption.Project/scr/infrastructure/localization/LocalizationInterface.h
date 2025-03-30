#ifndef LOCALIZATION_INTERFACE_H
#define LOCALIZATION_INTERFACE_H
#include "../../lib/lib.h"

class LocalizationInterface {
public:
    virtual ~LocalizationInterface() = default;
    virtual string translate(const string& key) const = 0;
};

#endif 