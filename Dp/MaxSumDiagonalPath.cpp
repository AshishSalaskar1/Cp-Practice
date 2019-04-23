/*Input:
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Ans: 73*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e+3;
int n;
int a[N][N],vis[N][N],dp[N][N];

int go(int i,int j){

    if(vis[i][j])
        return dp[i][j];

    vis[i][j] = 1;
    int &ans = dp[i][j];


    if (i==n-1 and j==n-1)
        ans =  a[i][j];
    if (i<n-1 and j<n-1)
        ans =  a[i][j] + max(go(i+1,j),go(i,j+1));
    if (i==n-1 and j<n-1)
        ans =  a[i][j] + go(i,j+1);
    if (j==n-1 and i<n-1)
        ans =  a[i][j] + go(i+1,j);

    return ans;

}

int main(){
    //ifstream cin ("inp.txt");
    cin >> n;
    int temp;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>temp;
            a[i][j] = temp;
        }

    }
    cout<<go(0,0)<<endl;
    return 0;
}
