#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

void sieveOfErastothenes(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    /* From p^2 mark all multiples of p as False
       Select next p which is true and repeat the same
       All true entry indices are prime numbers*/
    for(int p=2; p*p<=n; p++){
        if(prime[p]){
            for(int i=p*p; i<=n; i+=p)
               {
                    prime[i]=false;
               }
        }
    }


    //print all primes
    for(int i=2;i<n;i++){
        if(prime[i])
            cout<<i<<" ";
    }

}

int main()
{
    int n = 100;
    sieveOfErastothenes(n);
    return 0;
}
