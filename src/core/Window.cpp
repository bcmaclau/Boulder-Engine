#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Window.h"

namespace boulder {

    Window::Window() {}
    Window::~Window() {}

    void Window::init(unsigned int width, unsigned int height, const char* title) {
        engine_log = new EngineLog();
        engine_log->init("Window");

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (window == NULL) {
            glfwTerminate();
            engine_log->error("Failed to initialize GLFW window");
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            engine_log->error("Failed to initialize GLAD");
        }

        glViewport(0, 0, width, height);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void Window::shutdown() {
        engine_log->shutdown();
        delete engine_log;

        if (window) {
            glfwDestroyWindow(window);
        }
        glfwTerminate();
    }

    bool Window::shouldClose() const {
        return glfwWindowShouldClose(window);
    }

    void Window::pollEvents() {
        glfwPollEvents();
    }

    void Window::clear() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(window);
    }

    GLFWwindow* Window::getWindowPointer() const {
        return window;
    }

}
