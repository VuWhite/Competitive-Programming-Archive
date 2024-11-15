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
#define ll int64_t
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
const int N = 5e5 + 10;
int n, m, q;

int pa[N];
vector<int> A;

int f(int x) {
    return x == pa[x] ? x : pa[x] = f(pa[x]);
}

void u(int x, int y) {
    
    int px = f(x);
    int py = f(y);
    if (A[px] < A[py]) {
        swap(px, py);
    }
    pa[py] = px;
}

void run_case() {
    
    cin >> n;
    A.resize(n + 1);

    for (int i = 1; i <= n; i++) {
    	cin >> A[i];
        pa[i] = i;

    }
    vector<pii> F;
    F.emplace_back(make_pair(A[n], n));
    for (int i = n - 1; i; i--) {
        if (A[i] < F.back().first) {
            F.emplace_back(make_pair(A[i], i));
        } else if (A[i] > F.back().first) {
            for (int j = F.size() - 1; ~j; j--) {
                if (F[j].first >= A[i]) {
                    break;
                }
                u(F[j].second, i);
            }
        }
    }
    F.clear();
    F.emplace_back(make_pair(A[0], 1));
    for (int i = 0; i <= n; i++) {
        if (A[i] > F.back().first) {
            F.emplace_back(make_pair(A[i], i));
        } else if (A[i] < F.back().first) {
            for (int j = F.size() - 1; ~j; j--) {
                if (F[j].first <= A[i]) {
                    break;
                }
                u(F[j].second, i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int p = f(i);
        cout << A[p] << " \n"[i == n];
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