
#include<iostream>
#include<chrono>
#include<algorithm>
#define ll long long
using namespace std;
using namespace std::chrono;

int binSearch(int a[],int n,int item){

    sort(a,a+n);

    int l,r,mid;
    l = 0,r=n-1;
    while(l<=r){
        mid = (l+r)/2;

        if(a[mid] == item) return mid;

        else if(item<a[mid]) r=mid-1;

        else l = mid+1;
    }

    return -1;

}

int recursiveBinSearch(int a[],int l,int r,int item){
    if(l<=r){
        int mid = l+r/2;
         
        if(a[mid] == item) 
            return mid;
        else if(item<a[mid]) 
            return recursiveBinSearch(a,l,mid-1,item);
        else
            return recursiveBinSearch(a,mid+1,r,item);
    }

    return -1;
}


int main(){
    int a[] = {1,2,34,61,6,7,34,2,3,4};
    int n = sizeof(a)/sizeof(a[0]);

    sort(a,a+n);
   
    if(recursiveBinSearch(a,0,n-1,61) != -1)
         cout<<"Found"<<endl;
    else 
        cout<<"Not Found"<<endl;
    
   return 0;
}

