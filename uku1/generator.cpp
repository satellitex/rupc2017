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

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  srand((unsigned)time(NULL));

  int n = rand()%10 + 2;
  int m = rand()%(n*(n-1)/2-(n-1)) + n-1;

  UnionFind uf;
  bool used[n][n] = {};
  vector< tuple<int, int, int, int> > vec;
  do {
    uf = UnionFind(n);
    memset(used, 0, sizeof(used));
    vec.clear();
    while(vec.size() < m) {
      int a = rand()%n;
      int b = rand()%n;
      while(a == b) b = rand()%n;
      if(b < a) swap(a, b);
      if(used[a][b]++) continue;
      int w = rand()%1000000000 + 1;
      int t = rand()%1000000000;
      vec.emplace_back(a, b, w, t);
      uf.unite(a, b);
    }
  } while(uf.size(0) != n);

  cout << n << " " << m << endl;
  sort(all(vec));
  for(auto& v : vec) {
    int a, b, w, t;
    tie(a, b, w, t) = v;
    cout << a << " " << b << " " << w << " " << t << endl;
  }

  return 0;
}
