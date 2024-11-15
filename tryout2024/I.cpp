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
int n, m, q;



void run_case() {
    
    cin >> n >> m;
    vector<int> P(n), X(m);
    vector<ll> pre(n, 0);
    rep(i, 0, n) {
    	cin >> P[i];
    	pre[i] = P[i];
    	if (i) pre[i] += pre[i - 1];
    }
    rep(i, 0, m) {
    	cin >> X[i];
    	X[i] <<= 1;
    }
    sort(all(X));
    ll ans = 0;
    for (int i = 0, l = -1, r = 0; i <= (n - 1) * 200; i++) {
    	while (l + 1 < m & X[l + 1] <= i) {
    		l++;
    	}
    	while (r < m && X[r] < i) {
    		r++;
    	}
    	ll tmpL = l != -1 ? X[l] : -INF, tmpR = r < m ? X[r] : INF;
    	ll curL = (i + tmpL) / 2 + 1, curR = (i + tmpR + 1) / 2 - 1;
    	curL = max(0LL, (curL + 199) / 200), curR = min(n - 1LL, curR / 200);
    	if (curL <= curR) {
    		ll res = curL ? pre[curR] - pre[curL - 1] : pre[curR];
    		ans = max(res, ans);
    	}
    }
    cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}