/* Statement: Given M and N find all pairs of consecutive primes 
 (p1,p2) such that the difference is 6 ie p1-p2=6 & p2>p1,
 Value of m,n: 1 < m,n < 1,000,000 
 Note: The code only works upto 1,000,000, For greater values 
 segmented sieve needs to be implemented
*/


#include<iostream>
#include<string.h>
#define ll long long
using namespace std;

int secyPair(ll m,ll n){
    int countPairs = 0;
    bool primes[n+1];
    memset(primes,true,sizeof(primes));
    
    for(int i=2;i*i<=n;i++){
        if(primes[i]){
            for(int j=i*2;j<=n;j+=i)
                primes[j] = false;
        }
    }

    for(int i=m;i<=n-6;i++){
        if(primes[i] && primes[i+6])
            countPairs++;
    }

    return countPairs;
}

int main(){
    ll m,n;
    cin>>m>>n;
   cout<< secyPair(m,n)<<endl;

    return 0;
}
