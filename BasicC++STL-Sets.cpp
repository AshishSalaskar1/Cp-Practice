#include<iostream>
#include<set>
using namespace std;

void setDemo() {
	set <int> s;
	s.insert(1);
	s.insert(2);
	set<int>::iterator s1 = find(s.begin(), s.end(), 1);
	cout << *s1 << endl;;
	s1 = find(s.begin(), s.end(), 20);
	if (s1 == s.end()) {
		cout << "Not Found" << endl;
	}
	else {
	cout << *s1<<endl;

	}

	s.erase(2);

	for (int x : s) {
		cout << x;
	}
}



int main() {
	//setDemo();
	codeLong2();
	return 0;
}