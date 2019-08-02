#include<iostream>
#include<map>
#include<string>

using namespace std;

struct trie_node
{
    map<char , struct trie_node *> child;
    bool is_endofword;
};

struct trie_node * get_node()
{
    return new struct trie_node;
}

class Trie
{
    public:
        Trie() { root = new struct trie_node; }
        void insert(string word);
        bool search(string word);
        void print_words();
        void print(struct trie_node*  node, string &word);
    private:
        struct trie_node *root;
};

void Trie :: insert(string word)
{
    struct trie_node *current = root;
    struct trie_node *temp = NULL;

    if (!word.length()) return;

    for (int i = 0; i < word.length(); i++ )
    {
        temp = current->child[word[i]];
        if(temp == NULL)
        {
            current->child[word[i]] = temp = get_node();
    //        cout << "empty node " << endl;
        }
        current  = temp;
    }
    temp->is_endofword = true;
}

bool Trie :: search(string word)
{
    struct trie_node *current = root;

    for (int i = 0; i < word.length(); i++)
    {
        current = current->child[word[i]];
        if (!current) return false;
    }

    if(current && current->is_endofword) {
        cout << "search -->word found " << word << current->is_endofword << endl;
        return true;
    }
    return false;
}

void Trie :: print(struct trie_node*  node, string &word)
{
    struct trie_node* cur = node; 
    map<char, struct trie_node *> :: iterator  it = cur->child.begin();

    if (cur->is_endofword)
        cout << "end of word" << endl;

    while ( it !=  cur->child.end())
    {
        if (it->first) {
            word += it->first;

            cout << word << endl;
        
            //            cout << word << endl;
             print(it->second, word);

             if ( cur->is_endofword) {
                 cout << "from print " << word <<  " " << cur->is_endofword << endl;
            }

               // word.substr(0, word.length() - 1);
             word.erase(word.end() -1);
        }
        it++;
    }
    return;
}

void Trie :: print_words()
{ 
   string word = "";
   print(root, word);
}

int main(int argc , char **argv)
{
   // string str = argv[1];
    Trie t;

    t.insert("abc");
//    t.insert("bca");
    t.insert("ab");
  //  t.insert("bc");
    string str[] = { "abc", "ab" };

    for (int i = 0; i < 2;  i++) {
        if (t.search(str[i]))
            cout << " found word" <<  " " << str[i] << endl;
        else 
            cout << " not found the word" <<  " " << str[i] << endl;
    }
    t.print_words();
    return 0;
}
