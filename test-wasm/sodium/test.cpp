#include <emscripten/bind.h>
#include <iostream>

#include <sodium.h>

using namespace emscripten;

void TestRandomBytes()
{
    unsigned int buf_len = 16;
    unsigned char buf[buf_len];
    randombytes_buf(buf, buf_len);

    for (int i = 0; i < buf_len; i++)
        std::cout << buf[i];
    std::cout << std::endl;
}

void RunAll()
{
    TestRandomBytes();
}

EMSCRIPTEN_BINDINGS(Univalue)
{
function("TestRandomBytes", &TestRandomBytes);
function("runAll", &RunAll);
}

