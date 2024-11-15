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

const string seq = "narek";

void run_case() {
    
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> sta(5);
	ll res = 0;
	rep(i, 0, n) {
		rep(j, 0, m) {
			rep(k, 0, 5) {
				if (s[i][j] == seq[k]) {
					sta[k].push_back(i * m + j);
				}
			}
			if (sta[4].size()) {
				ll tot1 = 0, tot2 = 0, cur = sta[4].back();
				sta[4].pop_back();
				
			}
		}
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