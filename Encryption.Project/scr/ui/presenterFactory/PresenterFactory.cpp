#include "PresenterFactory.h"

unique_ptr<Presenter> PresenterFactory::create(
    unique_ptr<EncryptUseCase> encryptor,
    unique_ptr<DecryptUseCase> decryptor,
    unique_ptr<FileStorageAdapter> repo, 
    unique_ptr<View> view,
    ConfigInterface& config
) {
    return make_unique<Presenter>(
        move(encryptor),
        move(decryptor),
        move(repo),
        move(view),
        config
    );
}