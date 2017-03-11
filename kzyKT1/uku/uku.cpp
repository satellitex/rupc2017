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

int n, m, k;
vector<pint> pos;
map<pint, int> mp;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx2[] = {-2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2};
int dy2[] = {-2, -1, 0, 1, 2, -2, 2, -2, 2, -2, 2, -2, -1, 0, 1, 2};

bool in(int x, int y) {
  return 0<=x&&x<n&&0<=y&&y<m;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> m >> k;
  rep(i, k) {
    int x, y;
    cin >> x >> y;
    pint p = pint(x, y);
    pos.push_back(p);
    mp[p] = i;
  }
  mp[pint(-1, -1)] = k;
  mp[pint(n, m)] = k+1;

  // 既にある岩で2つの領域に分断できるか
  // 上/右と左/下が繋がったら分断できる
  UnionFind uf(k+2);
  rep(i, k) {
    int x, y;
    tie(x, y) = pos[i];
    rep(j, 8) {
      int nx = x + dx[j], ny = y + dy[j];
      if(nx < 0 || ny >= m) nx = -1, ny = -1;
      else if(nx >= n || ny < 0) nx = n, ny = m;
      pint np = pint(nx, ny);
      if(mp.count(np)) uf.unite(i, mp[np]);
    }
  }

  //rep(i, k+2) cout << uf.size(i) << endl;

  if(uf.same(k, k+1)) {
    cout << 0 << endl;
    return 0;
  }

  // 1つだけ飛ばして分断できるならそこに岩を作る
  // そうでないなら始点を囲むように2個作る
  rep(i, k) {
    int x, y;
    tie(x, y) = pos[i];
    rep(j, 16) {
      int nx = x + dx2[j], ny = y + dy2[j];
      if(nx < 0 || ny >= m) nx = -1, ny = -1;
      else if(nx >= n || ny < 0) nx = n, ny = m;
      pint np = pint(nx, ny);
      if(!mp.count(np)) continue;
      if(uf.same(i, k) && uf.same(mp[np], k+1) ||
	 uf.same(i, k+1) && uf.same(mp[np], k)) {
	cout << 1 << endl;
	return 0;
      }
    }
  }

  cout << 2 << endl;

  return 0;
}
