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

}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int period = 2 * k;
        int max_a = *max_element(a.begin(), a.end());
        unordered_set<int> mod_set;
        
        // Check for the earliest t that satisfies the condition for all rooms
        for (int start = max_a; ; start += period) {
            bool all_on = true;
            for (int i = 0; i < n; ++i) {
                if ((start - a[i]) % period != 0) {
                    all_on = false;
                    break;
                }
            }
            if (all_on) {
                cout << start << endl;
                break;
            }
        }
        cout << -1 << endl;
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    solve();
 
    return 0;
}