template <ObjectSignatureBase::DigestType DigestT>
    class  OpenSslDigestStrategy : public DigestStrategy
{
    public:

        typedef DigestTraits<DigestT>                           Traits;
        typedef boost::array<uint8_t, Traits::AlgorithmLength>  TempType;

        virtual void calc( const uint8_t* _data, const size_t _length,
            uint8_t* _out, const size_t _outLength )
        {
            if( Traits::AlgorithmLength > _outLength )
            {
                TempType tmp;
                doCalc( _data, _length, &tmp[ 0 ] );
                std::copy( &tmp[ 0 ], &tmp[ _outLength ], _out );
            }

            else
                doCalc( _data, _length, _out );
        }

    private:

        void check( const int _status, const char* _fn )
        {
            SVT_ASSERT( _status, boost::format(
                "Call to '%1%' failed : %2%" ) %
                _fn % ERR_error_string( ERR_peek_error(), NULL ) );
        }

        void doCalc( const uint8_t* _data, const size_t _length, uint8_t* _out )
        {
            EVP_MD_CTX mdc;
            EVP_MD_CTX_init( &mdc );

            int result = EVP_DigestInit_ex( &mdc, Traits::digestStruct(), NULL );
            check( result, "EVP_DigestInit_ex" );

            result = EVP_DigestUpdate( &mdc, _data, _length );
            check( result, "EVP_DigestUpdate" );

            result = EVP_DigestFinal_ex( &mdc, _out, NULL );
            check( result, "EVP_DigestFinal_ex" );

            result = EVP_MD_CTX_cleanup( &mdc );
            check( result, "EVP_MD_CTX_cleanup" );
        }
};
