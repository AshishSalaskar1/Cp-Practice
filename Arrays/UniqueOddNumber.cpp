#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*check only number which is not repeated where each no is repeated twice except one
3
5 8 5
sol: 8

Approach: a^a = 0 ; a^0 = a..so XOR all numbers..res will be the unique number
*/


int main()
{
    ifstream cin ("input.txt");

    int n;

    cin>>n;
    int arr[n];

    for (int i=0;i<n;i++)
        cin>>arr[i];

    int res = 0;
    for (int i=0;i<n;i++){
        res = res ^ arr[i];
    }

    cout<<res<<endl;




    return 0;
}
