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

#define MAX_N 100000
#define MAX_Q 100000

struct SegmentTree {
  vector< array<int, 10> > data;
  int sz;
  SegmentTree(){}
  SegmentTree(int n) {
    sz = 1; while(sz < n) sz <<= 1;
    data.resize(2*sz-1, array<int, 10>{0});
    rep(i, n) data[i+sz-1][0] = 1;
    for(int k = sz-2; k >= 0; k--)
      data[k][0] = data[2*k+1][0] + data[2*k+2][0];
  }
  void update(int a, int b, int x, int y, int k, int l, int r) {
    if(x == y) return;
    if(r <= a || b <= l) return;
    if(r - l == 1) {
      data[k][y] += data[k][x];
      data[k][x] = 0;
      return;
    }
    update(a, b, x, y, 2*k+1, l, (l+r)/2);
    update(a, b, x, y, 2*k+2, (l+r)/2, r);
    rep(i, 10) data[k][i] = data[2*k+1][i] + data[2*k+2][i];
  }
  void update(int a, int b, int x, int y) {
    //update(a, b, x, y, 0, 0, sz);
    if(x == y) return;
    for(int i = a; i < b; i++) {
      data[i+sz-1][y] += data[i+sz-1][x];
      data[i+sz-1][x] = 0;
    }
    for(int k = sz-2; k >= 0; k--) {
      data[k][x] = data[2*k+1][x] + data[2*k+2][x];
      data[k][y] = data[2*k+1][y] + data[2*k+2][y];
    }
  }
  int query(int a, int b, int x, int y, int k, int l, int r) {
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) {
      int res = 0;
      for(int i = x; i <= y; i++) res += data[k][i];
      return  res;
    }
    int vl = query(a, b, x, y, 2*k+1, l, (l+r)/2);
    int vr = query(a, b, x, y, 2*k+2, (l+r)/2, r);
    return vl + vr;
  }
  int query(int a, int b, int x, int y) {
    return query(a, b, x, y, 0, 0, sz);
  }
};

int n, q;
vector<int> graph[MAX_N];
int li[MAX_N], ri[MAX_N], idx;

SegmentTree seg;

void dfs(int u) {
  li[u] = idx++;
  for(int v : graph[u]) dfs(v);
  ri[u] = idx;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> q;
  rep(i, n-1) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }
  memset(li, -1, sizeof(li));
  memset(ri, -1, sizeof(ri));
  idx = 0;
  dfs(0);

  seg = SegmentTree(n);
  rep(i, q) {
    int t, r, x, y;
    cin >> t >> r >> x >> y;
    if(t == 1) cout << seg.query(li[r], ri[r], x, y) << endl;
    else seg.update(li[r], ri[r], x, y);
  }

  return 0;
}
