#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include "../../lib/lib.h"

class JsonParser {
public:
    unordered_map<string, string> parse(const string& json);
    
private:
    void skipWhitespace(const string& json, size_t& pos);
    string parseString(const string& json, size_t& pos);
    string parseValue(const string& json, size_t& pos);
    void parseObject(const string& json, size_t& pos, 
                    const string& currentPath,
                    unordered_map<string, string>& result);
    void throwParseError(const string& message, size_t pos) const;
};

#endif 