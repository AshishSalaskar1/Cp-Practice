/*
ip: 5
 1    2   3    4   5
 11   12  13   14  15
 21   22  23   24  25
 16   17  18   19  20
 6    7    8   9   10
 ip: 4
 1  2  3  4
 9 10 11 12
13 14 15 16
 5  6  7  8
*/
#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
int m,n;

#include <bits/stdc++.h>
using namespace std;

// n - number of rows given
void printPattern(int n){
	 int arr[n],temp=1;
    for(int i=0;i<n;i++){
        arr[i] = temp;
        temp += n;
    }
    


    for(int i=0;i<n;i+=2)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i]++<<" ";
        
        cout<<endl;  
    }

    for(int i=n-1;i>=0;i--)
    {
        if(i%2 == 0) continue;
        for(int j=0;j<n;j++)
            cout<<arr[i]++<<" ";
        
        cout<<endl;  
    }

}

int main(){
    int a[] = {1, 7 ,8 ,5 ,9};

    printPattern(5);

    return 0;
}

