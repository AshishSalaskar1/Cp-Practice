/*
n = no of nodes
m = no of edges
(unidirectional edges considered)
print no of nodes reachable from each node
i/p:
3 3
1 2
2 3
3 1
o/p:  3 3 3 
*/

#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int n;

void findPaths(int vertex,vector<int> *arr,bool vis[],int *count){
    int swaps = false;
    int next;
    *count += 1;
    vis[vertex] = true;
    for(int i=0;i<arr[vertex].size();i++){
        next = arr[vertex][i];
        if(!vis[next]){
            swaps = true;
            findPaths(next,arr,vis,count);
        }
    }

    if(!swaps) return;
}


int main(){
    int m,src,dest;
    cin>>n>>m;

    cout<<endl;

    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        cin>>src>>dest;
        arr[src].push_back(dest);
    }



    for(int i=1;i<=n;i++){
        int count = 0;
        bool vis[n+1];
        memset(vis,false,sizeof(vis));
        findPaths(i,arr,vis,&count);
        cout<<count<<endl;
    }


  

    return 0;
}

