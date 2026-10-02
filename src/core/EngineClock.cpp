#include "core/EngineClock.h"

#include "core/EngineLog.h"

namespace boulder {

    struct EngineClock::Impl {
        EngineClock* q;

        EngineLog* engine_log;

        void init() {
            engine_log = new EngineLog();
            engine_log->init("EngineClock");
        }

        void shutdown() {
            engine_log->shutdown();
            delete engine_log;
        }
    }

    EngineClock::EngineClock() {
        pImpl = new Impl;
        pImpl->q = this;
    }

    EngineClock::~EngineClock() {
        delete pImpl;
    }

}
