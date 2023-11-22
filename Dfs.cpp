#include <bits/stdc++.h>
using namespace std;

// dfs :

class Graph
{
    
    public : 
        
        int V; 
        
        vector<list<int>> adjList;
        
        Graph(int V)
        {
            this->V = V;
            adjList.resize(V);
        }
        
        void addEdge(int u , int v)
        {
            adjList[u].push_back(v);
        }
        
        void dfs(int s)
        {
            // Depth First Search : 
            stack<int> S;
            
            vector<bool> visited(V,false);
            
            visited[s] = 1; // pushing the source vertex in the stack
            
            S.push(s);
            
            while(!S.empty())
            {
                s = S.top();
                cout << s << " ";
                S.pop();
                
                for(auto it : adjList[s])
                {
                    if(visited[it] == 0)
                    {
                        visited[it] = 1;
                        S.push(it);
                    }
                }
            }
            cout << endl;
        }
    
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.dfs(2);

    
    return 0;
}
/*
Following is Depth First Traversal (starting from vertex 2) 
2 3 0 1 

Following is Breadth First Traversal (starting from vertex 2) 
2 0 3 1 
Visited array :1 1 1 1 
*/

