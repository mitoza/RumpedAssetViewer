#include <iostream>
#include "include/Application.h"


int main(int argc, char* argv[]) {
    std::cout << "Hello, Rumped Asset Viewer!" << std::endl;
    rumpedav::ApplicationConfig config(argc, argv);
    rumpedav::Application app(config.load());
    app.run();

    return 0;
}
