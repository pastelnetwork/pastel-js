#include <emscripten/bind.h>
#include <iostream>

#include <univalue.h>

using namespace emscripten;

void TestUnivalueBool()
{
    UniValue value;

    value.setBool(false);
    std::cout << "is false: " << value.isFalse() << std::endl;

    value.setBool(true);
    std::cout << "is true: " << value.isTrue() << std::endl;
}

void RunAll()
{
    TestUnivalueBool();
}

EMSCRIPTEN_BINDINGS(Univalue)
{
function("univalueBool", &TestUnivalueBool);
function("runAll", &RunAll)
}

