#pragma once

namespace boulder {

    class App;
    class Timer;

    class EngineClock {
        friend class App;
        
    public:
        static Timer* createTimer();
        static void destroyTimer(Timer* timer);

    private:
        EngineClock();
        ~EngineClock();    

        struct Impl;
        static Impl* pImpl;
    };

}
