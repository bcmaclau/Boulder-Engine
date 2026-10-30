#include "core/EngineLog.h"

#include <cstring>
#include <iostream>
#include <cstdlib>

namespace boulder {

    EngineLog::EngineLog() {}
    EngineLog::~EngineLog() {}

    void EngineLog::init(const char* module_name) {
        max_name_size = 32;
        std::strncpy(this->module_name, module_name, max_name_size - 1);
        this->module_name[max_name_size - 1] = '\0';
    }

    void EngineLog::shutdown() {}

    void EngineLog::log(const char* message) {
        std::cout << "[LOG] - " << module_name << ": " << message << std::endl;
    }

    void EngineLog::warn(const char* message) {
        std::cout << "[WARN] - " << module_name << ": " << message << std::endl;
    }

    void EngineLog::error(const char* message) {
        std::cout << "[ERROR] - " << module_name << ": " << message << std::endl;
        std::exit(EXIT_FAILURE);
    }

}
