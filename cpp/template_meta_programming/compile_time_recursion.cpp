#include<iostream>
//https://en.wikibooks.org/wiki/C%2B%2B_Programming/Templates/Template_Meta-Programming

using namespace std;
#if 0
template<int N> void f1()
{ 
        f1<N-1>(); 
            cout << N << '\n'; 
}

template<> void f1<1>() 
{ 
        cout << 1 << '\n'; 
}

int main()
{
        f1<1000>();
}
#endif

// Compile-time recursion to assign strategy implementations to an array.

template <ObjectSig::DigestType T>
    void recursivelyAssignDigestStrategies(
                    ObjectSigor::DigestTypeStrategyArrayType& _array )
{
        const ObjectSigBase::DigestType cur = static_cast<ObjectSign::DigestType>( T - 1 );
            recursivelyAssignDigestStrategies<cur>( _array );
                _array[cur].reset( new OpenSslDigestStrategy<cur>() );
}

template<>
    void recursivelyAssignDigestStrategies<static_cast<ObjectSignatureBase::DigestType>( 0 )>(
                    ObjectSignatureBaseAccessor::DigestTypeStrategyArrayType& _array )
{
        // Terminate Recursion
}

template <unsigned n>
struct factorial
{
      enum { value = n * factorial<n-1>::value };
};

template <>
struct factorial<0>
{
      enum { value = 1 };
};


 
int main() {
      int array[ factorial<7>::value ];
}
