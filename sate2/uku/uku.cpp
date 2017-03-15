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

struct Dinic {
  struct edge {
    int to, cap, rev;
    edge(){}
    edge(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
  };
  vector< vector<edge> > graph;
  vector<int> level, iter;
  Dinic(){}
  Dinic(int V):graph(V), level(V), iter(V){}
  void add_edge(int from, int to, int cap) {
    graph[from].emplace_back(to, cap, graph[to].size());
    graph[to].emplace_back(from, 0, graph[from].size()-1);
  }
  bool bfs(int s, int t) {
    fill(all(level), -1);
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while(que.size()) {
      int v = que.front(); que.pop();
      for(edge& e : graph[v]) {
	if(e.cap > 0 && level[e.to] < 0) {
	  level[e.to] = level[v] + 1;
	  que.push(e.to);
	}
      }
    }
    return level[t] >= 0;
  }
  int dfs(int v, int t, int f) {
    if(v == t) return f;
    for(int& i = iter[v]; i < graph[v].size(); i++) {
      edge& e = graph[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
	int d = dfs(e.to, t, min(f, e.cap));
	if(d > 0) {
	  e.cap -= d;
	  graph[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
      if(!bfs(s, t)) return flow;
      fill(all(iter), 0);
      int f; while((f = dfs(s, t, inf)) > 0) flow += f;
    }
  }
};

#define MAX_N 108
#define MAX_M 108

int n, m;
int h[MAX_N][MAX_M];
Dinic graph;

bool check(int d) {
  int S = n+m, s1 = S+1, s2 = s1+1, T = s2+1, V = T+1;
  graph = Dinic(V);
  graph.add_edge(S, s1, m/n * n);
  graph.add_edge(S, s2, m%n);
  rep(i, n) {
    graph.add_edge(s1, i, m/n);
    if(m%n) graph.add_edge(s2, i, 1);
  }
  rep(i, n) rep(j, m) {
    if(h[i][j] <= d) graph.add_edge(i, n+j, 1);
  }
  rep(i, m) graph.add_edge(n+i, T, 1);
  return graph.max_flow(S, T) == m;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n >> m;
  rep(i, n) rep(j, m) cin >> h[i][j];

  int lb = 0, ub = 1000000010;
  while(lb + 1 < ub) {
    int mb = (lb + ub) / 2;
    if(check(mb)) ub = mb;
    else lb = mb;
  }
  cout << (m%n == 0 ? 0 : 1) << endl;
  cout << ub << endl;

  return 0;
}
