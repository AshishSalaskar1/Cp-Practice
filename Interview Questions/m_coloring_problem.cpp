/*
4 4
1 2
2 3
3 4
4 1

*/


#include<iostream>
#include<string.h>
#include<vector>
#define ll long long
using namespace std;
int n;
int nColors;

/*
in cArray 0 == -1, notFilled
and >1 represent colors
*/

bool isSafe(int vertex,int color,vector<int> *arr,int cArray[]){
    for(int i=0;i<arr[vertex].size();i++){
        if(color == cArray[arr[vertex][i]])
        {
            return false;
        }
    }
    return true;
}

bool graphColorUtil(int vertex,vector<int> *arr,int cArray[]){

    if(vertex >= n)
        return true;
    
    for(int color=1;color <= nColors;color++){
        if(isSafe(vertex,color,arr,cArray )){
            cout<<"yes";
            cArray[vertex] = color;

            if(graphColorUtil(vertex+1,arr,cArray))
                return true;

            cArray[vertex] = 0;
        }
    }

    return false;
}

void printColorFilled(vector<int> *arr,int cArray[]){
    for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<":"<<cArray[i]<<endl;
    }
}


bool graphColor(vector<int> *arr){
    
    int cArray[n+1];
    memset(cArray,0,sizeof(cArray));

    if(!graphColorUtil(1,arr,cArray)){
        return false;
    }

    // printColorFilled(arr,cArray);
    return true;

}


int main(){
    int m,src,dest;
    cin>>n>>m;
    nColors = 2;

    cout<<endl;

    vector<int> arr[n+1];
    for(int i=0;i<m;i++){
        cin>>src>>dest;
        arr[src].push_back(dest);
        arr[dest].push_back(src);
    }

    cout<<graphColor(arr)<<endl;




    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<arr[i].size();j++)
    //         cout<<i<<":"<<arr[i][j]<<" ";
    //     cout<<endl;
    // }
  

    return 0;
}

