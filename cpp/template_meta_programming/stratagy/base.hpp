#pragma once
struct Strategy
{
    typedef boost::shared_ptr<Strategy> Ptr;
    virtual ~Strategy() {}
    virtual void calc( const uint8_t* _data, const size_t _length,
        uint8_t* _out, const size_t _outLength ) = 0;
};
