#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int scan(){
    	register int c = getchar_unlocked();
        register int n = 0;
        for( ; (c<48 || c>57); c = getchar_unlocked() );
        for( ; (c>47 && c<58); c = getchar_unlocked() ){
            n = (n<<1) + (n<<3) +c -48;
        }
        return n;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
   
    return 0;
}
