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
    vector<long long> B(n, 0);
    rep(i, 0, n - 1) {
    	cin >> B[i];
    }
    vector<long long> A(n, 0);
    A[0] = B[0];
    rep(i, 1, n) {
        A[i] = B[i - 1] | B[i];
    }
    rep(i, 0, n - 1) {
        if ((A[i] & A[i + 1]) != B[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    rep(i, 0, n) {
    	cout << A[i] << " \n"[i + 1 == n];
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