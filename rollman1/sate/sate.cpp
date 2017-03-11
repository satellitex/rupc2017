#include <bits/stdc++.h>
using namespace std;

const int mod = 3600;
int main() {
  int s1, s2; cin >> s1 >> s2;
  s1 *= 10;
  s2 *= 10;
  int res1 = (s1 + s2) / 2;
  res1 %= mod;
  int res2 = (s1 + s2 + mod) / 2;
  res2 %= mod;

  int t1 = min(abs(s1 - res1), min( abs(s1 - res1 + mod)%mod, abs(res1 - s1 + mod)%mod ) );
  int t2 = min(abs(s1 - res2), min( abs(s1 - res2 + mod)%mod, abs(res2 - s1 + mod)%mod ) );

  if (t1 > t2) {
    cout << res2 / 10 << "." << res2%10 << endl;
  } else {
    cout << res1 / 10 << "." << res1%10 << endl;
  }
}