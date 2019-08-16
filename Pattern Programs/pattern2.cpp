/*
ip: 5
1 
3 2 
4 5 6 
10 9 8 7 
11 12 13 14 15
 ip: 7
1
3 2
4 5 6
10 9 8 7
11 12 13 14 15
21 20 19 18 17 16
22 23 24 25 26 27 28
*/
#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
int m,n;

#include <bits/stdc++.h>
using namespace std;

void printPatt(int n)
{

    int count = 0;
    for(int i=1;i<=n;i++){
        int temp = count+i;
        
        if(i%2 ==0){
            count = temp;
            for(int j=0;j<i;j++){
                cout<<temp--<<" ";
            }
            
        }
        else{
            for(int j=0;j<i;j++){
                cout<<++count<<" ";
            }
        }

        
        cout<<endl;
        
    }
}


int main(){
    int a[] = {1, 7 ,8 ,5 ,9};

    printPatt(5);

    return 0;
}

