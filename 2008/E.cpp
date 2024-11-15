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
    string s;
    cin >> n >> s;
    vector<vector<int>> cnt(n, vector<int>(26, 0));
    rep(i, 0, n) {
    	if (i - 2 >= 0) {
    		rep(j, 0, 26) {
	    		cnt[i][j] = cnt[i - 2][j];
	    	}
    	}	
    	cnt[i][s[i] - 'a']++;
    }
    auto f = [&](int l, int r, int c1, int c2) {
        if (l > r) {
            return 0;
        }
        int odd = (r - l + 1) & 1;
        int mx1 = 0, mx2 = 0;

        int gp = cnt[r][c1];
        if (l - 1 >= 0 && !odd) {
            gp -= cnt[l - 1][c1];
        } else if (l - 2 >= 0 && odd) {
            gp -= cnt[l - 2][c1];
        }
        mx1 = max(mx1, gp);

        if (r - 1 >= 0) {
            
            int gp = cnt[r - 1][c2];
            if (l - 2 >= 0 && !odd) {
                gp -= cnt[l - 2][c2];
            } else if (l - 1 >= 0 && odd) {
                gp -= cnt[l - 1][c2];
            }
            mx2 = max(mx2, gp);

        }
        if ((r - l + 2) / 2 - mx1 + (r - l + 1) / 2 - mx2 < 0) cout << l << ' ' << r << '\n';
        return (r - l + 2) / 2 - mx1 + (r - l + 1) / 2 - mx2;
    };
    if (n & 1) {
    	int mn = INF;
        rep(i, 0, n) {
            rep(j, 0, 26) {
                rep(k, 0, 26) {
                    if (i & 1)
                        mn = min(f(0, i - 1, j, k) + f(i + 1, n - 1, k, j) + 1, mn);
                    else {
                        mn = min(f(0, i - 1, j, k) + f(i + 1, n - 1, j, k) + 1, mn);
                    }
                }      
            }            
        }
        cout << mn << '\n';
    } else {
    	int mn = INF;
        rep(j, 0, 26) {
            rep(k, 0, 26) {
                mn = min(f(0, n - 1, j, k), mn);
            }
        }
    	cout << mn << '\n';
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