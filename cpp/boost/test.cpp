#include<iostream>
#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>
#define BOOST_TEST_MODULE example

struct F {
    F() : i( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" ); }
    ~F()         { BOOST_TEST_MESSAGE( "teardown fixture" ); }

    int i;
};

//____________________________________________________________________________//

BOOST_FIXTURE_TEST_SUITE( s, F )

BOOST_AUTO_TEST_CASE( test_case1 )
{
        BOOST_CHECK( i == 1 );
}

//____________________________________________________________________________//

BOOST_AUTO_TEST_CASE( test_case2 )
{
        BOOST_CHECK_EQUAL( i, 0 );
}

//____________________________________________________________________________//

BOOST_AUTO_TEST_SUITE_END()

#if 0    
#define BOOST_TEST_MODULE const_string test
#include <boost/test/unit_test.hpp>

    BOOST_AUTO_TEST_CASE(dummy) {
        BOOST_CHECK(1 + 1 == 2);
        BOOST_TEST_MESSAGE("hellow world");
    }
#endif
