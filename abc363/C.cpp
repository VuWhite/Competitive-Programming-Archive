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

void run_case() {
    int n, m, q;
    string s;
    cin >> n >> m >> s;
    sort(all(s));
    ll ans = 0;
    do {
    	bool ok = true;
    	for (int i = 0; i + m <= n; i++) {
            bool pal = true;
    		for (int j = 0; j < m / 2; j++) {
    			if (s[i + j] != s[i + m - 1 - j]) {
    				pal = false;
    			}
    		}
            if (pal) {
                ok = false;
                break;
            }
    	}
        ans += ok;
    } while (next_permutation(all(s)));
    cout << ans << '\n';
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