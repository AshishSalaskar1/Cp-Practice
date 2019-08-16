/*
find no of islands: use flood fill
3 3    
1 1 1
0 1 0
1 1 1
Ans: 2
*/

#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int m,n;

void findIsland(vector<vector<int>> &arr,int i,int j){
     if(i>=m || j>=m || i<0 || j<0 || arr[i][j]==0)
        return;
    else{
        arr[i][j] = 0;
        findIsland(arr,i+1,j);
        findIsland(arr,i,j+1);
        findIsland(arr,i-1,j);
        findIsland(arr,i,j-1);
    }
}

int main(){
    int temp,res=0;

    cin>>m>>n;
    vector<vector<int>> arr;

    for(int i=0;i<m;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            cin>>temp;
            row.push_back(temp);
        }
        arr.push_back(row);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                res++;
                findIsland(arr,i,j);
            }
        }
    }
    
    cout<<res<<endl;
 
   return 0;
}

