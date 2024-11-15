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
int n, m, k;



void run_case() {
    
    cin >> n >> k;
    map<int, int> freq;
    rep(i, 0, n) {
    	cin >> m;
    	freq[m]++;
    }

	int res = 0, cur = 0, diff = 0, lst = (*freq.begin()).first - 1;
	for (auto &[a, b]: freq) {
		//cout << a << ' ' << b << '\n';
		if (lst + 1 != a) {
			cur = 0;
			diff = 0;
		}
		cur += b;
		if (diff + 1 > k)
			cur -= freq[a - k];
		else
			diff++;
		res = max(cur, res);
		lst = a;
	}
	cout << res << '\n';
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