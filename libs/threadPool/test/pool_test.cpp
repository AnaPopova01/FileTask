#include <gtest/gtest.h>
#include <functional>
#include "threadPool/threadpool.h"

std::mutex mute;

int returnInc( double x ) {

    return x + 1;
}

std::string sumTwoInt( int a, int b ) {

    return std::to_string( a + b );
}

int getOne() {

    std::lock_guard< std::mutex > guard( mute );
    std::cerr << "\t getOne function \n";
    return 1;
}


TEST( PoolTests, addTask_oneThread_sumTask ) {

    int threadCount = 1;
    ThreadPool pool( threadCount );

    auto res = pool.addTask( [ & ] () {
        return sumTwoInt( 1, 2 );
    }
                             );
    pool.stop();
    auto x = res.get();
    ASSERT_EQ( x, "3" );

}


TEST( PoolTests, addTask_oneThread_oneTask ) {

    int threadCount = 1;
    ThreadPool pool( threadCount );

    auto lambda = [ & ] () {
                  return returnInc( 88.8 );
              };

    auto res = pool.addTask( lambda  );
    pool.stop();
    auto x = res.get();
    ASSERT_EQ( x, 89 );

}


TEST( PoolTests, addTask_oneThread_twoTasks ) {

    int threadCount = 1;
    ThreadPool pool( threadCount );

    auto biba = [ & ] () {
                return returnInc( 7 );
            };

    auto boba = [ & ] () {
                return returnInc( 0 );
            };

    auto resBi = pool.addTask( biba  );
    auto resBo = pool.addTask( boba  );

    pool.stop();
    auto x = resBi.get();
    auto y = resBo.get();
    ASSERT_EQ( x, 8 );
    ASSERT_EQ( y, 1 );

}


TEST( PoolTests, addTask_twoThreads_oneTasks ) {

    int threadCount = 2;
    ThreadPool pool( threadCount );

    auto lambda = [ & ] () {
                  return returnInc( 88.8 );
              };

    auto res = pool.addTask( lambda  );
    pool.stop();
    auto x = res.get();
    ASSERT_EQ( x, 89 );
}

TEST( PoolTests, addTask_fiveThreads_tenTask ) {

    int threadCount = 5;
    ThreadPool pool( threadCount );

    std::vector< std::future< int > > res( 10 );
    std::vector< int > final ( 10 );

    for( int var = 0; var < 10; var++ ) {
        res[ var ] = pool.addTask( [ var ] () {
            return returnInc( var );
        } );
    }

    for( int var = 0; var < 10; ++var ) {

        final[ var ] = res[ var ].get();
    }
    std::vector< int > correct { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


    pool.stop();
    ASSERT_EQ( final, correct );

}

TEST( PoolTests, hytyophdtkhtyp ) {

    int threadCount = 5;
    ThreadPool pool( threadCount );

    std::vector< std::future< std::string > > res( 10 );
    std::vector< std::string > final ( 10 );

    for( int var = 0; var < 10; var++ ) {
        res[ var ] = pool.addTask( [ var ] () {
            return sumTwoInt( var, var + 1 );
        } );
    }

    for( int var = 0; var < 10; ++var ) {

        final[ var ] = res[ var ].get();
    }
    std::vector< std::string > correct { "1", "3", "5", "7", "9", "11", "13", "15", "17", "19" };


    pool.stop();
    ASSERT_EQ( final, correct );

}
