//
// Created by mito on 19.06.2024.
//

#include "../include/ApplicationConfig.h"

namespace rumpedav {
    ApplicationConfig::ApplicationConfig(int argc, char *argv[]) {

    }

    ApplicationConfig &ApplicationConfig::load() {
        return *this;
    }

    std::string ApplicationConfig::getTitle() {
        return "Rumped Asset viewer";
    }

    bool ApplicationConfig::isVSync() {
        return false;
    }

    unsigned int ApplicationConfig::getFramerateLimit() {
        return 60;
    }

}
