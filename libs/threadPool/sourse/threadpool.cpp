#include "threadPool/threadpool.h"


ThreadPool::ThreadPool( int threadAmount ) : threadAmount( threadAmount ) {

    threads.reserve( threadAmount );
    // std::cerr << "Pool created, thread count: " << threadAmount << std::endl;

    for( uint32_t i = 0; i < threadAmount; ++i ) {
        threads.push_back( std::thread( &ThreadPool::waitForProcessing, this ) );
    }

}

bool ThreadPool::IsQueueEmpty() {

    // checking is there any task in queue
    // std::unique_lock< std::mutex > lock( taskMtx );
    std::lock_guard< std::mutex > guard( taskMtx );
    return taskQueue.empty();

}

void ThreadPool::waitForProcessing() { // режим ожидания, ждет таски


    if( stopFlag == false ) {
        IsQueueEmpty() ? waitForProcessing() : processing();
    }

}

bool ThreadPool::waitForStop() {

    // std::cerr << "Waiting for stop \n";

    IsQueueEmpty() ? stopFlag = true : waitForStop();
    return stopFlag;
}

void ThreadPool::stop() {

    if( waitForStop() ) {

        for( uint16_t i = 0; i < threads.size(); i++ ) {
            threads[ i ].join();
        }
        // std::cerr << " Pool stopped \n";

    }

}
