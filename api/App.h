#pragma once

namespace boulder {

    class App {
    public:
        App();
        ~App();

        void run();

    private:
        struct Impl;
        Impl* pImpl;
    }

}
