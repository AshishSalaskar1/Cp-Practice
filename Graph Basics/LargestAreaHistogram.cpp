#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxAreaHist(int a[],int n){
    
    stack<int> s;
    int maxArea,curArea;
    int i=0,tp;
    
    while(i<n) {
        //current bar greater than previous bar
        if (s.empty() || a[s.top()] <= a[i] ){
            s.push(i++);
        }
        
        //if present bar is lower than higher
        else {
            tp = s.top();
            s.pop();
            
            if(s.empty()) {
                //popped bar height * index
                curArea = a[tp] * i;
            }
            else {
                //popped bar height * (index- rightBound - 1);
                 curArea = a[tp] * (i - s.top() - 1);
            }
            
            if (curArea > maxArea) {
                maxArea = curArea;
            }
        }
    }
    
    //pop all remaining bars
    while(!s.empty()) {
        tp = s.top();
            s.pop();
            
            if(s.empty()) {
                curArea = a[tp] * i;
            }
            else {
                 curArea = a[tp] * (i - s.top() - 1);
            }
            
            if (curArea > maxArea) {
                maxArea = curArea;
            }
    }
    
    // cout<<maxArea<<endl;
    return maxArea;
   
    
}

int main()
{
   int n;
   cin>>n;
   int a[n];

   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   
   cout<<maxAreaHist(a,n)<<endl;
   
   
   
   return 0;
}