#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n == 1) cout << 0 << '\n';
	else {
		n -= 2;
		long long p = 9;
		while (n >= 2 * p) {
			n -= 2 * p;
			p = p * 10;
		}
		string s = to_string(n % p + p / 9);
		string t = s;
		reverse(t.begin(), t.end());
		if (n < p) s.pop_back();

		cout << s + t << '\n';
	}
}