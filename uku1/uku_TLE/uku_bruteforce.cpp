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

struct UnionFind
{
  vector<int> data;
  UnionFind(){}
  UnionFind(int sz):data(sz, -1){};
  int size(int x) { return -data[find(x)]; }
  int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]); }
  bool same(int x, int y) { return find(x) == find(y); }
  int unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x != y) {
      if(data[x] < data[y]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return -data[x];
  }
};

struct edge {
  int u, v;
  double w, t;
  edge(){}
  edge(int u, int v, double w, double t):u(u), v(v), w(w), t(t){}
};

int n, m;
vector<edge> E;
int cnt;
double mnT, mnW;
vector<int> ans;
void check(vector<int>& vec)
{
  UnionFind uf(n);
  double W = 0, T = 0;
  rep(i, m) {
    bool flag = false;
    rep(j, vec.size()) {
      if(i == vec[j]) flag = true;
    }
    if(flag) {
      W += E[i].w;
      T += E[i].t;
    } else {
      uf.unite(E[i].u, E[i].v);
    }
  }
  if(uf.size(0) == n) {
    if(T/W <= mnT/mnW) {
      ans = vec;
      mnT = T, mnW = W;
    }
  }
}

void solve(int idx, vector<int>& vec)
{
  if(vec.size() == m-(n-1)) {
    check(vec);
    return;
  }
  if(idx == m) return;
  for(int i = idx; i < m; i++) {
    vec.push_back(i);
    solve(i+1, vec);
    vec.pop_back();
  }
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> m;
  rep(i, m) {
    int a, b; double w, t;
    cin >> a >> b >> w >> t;
    E.emplace_back(a, b, w, t);
  }
  vector<int> vec;
  int idx = 0;
  mnT = 1e9, mnW = 1;
  solve(idx, vec);
  rep(i, ans.size()) cout << ans[i] << endl;
  if(mnT == 1e9) {
    cout << 0.0 << " " << 0.0 << endl << -1.0 << endl;
  } else {
    cout << mnT << " " << mnW << endl;
    cout << mnT/mnW << endl;
  }

  return 0;
}
