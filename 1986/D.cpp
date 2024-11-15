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

int h1(string ss) {
	return (ss[0] - '0') * 10 + ss[1] - '0';
}
int h1(char c) {
	return c - '0';
}
string s;
ll f(int l, int r) {
	if (l > r) return 1LL;
	rep(i, l, r + 1) {
		if (s[i] == '0') return 0LL;
	}
	ll res = h1(s[l]);
	rep(i, l + 1, r + 1) {
		if (s[i] != '1' && res != 1) res += h1(s[i]);
		else res *= h1(s[i]);
	}
	return res;
}

void run_case() {
    int n, m, q;
    
    cin >> n >> s;
    ll res = 0x3f3f3f3f3f3f;
    rep(i, 0, n - 1) {
    	string ss = "";
    	ss.push_back(s[i]);
    	ss.push_back(s[i + 1]);
    	int val = h1(ss);
    	ll lv = f(0, i - 1), rv = f(i + 2, n - 1);
    	ll ans = val;
    	if (val != 1) {
    		if (lv == 0 || rv == 0) ans = 0;
	    	else if (lv == 1 && rv == 1) ans = val;
	    	else if (lv == 1) ans += rv;
	    	else if (rv == 1) ans += lv;
	    	else ans += lv + rv;
    	} else {
    		if (lv == 0 || rv == 0) ans = 0;
	    	else if (lv == 1 && rv == 1) ans = val;
	    	else if (lv == 1) ans *= rv;
	    	else if (rv == 1) ans *= lv;
	    	else ans = lv + rv;
    	}
    	
    	res = min(ans, res);
    }
    cout << res << '\n';
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