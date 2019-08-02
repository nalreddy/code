// Compile line : g++ thread.cpp -lboost_thread -lboost_system

#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/unordered_map.hpp>
#include <boost/format.hpp>
#include <boost/thread/mutex.hpp>

using namespace std;
using boost::thread;

const int THREAD_COUNT = 2;

void abortWithContext( size_t _line, const char* _file, const char* _func, const char* _context )
{
    boost::format f = boost::format( "%1%:%2%:%3%: %4%" ) % _file % _line % _func % _context;

    std::cerr << f << std::endl << std::flush;
    abort();
}

#define SVT_ASSERT( cond, msg )                                                 \
    if( !( cond ) ) {                                                           \
        boost::format ctx( msg );                                               \
        abortWithContext( __LINE__, __FILE__, __func__, ctx.str().c_str() ); }  \

#define MOD_TREE_INDEX_BUCKET 40000
typedef boost::unordered_map<size_t, size_t> SubTreeMutexIndexMap;
SubTreeMutexIndexMap                   mSubTreeMutexIndexMap;
boost::mutex    mMutex[MOD_TREE_INDEX_BUCKET];

void push_worker()
{
    cout << "Worker thread:  " << __func__ << endl;
    for(int i = 0; i < MOD_TREE_INDEX_BUCKET; i++) {
        {
            boost::mutex::scoped_lock vLock(mMutex[i]);
            if(!mSubTreeMutexIndexMap[i])
            {
                mSubTreeMutexIndexMap[i] = ((i + 1) * 10);
            } // end if
            SVT_ASSERT((mSubTreeMutexIndexMap[i] == ((i + 1) * 10)), boost::format("improper value, vIndex: %1%, mSMI[vI]: %2%, bucket_count %3%, max_bucket_count %4%.") % i % mSubTreeMutexIndexMap[i] % mSubTreeMutexIndexMap.bucket_count() % mSubTreeMutexIndexMap.max_bucket_count());
        } // end scope
    } // end for loop
}

void pop_worker()
{
    cout << "Worker thread:  " << __func__ << endl;
    for(int i = 0; i < MOD_TREE_INDEX_BUCKET; i++) {
        {
            boost::mutex::scoped_lock vLock(mMutex[i]);
            if(mSubTreeMutexIndexMap[i])
            {
                if ((mSubTreeMutexIndexMap[i] == -1) && mSubTreeMutexIndexMap[i] != ((i + 1) * 10)) {
                    boost::unordered::unordered_map<size_t, size_t >::iterator it;
                    for (it=mSubTreeMutexIndexMap.begin();it!=mSubTreeMutexIndexMap.end();++it)
                        std::cout << it->first <<", " << it->second << std::endl;
                }
                SVT_ASSERT((mSubTreeMutexIndexMap[i] == ((i + 1) * 10)), boost::format("improper value, vIndex: %1%, mSMI[vI]: %2%, bucket_count %3%, max_bucket_count %4%.") % i % mSubTreeMutexIndexMap[i] % mSubTreeMutexIndexMap.bucket_count() % mSubTreeMutexIndexMap.max_bucket_count());
                mSubTreeMutexIndexMap[i] = -1;
            } //end if
        } // end scope
    } //end for loop
}

void worker(int i) {
    if(!i)
    {
        push_worker();
    }
    else
    {
        pop_worker();
    }
}

int main(int argc, char** argv)
{
    thread *threads[THREAD_COUNT];

    cout << "Before starting bucket_count = " << mSubTreeMutexIndexMap.bucket_count()
        << " max_bucket_count = " << mSubTreeMutexIndexMap.max_bucket_count() << endl;
    // Creation
    for(int i = 0; i < THREAD_COUNT; i++) {
        threads[i] = new thread(worker, i);
    }

    // Cleanup
    for(int i = 0; i < THREAD_COUNT; i++) {
        threads[i]->join();
        delete threads[i];
    }

    return 0;
}

