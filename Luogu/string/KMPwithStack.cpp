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
vector<int> nxt;
void nextArray(string &s) {
    int n = s.length();
    nxt.resize(n + 2);
    nxt[0] = -1;
    nxt[1] = 0;
    int i = 2, cn = 0;
    while (i <= n) {
        if (s[i - 1] == s[cn]) {
            nxt[i++] = ++cn;
        } else if (cn) {
            cn = nxt[cn];
        } else {
            nxt[i++] = 0;
        }
    }
}
int kmp(string& s1, string& s2) { // l pos of the first occurrence

		int n = s1.length(), m = s2.length(), x = 0, y = 0;
		nextArray(s2);

		while (x < n && y < m) {
			if (s1[x] == s2[y]) {
				x++;
				y++;
			} else if (y == 0) {
				x++;
			} else {
				y = nxt[y];
			}
		}
		return y == m ? x - y : -1;
	}

void run_case() {
    
    string s1, s2;
    cin >> s1 >> s2;
    n = s1.length(), m = s2.length();
    nextArray(s2);
    int x = 0, y = 0, cn = 0;
    vector<int> sta1(n + 1, -1), sta2(n + 1, -1);
    while (x < n) {
    	if (s1[x] == s2[y]) {
    		sta1[cn] = x;
    		sta2[cn] = y;
    		cn++;
    		y++;
    		x++;
    	} else if (!y) {
    		sta2[cn] = -1;
    		sta1[cn++] = x;
    		x++;
    	} else {
    		y = nxt[y];
    	}
    	if (y == m) {
    		cn -= m;
    		y = cn > 0 ? sta2[cn - 1] + 1 : 0;
    	}
    }
    rep(i, 0, cn) {
    	cout << s1[sta1[i]];
    }
    cout << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}