#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <thread>
#include <mutex>
#include <vector>
#include <cstdint>
#include <queue>


class ThreadPool {
public:

    ThreadPool( uint32_t& threadAmount );

    friend void addTask( std::unique_ptr< int > task );

    friend void stop();

private:

    void processing();
    uint32_t threadAmount;
    std::mutex mtxForMap;
    std::queue< std::unique_ptr< int > > taskQueue;
    std::vector< std::thread > threads;

};

void addTask( std::unique_ptr< int > task );


void stop();




#endif
