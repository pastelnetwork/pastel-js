#include <emscripten/bind.h>
#include <iostream>

using namespace emscripten;

bool AppInit(int argc, const char* argv[]);

void _test()
{
    
    const char* argv[] = {"param", "-help"};
    //AppInit(2, argv);

    std::cout << "Hello from pasteld" << std::endl;
}

EMSCRIPTEN_BINDINGS(PastelD)
{
function("test", &_test);
}