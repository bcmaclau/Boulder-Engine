#include "App.h"

#include <iostream>

namespace boulder {

    struct App::Impl {
        App* q;

        void init() {
            std::cout << "initializing" << std::endl;
        }

        void shutdown() {
            std::cout << "shutting down" << std::endl;
        }
    };

    App::App() {
        pImpl = new Impl();
        pImpl->q = this;
    }

    App::~App() {
        delete pImpl;
    }

    void App::run() {
        pImpl->init();

        pImpl->shutdown();
    }

}
