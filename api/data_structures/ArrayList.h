#pragma once

#include "core/EngineLog.h"

namespace boulder {

    template <typename T>
    class ArrayList {
    public:
        ArrayList() {}
        ~ArrayList() {}

        void init() {
            engine_log = new EngineLog();
            engine_log->init("ArrayList");

            list = new T[32];
            current_max = 32;
            current_size = 0;
        }

        void shutdown() {
            engine_log->shutdown();
            delete engine_log;

            delete[] list;
        }

        void pushBack(const T& data) {
            if (current_size == current_max) {
                grow();
            }

            list[current_size] = data;
            current_size++;
        }

        void popBack() {
            if (current_size == 0) {
                engine_log->error("Attempting to pop_back at size 0");
            }
            current_size--;
        }

        void clear() {
            current_size = 0;
        }

        void swapIndices(unsigned int first, unsigned int second) {
            if (first >= current_size || second >= current_size) {
                engine_log->error("Attempting to swap with an out of bounds index");
            }

            if (first == second) {
                return;
            }

            T temp = list[first];
            list[first] = list[second];
            list[second] = temp;
        }

        const T at(unsigned int index) const {
            if (index >= current_size) {
                engine_log->error("Index out of bounds");
            }

            return list[index];
        }

        T at(unsigned int index) {
            if (index >= current_size) {
                engine_log->error("Index out of bounds");
            }

            return list[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= current_size) {
                engine_log->error("Index out of bounds");
            }

            return list[index];
        }

        T& operator[](unsigned int index) {
            if (index >= current_size) {
                engine_log->error("Index out of bounds");
            }

            return list[index];
        }

        unsigned int size() const {
            return current_size;
        }

    private:
        EngineLog* engine_log;

        T* list;
        unsigned int current_max;
        unsigned int current_size;

        void grow() {
            T* temp = new T[current_max * 2];
            for (unsigned int i = 0; i < current_size; i++) {
                temp[i] = list[i];
            }
            delete[] list;
            list = temp;
            current_max *= 2;
        }
    };

}
