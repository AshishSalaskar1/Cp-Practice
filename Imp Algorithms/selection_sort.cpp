
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
   
    int a[] = {1,2,7,3,5,8,22,12,9,0};
    int n = sizeof(a)/sizeof(a[0]);

    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[i]) minIndex = j;
        
        swap(a[i],a[minIndex]);
    }

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl; 
    
   return 0;
}
