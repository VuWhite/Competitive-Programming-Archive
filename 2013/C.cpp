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

//110
//0 1
//00 0
//01 1
//0

void run_case() {
    
    cin >> n;
    string s = "";
    int l = 1;
    while (s.length() != n) {
    	int a;
    	if (l) {
    		
    		cout << "? " + s + "0" << endl;
    		cin >> a;
			if (a) {
				s += '0';
			} else {
				cout << "? " + s + "1" << endl;
				cin >> a;
				if (a) {
					s += '1';
				} else {
					l = 0;
				}
			}
    	} else {
    		cout << "? 0" + s << endl;
    		cin >> a;
    		if (a) {
    			s = '0' + s;
    		} else {
    			s = '1' + s;
    		}
    	}
    }
    cout << "! " + s << endl;
}
int main()
{

    int t;
    cin >> t;
    while (t--) {
        run_case();
    }
 
    return 0;
}