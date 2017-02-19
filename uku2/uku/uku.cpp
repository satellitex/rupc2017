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

struct SegmentTree {
  vector<int> sum[3], lazy;
  int sz;
  void init(int n)
  {
    sz = 1;
    while(sz <= n) sz <<= 1;
    rep(i, 3) sum[i].resize(2*sz-1, 0);
    lazy.resize(2*sz-1, 0);
    rep(i, n) sum[0][i+sz-1] = 1;
    for(int k = sz-2; k >= 0; k--) {
      sum[0][k] = sum[0][2*k+1] + sum[0][2*k+2];
    }
  }
  inline void lazy_evaluate(int k, int l, int r)
  {
    if(lazy[k]) {
      vector<int> temp[3];
      rep(i, 3) temp[i] = sum[i];
      rep(i, 3) sum[(i+lazy[k])%3][k] = temp[i][k];
      if(r - l > 1) {
	(lazy[2*k+1] += lazy[k]) %= 3;
	(lazy[2*k+2] += lazy[k]) %= 3;
      }
      lazy[k] = 0;
    }
  }
  void update(int a, int b, int k, int l, int r)
  {
    lazy_evaluate(k, l, r);
    if(r <= a || b <= l) return;
    if(a <= l && r <= b) {
      (lazy[k] += 1) %= 3;
      lazy_evaluate(k, l, r);
      return;
    }
    update(a, b, 2*k+1, l, (l+r)/2);
    update(a, b, 2*k+2, (l+r)/2, r);
    rep(i, 3) sum[i][k] = sum[i][2*k+1] + sum[i][2*k+2];
  }
  void update(int a, int b)
  {
    update(a, b, 0, 0, sz);
  }
  int query(int a, int b, int c, int k, int l, int r)
  {
    lazy_evaluate(k, l, r);
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b)  return sum[c][k];
    return query(a, b, c, 2*k+1, l, (l+r)/2) + query(a, b, c, 2*k+2, (l+r)/2, r);
  }
  int query(int a, int b, int c)
  {
    return query(a, b, c, 0, 0, sz);
  }
};

vector< vector<int> > graph;
vector<int> be, en;
int idx;

void dfs(int u, int p)
{
  be[u] = idx;
  idx++;
  for(int v : graph[u]) {
    if(v == p) continue;
    dfs(v, u);
  }
  en[u] = idx;
}

int n, q;
SegmentTree seg;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> q;
  graph.resize(n);
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  be.resize(n);
  en.resize(n);
  idx = 0;
  dfs(0, -1);
  seg.init(n);

  rep(i, q) {
    //rep(j, 3) {
    //rep(k, seg.sum[j].size()) cout << seg.sum[j][k] << " ";
    //cout << endl;
    //}
    int t, r;
    cin >> t >> r;
    if(t == 1) {
      seg.update(be[r], en[r]);
    } else if(t == 2) {
      int c;
      cin >> c;
      cout << seg.query(be[r], en[r], c) << endl;
    }
  }

  return 0;
}
