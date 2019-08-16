/*
Find and return the equilibrium index of an array. 
Equilibrium index of an array is an index i,
such that sum of elements on either side of i are same
i/p: 
7
-7 1 5 2 -4 3 0
and: 3

*/
#include<iostream>
#include<vector>
#include<string.h>
#define ll long long
using namespace std;
int m,n;

int printPattern(int arr[],int n){

    int lSum = arr[0];
    int rSum = 0;
    int total = 0;

    for(int i=0;i<n;i++)
         total += arr[i];


    for(int i=1;i<n;i++){
       
        rSum = total - (lSum + arr[i]);
        if (rSum == lSum) return i;
        lSum += arr[i];

    }

    return -1;
}

int main(){
    int a[] = {-7, 1, 5, 2 ,-4 ,3 ,0};

    cout<<printPattern(a,7)<<endl;

    return 0;
}

