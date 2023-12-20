#include "threadPool/threadpool.h"


ThreadPool::ThreadPool( uint32_t& threadAmount ) : threadAmount( threadAmount ) {

    threads.reserve( threadAmount );

// for( uint32_t i = 0; i < threadAmount; ++i ) {
// threads.emplace_back( &ThreadPool::processing );
// }

}

void ThreadPool::processing() {


}

void addTask( std::unique_ptr< int > task ) {


}


void stop() {

    // if can stop (queue is empty) then
    // all threads join
}
