//
// Created by lbypa on 2020/4/6.
//

#include "Thread.hpp"

Thread::Thread(thread t) {
    in_ = static_cast<thread &&>(t);
}

void Thread::start() {

    out_ = thread([&] {
        in_.join();
        isDone_ = true;
    });

    out_.detach();

}

void Thread::run() {
    out_ = thread([&] {
        in_.join();
        isDone_ = true;
    });

    out_.join();
}

bool Thread::isDone() {
    return isDone_;
}
