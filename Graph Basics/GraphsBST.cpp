#include <bits/stdc++.h>
#define pb push_back
using namespace std;

//Graph of ints
class Graph1{
    int V;
    
    //int *a : dynamic array
    list<int> *adjList;
    
    public:
    
        Graph1(int v){
          V = v;
          adjList = new list<int>[V];
        }
        
        void addEdge(int u,int v,bool bi = false){
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
        
};


//Graph of type t
template<typename T>
class Graph2{
    int V;
    //incase of weighted: map <T, list<pair<T,int>> > adjList; 
    map <T,list<T> > adjList;
    
    public:
       
        void addEdge(T u,T v,bool bi = true){
            adjList[u].pb(v);
            if(bi){
                adjList[v].pb(u);
            }
        }
        
        void printGraph(){
            for(pair<T,list<T> > row: adjList){
                cout<<row.first<<"-->";
                
                for(T element: row.second ){
                    cout<<element<<" ";
                }
                cout<<"\n";
            }
        }
        
        void bfs(int src){
                    queue<int> q;
                    bool *visited = new bool[V]{0};
                    
                    //push src node
                    q.push(src);
                    visited[src] = true;
                    
                    while(!q.empty()){
                        int node = q.front();
                        q.pop();
                        cout<<node<<endl;
                        
                        for(int neighbour: adjList[node]){
                            if(!visited[neighbour]){
                                q.push(neighbour);
                                visited[neighbour] = true;
                            }
                        }
                    }
                    
        }
        
        
        
};


int main()
{
   Graph2<int> g;
  
  g.addEdge(1,2);
  g.addEdge(1,5);
  g.addEdge(1,3);
  g.addEdge(1,4);
  g.addEdge(3,4);
  g.addEdge(5,4);
  g.printGraph();
   
   return 0;
}