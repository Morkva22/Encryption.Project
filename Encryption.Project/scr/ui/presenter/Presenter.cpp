#include "Presenter.h"

Presenter::Presenter(
    unique_ptr<EncryptUseCase> encryptor,
    unique_ptr<DecryptUseCase> decryptor,
    unique_ptr<Repository> repository,
    unique_ptr<View> view,
    ConfigInterface& config
) : encryptUseCase(move(encryptor)),
    decryptUseCase(move(decryptor)),
    repository(move(repository)),
    view(move(view)),
    config(config) {}

void Presenter::run() {
    while (true) {
        view->showMainMenu();
        int choice = view->getUserChoice();
        
        try {
            switch (choice) {
            case 1: handleEncryption(); break;
            case 2: handleDecryption(); break;
            case 3: return;
            default: view->showError("Invalid choice");
            }
        } catch (const exception& e) {
            view->showError(e.what());
        }
    }
}

void Presenter::handleEncryption() {
    auto text = view->getInputText();
    auto key = view->getEncryptionKey();
    auto cipherType = view->getCipherType();
    
    EncryptedDocument doc(text, cipherType, key);
    
    string encryptedText = encryptUseCase->execute(text, cipherType, key);
    doc.setEncryptedText(encryptedText);
    
    repository->save(doc);
    view->showResult(encryptedText);
}

void Presenter::handleDecryption() {
    auto encryptedText = view->getInputText();
    auto key = view->getEncryptionKey();
    auto cipherType = view->getCipherType();
    
    string decryptedText = decryptUseCase->execute(encryptedText, cipherType, key);
    view->showResult(decryptedText);
}