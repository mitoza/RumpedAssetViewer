#include <iostream>
#include "include/Application.h"


int main(int argc, char* argv[]) {
    std::cout << "Hello, Rumped Asset Viewer!" << std::endl;
    ApplicationConfig config;

    Application app(config);
    app.run();

    return 0;
}
