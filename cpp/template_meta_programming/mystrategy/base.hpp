#include<array>
#include"strategy.hpp"

class Base
{
    public:
        enum DigType{
            UN,
            SHA1,
            SHA2
        };
        template<DigType T>
        static recur(Base::Table &tb)
        {
            DigType cur = static_cast<DigType>(T -1);
            recur<cur>(tb);
            tb[cur].reset(new SslStrategy<cur>());
        }
        template<>
         void recur<static_cast<DigType> (0)>(Base::Table& tb)
         {
         }
        static void buildarray()
        {
            recur<2>(tb);
        }
        static  SslStrategy& getStrategy(DigType T)
        {
            return *(tb[T]);
        }
    private:
        typedef static std::array<SslStrategy*, 3> Table;
        Table tb;
};
