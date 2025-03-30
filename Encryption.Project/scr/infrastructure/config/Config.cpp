#include "Config.h"

Config::Config() {
    loadConfig();
}

void Config::loadConfig() {
    ifstream file("config.json");
    if (!file.is_open()) {
        throw runtime_error("Failed to open config file");
    }
    
    string content((istreambuf_iterator<char>(file)), 
                       istreambuf_iterator<char>());
    
    try {
        auto parsed = parser.parse(content);
        configData = parsed;
        
        colors["primary"] = getString("ui.colors.primary");
        colors["secondary"] = getString("ui.colors.secondary");
        colors["error"] = getString("ui.colors.error");
        colors["background"] = getString("ui.colors.background");
        colors["text"] = getString("ui.colors.text");
    } catch (const exception& e) {
        throw runtime_error(string("Config parse error: ") + e.what());
    }
}

bool Config::getBool(const string& key) const {
    auto it = tempValues.find(key);
    if (it != tempValues.end()) {
        return it->second == "true";
    }

    it = configData.find(key);
    if (it == configData.end()) {
        throw runtime_error("Config key not found: " + key);
    }
    return it->second == "true";
}

string Config::getString(const string& key) const {
    auto it = tempValues.find(key);
    if (it != tempValues.end()) {
        return it->second;
    }

    it = configData.find(key);
    if (it == configData.end()) {
        throw runtime_error("Config key not found: " + key);
    }
    return it->second;
}

string Config::getLanguage() const {
    return getString("ui.language");
}

int Config::getInt(const string& key) const {
    string value = getString(key);
    try {
        return stoi(value);
    } catch (...) {
        throw runtime_error("Invalid integer value for key: " + key);
    }
}

double Config::getDouble(const string& key) const {
    string value = getString(key);
    try {
        return stod(value);
    } catch (...) {
        throw runtime_error("Invalid double value for key: " + key);
    }
}

void Config::reload() {
    loadConfig();
}

string Config::getColor(const string& name) const {
    auto it = colors.find(name);
    return it != colors.end() ? it->second : "#000000";
}

void Config::setTemporaryValue(const string& key, const string& value) {
    tempValues[key] = value;
}

void Config::clearTemporaryValues() {
    tempValues.clear();
}