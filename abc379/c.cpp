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

pii inn[200005];
int A[200005], X[200005];

void run_case() {
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	cin >> inn[i].first;
    }
    for (int i = 0; i < m; i++) {
    	cin >> inn[i].second;
    }
    sort(inn, inn + m);
    for (int i = 0; i < m; i++) {
    	A[i] = inn[i].second;
    	X[i] = inn[i].first;
    }
    ll res = 0, st = 0;
    for (int i = 0; i < m; i++) {
    	if (st >= X[i]) {
    		res += 1LL * (A[i] + 1) * A[i] / 2 + 1LL * (st - X[i]) * A[i];
    		st += A[i];
    	} else if (st == X[i] - 1) {
    		res += 1LL * (A[i] - 1) * A[i] / 2;
    		st = 0LL + X[i] + A[i] - 1;
    	} else {
    		cout << "-1\n";
    		return;
    	}
    	if (st > n) {
    		cout << "-1\n";
    		return;
    	}
    }
    if (st != n) {
    	cout << "-1\n";
    	return;
    }
    cout << res << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}