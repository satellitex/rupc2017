#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
const int inf = 1LL << 55;
const int mod = 1e9 + 7;
signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;
  double a[N];
  vector<double> A;
  rep(i, N) cin >> a[i], A.push_back(a[i]);
  sort(all(A));
  rep(i, N) {
    int up = upper_bound(all(A), a[i]) - begin(A);
    int lw = lower_bound(all(A), a[i]) - begin(A);
    cout << up-lw-1 + lw*3 << endl;
  }

  return 0;
}
