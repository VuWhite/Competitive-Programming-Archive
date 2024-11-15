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

int dp[5005][5005], S[5005], I[5005];
void run_case() {
    
    cin >> n >> m;
    vector<int> le;
    vector<int> A(n);
    //le.push_back(0);
    rep(i, 0, n) {
    	cin >> A[i];
    	if (!A[i]) {
    		le.push_back(i);
    	}
    }
    le.push_back(n);
   	rep(i, 1, le.size()) {

   		rep(j, 0, m + 1) {
   			S[j] = I[j] = 0;
   		}
   		rep(j, le[i - 1] + 1, le[i]) {
   			if (A[j] > 0) {
   				I[A[j]]++;
   			} else if (A[j] < 0) {
   				S[-A[j]]++;
   			}
   		}
   		rep(j, 1, m + 1) {
   			I[j] += I[j - 1];
   			S[j] += S[j - 1];
   		}
   		rep(j, 0, i + 1) {
   			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][max(j - 1, 0)]) + I[j] + S[i - j]);
        }
   	}
   	cout << (*max_element(dp[m], dp[m] + m + 1)) << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int t = 1;
    while (t--) {
        run_case();
    }
 
    return 0;
}