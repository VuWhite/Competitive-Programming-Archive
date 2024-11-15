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
const string T = "RPS";
const int INF = 0x3f3f3f3f;
void run_case() {
    int n, m, q;
    cin >> n;
    string s;
    cin >> s;
    vector<int> A(n);
    rep(i, 0, n) {
    	A[i] = find(T.begin(), T.end(), s[i]) - T.begin();
    }
    vector<vector<int>> dp(2, vector<int>(3, -INF));
    rep(i, 0, 3) dp[0][i] = 0;
    rep(i, 0, n) {
    	rep(j, 0, 3) {
    		rep(k, 0, 3) {
    			if (j != k && k != (A[i] + 2) % 3) {
    				if (k == (A[i] + 1) % 3) {
    					dp[1][k] = max(dp[0][j] + 1, dp[1][k]);
    				} else {
    					dp[1][k] = max(dp[1][k], dp[0][j]);
    				}
    			}
    		}
    	}
    	rep(j, 0, 3) {
    		dp[0][j] = dp[1][j];
    		dp[1][j] = -INF;
    	}
    }
    cout << *max_element(all(dp[0])) << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}