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
    cin >> n;
    vector<int> A(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> A[i];
    ll ans = 0, lst = 0, a1 = -1, a2 = -1;
	for (int i = 1; i <= n; i++) {
		if (!lst) {
			if (A[i] && A[i] <= 2) {
				lst = 1;
				a1 = 1, a2 = 2;
			}
			if (A[i])
				ans++;
		} else if (A[i]) {
			int cnt = A[i];
			if (a1 <= A[i]) cnt--;
			if (a2 <= A[i]) cnt--;
			if (cnt > 0) {
				ans++;
			}
			if (cnt > 2) {
				lst = 0;
				a1 = -1, a2 = -1;
			} else {
				if (a1 == 1) {
					a1 = a1 + 2;
					a2 = a2 + 2;
				} else {
					a1 = 1;
					a2 = 2;
				}
				
			}
			
		} else {
			lst = 0;
			a1 = -1, a2 = -1;
		}

	}
	cout << ans << endl;
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