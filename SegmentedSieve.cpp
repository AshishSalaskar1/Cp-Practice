/* Input: 
N
Left Right
ex: 1
    1 10
*/


#include <bits/stdc++.h>
#define ll long long
const int MAX = 100003;
using namespace std;

void simpleSieve(vector<int> &primes){

    //Simple Sieve of eratosthenes
    bool isPrime[MAX];
    memset(isPrime,true,sizeof(isPrime));

    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j = i*i;j<MAX;j+=i){
                isPrime[j] = false;
            }

        }
    }

    for (int i=2;i<MAX;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }

}


void segmentedSieve(ll l,ll r){
    vector<int> primes;
    simpleSieve(primes);

    bool isPrime[r-l+1];
    memset(isPrime,true,sizeof(isPrime));

    for(int i=0; primes[i]*(ll)primes[i]<=r ;i++){
        ll curPrime = primes[i];

        //reduce base to val less than or equal to base (floor can also be used)
        ll base = (l/curPrime)*curPrime;
        if(base<l)
            base += curPrime;

        for(ll j=base; j<=r; j+=curPrime){
            isPrime[j-l] = false;
        }

        //if base itself is prime
        if(base == curPrime)
            isPrime[base-l] = true;

    }

    for(int i=0; i<r-l+1; i++){
        if(isPrime[i])
//            primes.push_back(l+i);
            cout<<i+l<<endl;
    }

}


int main(){

    int n;
    ifstream cin ("input.txt");
    cin >> n;
    while(n--){
        ll l,r;
        cin>>l>>r;
        segmentedSieve(l,r);
    }


    return 0;
}
