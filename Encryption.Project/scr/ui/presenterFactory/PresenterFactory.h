#ifndef PRESENTER_FACTORY_H
#define PRESENTER_FACTORY_H
#include "../Presenter/Presenter.h"
#include "../../Domain/UseCases/EncryptUseCase/EncryptUseCase.h"
#include "../../Domain/UseCases/DecryptUseCase/DecryptUseCase.h"
#include "../../Infrastructure/Adapters/FileStorageAdapter.h"
#include "../../UI/View/View.h"
#include "../../Infrastructure/Config/ConfigInterface.h"
#include "../../lib/lib.h"

class Presenter;

class PresenterFactory {
public:
    static unique_ptr<Presenter> create(
        unique_ptr<EncryptUseCase> encryptor,
        unique_ptr<DecryptUseCase> decryptor,
        unique_ptr<FileStorageAdapter> repo,
        unique_ptr<View> view,
        ConfigInterface& config
    );
};

#endif 