#pragma once
#include "base.hpp"
#include "mysha.hpp"

template <Base::DigType> struct DigTraits {};

#define DECLARE_DIG_TRAITS( Algorithm, AlgoLen, Fn )                           \
template <> struct DigTraits<Base::Algorithm>                                       \
{                                                                                   \
    BOOST_STATIC_CONSTANT( size_t, AlgorithmLength = AlgoLen );                     \
    static const func* digStruct() { return Fn(); }                               \
};

DECLARE_DIGEST_TRAITS( SHA1, 4, sha1);
DECLARE_DIGEST_TRAITS( SHA2, 8, sha2);
