#pragma once

namespace boulder {

    class EngineClock;

    class Timer {
        friend class EngineClock;

    public:
        void start();
        void stop();
        void reset();
        
        unsigned int getTick() const;

    private:
        Timer();
        ~Timer();

        struct Impl;
        Impl* pImpl;
    };

}
