#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*check latgest number which can be formed
5
3 30 34 5 9
sol: 3 30:330, 330 34:34330...
*/

//custom comparator function
struct cmp{
    bool operator() (string s1,string s2){
        return s1+s2 > s2+s1;
    }
};

int main()
{
    ifstream cin ("input.txt");

    int n;

    cin>>n;
    string arr[n];

    for (int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n,cmp());

    for (int i=0;i<n;i++)
        cout<<arr[i];



    return 0;
}
