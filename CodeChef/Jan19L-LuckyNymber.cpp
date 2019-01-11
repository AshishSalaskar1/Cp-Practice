
#include <iostream>
#include <set>
using namespace std;

void winner(int a) {
	if (a == 0) {
		cout << "BOB" << endl;
	}
	else {
		cout << "ALICE" << endl;
	}
}

int main() {
	int res;
	int n;
	cin >> n;

readNextSet:
	while (n--) {
		int m, a, b, temp;
		cin >> m;
		set<int> s;
		cin >> b;
		cin >> a;
		while (m--) {
			cin >> temp;
			s.insert(temp);
		}
		set<int>::iterator s1;
		int turn = 0;

	loopStart:
		while (1) {

			if (turn == 0) {
				int i;

				for (i = a; i <= *s.rbegin(); i = i + a) {
					// cout << "turn1: "<< i;
					s1 = s.find(i);
					if ((s1 != s.end()) && ((i%b)==0)) {
						goto bobRemove;
					}

				}

				for (i = b; i <= *s.rbegin(); i = i + b) {
					//cout << "Enter bobloop as " << i;
					s1 = s.find(i);

					if (s1 != s.end()) {
						break;
					}

				}
			bobRemove:
				if (s1 == s.end()) {
				winner(1);
				goto readNextSet;
				}

				else {
				//cout << "Bob Removing:" << i << endl;
				s.erase(i);
				turn = 1;
				goto loopStart;
				}

			}
			if (turn == 1) {
				int i;

				for (i = b; i <= *s.rbegin(); i = i + b) {
					//cout << "Enter bobloop as " << i;
					s1 = s.find(i);

					if ((s1 != s.end()) && ((i%a) == 0)) {
						goto aliceRemove;
					}

				}


				for ( i = a; i <= *s.rbegin(); i = i + a) {
					// cout << "turn1: "<< i;
					s1 = s.find(i);
					if (s1 != s.end()) {
						break;
					}
					
				}

			aliceRemove:
				if (s1 == s.end()) {
					winner(0);
					goto readNextSet;
				}
				else {
					//cout << "Alice Removing:" << i << endl;
					s.erase(i);
					turn = 0;
					goto loopStart;
				}

			}

		}

	}

	return 0;
}