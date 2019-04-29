#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*check min hotel rooms needed
3
1 3 5 : arrival
2 6 8 : departure
*/


int main()
{
    ifstream cin ("input.txt");

    int n,temp,counter = 0;
    cin>>n;

    //pair => <day,arrive:0,check-out: 1>
    vector<pair<int,int>> a;

    for (int i=0;i<n;i++){
        cin >> temp;
        a.push_back(make_pair(temp,0));
        counter++;
    }

    for (int i=counter;i<2*n;i++){
        cin >> temp;
        a.push_back(make_pair(temp,1));
    }

    //cout<<"size: "<<a.size()<<endl;
    sort(a.begin(),a.end());

    //sort -> iterate -> 0 room++ -> 1 room-- -> res = maxRoomsAtAnyTime
    int rooms=0,resMax=0;
    for (int i=0;i<a.size();i++){
        //cout<<a[i].first<<" : "<<a[i].second<<endl;
        
        if(resMax < rooms)
            resMax = rooms;

        if(a[i].second == 0)
            rooms++;
        else
            rooms--;
    }

    cout<<resMax<<endl;


    return 0;
}
