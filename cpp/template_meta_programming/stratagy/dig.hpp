#pragma once

#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/err.h>

template <Base::stType> struct DTraits {};

#define DECLARE_DIG_TRAITS( Algorithm, Len, AlgoLen, Fn )                         \
template <> struct DigTraits<Base::Algorithm>                                       \
{                                                                                   \
    BOOST_STATIC_CONSTANT( size_t, Length = Len );                                  \
    BOOST_STATIC_CONSTANT( size_t, AlgorithmLength = AlgoLen );                     \
    static const EVP_MD* digStruct() { return Fn(); }                            \
};

DECLARE_DIGEST_TRAITS( Sha1,     SHA_LENGTH,    SHA_DIGEST_LENGTH,    EVP_sha1 );
DECLARE_DIGEST_TRAITS( Sha2_256, SHA256_LENGTH, SHA256_LENGTH, EVP_sha256 );
DECLARE_DIGEST_TRAITS( Sha224,   SHA224_LENGTH, SHA224_LENGTH, EVP_sha224 );
DECLARE_DIGEST_TRAITS( Sha256,   SHA256_LENGTH, SHA256_LENGTH, EVP_sha256 );
DECLARE_DIGEST_TRAITS( Sha384,   SHA384_LENGTH, SHA384_LENGTH, EVP_sha384 );
DECLARE_DIGEST_TRAITS( Sha512,   SHA512_LENGTH, SHA512_LENGTH, EVP_sha512 );

