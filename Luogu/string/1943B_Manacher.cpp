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
vector<int> P;
string ManacherString(string &s) {
	int n = s.length() * 2 + 1;
	string ss;
	ss.resize(n);
	for (int i = 0, j = 0; i < n; i++) {
		ss[i] = (i & 1) ? s[j] : '#';
		if (i & 1) j++;
	}
	return ss;
}
int Manacher(string &s) {
	string ss = ManacherString(s);
	int res = 0;
	int n = ss.length();
	for (int i = 0, c = 0, r = 0, len; i < n; i++) {
		len = r > i ? min(P[2 * c - i], r - i) : 1;
		while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len]) {
			len++;
		}
		if (i + len > r) {
			r = i + len;
			c = i;
		}
		res = max(res, len);
		P[i] = len;
	}
	return res - 1;
}
void run_case() {
    int n, m, q;
    cin >> n >> q;
    string s;
    cin >> s;
    P.assign(2 * n + 1, 0);
    vector<int> f1(n), f2(n);
    per(i, n - 1, 0) {
    	f1[i] = i + 1 < n && s[i] == s[i + 1] ? f1[i + 1] : i + 1;
    	f2[i] = i + 2 < n && s[i] == s[i + 2] ? f2[i + 2] : i + 2;
    }
    int mxPa = Manacher(s);
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	l--;
    	ll ans = 0;
    	int len = r - l;
    	if (f1[l] < r) {
    		int mx = (len - 1) - (len - 1) % 2;
    		ans += 1LL * (mx / 2) * (mx + 2) / 2;
    	}
    	if (f2[l] < r || f2[l + 1] < r) {
    		int mx = (len - 1) - len % 2;
    		ans += 1LL * (mx - 1) / 2 * (mx + 3) / 2;
    	}
    	if (P[l + r] <= len) {
    		ans += len;
    	}
    	cout << ans << '\n';
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        run_case();
    }
 
    return 0;
}