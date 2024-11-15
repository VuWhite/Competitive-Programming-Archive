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
    int ans = 0;
    vector<int> fl(1001, 0);
    for (int i = (n & 1) ? n : n + 1; i <= m; i += 2) {
        if (fl[i]) continue;
    	for (int j = i + 1; j <= m; j++) {
            if (fl[j]) continue;
    		if (__gcd(i, j) == 1) {
    			for (int k = j + 1; k <= m; k++) {
                    if (fl[k]) continue;
    				if (__gcd(i, k) == 1 && __gcd(k, j) == 1) {
    					ans++;
                        fl[i] = 1;
                        fl[j] = 1;
                        fl[k] = 1;
                        //cout << i << ' ' << j <<  ' ' << k << '\n';
                        break;
    				}
                    if (fl[j] || fl[i]) break;
    			}
    		}
            if (fl[i]) break;
    	}
    }
    cout << ans << '\n';
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