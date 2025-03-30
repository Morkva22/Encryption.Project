#include "../Infrastructure/Config/Config.h"
#include "../Infrastructure/Localization/Localization.h"
#include "../UI/View/View.h"
#include "../UI/Presenter/Presenter.h"
#include "../UI/PresenterFactory/PresenterFactory.h"
#include "../Domain/UseCases/EncryptUseCase/EncryptUseCase.h"
#include "../Domain/UseCases/DecryptUseCase/DecryptUseCase.h"
#include "../Infrastructure/Adapters/FileStorageAdapter.h"
#include "../Utils/Ciphers/Caesar/CaesarCipher.h"
#include "../Utils/Ciphers/XOR/XorCipher.h"
#include "../lib/lib.h"

int main() {
    try {
        // 1. Load config
        Config config;
        
        // 2. Initialize localization (auto-create files if missing)
        const string localesPath = "../Infrastructure/Localization/locales/";
        auto localization = Localization::createWithFallback(
            localesPath,
            config.getLanguage(),
            "en"
        );
        
        // 3. Setup UI
        auto view = make_unique<View>(localization);
        
        // 4. Initialize storage
        auto fileAdapter = make_unique<FileStorageAdapter>("data.txt");
        
        // 5. Register ciphers
        auto caesar = make_shared<CaesarCipher>();
        auto xorCipher = make_shared<XorCipher>();
        
        auto encryptor = make_unique<EncryptUseCase>();
        encryptor->registerCipher("caesar", caesar);
        encryptor->registerCipher("xor", xorCipher);
        
        auto decryptor = make_unique<DecryptUseCase>();
        decryptor->registerCipher("caesar", caesar);
        decryptor->registerCipher("xor", xorCipher);
        
        // 6. Create presenter
        auto presenter = PresenterFactory::create(
            move(encryptor),
            move(decryptor),
            move(fileAdapter),
            move(view),
            config
        );
        
        // 7. Run app
        presenter->run();
        
    } catch (const exception& e) {
        cerr << "\nERROR:\n" << e.what() << endl;
        cerr << "\nTroubleshooting:\n";
        cerr << "1. Check '../Infrastructure/Localization/locales/' folder exists\n";
        cerr << "2. Verify program has write permissions\n";
        return 1;
    }
    
    return 0;
}