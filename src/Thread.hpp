#pragma once
#include "Includes.hpp"

class Thread {
private:
    thread in_, out_;
    bool isDone_ = false;
public:
    Thread(thread t);
    void start();
    bool isDone();

    void run();
};
