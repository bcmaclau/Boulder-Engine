#include "App.h"

#include <iostream>

namespace boulder {

    struct App::Impl {
        // Engine design: Any class using a forward declared Impl struct will have a pointer 'q' to the class object it was created by
        App* q;

        bool running;

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
