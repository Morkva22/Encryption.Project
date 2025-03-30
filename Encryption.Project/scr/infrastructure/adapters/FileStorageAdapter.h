#ifndef FILE_STORAGE_ADAPTER_H
#define FILE_STORAGE_ADAPTER_H

#include "../../Domain/Repositories/Repository.h"
#include "../../Data/Mappers/EncryptionMapper.h"
#include "../../lib/lib.h"

class FileStorageAdapter : public Repository {
public:
    explicit FileStorageAdapter(const string& filePath);
    void save(const EncryptedDocument& document) override;
    vector<EncryptedDocument> loadAll() override;
    string getFilePath() const override;
    
    vector<string> readLines(const string& file_path);
    void writeLines(const string& file_path, const vector<string>& lines);
    void deleteFile(const string& filePath);
    bool fileExists(const string& file_path) const;

private:
    string filePath;
    void ensureFileExists() const;
};

#endif 