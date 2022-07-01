/*
Problem Statement
You are given an undirected and disconnected graph G(V, E) having V vertices numbered from 0 to V-1 and E edges. Your task is to print its BFS traversal starting from the 0th vertex.
BFS or Breadth-First Traversal of a graph is an algorithm used to visit all of the nodes of a given graph. In this traversal algorithm, one node is selected, and then all of the adjacent nodes are visited one by one.
An undirected graph is a graph where all the edges are bidirectional, i.e., they point from source to destination and destination to source.
A graph is disconnected if at least two vertices of the graph are not connected by a path.
Note:
1. Here, you need to consider that you need to print the BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G, and all vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Graph input is provided as the number of vertices and a list of edges.
5. Handle for Disconnected Graphs as well.
For Example: Consider graph:

Here, starting from 0, it is connected to 1 and 2 so, BFS traversal from here will be [0, 1, 2 ]. Now, 3 is also connected to 2. So, BFS traversal becomes [0, 1, 2, 3].
Note:
For each node, the correct order of printing the connected nodes will be sorted order, i.e., if {3,6,9,4} are connected to 1, then the correct order of their printing is {1,3,4,6,9}.
Input Format :
The first line of input contains two integers that denote the value of V and E.
Each of the following E lines contains space-separated two integers that denote an edge between vertex A and B.
Output Format :
For each test case, print the BFS Traversal, as described in the task.
Output for each test case will be printed in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints :
0 <= V <= 10^4
0 <= E <= (V * (V - 1)) / 2
0 <= A <= V - 1
0 <= B <= V - 1

Where 'V' is the number of vertices, 'E' is the number of edges, 'A' and 'B' are the vertex numbers.
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>res;
    vector<int>adj[vertex+1];
    for(auto it:edges)
    {
        int u=it.first;
        int v=it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>visited(vertex+1,false);
    
//     q.push(0);
//     visited[0]=true;
    for(int i=0;i<=vertex-1;i++)
    {
        if(!visited[i])
        {
            queue<int>q;
            q.push(i);
            visited[i]=true;
            while(!q.empty())
            {
                auto u=q.front();q.pop();
                res.push_back(u);
                for(auto it:adj[u])
                {
                    if(visited[it]) continue;
                    else
                    {
                        visited[it]=true;
                        q.push(it);
                    }
                }
            }
//             q.clear();
        }
    }
    return res;
}


