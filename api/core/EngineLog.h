#pragma once

/*
    This module should be included in every other module
    Any iostream output from all engine modules should take place through EngineLog
*/

namespace boulder {

    class EngineLog {
    public:
        EngineLog();
        ~EngineLog();

        void init(const char* module_name);
        void shutdown();

        void log(const char* message);
        void warn(const char* message);
        void error(const char* message);
    
    private:
        unsigned int max_name_size;
        char module_name[32];
    };

}
