#pragma once

namespace boulder {

    class Timer {
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
    }

}
