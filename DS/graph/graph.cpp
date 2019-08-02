#include<iostream>
#include<queue>
#include"graph.hpp"

using namespace std;

Graph::Graph(int _size) : mSize(_size)
{
    mAdj = new std::list<int>[mSize];
    std::cout <<" ctor " << std::endl;
}

Graph::~Graph()
{
    delete []mAdj;
    std::cout <<" dtor " << std::endl;
}

void Graph::addEdge(const int source, const int dest)
{
    mAdj[source].push_back(dest);
}

void Graph::print()
{
    for (int i = 0; i < mSize; i++)
    {
        std::cout << "i = " << i << std::endl;
        for(list<int>::iterator itr = mAdj[i].begin(); itr != mAdj[i].end(); itr++)
            std::cout <<  *itr << " ";
        std::cout << std::endl;
    }
}

void Graph::bfs(int start)
{
    std::cout << "BFS " << std::endl;
    bool *visited = new bool[mSize];
    for (int i = 0; i < mSize; i++)
    {
        visited[i] = false;
    }

    queue<int> gq;

    visited[start] = true;
    gq.push(start);

    typedef list<int>::iterator iter;
    while (!gq.empty())
    {
        int v = gq.front();
        std::cout<< " " << v;
        gq.pop();
        for (iter itr = mAdj[v].begin(); itr != mAdj[v].end(); itr++)
        {
            std::cout << " print level " << *itr;
            if (!visited[*itr])
            {
                visited[*itr] = true;
                gq.push(*itr);
            }
        }
        std::cout << std::endl;
    }
    delete []visited;
}

void Graph::dfs(int start)
{
    std::cout << "DFS" << std::endl;
    bool *visited = new bool[mSize];
    for (int i = 0; i < mSize; i++)
    {
        visited[i] = false;
    }
    dfsInternal(start, visited);
    delete []visited;
}

void Graph::dfsInternal(int node, bool visited[])
{
    visited[node] = true;

    std::cout<< "visited " << node;
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
