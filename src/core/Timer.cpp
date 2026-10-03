#include "core/Timer.h"

namespace boulder {

    struct Timer::Impl {
        Timer* q;

        EngineLog* engine_log;

        unsigned int tick;
        bool running;
        unsigned int timer_id;

        void init(unsigned int timer_id) {
            engine_log = new EngineLog();
            engine_log->init("Timer");

            tick = 0;
            running = false;
            this->timer_id = timer_id;
        }

        void shutdown() {
            engine_log->shutdown();
            delete engine_log;
        }

        void update() {
            if (running) {
                tick++;
            }
        }

        void getTimerID() const {
            return timer_id;
        }

        void setTimerID(unsigned int timer_id) {
            this->timer_id = timer_id;
        }
    };

    Timer::Timer() {
        pImpl = new Impl();
        pImpl->q = this;
    }

    Timer::~Timer() {
        delete pImpl;
    }

    void Timer::start() {
        pImpl->running = true;
    }

    void Timer::stop() {
        pImpl->running = false;
    }

    void Timer::reset() {
        pImpl->tick = 0;
    }

    unsigned int Timer::getTick() const {
        return pImpl->tick;
    }

}
