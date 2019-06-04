namespace  ds
{
class Container
{
    public:
        Container(int s) { } ;
        Container() { } ;
        virtual ~Container() { };
        virtual double& operator [](int i) = 0;
        virtual int size() = 0;
};
}
