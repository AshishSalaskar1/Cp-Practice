
/*
BubbleSort
*/

#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

void bubbleSort(int a[],int n){
    //if no swaps made === already sorted
    bool flag = false;
    for(int i=0;i<n;i++){
        flag = false;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag = true;
            }      
        }
        if(!flag) break;
    }
}


int main(){
    int a[] = {1,2,34,61,6,7,34,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);

    bubbleSort(a,n);
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    
    
   return 0;
}

