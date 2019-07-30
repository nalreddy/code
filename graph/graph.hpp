#include<list>
class Graph
{
    public:
        Graph(int size);
        ~Graph();
        size_t size() const { return mSize; }
        void addEdge(const int source, const int dest);
        void print();
        void bfs(int start);
        void dfs(int start);
    private:
        void dfsInternal(int node, bool visited[]);
        std::list<int> *mAdj;
        int       mSize;
};
