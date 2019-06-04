#   include <boost/integer/static_log2.hpp>
#   include <boost/array.hpp>
#   include <numeric>
#   include "imath.hpp"
#include <algorithm>

#define buckets 256 
using namespace std;

void initialize(size_t _size )
{
    typedef boost::array<size_t, 10>      SizeArray;

    size_t                      mLevels = 0;
    size_t                      mSize;
    SizeArray                   mSizes;
    SizeArray                   mOffsets;


    size_t adjCap = buckets; 
    size_t offset = 0;
    size_t div = 1;

    do
    {

        div *= 64;
        typename Divider<size_t>::result_type result = Divider<size_t>()( adjCap, div );
        size_t blocksAtLevel = result.quot + ( ( result.rem == 0 ) ? 0 : 1 );


        mSizes[ mLevels ] = blocksAtLevel;
        mOffsets[ mLevels ] =  offset;
        cout << " blockAt level " << blocksAtLevel  << "   offset : " << offset << "  level :" << mLevels << endl;
        offset += blocksAtLevel;

    } while(  mSizes[ mLevels++ ] > 1 );

    mSize = mSizes[ 0 ] * 64;
    cout << mSize << endl;

     int total = mSizes[0] + mSizes[1];
     size_t footprint = sizeof(size_t ) * total ;

     cout << "  footprint " << footprint  << " msize " <<  mSize  << "bits per entry " << ( ( static_cast<double>( footprint ) * 8.0 ) / static_cast<double>( mSize ) ) ;

}

int main()
{
    initialize(buckets);
    return 0;
}

