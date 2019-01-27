#include <bits/stdc++.h>
using namespace std;

// Demo Input
// 11 11 
// 5 5 
// a
// . . . . . # . . . . . 
// . . . . # . # . . . .
// . . . # . . . # . . .
// . . # . . . . . # . .
// . # . . . . . . . # .
// # . . . . . . . . . #
// . # . . . . . . . # .
// . . # . . . . . # . .
// . . . # . . . # . . .
// . . . . # . # . . . .
// . . . . . # . . . . .


int m,n;


void printFig(char a[][11]){

    for (int i=0;i<m;i++){
        for (int j=0;j<11;j++){
            
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
  }
  cout<<"\n";
}


void floodFill(char a[][11],int i,int j,char ch,char color){
    
    if(i<0 || j<0 || i>=m || j>=n || a[i][j]!=ch ){
        return;
    }
    
    a[i][j] = color;
    
    floodFill(a,i+1,j,ch,color);
    floodFill(a,i,j+1,ch,color);
    floodFill(a,i-1,j,ch,color);
    floodFill(a,i,j-1,ch,color);
}

int main()
{
 
   int srcI,srcJ;
   char color;
   cin>>m>>n>>srcI>>srcJ>>color;
   
  char a[m][11];
   
   
   for (int i=0;i<m;i++){
     for (int j=0;j<n;j++){
            cin>>a[i][j];
            
     }
   }
   
    cout<<"Before FloodFill"<<"\n\n";
    printFig(a);
    
    floodFill(a,srcI,srcJ,'.',color);

     cout<<"After FloodFill with '"<<color<<"' starting at ("<<srcI<<","<<srcJ<<")\n\n";
    printFig(a);
    
    
  
   return 0;
}