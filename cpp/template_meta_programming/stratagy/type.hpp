
#pragma once


template <Base::SType T> struct STypeTraits {};

#define DECLARE_STYPE_TRAITS( Enum, Mta, Kb, Blocks )          \
template <>                                                         \
    struct STypeTraits<Enum>                                     \
{                                                                   \
    BOOST_STATIC_CONSTANT( bool, Mtdata = Meta );                 \
    BOOST_STATIC_CONSTANT( size_t, SKb = Kb##ull );              \
    BOOST_STATIC_CONSTANT( size_t, SBytes = SizeKb * 1024ull );  \
    BOOST_STATIC_CONSTANT( size_t, BlckCount = Blocks );           \
};

DECLARE_STYPE_TRAITS( Base::m_1K,  true,  1,  1 );
DECLARE_STYPE_TRAITS( Base::d_4K,  false, 4,  1 );
DECLARE_STYPE_TRAITS( Base::d_8K,  false, 8,  2 );
DECLARE_STYPE_TRAITS( Base::d_16K, false, 16, 4 );
DECLARE_STYPE_TRAITS( Base::d_32K, false, 32, 8 );
DECLARE_STYPE_TRAITS( Base::d_64K, false, 64, 16 );
