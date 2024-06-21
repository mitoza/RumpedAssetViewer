#include <iostream>
#include "include/Application.h"

// https://www.wxwidgets.org/docs/book/Cross-Platform%20GUI%20Programming%20with%20wxWidgets.pdf
//
// https://docs.wxwidgets.org/3.2/

rumpedav::Application &wxGetApp() {
    return *dynamic_cast<rumpedav::Application *>(wxApp::GetInstance());
}

wxAppConsole *wxCreateApp() {
    wxAppConsole::CheckBuildOptions(
            "3" "." "2" " (" "wchar_t" ",compiler with C++ ABI compatible with gcc 4" ",wx containers" ")",
            "your program"
    );
    return new rumpedav::Application;
}

wxAppInitializer wxTheAppInitializer((wxAppInitializerFunction) wxCreateApp);


int main(int argc, char **argv) {
    //    std::cout << "Hello, Rumped Asset Viewer!" << std::endl;
    //    if (!wxInitialize(argc, argv)) {
    //        std::cout << "Not Initialized" << std::endl;
    //    }
    //
    //
    //    wxDECLARE_APP(rumpedav::Application);
    //
    //    //rumpedav::ApplicationConfig config(argc, argv);
    //    //rumpedav::Application app(config.load());
    //    //app.run();
    return wxEntry(argc, argv);
}
