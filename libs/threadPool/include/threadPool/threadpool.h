#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <thread>
#include <mutex>
#include <vector>
#include <cstdint>
#include <queue>
#include <functional>
#include <iostream>
#include <future>
#include <type_traits>

class ThreadPool {
public:

    ThreadPool( int threadAmount );

    template < typename FuncType >
    std::future< typename std::result_of< FuncType() >::type >  addTask( FuncType func ) {

        typedef typename std::result_of< FuncType() >::type resultType;

        std::packaged_task< resultType() > packedTask( std::move( func ) );
        std::future< resultType > res = packedTask.get_future();

        {
            std::lock_guard< std::mutex > guard( taskMtx );
            taskQueue.push( std::move( packedTask ) );
        }
        return res;
    }

    void stop();

private:

    class FunctionWrapper;
    void processing() {

        FunctionWrapper task;

        {
            std::lock_guard< std::mutex > guard( taskMtx );

            if( !taskQueue.empty() ) {
                task =  std::move( taskQueue.front() );
                taskQueue.pop();
            }
        }
        task();
        waitForProcessing();
    }

    void waitForProcessing();
    bool waitForStop();
    bool IsQueueEmpty();
    bool stopFlag = false;
    uint32_t threadAmount;
    std::mutex taskMtx;
    std::vector< std::thread > threads;
    std::queue< FunctionWrapper > taskQueue;

    class FunctionWrapper {

        struct ImplBase {
            virtual void call() = 0;
            virtual ~ImplBase() = default;
        };

        template < typename FuncType >
        struct ImplType: ImplBase {

            FuncType m_function;

            ImplType( FuncType&& f ) : m_function( std::move( f ) ) {
            }
            void call() {
                m_function();
            }
        };

public:

        template < typename FuncType >
        FunctionWrapper( FuncType&& f ) : impl( std::make_unique< ImplType< FuncType > >( std::move( f ) ) ) {

        }
        void operator()() {
            if( impl != nullptr ) {
                impl->call();
            }
        }
        FunctionWrapper() = default;

private:
        std::unique_ptr< ImplBase > impl;

    };


};


#endif
