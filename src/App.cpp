#include "App.h"

#include "core/Window.h"

#include <iostream>

namespace boulder {

    struct App::Impl {
        App* q;

        Window* window;

        bool running;

        void init() {
            window = new Window();
            window->init(800, 600, "fortnite");

            running = true;

            std::cout << "initializing" << std::endl;
        }

        void shutdown() {
            window->shutdown();
            delete window;

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

        while (pImpl->running && !pImpl->window->shouldClose()) {
            pImpl->window->pollEvents();
            pImpl->window->clear();
            pImpl->window->swapBuffers();
        }

        pImpl->shutdown();
    }

}
