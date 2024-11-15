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
    vector<int> A(n);
    int C[2] = {0};
    rep(i, 0, n) {
    	cin >> A[i];
        C[A[i] & 1] = 1;
    }
    if (C[0] && C[1]) {
        cout << -1 << '\n';
        return;
    }
    // 40 30 20 0, 20 10 10 0, 10 10 0 0, 5 5 5 5
    // 3 7 9 13, 7 3 3 1, 4 2 0 0, 2 2 2 0, 1 1 1 1
    // 15 5 15, 8 8 2, 4 4 2, 2 2 0, 
    vector<int> op;
    while (op.size() < 40) {
        sort(all(A));
        int c = A[n - 1] / 2;
        if (!c) break;
        op.push_back(c);
        bool done = true;
        rep(i, 0, n) {
            A[i] = abs(c - A[i]);
            if (i && A[i] != A[i - 1]) {
                done = false;
            }
        }
        if (done) {
            if (A[0])
                op.push_back(A[0]);
            break;
        }
    }
    // rep(i, 0, n) {
    //     cout << A[i] << " \n"[i + 1 == n];
    // }
    cout << op.size() << '\n';
    rep(i, 0, op.size()) {
        cout << op[i] << " \n"[i + 1 == op.size()];
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