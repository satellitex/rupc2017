#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

const int inf = 1<<25;//1LL << 55;
const int mod = 1e9 + 7;

struct UnionFind {
  vector<int> data;
  UnionFind(){}
  UnionFind(int sz):data(sz, -1){}
  int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]); }
  int size(int x) { return -data[find(x)]; }
  bool same(int x, int y) { return find(x) == find(y); }
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] < data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }
};

struct SCC {
  vector< vector<int> > graph, rgraph, cnn; // 強連結成分の集合
  vector<int> order, cmp, color;
  vector<bool> used, isbi;
  int sz; // 強連結成分を潰した後の頂点数
  SCC(){}
  SCC(int V):graph(V), rgraph(V), cmp(V, -1), color(V, -1), used(V, false){}
  void add_edge(int from, int to) {
    graph[from].push_back(to);

  }
  void dfs(int u) {
    if(used[u]) return;
    used[u] = true;
    for(int v : graph[u]) dfs(v);
    order.push_back(u);
  }
  void rdfs(int u, int cnt) {
    cmp[u] = cnt;
    for(int v : rgraph[u]) if(cmp[v] == -1) rdfs(v, cnt);
  }
  int compose() {
    sz = 0;
    rep(u, graph.size()) {
      for(int v : graph[u]) rgraph[v].push_back(u);
    }
    rep(u, graph.size()) dfs(u);
    reverse(all(order));
    rep(i, order.size()) {
      if(cmp[order[i]] == -1) rdfs(order[i], sz++);
    }
    cnn.resize(sz);
    rep(u, graph.size()) cnn[cmp[u]].push_back(u);
    return sz;
  }
  void sort_edge() {
    rep(u, graph.size()) {
      sort(all(graph[u]), [&](int i, int j){
	  return cmp[i] < cmp[j];
	});
    }
  }
  bool dfs2(int u, int c) {
    color[u] = c;
    for(int v : graph[u]) {
      if(cmp[u] != cmp[v]) continue;
      if(color[v] == c) return false;
      if(color[v] == -1 && !dfs2(v, !c)) return false;
    }
    return true;
  }
  void coloring() {
    isbi.resize(sz, false);
    rep(i, sz) {
      for(int u : cnn[i]) {
	if(color[u] == -1) {
	  isbi[i] = dfs2(u, 0);
	  break;
	}
      }
    }
  }
};

#define MAX_N 100010

int n, m;
int c[MAX_N];
SCC scc;

UnionFind uf;
vector<int> sati[2];
bool used[2][MAX_N];
vector<int> graph2[2][MAX_N];
int maxi[2][2][MAX_N];
/*
void dfs(int u, int p, int f) {
  if(used[f][u]) return;
  used[f][u] = true;
  for(int v : scc.graph[u]) {
    if(p != -1 && scc.cmp[p] == scc.cmp[v]) uf.unite(v, p);
    if(!used[!f][v]) dfs(v, u, !f);
  }
}
*/

void bfs() {
  queue< tuple<int, int, int> > que;
  que.emplace(0, -1, 0);
  while(que.size()) {
    int u, p, f; tie(u, p, f) = que.front(); que.pop();
    if(used[f][u]) continue;
    used[f][u] = true;
    for(int v : scc.graph[u]) {
      if(p != -1 && scc.cmp[p] == scc.cmp[v]) uf.unite(v, p);
      if(!used[!f][v]) que.emplace(v, u, !f);
    }
  }
}

void calc() {
  uf = UnionFind(n);
  memset(used, false, sizeof(used));
  //dfs(0, -1, 0);
  bfs();
  scc.coloring();

  rep(i, 2) sati[i].resize(scc.sz, 0);
  rep(u, n) {
    if(scc.isbi[scc.cmp[u]]) sati[scc.color[u]][scc.cmp[u]] += c[u];
    else {
      scc.color[u] = 0;
      sati[0][scc.cmp[u]] += c[u];
      sati[1][scc.cmp[u]] += c[u];
    }
  }

  scc.sort_edge();
  rep(u, n) {
    for(int v : scc.graph[u]) {
      if(scc.cmp[u] == scc.cmp[v]) continue;
      if(scc.isbi[scc.cmp[u]]) graph2[scc.color[u]][scc.cmp[u]].push_back(v);
      else {
	graph2[0][scc.cmp[u]].push_back(v);
	graph2[1][scc.cmp[u]].push_back(v);
      }
    }
  }
}

int solve() {
  memset(maxi, -1, sizeof(maxi));
  maxi[0][0][scc.cmp[0]] = sati[scc.color[0]^0][scc.cmp[0]];
  rep(c, scc.sz) {
    rep(i, 2) { //とる色
      rep(j, 2) { //今の偶奇
	if(maxi[i][j][c] == -1) continue;
	rep(k, 2) { //出る場所
	  for(int v : graph2[k][c]) {
	    int nf = !(i^j^k);
	    if(maxi[scc.color[v]][nf][scc.cmp[v]] < maxi[i][j][c] + sati[scc.color[v]^nf][scc.cmp[v]]) {
	      maxi[scc.color[v]][nf][scc.cmp[v]] = maxi[i][j][c] + sati[scc.color[v]^nf][scc.cmp[v]];
	    }
	  }
	}
      }
    }
  }
  int res = 0;
  rep(i, 2) rep(j, 2) rep(k, n) chmax(res, maxi[i][j][k]);
  return res;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> m;
  rep(i, n) cin >> c[i];
  scc = SCC(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    scc.add_edge(a, b);
  }
  scc.compose();
  calc();
  cout << solve() << endl;

  return 0;
}
