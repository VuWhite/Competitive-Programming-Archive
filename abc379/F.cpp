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
int n, m, q;

int H[200005], F[200005];
int table[40][200005];
int lg[200005];

void run_case() {
    
    cin >> n >> q;
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; i++) {
    	cin >> H[i];
        table[0][i] = i;
    }
    for (int i = 1; i <= lg[n]; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            int l = table[i - 1][j], r = table[i - 1][j + (1 << (i - 1))];
            table[i][j] = H[l] >= H[r] ? l : r;
        }
    }
    stack<int> st;
    for (int i = n - 1; ~i; i--) {
    	while (!st.empty() && st.top() < H[i]) {
    		st.pop();
    	}
    	F[i] = st.size();
    	st.push(H[i]);
    }
    while (q--) {
    	int l, r;
    	cin >> l >> r;
        int i = lg[r - 2 - l + 1];
        if (l + 1 == r)
    	   cout << F[r - 1] << '\n';
        else {
            int mx = H[table[i][l]] >= H[table[i][r - 2 - (1 << i) + 1]] ? table[i][l]: table[i][r - 2 - (1 << i) + 1];
            if (H[mx] > H[r - 1]) {
                cout << F[mx] << '\n';
            } else {
                cout << F[r - 1] << '\n';
            }
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}