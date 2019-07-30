class inter
{
    public:
        virtual void add() = 0;
};
class A : public inter
{
    public:
        A();
        ~A() {}
        void add();
};
