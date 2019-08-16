/*
Find sum of array elements.
But the final sum should also be single digit.
Add digits of sum untill single digit is left.
i/p: 
5
1 7 8 5 9
o/p: 3 (sum = 30 = 3+0 = 0)
*/
#include<iostream>
#include<string.h>
#define ll long long
using namespace std;
int m,n;

int returnSingle(int sum){
    
    int res = 0;
    int rem = 0;
    while(sum>0){
        rem = sum % 10;
        sum = sum/10;
        res += rem;
    }
    
    if(res/10 < 1)
        return res;
    else
        return returnSingle(res);
    
}

int findSum(int arr[],int n){
    int sum =0;
    for(int i=0;i<n;i++) sum += arr[i];

    return returnSingle(sum);

}




int main(){
    int a[] = {1, 7 ,8 ,5 ,9};

    cout<<findSum(a,5)<<endl;

    return 0;
}

