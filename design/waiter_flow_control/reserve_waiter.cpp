#include<boost/intrusive/list>

class SourceList
{
    SourceList(const size_t capacity) : mFree(capacity)
    {
    }
    ~SourceList() { }

    void reserve( Request& _res )
    {
        if( 0 == _res.mRequested )
            return;

        if( _res.mRequested > free() )
            exception

        {
             lock( mMutex );

             size_t prev = mReserve.load( boost::memory_order_relaxed );
             mReserve.store( prev + 1, boost::memory_order_relaxed );

             const size_t available = std::min( _res.mRequested, mFree );

             _res.mReserved += available;
             mFree -= available;

             if( available == _res.mRequested )
                 return;

            _res.mQueued = true;
            mRequestQueue.push_back( _res );
        }
        {
            mRequestWait.fetch_add( 1, boost::memory_order_relaxed );
            _res.wait();
        }
    }

    void release( Request& _res )
    {
        if( 0 != _res.reserved())
        {

            if (_res.mReserved > 0)
            {
                RequestQueue toNotify;
                {
                    lock( mMutex );
                    freeEntries( _res.mReserved, toNotify );
                }
                notifyRequests( toNotify );
            }
        }
    }

    void notifyRequests( RequestQueue& _requests )
    {
        while( !_requests.empty() )
        {
            Request& res = _requests.front();
            _requests.pop_front();
            res.notify();
        }
    }

    void freeEntries( const size_t _count,RequestQueue& _toNotify )
    {
        size_t remaining = _count;

        while( remaining && !mRequeQueue.empty() )
            remaining = dispatch( remaining, _toNotify );

        if( remaining > 0 )
            mFree += remaining;
    }

    size_t dispatch( const size_t _available, RequestQueue& _toNotify )
    {
        size_t remaining = _available;

        if( !mRequestQueue.empty() )
        {
            Request& res = mRequestQueue.front();
            size_t consumed;

              const bool pop = res.transfer( remaining, consumed );
            remaining -= consumed;

              if( pop )
            {
                mRequestQueue.pop_front();
                _toNotify.push_back( res );
            }
          }
        return remaining;
    }
};

typedef boost::intrusive::listbase_hook<
boost::intrusive::linkmode<boost::intrusive::normal_link>
> RequestHook;

class Request : public RequestHook, private boost::noncopyable
{
    friend class SourceList;

    Request(SourceList& sList, const sizet _req = 0 );
    Request(SourceList& sList, const sizet _req, const bool Try& );

    Request( Request&  other) :
        mRequested( other.mRequested ),
        mReserved( other.mReserved ),
        mQueued( false )
    {
        other.mRequested = 0;
        other.mReserved = 0;
        other.mReservedHB = 0;
    }

    ~Request();
    sizet requested() const { return mRequested; }
    sizet reserved() const { return mReserved; }

    private:
    void wait();
    bool decrement();
    void notify();

    SourceList&                mSList;
    sizet                      mRequested;
    sizet                      mReserved;
    bool                       mQueued;
    boost::mutex               mMutex;
    boost::conditionvariable   mCondition;
};

Request::Request( SourceList& sList, const sizet _req ) :
    mSList(sList),  mRequested( req ), mReserved( 0 ), mReservedHB( 0 ), mQueued( false )
{
    sList.reserve( *this );
}

Request::Request( SourceList& sList, const size_t _req,
        const TryReservet& ) :
    mSList( sList ), mRequested( _req ), mReserved( 0 ), mReservedHB( 0 ), mQueued( false )
{
    mSList.tryReserve( *this );
}

Request::~Request()
{
    mSList.release( *this );
}

void Request::reset()
{
    mSList.release( *this );
    mReserved = 0;
    mReservedHB = 0;
}

void Request::wait()
{
    boost::mutex::scopedlock lock( mMutex );

    while( mQueued )
        mCondition.wait( lock );

}

bool Request::decrement()
{
    --mReserved;
    return false;
}

Request::notify()
{
    boost::mutex::scopedlock lock( mMutex );
    mQueued = false;

    mCondition.notifyone();
}

typedef boost::intrusive::list<Request> RequestQueue;

class RequestMgr
{
    RequestQueue mRequestQueue;
};
