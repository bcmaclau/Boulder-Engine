#pragma once

#include "core/EngineLog.h"

struct GLFWwindow;

namespace boulder {

    class Window {
    public:
        Window();
        ~Window();

        void init(unsigned int width, unsigned int height, const char* title);
        void shutdown();

        bool shouldClose() const;
        void pollEvents();
        void clear();
        void swapBuffers();

        GLFWwindow* getWindowPointer() const;

    private:
        EngineLog* engine_log;

        GLFWwindow* window;
    };

}
