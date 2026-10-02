#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/Window.h"

namespace boulder {

    Window::Window() {}
    Window::~Window() {}

    void Window::init(unsigned int width, unsigned int height, const char* title) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (window == NULL) {
            glfwTerminate();
            // THROW AN ERROR HERE
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            // THROW AN ERROR HERE
        }

        glViewport(0, 0, width, height);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void Window::shutdown() {
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
