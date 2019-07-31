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

template <OSig::DigestType T>
    void recurStrategies(
                    Oigor::DigyArrayType& _array )
{
        const Oe::DigestType cur = static_cast<Obegn::DigestType>( T - 1 );
            recurStrategies<cur>( _array );
                _array[cur].reset( new Orategy<cur>() );
}

template<>
    void recurStrategies<static_cast<OeBase::DigestType>( 0 )>(
                    Objer::DyType& _array )
{
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
