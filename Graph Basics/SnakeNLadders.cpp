#include <bits/stdc++.h>
#define pb push_back
using namespace std;

//Graph of ints
class Graph{
    int V;
    
    //int *a : dynamic array
    list<int> *adjList;
    
    public:
    
        Graph(int v){
          V = v;
          adjList = new list<int>[V];
        }
        
        void addEdge(int u,int v,bool bi = true){
            adjList[u].pb(v);
            if(bi){
                adjList[v].pb(u);
            }
        }
        
        void printGraph(){
            for(int i=0;i<V;i++){
                cout<<i<<"-->";
                
                for(int x: adjList[i]){
                    cout<<x<<" ";
                }
                
                cout<<"\n";
            }
        }
        
        void bfsShortestPath(int src,int dest){
            queue<int> q;
            bool *visited = new bool[V]{0};
            int *distance = new int[V]{0};
            int *parent = new int[V]{-1};
            
            //push src node
            q.push(src);
            visited[src] = true;
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                // cout<<node<<endl;
                
                for(int neighbour: adjList[node]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        
                        distance[neighbour] = distance[node]+1;
                        parent[neighbour] = node;
                    }
                }
                
            }
            
            cout<<"Shortest Distance: "<<distance[dest]<<endl;
            cout<<"Shortest Path is: "<<endl;
            int temp = dest;
            while (temp != -1){
                
                cout<<temp<<"<--";
                temp = parent[temp];
            }

            
        }
        
};


int main()
{

    Graph g(50);
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    
    cout<<"asda\n";
    for(int u=0;u<36;u++){
        for(int dice =1;dice<=6;dice++){
            int v = u + dice + board[u+dice];  //with snakes and ladder added
            g.addEdge(u,v,false);
        }
    }
  
 
    g.bfsShortestPath(0,36);
   
   return 0;
}