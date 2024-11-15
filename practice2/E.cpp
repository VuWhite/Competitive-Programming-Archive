#include <bits/stdc++.h>

using namespace std;

int main() {
      int p, q;
      char slash;
      cin >> p >> slash >> q;
      if (p < q - 1) {
           cout << "impossible\n";
           return 0;
      }
      int k = (p + p + q + q * q - 1) / (q * q);
      int n = k * q;
      cout << n << ' ' << n - 1 << endl; 
      int sum = k * p;
      int cur = 0; 
      for (int i = 0; i < n; i++) {
           int tmp = min(i, sum - cur - n + i + 1);
           cur += tmp;
           if (i) cout << i + 1<< ' ' << tmp << endl;
      }
}