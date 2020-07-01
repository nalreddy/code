template <typename TraitsT>
class ResourceConfigValue
{
    public:
        using traits_type = TraitsT;
        using value_type = typename traits_type::value_type;

        static_assert( std::is_pod<value_type>::value ); // value_type must be a POD

        static constexpr const char* label() { return traits_type::Label; }
        static constexpr const value_type defaultValue() { return traits_type::DefaultValue; }

        static const value_type& get() { return mValue; }
        static void set( const value_type& _value ) { mValue = _value; }

    private:
        static value_type mValue;
};

struct LogicalDiskCapacityTraits
{
        using value_type = size_t;
        static constexpr const value_type DefaultValue = value_type();
        static constexpr const char* Label = "LogicalDiskCapacity";
};

//using LogicalDiskCapacity = ResourceConfigValue<LogicalDiskCapacityTraits>;
//template <> size_t LogicalDiskCapacity::mValue = size_t();
#define DEFINE_RESOURCE_CONFIG_VALUE_DEFAULT( name, type, def ) \
            struct name##Traits    \
                    {   \
                      using value_type = type;  \
                      static constexpr value_type DefaultValue = def;    \
                      static constexpr const char* Label = #name; \
                    }; \
                      \
                    using name = ResourceConfigValue<name##Traits>; \
                    template <> type name::mValue = def;

#define DEFINE_RESOURCE_CONFIG_VALUE( name, type ) DEFINE_RESOURCE_CONFIG_VALUE_DEFAULT( name, type, type() )


namespace  meta
{
    DEFINE_RESOURCE_CONFIG_VALUE( LogicalDiskCapacity, size_t );
    DEFINE_RESOURCE_CONFIG_VALUE( MetadataCacheSizeMB, size_t );
    DEFINE_RESOURCE_CONFIG_VALUE_DEFAULT( UnitCount, size_t, 1ull );
}

/*
BOOST_AUTO_TEST_CASE( test_logicalDiskCapacity )
{
    BOOST_REQUIRE_EQUAL( LogicalDiskCapacity::get(), LogicalDiskCapacity::defaultValue() );

    const size_t newValue = 1024ull;
    LogicalDiskCapacity::set( newValue );
    BOOST_REQUIRE_EQUAL( LogicalDiskCapacity::get(), newValue );
}
*/
