#include <GLFW/glfw3.h>

#include "core/EngineClock.h"

#include "core/EngineLog.h"
#include "data_structures/ArrayList.h"

namespace boulder {

    EngineClock::Impl* EngineClock::pImpl = nullptr;

    void Timer::Impl::init(unsigned int timer_id);
    void Timer::Impl::shutdown();

    struct EngineClock::Impl {
        EngineClock* q;

        EngineLog* engine_log;
        ArrayList<Timer*>* all_timers;

        float delta_time;
        float last_time;
        float acc;
        float tick_interval;

        void init(unsigned int ticks_per_second) {
            engine_log = new EngineLog();
            engine_log->init("EngineClock");

            all_timers = new ArrayList<Timer*>();
            all_timers->init();

            delta_time = 0.0f;
            last_time = 0.0f;
            acc = 0.0f;
            tick_interval = 1.0f / (float)ticks_per_second;
        }

        void shutdown() {
            for (unsigned int i = 0; i < all_timers->size(); i++) {
                Timer* timer = (*all_timers)[i];
                timer->pImpl->shutdown();
                delete timer;
            }

            all_timers->shutdown();
            delete all_timers;

            engine_log->shutdown();
            delete engine_log;
        }

        void update() {
            float current_time = glfwGetTime();
            delta_time = current_time - last_time;
            last_time = current_time;

            unsigned int num_updates = 0;
            acc += delta_time;
            while (acc >= tick_interval) {
                num_updates++;
                acc -= tick_interval;
            }

            for (unsigned int i = 0; i < all_timers->size(); i++) {
                Timer* timer = (*all_timers)[i];
                for (unsigned int j = 0; j < num_updates; j++) {
                    timer->pImpl->update();
                }
            }
        }
    }

    EngineClock::EngineClock() {
        pImpl = new Impl;
        pImpl->q = this;
    }

    EngineClock::~EngineClock() {
        delete pImpl;
    }

    Timer* EngineClock::createTimer() {
        Timer* new_timer = new Timer();
        new_timer->pImpl->init(pImpl->all_timers->size());
        pImpl->all_timers->pushBack(new_timer);
        return new_timer;
    }

    void EngineClock::destroyTimer(Timer* timer) {
        if (timer->pImpl->getTimerID() >= pImpl->all_timers->size()) {
            engine_log->error("Attempting to delete a timer with invalid ID");
        }

        unsigned int current_id = timer->pImpl->getTimerID();
        unsigned int last_id = pImpl->all_timers->size() - 1;

        if (current_id != last_id) {
            pImpl->all_timers->swapIndices(current_id, last_id);
            (*pImpl->all_timers)[current_id]->pImpl->setTimerID(current_id);
        }

        pImpl->all_timers->popBack();
        timer->pImpl->shutdown();
        delete timer;
    }

}
