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
const double eps = 1e-9;
long double h, r, da, dw;



void run_case() {
    
    cin >> h >> r >> da >> dw;
    auto f = [&] (long double x) {
        return ((h - x / 2) * da * x + (h - x) / 2 * dw * (h - x)) / 
            (x * da + dw * (h - x));

    };
    long double l = 0, r = h;
    while (r - l >= eps) {
        if (f(l + (r - l) / 3) < f(r - (r - l) / 3)) {
            r = r - (r - l) / 3;
        } else {
            l = l + (r - l) / 3;
        }
    }
    cout << setprecision(15) << f(l) << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}