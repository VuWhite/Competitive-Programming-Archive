#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <functional>
#include <stack>
#include <random>
#include <ctime>
#include <iomanip>
#include <numeric>

#define all(arr) arr.begin(), arr.end()
#define ll long long
#define MS(arr, val) memset(arr, val, sizeof(arr))
#define vi vector<int>
#define pb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lll __int128
#define ull unsigned long long
#define Kases int T; rd(T); rep(kase, 1, T)
#define rep(i, a, b) for(int i = (a), __ ## i = (b); i < __ ## i; ++i)
#define per(i, b, a) for(int i = (b), __ ## i = (a); i >= __ ## i; --i)
using namespace std;
const int INF = 0x3f3f3f3f;
const int BASE = 499;
int charToInt(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0' + 1;
	} else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 11;
	} else {
		return c - 'a' + 37;
	}
}

unsigned long long hashValue(string &s) {
	if (!s.length()) return 0;
	unsigned long long res = charToInt(s[0]);
	for (int i = 1; i < s.length(); i++) {
		res = res * BASE + charToInt(s[i]);
	}
	return res;
}

void run_case() {
    int n, m, q;
    cin >> n;
    vector<ull> vt(n);
    rep(i, 0, n) {
    	string s;
    	cin >> s;
    	vt[i] = hashValue(s);
    }
    sort(all(vt));
    int ans = 0;
    int i = 0;
    while (i < n) {
    	int j = i + 1;
    	while (j < n && vt[j] == vt[i]) {
    		j++;
    	}
    	ans++;
    	i = j;
    }
    cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t = 1;
    while (t--) {
        run_case();
    }
 
    return 0;
}