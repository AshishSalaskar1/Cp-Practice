
/*
QuickSort |-
Average: nLogn
Worst: n*n
In-Place
used for arays 
 Mergesort used for linked lists (worst:nLogn, best: n)
*/

#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int partition(int a[],int start,int end){
    int pivot = a[end];
    int pIndex = start;

    for(int i=start;i<end;i++){
        if(a[i]<=pivot){
            swap(a[i],a[pIndex]);
            pIndex++;
        }
    }

    swap(a[end],a[pIndex]);
    return pIndex;
}

void quickSort(int a[],int start, int end){
    if(start<end){
        int partitionIndex = partition(a,start,end);
        quickSort(a,start,partitionIndex-1);
        quickSort(a,partitionIndex+1,end);
    }
}


int main(){
    int a[] = {1,2,34,61,6,7,34,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);

    quickSort(a,0,n-1);
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    
    
   return 0;
}

