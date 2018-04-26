#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define MAX_SIZE 26

#define char_int(c) ((int)c - (int)'a')
 
//converts current integer into character
#define int_to_char(c) ((char)c + (char)'a')


typedef struct trie_node
{
    struct trie_node* child[MAX_SIZE];
    bool is_endofword;
}node;

node* get_node()
{
    node* temp = new struct trie_node;

    for (int i = 0; i < MAX_SIZE; i++) {
        temp->child[i] = NULL;
    }
    temp->is_endofword = false;
    return temp;
}

class Trie
{
    public :
        Trie() { root = get_node(); }
        void insert(string word);
        bool search(string word);
    private:
        node* root;
};

void Trie :: insert(string word)
{
    node* cur = root;
    node* temp = NULL;


    for (int i = 0; i < word.length(); i++) {
         temp = cur->child[char_int(word[i])];
         if (!temp) {
             temp = cur->child[char_int(word[i])] =  get_node();
             cur = temp;
         }
    }
    cur->is_endofword = true;
}

bool Trie :: search(string word)
{
    node* cur = root;

    for (int i = 0; i < word.length(); i++) 
    {
        cur = cur->child[char_int(word[i])];

        if(!cur) { return false;};
    }

    if(cur && cur->is_endofword) {
        cout << "search word " << word << endl;
        return true;
    }

    return false;
}

void Trie :: print(node* root, string word)
{
    node* temp = root;

    for ( int i = 0; i < MAX_SIZE; i++) {
        
         if(temp->child[i]) {
             word += int_char(i);
         }
         print(temp->child[i], word);
         if(temp->is_endofword) cout << word << endl;
         word.erase(word.end() -1);
    }
    return;
}

void Trie :: print_words()
{
    string str = "" ;

    print(root, str);
}

int main()
{
    Trie t;

    t.insert("abc");
    t.search("abc");

    return 0;
}
