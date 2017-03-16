#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1;
const int N_MAX = 100000;
const int Q_MIN = 1;
const int Q_MAX = 100000;

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

int n, q;
int u[N_MAX], v[N_MAX];
int t[Q_MAX], r[Q_MAX], x[Q_MAX], y[Q_MAX];

vector<int> graph[N_MAX];
set< pair<int, int> > st;

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readSpace();
  q = inf.readInt(Q_MIN, Q_MAX, "q");
  inf.readEoln();
  for(int i = 0; i < n-1; i++) {
    u[i] = inf.readInt(0, n-1, format("u[%d]", i+1));
    inf.readSpace();
    v[i] = inf.readInt(0, n-1, format("v[%d]", i+1));
    inf.readEoln();
  }
  for(int i = 0; i < q; i++) {
    t[i] = inf.readInt(1, 2, format("t[%d]", i+1));
    inf.readSpace();
    r[i] = inf.readInt(0, n-1, format("r[%d]", i+1));
    inf.readSpace();
    x[i] = inf.readInt(0, 9, format("x[%d]", i+1));
    inf.readSpace();
    y[i] = inf.readInt(0, 9, format("y[%d]", i+1));
    inf.readEoln();
  }
  inf.readEof();
}

void dfs(int a, int p) {
  if(st.count(make_pair(a, p))) {
    ensuref(false, "Exist wrong edge");
    exit(0);
  }
  for(int b : graph[a]) {
    if(b != p) dfs(b, a);
  }
}

void check() {
  UnionFind uf(n);
  for(int i = 0; i < n-1; i++) {
    uf.unite(u[i], v[i]);
    st.insert(make_pair(u[i], v[i]));
    graph[u[i]].push_back(v[i]);
    graph[v[i]].push_back(u[i]);
  }
  ensuref(uf.size(0) == n, "Disconnected graph");
  dfs(0, -1);
  for(int i = 0; i < q; i++) {
    if(t[i] == 1 && x[i] > y[i]) {
      ensuref(false, "Exist x such that is larger than y");
      exit(0);
    }
  }
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
