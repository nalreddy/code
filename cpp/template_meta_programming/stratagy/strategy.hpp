#pragma once


template <Base::Type stT>
    class  SslStrategy : public Strategy
{
    public:

        typedef Traits<estT>                           Traits;
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
        void doCalc( const uint8_t* _data, const size_t _length, uint8_t* _out )
        {
            EVP_MD_CTX* mdc = EVP_MD_CTX_new();

            int result = EVP_DigestInit_ex( mdc, Traits::Struct(), NULL );
            check( result, "EVP_DigestInit_ex" );

            result = EVP_DigestUpdate( mdc, _data, _length );
            check( result, "EVP_DigestUpdate" );

            result = EVP_DigestFinal_ex( mdc, _out, NULL );
            check( result, "EVP_DigestFinal_ex" );

            EVP_MD_CTX_free( mdc );
        }
};
