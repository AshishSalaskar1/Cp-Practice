#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*check if at any index sum before == sum after
5
1 3 5 2 2

*/


int main()
{
    ifstream cin ("input.txt");

    int n,prevSum=0,total = 0;
    cin>>n;
    int a[n];

    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        total += a[i];
    }

    bool win = false;
    for(int i=0;i<n;i++){
        if( prevSum == total - (prevSum+a[i])){
            win = true;
            break;
        }
        else{
            prevSum += a[i];
        }
    }

    cout<<win<<endl;


    return 0;
}
