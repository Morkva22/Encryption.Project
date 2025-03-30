#ifndef CONFIG_H
#define CONFIG_H

#include "ConfigInterface.h"
#include "../../Data/Parsers/JsonParser.h"
#include "../../lib/lib.h"

class Config : public ConfigInterface {
public:
    Config();
    bool getBool(const string& key) const override;
    string getString(const string& key) const override;
    string getLanguage() const override;
    int getInt(const string& key) const override;
    double getDouble(const string& key) const override;
    void reload() override;

    string getColor(const string& name) const;
    void setTemporaryValue(const string& key, const string& value);
    void clearTemporaryValues();

private:
    void loadConfig();
    unordered_map<string, string> configData;
    unordered_map<string, string> colors;
    unordered_map<string, string> tempValues;
    JsonParser parser;
};

#endif 