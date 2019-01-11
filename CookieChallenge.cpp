#include <iostream>
#include <vector>
using namespace std;
const int m = 4;
const int n = 4;
//int res = 0;

void printAr(int a[][n]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "\n";
}

int cookie(int a[][n], int i, int j) {

	//cout << "Entered";

	if (i>=m || j>=n || j<0 || i<0 || a[i][j] == 999 || a[i][j] == 0) {
		return 0;
	}

	else {
		a[i][j] = 999;
		return cookie(a, i + 1, j) + 1 + cookie(a, i, j + 1)+ cookie(a, i, j-1)+cookie(a,i-1,j);
	}

	
}

int main() {

	vector<int> rvc;
	int a[4][4] = { 0,0,1,1,
					1,1,0,1,
					1,0,1,1,
					1,1,1,0};

	int len;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			
		}
	}
	cout << "Before processing: " << endl;
	printAr(a);

	int res;

	cout << "Processing the recursive loop:"<<endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[i][j] == 1) {
				res = cookie(a, i, j);
				printAr(a);
				rvc.push_back(res);
			}
		}
	}


	//cin.clear();
	//cin.ignore();
	//cin.get();
	cout << "\n\n";
	cout << "Print After" << endl;
	printAr(a);

	cout << "\nFinal paths of maximum length are" << endl;
	for (int x : rvc) {
		cout << x << "\t";
	}
	cout << endl;


	return 0;


}