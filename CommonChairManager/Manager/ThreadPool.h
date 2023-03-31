//
// Created by theli on 3/29/2023.
//
#pragma once
#ifndef CHAIRLOADER_THREADPOOL_H
#define CHAIRLOADER_THREADPOOL_H


#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>

class ThreadPool {
public:
    ThreadPool(size_t numThreads) : stop(false), numPendingTasks(0) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                for (;;) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                            return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        --numPendingTasks;
                        if (numPendingTasks == 0)
                            completion_condition.notify_one();
                    }
                }
            });
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread& worker : workers)
            worker.join();
    }

    template<typename F, typename... Args>
    void enqueue(F&& f, Args&&... args) {
        auto task = std::make_shared<std::packaged_task<void()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace([task]() { (*task)(); });
            ++numPendingTasks;
        }
        condition.notify_one();
    }

    void wait() {
        std::unique_lock<std::mutex> lock(queue_mutex);
        completion_condition.wait(lock, [this] { return numPendingTasks == 0; });
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    std::condition_variable completion_condition;
    bool stop;
    size_t numPendingTasks;
};

#endif //CHAIRLOADER_THREADPOOL_H
