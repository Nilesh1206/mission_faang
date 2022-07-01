/*
Problem Statement
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ 
edges. Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance 
between them.
Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex 
given to you in the graph. The graph may contain negatively weighted edges.


Sample Input 1 :
1    
4 4 1 4
1 2 4
1 3 3
2 4 7 
3 4 -2
Sample Output 1 :
1
*/


// In this program we are going to find the shotest distance between all nodes from the single soure of node

#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>>edges;
const int n=100;
int dist[n];

void addEdge(int u,int v,int w)
{
    edges.push_back({u,v,w});
    edges.push_back({v,u,w});
}

void BellmanFord(int s,int size,int nodes)
{
    // Initialises all the points as infinite 
    for(int i=1;i<=size;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0; // Source point at 0 distance


    //In this graph each node visited n-1 times , so every iteration it calculate the minumum distance and update it
    // also this graph can help us to find any negative cycle is present or not
    for(int i=1;i<=size-1;i++)
    {
        // int u,v,w;
        for(auto ele:edges)
        {
            int u,v,w;
            tie(u,v,w)=ele;   // source , target , weight
            dist[v]=min(dist[v],dist[u]+w);  // Update the distance of target from the source if it is less 
        }
    }
    cout<<"Below is the  shortest distance of a nodes from the single source of of a node "<<endl;
    for(int i=1;i<=nodes;i++)
    {
        cout<<s<<"-->"<<i<<"="<<dist[i]<<endl;
    }
}
// Time Complexity: O(n*m)
//Space Somplexity: O(n);


int main()
{
    int nodes;
    int edge;
    cin>>nodes>>edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
    }
    BellmanFord(1,edge,nodes);
}


/*
Auxilary Function to detect negative weight cycle in graph
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int des[n]={0};
	    for(int i=0;i<n-1;i++)
	    {
	        bool notUpd=true;
	        for(auto edge:edges)
	        {
	            int u=edge[0];
	            int v=edge[1];
	            int weight=edge[2];
	            if(des[v]>des[u]+weight)
	            {
	                des[v]=des[u]+weight;
	            }
	        }
	        if(notUpd)
	        {
	            break;
	        }
	    }
	    for(auto edge: edges)
	    {
	        int u=edge[0];
	            int v=edge[1];
	            int weight=edge[2];
	            if(des[v]>des[u]+weight)
	            {
	                return true;
	            }
	    }
	    return false;
	}
};
*/









// Time Complexity: O(N*E). We check E edges N times
// Space Complexity: O(N). Distance Array