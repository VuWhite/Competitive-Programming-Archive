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
const int MOD = 1000000007;
const int N = 1e5 + 10;
int n, m, q;


int qp(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) {
			res = 1LL * res * x % MOD;
		}
		x = 1LL * x * x % MOD;
		p /= 2;
	}
	return res;
}
// n, k = n, k - 1 + n - 1, k - 1
// 
// n, k = 
void run_case() {
    
    cin >> n;
    rep(i, 0, n) {
    	int c;
    	cin >> c;
    }
    rep(i, 0, n) {
    	cin >> q;
    	cout << qp(2, q) << ' ';
    }
    cout << '\n';
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