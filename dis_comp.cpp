#include<iostream>
#include<list>
#include<stdio.h>
#include"opencv2/highgui.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/core.hpp"

using namespace std;
using namespace cv;

typedef struct node
{
    int i;
    int j;
}node;
 
class Graph
{
    int V;    
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(node V);  
    void addEdge(node v, node w);
    void DFS(node v);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<node>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    //cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}