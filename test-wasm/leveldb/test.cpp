#include <emscripten/bind.h>
#include <iostream>

#include <base58.h>

using namespace emscripten;

void TestEncodeBase58()
{
    std::vector<unsigned char> data;

    for (size_t i = 0; i < 10; ++i)
        data.push_back('a');
    
    std::cout << EncodeBase58(data) << std::endl;
}

EMSCRIPTEN_BINDINGS(Common)
{
function("encodeBase58", &TestEncodeBase58);
}

