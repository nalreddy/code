
template <ObjectSignatureBase::SizeType T> struct SizeTypeTraits {};

#define DECLARE_SIZE_TYPE_TRAITS( Enum, Meta, Kb, Blocks )          \
template <>                                                         \
    struct SizeTypeTraits<Enum>                                     \
{                                                                   \
    BOOST_STATIC_CONSTANT( bool, Metadata = Meta );                 \
    BOOST_STATIC_CONSTANT( size_t, SizeKb = Kb##ull );              \
    BOOST_STATIC_CONSTANT( size_t, SizeBytes = SizeKb * 1024ull );  \
    BOOST_STATIC_CONSTANT( size_t, BlockCount = Blocks );           \
};

DECLARE_SIZE_TYPE_TRAITS( ObjectSignatureBase::meta_1K,  true,  1,  1 );
DECLARE_SIZE_TYPE_TRAITS( ObjectSignatureBase::data_4K,  false, 4,  1 );
DECLARE_SIZE_TYPE_TRAITS( ObjectSignatureBase::data_8K,  false, 8,  2 );
DECLARE_SIZE_TYPE_TRAITS( ObjectSignatureBase::data_16K, false, 16, 4 );
DECLARE_SIZE_TYPE_TRAITS( ObjectSignatureBase::data_32K, false, 32, 8 );
DECLARE_SIZE_TYPE_TRAITS( ObjectSignatureBase::data_64K, false, 64, 16 );
