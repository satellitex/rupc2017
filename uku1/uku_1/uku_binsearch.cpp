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

struct UnionFind {
  vector<int> data;
  UnionFind(){}
  UnionFind(int n):data(n, -1){}
  int size(int x) {
    return -data[find(x)];
  }
  int find(int x) {
    return data[x] < 0 ? x : data[x] = find(data[x]);
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] < data[y]) swap(x, y);
    data[x] += data[y]; data[y] = x;
    return true;
  }
};

struct edge {
  int u, v;
  double c, t;
  edge(){}
  edge(int u, int v, double c, double t):u(u), v(v), c(c), t(t){}
};

#define MAX_M 10010

int n, m;
vector<edge> roads;

UnionFind uf;
bool used[MAX_M];

double Kruskal(double t)
{
  pair<double, int> key[MAX_M];
  for(int i = 0; i < m; i++) {
    key[i].first = roads[i].t - t*roads[i].c;
    key[i].second = i;
  }
  sort(key, key + m, greater< pair<double, int> >());

  uf = UnionFind(n);
  fill(used, used + m, false);

  for(auto& p : key) {
    edge& e = roads[p.second];
    if(uf.unite(e.u, e.v)) used[p.second] = true;
  }

  double sum = 0;
  for(auto& p : key)
    if(!used[p.second]) sum += p.first;

  return sum <= 0.0;
}

double BinarySearch()
{
  double lb = 0, ub = 10000000000000;
  for(int i = 0; i < 100; i++) {
    double mb = (lb + ub) / 2;
    if(Kruskal(mb)) ub = mb;
    else lb = mb;
  }

  //for(int i = 0; i < m; i++)
  //if(!used[i]) cout << i << endl;

  return ub;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    double c, t;
    cin >> a >> b >> c >> t;
    roads.emplace_back(a, b, c, t);
  }

  if(m == n-1) cout << 0 << endl;
  else cout << BinarySearch() << endl;
  //printf("%.5f\n", BinarySearch());

  return 0;
}
