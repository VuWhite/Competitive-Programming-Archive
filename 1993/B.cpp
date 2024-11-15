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

void run_case() {
    int n, m, q;
    cin >> n;
    vector<long long> odd, eve;
    rep(i, 0, n) {
    	int a;
    	cin >> a;
    	if (a & 1) odd.push_back(a);
    	else eve.push_back(a);
    }
    if (!odd.size() || !eve.size()) {
        cout << "0\n";
        return;
    }
    sort(all(odd));
    sort(all(eve));
    int ans = eve.size();
    for (int i = 0; i < eve.size(); i++) {
        long long num = eve[i];
    	while (num > odd.back()) {
    		odd.push_back(eve.back() + odd.back());
    		ans++;
    	}
        odd.push_back(num + odd.back());
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