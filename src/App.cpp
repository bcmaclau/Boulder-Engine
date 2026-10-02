#include "App.h"

#include "core/EngineLog.h"
#include "core/Window.h"

#include <iostream>

namespace boulder {

    struct App::Impl {
        // Engine design: Any class using a forward declared Impl struct will have a pointer 'q' to the class object it was created by
        App* q;

        // Engine design: Every class should have a list of modules that it uses declared before all other fields
        EngineLog* engine_log;
        Window* window;

        bool running;

        void init() {
            engine_log = new EngineLog();
            engine_log->init("App");

            window = new Window();
            window->init(800, 600, "fortnite");

            running = true;

            std::cout << "initializing" << std::endl;
        }

        void shutdown() {
            window->shutdown();
            delete window;

            engine_log->shutdown();
            delete engine_log;

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
