#include<iostream>
#include<list>
//#include<queue>

using namespace std;

class Graph
{
    public:
        Graph(int _size) : mSize(_size)
        {
            mAdj = new list<int>[mSize];
        }
        virtual ~Graph() {}

        void addEdge(const char source, const char dest)
        {
            mAdj[source].push_back(dest);
        }

        void printG()
        {
            for (int i = 0; i < mSize; i++)
            {
                std::cout << "i = " << i << std::endl;
                for(list<int>::iterator itr = mAdj[i].begin(); itr != mAdj[i].end(); itr++)
                    std::cout <<  *itr << " ";
                std::cout << std::endl;
            }
        }

        void dfs(int start)
        {
            bool *visited = new bool[mSize];
            for (int i = 0; i < mSize; i++)
            {
                visited[i] = false;
            }
            dfsInternal(start, visited);
            delete []visited;
        }

        void dfsInternal(int node, bool visited[])
        {
            visited[node] = true;

            cout<< "visited " << node;
            std::cout << std::endl;
            typedef list<int>::iterator iter;
            for (iter itr = mAdj[node].begin(); itr != mAdj[node].end(); itr++)
            {
              //  cout << " print level " << *itr;
                if (!visited[*itr])
                {
                    dfsInternal(*itr, visited);
                }
            }
        }

    private:
        list<int> *mAdj;
        int       mSize;
};
int main()
{
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,4);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,6);
    g.addEdge(5,6);

//    g.printG();
    g.dfs(0);

    return 0;
}
