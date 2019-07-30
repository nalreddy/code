class A;

class B
{
    public:
        B();
        ~B() {}
        inter& getA() { return *ai; }
    private:
        inter* ai;
};

