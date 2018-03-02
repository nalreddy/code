#include<iostream>

using namespace std;

class A
{
    private:
        int x;
    
    public:
        /*
      //  A(int a, char s, float d)
      //  { 
      //      x = a;
      //      c = s;
      //      f = d;
      //      cout<<"x = "<<x <<"c ="<< c << "f"<< f<<endl;
      //  }

        A(const A &a)
        {
            x = a.x;
            c = a.c;
            f = a.f;
            cout<<" copy constructor x = "<<x <<"c ="<< c << "f"<< f<<endl;
        }

        A(int a, char s, float d):  c(s),x(a), f(d)
        { 
            x = a;
            c = s;
            f = d;
         //   cout<<"x = "<<x <<"c ="<< c << "f"<< f<<endl;
        }
        */
        A()
        {
            cout << "default constructor "<<endl;
        }

       // void get_x()
       // {
       //     cout<<"x = "<<x<<endl;
       // }
        
        void set_x(int x);
        ~A()
        {
            cout <<"default destructor " << endl;
        }
};

void A::set_x(int x)
{
   this->x = x;
}


int main()
{
    A a;
    
   // A a(1,'b',2.4);
   // A b(a);
   // A c = b; 
//    
//    A *a = new A(20);
//    a->get_x();
//    a->set_x(10);
//    a->get_x();
//
    return 0;
}

