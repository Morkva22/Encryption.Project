#include "FileStorageAdapter.h"

FileStorageAdapter::FileStorageAdapter(const string& filePath) 
    : filePath(filePath) {
    ensureFileExists();
}

void FileStorageAdapter::ensureFileExists() const {
    ifstream test(filePath.c_str());
    if (!test) {
        ofstream create(filePath.c_str());
        if (!create) throw runtime_error("Failed to create file");
    }
}

void FileStorageAdapter::save(const EncryptedDocument& document) {
    auto dto = EncryptionMapper::toDTO(document);
    ofstream file(filePath.c_str(), ios::app);
    if (!file) throw runtime_error("Failed to open file");
    file << EncryptionMapper::toStorageString(dto) << "\n";
}

vector<EncryptedDocument> FileStorageAdapter::loadAll() {
    ifstream file(filePath.c_str());
    if (!file) throw runtime_error("Failed to open file");

    vector<EncryptedDocument> documents;
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            auto dto = EncryptionMapper::fromStorageString(line);
            documents.push_back(EncryptionMapper::toDomain(dto));
        }
    }
    return documents;
}

string FileStorageAdapter::getFilePath() const {
    return filePath;
}

vector<string> FileStorageAdapter::readLines(const string& file_path) {
    ifstream file(file_path.c_str());
    if (!file.is_open()) {
        throw runtime_error("Failed to open file: " + file_path);
    }

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

void FileStorageAdapter::writeLines(const string& file_path, const vector<string>& lines) {
    ofstream file(file_path.c_str());
    if (!file.is_open()) {
        throw runtime_error("Failed to open file for writing: " + file_path);
    }

    for (const auto& line : lines) {
        file << line << "\n";
    }
}

void FileStorageAdapter::deleteFile(const string& filePath) {
    if (remove(filePath.c_str()) != 0) {
        throw runtime_error("Failed to delete file: " + filePath);
    }
}

bool FileStorageAdapter::fileExists(const string& file_path) const {
    ifstream file(file_path.c_str());
    return file.good();
}