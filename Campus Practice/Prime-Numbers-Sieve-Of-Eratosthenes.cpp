//Prime number - Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

vector<int> primes(int n){

	vector<int> v;

	bool temp[n+1];
	memset(temp,true,sizeof(temp));
	temp[1] = false;

	for(int i=2;i<=n ;i++){
		if(temp[i]){
			// cout<<i<<endl;
			for(int j=i+i;j<=n;j += i){
				temp[j] = false;
			}
		}	
	}

	for(int i=2;i<=n;i++){
		if(temp[i])
		v.push_back(i);
	}

	return v;
}

int main(){

	int N = 100;
	vector<int> primeNumbers;
	primeNumbers = primes(N);

	for(int i=0;i<primeNumbers.size();i++)
		cout<<primeNumbers[i]<<endl;
	

	return 0;
}




