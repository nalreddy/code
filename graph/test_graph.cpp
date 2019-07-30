#include "graph.hpp"

int main()
{
    //loops 
    //self loop
    //disconnected component
    //dfs test
    {
        Graph g(7);

        g.addEdge(1,1);
        g.addEdge(0,1);
        g.addEdge(0,1);
        g.addEdge(0,2);
        g.addEdge(0,3);
        g.addEdge(1,4);
        g.addEdge(2,4);
        g.addEdge(3,5);
        g.addEdge(4,6);
        g.addEdge(5,6);

        g.print();
        g.dfs(0);
        g.bfs(0);
    }

    return 0;
}
