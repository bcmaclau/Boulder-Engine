#pragma once

struct GLFWwindow;

namespace boulder {

    //Engine Design: The only class to use the window module should be App
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
        GLFWwindow* window;
    };

}
