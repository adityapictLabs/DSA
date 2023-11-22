// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // Number of vertices 
    public : 
        int V;
        
        // Adjacency List : 
        vector<vector<int>> adjList;
        
        Graph(int V)
        {
            this->V = V;
            adjList.resize(V);
        }
        
        void addEdge(int u , int v)
        {
            // Add v to the list of u
            adjList[u].push_back(v);
        }
        
        void bfs(int s)
        {
            // s -> source : 
            list<int> Queue;
            
            vector<bool> visited(V,false);
            
            visited[s] = 1; // Source visited 
            
            Queue.push_back(s);
            
            while(!Queue.empty())
            {
                s = Queue.front();
                cout << s << " ";
                Queue.pop_front();
                
                for(auto it : adjList[s])
                {
                    if(visited[it] == 0)
                    {
                        
                        visited[it] = 1;
                        Queue.push_back(it);
                    }
                }
            }
            cout <<endl << "Visited array :" ;
            for(int i = 0 ; i < V;i++)
            {
                cout << visited[i] << " ";
            }
            cout << endl;
        }
};




int main() {
    
    // Bfs code : 
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
    

    return 0;
}
