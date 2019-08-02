#include<iostream>
#include <boost/intrusive/list.hpp>

using namespace boost::intrusive;
using namespace std;

//A class that can be inserted in an intrusive list
class my_class : public list_base_hook<>
{
   public:
   my_class(int o, int l)
      :  offset(o), level(l)
   {}

   int offset;
   int level;
   //...
};

//Definition of the intrusive list
typedef list<my_class> my_class_list;

//The predicate function
struct predicate
{
    int offset;
    int level;
    predicate(int o, int l) : offset(o), level(l) {}

   bool operator()(const my_class &c) const
   {  return (offset == c.offset) && ( level == c.level);  }
};

//The disposer object function
struct delete_disposer
{
   void operator()(my_class *delete_this)
   {  delete delete_this;  }
};

int main()
{
   const int MaxElem = 100;

   //Fill all the nodes and insert them in the list
   my_class_list mlist;

   try{
      //Insert new objects in the container
      for(int i = 0; i < MaxElem; ++i) mlist.push_back(*new my_class(i, i));

      std::cout << " list size " <<mlist.size() << endl;
      predicate pre( 1, 1);
      //Now use remove_and_dispose_if to erase and delete the objects
      mlist.remove_and_dispose_if(pre, delete_disposer());
   }
   catch(...){
      //If something throws, make sure that all the memory is freed
     mlist.clear_and_dispose(delete_disposer());
     throw;
   }
 
   list<my_class>::iterator it;

   for( it = mlist.begin(); it != mlist.end(); ++it )
   {
       my_class node= *it;
       cout << " offset " << node.offset << " level " << node.level << endl;
   }
   std::cout << " list size " << mlist.size() << endl;
   //Dispose remaining elements
   mlist.erase_and_dispose(mlist.begin(), mlist.end(), delete_disposer());
   return 0;
}
