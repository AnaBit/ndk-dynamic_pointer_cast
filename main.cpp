#include <iostream>

#include "headers.h"
#include "dlopen_lib.h"

#include <dlfcn.h>

using namespace std;

extern int load_lib(int argc, char * argv[]);

int main(int argc, char * argv[])
{
    load_lib(argc, argv);

    return 0;
}
