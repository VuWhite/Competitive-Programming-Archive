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
const int N = 2e5 + 10;
int n, m, q;

int pa[N], sz[N];

int findPa(int x) {
	return x == pa[x] ? x : pa[x] = findPa(pa[x]);
}

void unite(int u, int v) {
	if (u > v) swap(u, v);
	u = findPa(u);
	v = findPa(v);
	if (u != v) {
		sz[u] += sz[v];
		pa[v] = u;
	}
}

void run_case() {
    
    cin >> n;
    std::vector<int> p(n + 1);
    rep(i, 1, n + 1) {
    	cin >> p[i];
    	pa[i] = i;
    	sz[i] = 1;
    }
    string s;
    cin >> s;
    rep(i, 0, n) {
        if (s[i] == '1') {
            sz[i + 1] = 0;
        }
    }
    rep(i, 0, n) {
    	//if (s[i] == '0' && s[p[i + 1]] == '0') {
    		unite(i + 1, p[i + 1]);
    	//}
    }
    rep(i, 1, n + 1) {
    	int c = sz[findPa(i)];
    	if (s[p[i] - 1] == '0') {
    		c = sz[findPa(i)];
    	}
    	cout << c << " \n"[i == n];
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