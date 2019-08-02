#include"node.hpp"

class Btree
{
    public:
        Btree()
        {
            root = nullptr; // ??
        }
        ~Btree()
        {
            //delete tree
        }

        void insert(const int);
    private:
        struct Node* root;  // nulptr
};

void Btree :: 
