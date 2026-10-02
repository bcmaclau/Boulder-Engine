#pragma once

namespace boulder {

    class App;

    class EngineClock {
        friend class App;
        
    public:
    
    private:
        EngineClock();
        ~EngineClock();    

        struct Impl;
        Impl* pImpl;
    };

}
