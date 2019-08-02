template<typename T>
class A
{
    public:
        A(T _x): x(_x) {}
        ~A() {}
        void print();
    private:
        T x;
};
