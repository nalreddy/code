pure virtual function implementation in base clase or definition in base class

struct S 
{
    virtual void foo() = 0;
};

void S::foo() 
{
    // body for pure virtual function `S::foo`
}

struct D : S 
{
    void foo() 
    {
        S::foo();       
        // Non-virtual call to `S::foo` from derived class

        this->S::foo(); 
        // Alternative syntax to perform the same non-virtual call 
        // to `S::foo` from derived class
    }
};



int main() 
{
    D d;

    d.S::foo(); 
    // Another non-virtual call to `S::foo`
}
