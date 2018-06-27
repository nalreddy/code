#include<iostream>
#include<map>

using namespace std;

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;

struct node* get_node (int key)
{
    struct node* temp = new struct node;

    temp->data = key;
    return temp;
}

int main() 
{
    map<int, Node *> mp;

    mp[1] = get_node(1);
    mp[2] = get_node(2);
    mp[3] = get_node(3);
    mp[4] = get_node(4);

    if (mp.find(1) != mp.end())
        cout << "found \n";
//    mp.insert(make_pair(1, 111));
    map<int, struct node *> :: iterator it;

    for (it = mp.begin() ; it != mp.end(); it++){
         cout << (*it).first << " " <<(*it).second->data << endl;
    }

    
    return 0;
}
