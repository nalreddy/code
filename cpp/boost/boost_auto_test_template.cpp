#define BOOST_TEST_MODULE example
#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<int,long,unsigned char> test_types;

BOOST_AUTO_TEST_CASE_TEMPLATE( my_test, T, test_types )
{
      BOOST_TEST( sizeof(T) == (unsigned)4 );
}

typedef std::tuple<int, long, unsigned char> test_types_w_tuples;

BOOST_AUTO_TEST_CASE_TEMPLATE( my_tuple_test, T, test_types_w_tuples )
{
      BOOST_TEST( sizeof(T) == (unsigned)4 );
}

