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
string s1, s2;



void run_case() {
    
    cin >> s1 >> s2;
    if ((s1.length() - s2.length()) & 1) { // odd 'B' out
    	cout << "NO\n";
    	return;
    }
    auto f = [&] (string s) {
            string t;
            function<void(char)> add = [&](char c) {
                if (t.empty()) 
                	t.push_back(c);
                else if (t.back() == c)
                	t.pop_back();
                else
                	t.push_back(c);
            };
            for (char c : s) if (c != 'B') add(c); //only A, C pos matters
            return t;
    };
    cout << (f(s1) == f(s2) ? "YES" : "NO") << '\n';
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