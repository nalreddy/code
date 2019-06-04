//
// Copyright © 2010 - 2014 SimpliVity Corporation
// All Rights Reserved
//

#pragma once

#include <boost/static_assert.hpp>
#include <limits>
#include <stdexcept>
#include <stdint.h>

// divide x by m and round up
//
#define     DIVIDE_UP(x, m)     (((x) + (m) - 1) / (m))

// round up/down x to a multiple of m
//
#define     ROUND_UP(x, m)      ((x + m - 1) / m * m)
#define     ROUND_DOWN(x, m)    (x / m * m)

// return X iff it doesn't exceed the ceiling, in which
// case return the ceiling.
//
template <class T>
T ceiling (const T c, const T x) {
    return x > c ? c : x;
}

// return X iff it is greater than the floor, in which
// case return the floor.
//
template <class T>
T floor (const T f, const T x) {
    return x > f ? x : f;
}

template <class T>
bool isPowerOf2 (T _val) {
    return _val && !( _val & ( _val - 1 ) );
}

template <class T>
T ipower (const T x, const unsigned int pwr) {
    T result = 1;
    for (unsigned int i=0; i<pwr; i++) {
        result *= x;
    }
    return result;
}

template <class T>
T ilog2 (const T x) {
    if (x <= 0) return -1;
    if (x <= 1) return 0;
    if (x <= 2) return 1;

    T log = 0;
    T mask = 1;
    while (mask < x) {
        log++;
        mask <<= 1;
    }
    return log;
}

template <class T>
T absolute (const T x) {
    return (x < 0) ? -(x) : (x);
}

template<class T>
T gcd2(T a, T b)
{
    if (a == 0 || b == 0) {
        return 0;
    }

    a = absolute<T>(a);
    b = absolute<T>(b);
    while (b > 0)
    {
        T tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

template <class InputIterator, class T>
T gcd (InputIterator first, InputIterator last) {
    if (first == last) return 0;

    T d = *first++;
    while (first != last) {
        d = gcd2 (d, *first++);
    }
    return d;
}

#if !defined(WIN32)
#   include <string.h>
#endif

template<class T>
    inline size_t firstSetBit(T n)
{
#if defined(WIN32)
    unsigned long retVal = 0;

    if( _BitScanForward( &retVal, n ) )
        ++retVal;

    return static_cast<size_t>( retVal );
#else
    return static_cast<size_t>( ::ffs( n ) );
#endif
}

#if !defined(WIN32)
template<>
    inline size_t firstSetBit<uint32_t>(uint32_t n)
{
    return static_cast<size_t>( ::ffsl( n ) );
}
#endif

template<>
    inline size_t firstSetBit<uint64_t>(uint64_t n)
{
#if defined(WIN32)
    unsigned long retVal = 0;

    if( _BitScanForward64( &retVal, n ) )
        ++retVal;

    return static_cast<size_t>( retVal );
#else
    return static_cast<size_t>( ::ffsll( n ) );
#endif
}

template<class T>
    struct Divider
{
    typedef std::div_t result_type;

    inline result_type operator()(T _n, T _d)
    {
        return std::div(_n, _d);
    }
};

template<>
    struct Divider<uint32_t>
{
    typedef std::ldiv_t result_type;

    inline result_type operator()(uint32_t _n, uint32_t _d)
    {
        return std::ldiv(_n, _d);
    }
};

template<>
    struct Divider<uint64_t>
{
    typedef std::lldiv_t result_type;

    inline result_type operator()(uint64_t _n, uint64_t _d) const
    {
        return std::lldiv(_n, _d);
    }
};

template <class T>
inline T unsignedSaturatingAdd( const T _l, const T _r )
{
    BOOST_STATIC_ASSERT( !std::numeric_limits<T>::is_signed );

    // Branch Free Saturating Unsigned Addition
    // (see http://locklessinc.com/articles/sat_arithmetic/)

    // "If the result is smaller than either of the initial values (and we
    // only need to check one of them), then we have overflowed. If so, we
    // go to the all-bits set state. This can be done by logical-oring with
    // -1. Since 1 is the "true" value returned by Boolean operations, all
    // we need is to negate it to create the bit-mask."

    T result = _l + _r;
    return ( result | -( result < _l ) );
}

namespace imath_detail
{

template<class T, int B> struct NPO2Shifter;

template <class T>
    struct NPO2Shifter<T, 1>
{
    inline T operator()( T _n ) const
    {
        _n |= _n >> 1;
        _n |= _n >> 2;
        _n |= _n >> 4;

        return _n;
    }
};

template <class T>
    struct NPO2Shifter<T,2>
{
    inline T operator()( T _n ) const
    {
        _n = NPO2Shifter<T, 1>()( _n );
        _n |= _n >> 8;
        return _n;
    }
};

template <class T>
    struct NPO2Shifter<T,4>
{
    inline T operator()( T _n ) const
    {
        _n = NPO2Shifter<T, 2>()( _n );
        _n |= _n >> 16;
        return _n;
    }
};

template <class T>
    struct NPO2Shifter<T,8>
{
    inline T operator()( T _n ) const
    {
        _n = NPO2Shifter<T, 4>()( _n );
        _n |= _n >> 32;
        return _n;
    }
};

} // ns imath_detail

// Implementation based on http://stackoverflow.com/a/365068.

template<typename T>
    inline T nextPowerOfTwo( const T _n )
{
    BOOST_STATIC_ASSERT( std::numeric_limits<T>::is_integer );
    BOOST_STATIC_ASSERT( !std::numeric_limits<T>::is_signed );

    static const T maxPowerOfTwo = ( T(1) << ( T( ( sizeof(T) * 8 ) - 1 ) ) );

    if( _n > maxPowerOfTwo )
        throw std::overflow_error( "Cannot represent next power of two." );

    T n = _n;
    --n;
    n = imath_detail::NPO2Shifter<T, sizeof(T)>()( n );
    return ++n;
}
