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

#define MAX_N 20000

int N;
int A[1<<22];
int dp[1<<22];

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N;
  rep(i, N) {
    int k, bit = 0;
    cin >> k;
    rep(i, k) {
      int a; cin >> a; --a;
      bit |= 1<<a;
    }
    A[bit]++;
  }

  int ans = 0;
  for(int bit = (1<<22)-1; bit > 0; bit--) {
    if(A[bit] == 0) continue;
    dp[bit] = bit;
    set<int> st;
    st.insert(bit);
    rep(i, 22) {
      if((bit>>i)&1) continue;
      int nbit = bit | (1<<i);
      dp[bit] |= dp[nbit];

    }
    int cnt = 0;
    for(int s : st) cnt += A[s];
    if(cnt > 2)
      chmax(ans, __builtin_popcount(bit)*__builtin_popcount(dp[bit]));
  }
  cout << ans << endl;

  return 0;
}
