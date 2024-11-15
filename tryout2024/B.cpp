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
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define lll __int128
#define ull unsigned long long
#define Kases int T; rd(T); rep(kase, 1, T)
#define rep(i, a, b) for(int i = (a), __ ## i = (b); i < __ ## i; ++i)
#define per(i, b, a) for(int i = (b), __ ## i = (a); i >= __ ## i; --i)
using namespace std;

const int INF = 0x3f3f3f3f;
string S[3];

int cnt[3][26], len[3];
vector<string> ans;
vector<int> tmp[3];


void run_case() {
    
    cin >> S[0] >> S[1] >> S[2];
    int mnLen = INF;
    rep(i, 0, 3) {
    	len[i] = S[i].length();
    	rep(j, 0, len[i]) {
    		cnt[i][S[i][j] - 'A']++;
    	}
    	mnLen = min(len[i], mnLen);
    }
    rep(i, 0, 26) {
    	while (mnLen > 0 && (cnt[0][i] > 0) + (cnt[1][i] > 0) + (cnt[2][i] > 0) >= 2) {
    		int temp = 0;
    		if (cnt[1][i] < cnt[temp][i]) temp = 1;
    		if (cnt[2][i] < cnt[temp][i]) temp = 2;
    		rep(j, 0, 3)
    			if (j != temp)
    				cnt[j][i]--;
    		tmp[temp].pb(i);
    		mnLen--;
    	}
    }
    rep(i, 0, 3) {
    	rep(j, 0, 26) {
    		while (!tmp[i].empty() && cnt[i][j] > 0) {
    			string cur;
    			cur += 'A' + tmp[i].back();
    			cur += 'A' + j;
    			ans.pb(cur);
    			cnt[i][j]--;
    			tmp[i].pop_back();
    		}
    	}
    }
    rep(i, 0, 3) {
    	len[i] = 0;
    	rep(j, 0, 26)
    		len[i] += cnt[i][j];
    }
    while (len[0] + len[1] + len[2] > 0) {
    	int temp = 0;
		if (len[1] < len[temp]) temp = 1;
		if (len[2] < len[temp]) temp = 2;
		string cur;
		rep(j, 0, 3) {
			if (j != temp) {
				char c = 'A';
				rep(k, 0, 26) {
					if (cnt[j][k] > 0) {
						cnt[j][k]--;
						len[j]--;
						c = 'A' + k;
						break;
					}
				}
				cur += c;
			}
		}
		ans.pb(cur);
    }
    cout << ans.size() << '\n';
    for (auto s: ans) cout << s << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    run_case();
 
    return 0;
}