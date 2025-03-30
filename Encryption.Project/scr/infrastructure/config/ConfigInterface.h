#ifndef CONFIG_INTERFACE_H
#define CONFIG_INTERFACE_H

#include "../../lib/lib.h"

class ConfigInterface {
public:
    virtual ~ConfigInterface() = default;
    virtual bool getBool(const string& key) const = 0;
    virtual string getString(const string& key) const = 0;
    virtual string getLanguage() const = 0;

    virtual int getInt(const string& key) const = 0;
    virtual double getDouble(const string& key) const = 0;
    virtual void reload() = 0;
};

#endif 