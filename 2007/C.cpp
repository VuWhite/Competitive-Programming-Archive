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
int n, a, b;



void run_case() {
    
    cin >> n >> a >> b;

    if (a > b) swap(a, b);
    vector<ll> A(n + 1);
    rep(i, 0, n) {
    	cin >> A[i];
    }
    sort(all(A));
    ll mx = A.back(), mn = INF;
    rep(i, 0, n) {
        ll gp = A.back() - A[i];
        int ra = gp % a, rb = gp % b;
        cout << ra << ' ' << rb << '\n';
        //A[i] = A[i] + (gp + a - 1) / a * a;
    }
    cout << mn << '\n';

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