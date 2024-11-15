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

const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, q;

// 19, 7, 18, 3, 1
// 19, 19; 13, 13; 13, 13, 18; 11, 12, 12, 12
// 26 + 18 = 44 + 3 = 47 / 4 = 11 ... 3
// 1, 9, 13, 29, 34, 2
void run_case() {
    
    cin >> n;
    vector<ll> A(n);
    ll sum = 0;
    for (auto &a: A) {
    	cin >> a;
    }
    

    ll mx = 0, mn = A[0];
    for (int i = 0; i < n; i++) {
        sum += A[i];
        mn = min(sum / (i + 1), mn);
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += A[i];
        mx = max((sum + n - i - 1) / (n - i), mx);
    }
    cout << mx - mn << '\n';
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