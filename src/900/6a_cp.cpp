// Powered by CP Editor (https://cpeditor.org)
// author:  josuerom
// created: 14/03/2024 10:09:49

#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define br  '\n'

const int M = 20;
char s[M], d[M];
int n, m;

void solve() {
   cin >> n >> s;
   m = strlen(s);
   int ans = 21;
   for (int i = 1; i < n; i++) {
      int cnt = 0;
      cin >> d;
      for (int j = 0; j < m; j++) {
         if (s[j] == d[j]) cnt++;
         else break;
      }
      ans = min(ans, cnt);
   }
   cout << ans << br;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tt = 1;
   // cin >> tt;
   while (tt--) solve();
   return 0;
}
