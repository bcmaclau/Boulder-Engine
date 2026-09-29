cmake_minimum_required(VERSION 3.20)
project(BoulderEngine VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(BoulderEngine STATIC
    src/App.cpp

    dependencies/glad/src/glad.c
    dependencies/stb/stb_image.cpp
)

target_include_directories(BoulderEngine PUBLIC
    include/
)

target_include_directories(BoulderEngine PRIVATE
    src/
    api/
    dependencies/glad/include/
    dependencies/
)

# changing configuration for development on nixos
# add_subdirectory(dependencies/glfw)
find_package(glfw3 REQUIRED)
add_subdirectory(dependencies/glm)

target_link_libraries(BoulderEngine PUBLIC
    glfw
    glm::glm
)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(tests/module_tests)
endif()
