#include <iostream>
#include <Test0App.h>
#include <cassert>
int main(int argc, const char *argv[])
{
    auto app = Test0::Test0App(800, 600, "Test0App");
    app.Init();
    app.Loop();
    app.Free();
    return 0;
}
