#include <iostream>

#include "headers.h"
#include "dlopen_lib.h"

#include <dlfcn.h>

using namespace std;

int load_lib(int argc, char * argv[])
{
    void * handle = ::dlopen(argv[1], RTLD_LAZY | RTLD_GLOBAL);

    if (handle == nullptr) {
        std::cout << "dlopen error" << std::endl;
        exit(-1);
    }

    dlopen_func func = (dlopen_func)::dlsym(handle, "create_lib");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cout << "dlerror" << dlsym_error << std::endl;
        dlclose(handle);
    }

    auto create_c_func = (*func)();
    if (!create_c_func) {
        std::cout << "dlopen function return null" << std::endl;
        exit (-1);
    }

    auto b = create_c_func();

    std::cout << "b base ptr : " << b.get() << std::endl;
    try {
        std::cout << "plugin ptr : " << typeid (b.get()).name() << std::endl;
        auto aaaa = std::dynamic_pointer_cast<configuration>(b);
        if (!aaaa) {
            std::cout << "dynamic_pointer_cast return null" << std::endl;
            exit (-1);
        }
        std::cout << "a base ptr : " << aaaa.get() << std::endl;

        aaaa->show();
    } catch (std::exception & e) {
        std::cout << "exception : " << e.what() << std::endl;
    }

    std::cout << "end of process" << std::endl;

    return 0;
}
