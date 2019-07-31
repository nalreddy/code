#pragma once

#include "dig.hpp"

template <Base::DigType T>
class  SslStrategy
{
    public:
        typedef DigTraits<T> Traits;

        void doCalc( const uint8_t* _data, const size_t _length, uint8_t* _out, size_t len )
        {
            init_sha(Traits::digStruct(), data, _length, out, &len);
        }
};
