#ifndef PRESENTER_H
#define PRESENTER_H

#include "../../lib/lib.h"
#include "../../Domain/UseCases/EncryptUseCase/EncryptUseCase.h"
#include "../../Domain/UseCases/DecryptUseCase/DecryptUseCase.h"
#include "../../Domain/Repositories/Repository.h"
#include "../View/View.h"
#include "../../Infrastructure/Config/ConfigInterface.h"
#include "../../Domain/Entities/EncryptionDocument.h"

class Presenter {
public:
    Presenter(
        unique_ptr<EncryptUseCase> encryptor,
        unique_ptr<DecryptUseCase> decryptor,
        unique_ptr<Repository> repository,
        unique_ptr<View> view,
        ConfigInterface& config
    );
    
    void run();

private:
    void handleEncryption();
    void handleDecryption();
    
    unique_ptr<EncryptUseCase> encryptUseCase;
    unique_ptr<DecryptUseCase> decryptUseCase;
    unique_ptr<Repository> repository;
    unique_ptr<View> view;
    ConfigInterface& config;
};

#endif // PRESENTER_H