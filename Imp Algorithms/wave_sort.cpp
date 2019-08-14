
#include<iostream>
#include<chrono>
#include<algorithm>
#define ll long long
using namespace std;
using namespace std::chrono;

void withoutSort(){
    int a[] = {1,6,22,76,23,5,12,68,2,423,45,67,87,23,45,23};

    int n = sizeof(a)/sizeof(a[0]);

    for(int i=0;i<n;i+=2){
       if(i>0 && a[i]<a[i-1]) swap(a[i],a[i-1]);
    
       if(i<= n-3 && a[i]<a[i+1]) swap(a[i],a[i+1]);
    }

    for(int i=0;i<n;i++)    cout<<a[i]<<" ";
    cout<<endl;
}

void withSort(){
     int a[] = {1,6,22,76,23,5,12,68,2,423,45,67,87,23,45,23};
     int n = sizeof(a)/sizeof(a[0]);
     sort(a,a+n);

     for (int i=0; i<n-1; i += 2) 
        swap(a[i], a[i+1]); 

    for(int i=0;i<n;i++)    cout<<a[i]<<" ";
    cout<<endl;

}


int main(){
   
    auto start = high_resolution_clock::now(); 
  
    withoutSort();

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout<<"Time taken by Without Sort: "<< duration.count()<<"ms"<< endl; 

    start = high_resolution_clock::now(); 
  
    withSort();

    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 
    cout<<"Time taken by with Sort: "<< duration.count()<<"ms"<< endl; 
    
   return 0;
}
