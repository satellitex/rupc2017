#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

#define MAX_N 100

int N, P;
int X[MAX_N], Y[MAX_N];

int p[MAX_N][MAX_N+1];
int dp[MAX_N+1][MAX_N+1][MAX_N+1];

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> P;
  rep(i, N) cin >> X[i] >> Y[i];

  fill(p[0], p[MAX_N], inf);
  // p[i][j] := 直前j回を連続で登校した時に必要なi日目に消費する励まし力
  rep(i, N) {
    rep(j, N-i) {
      p[i][j] = max(0LL, Y[i+j]-max(0LL, X[i+j]-(j?p[i][j-1]:0)));
    }
  }

  fill((int*)begin(dp), (int*)end(dp), inf);
  dp[0][0][0] = 0;

  // dp[i][j][k] := i日目までにj回、うち直前k回を連続で登校した時の最小の消費する励まし力
  rep(i, N) {
    rep(j, i+1) {
      rep(k, j+1) { // don't go
	chmin(dp[i+1][j][0], dp[i][j][k]);
      }
      rep(k, j+1) { // go
	if(p[i-k][k] > 0) chmin(dp[i+1][j+1][k+1], dp[i][j][k]+p[i-k][k]);
	else chmin(dp[i+1][j+1][0], dp[i][j][k]);
      }
    }
  }

  int ans = 0;
  rep(j, N+1) rep(k, N+1) if(dp[N][j][k] <= P) chmax(ans, j);
  cout << ans << endl;

  return 0;
}
