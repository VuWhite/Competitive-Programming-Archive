#include <bits/stdc++.h>

using namespace std;

int main() {
	string randPattern = "";
	for (int i = 0; i < 30; i++) {
		randPattern += (rand() & 1) ? '1' : '0';
	}

	int cnt = 0;
	string cur = "";
	while (true) {
		char c;
		cin >> c;
		cur += c;
		if (cur.length() >= 30
			&& equal(randPattern.rbegin(), randPattern.rend(), cur.rbegin())) {
			cout << "! " << cur.length() - randPattern.length() << endl;
			return 0;
		}
		if (cnt < 30 && randPattern[cnt] != c) {
			cout << "? flip" << endl;
			cin >> c;
		}
		cout << "? left" << endl; 
		cnt++;
	}
	return 0;
}