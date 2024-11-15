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
    
    cin >> n;
    vector<pii> P(n * n + 1);
    rep(i, 1, n + 1) {
    	rep(j, 1, n + 1) {
            int x;
    		cin >> x;
    		P[x] = make_pair(i, j);
    	}
    }

    ll ans = 0;
    vector<int> r(n * n + 1, 0), c(n * n + 1, 0);
    rep(i, 1, n * n + 1) {
    	ll x = r[P[i].first]++;
        ll y = c[P[i].second]++;
    	ans += x * (n - 1 - y) + y * (n - 1 - x);
    }
    cout << (ans / 2) << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) {
        run_case();
    }
 
    return 0;
}