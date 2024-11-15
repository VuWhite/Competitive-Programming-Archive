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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> vt(n, 1);
    for (int i = x; i < n; i += 2) {
        vt[i] = -1;
        if (i + 1 < n) vt[i + 1] = 1;
    }
    for (int i = y - 2; i >= 0; i -= 2) {
        vt[i] = -1;
        if (i - 1 >= 0) vt[i - 1] = 1;
    }
    for (int c: vt) cout << c << ' ';
    cout << '\n';
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