#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 2;
const int N_MAX = 10000;
const int M_MAX = 10000;
const int C_MIN = 1;
const int C_MAX = 1000000;
const int T_MIN = 0;
const int T_MAX = 1000000;

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

int n, m;
int a[N_MAX], b[N_MAX], c[N_MAX], t[N_MAX];

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readSpace();
  m = inf.readInt(n-1, min(n*(n-1)/2, M_MAX), "m");
  inf.readEoln();
  for(int i = 0; i < m; i++) {
    a[i] = inf.readInt(0, n-1, format("a[%d]", i+1));
    inf.readSpace();
    b[i] = inf.readInt(0, n-1, format("b[%d]", i+1));
    inf.readSpace();
    c[i] = inf.readInt(C_MIN, C_MAX, format("c[%d]", i+1));
    inf.readSpace();
    t[i] = inf.readInt(T_MIN, T_MAX, format("t[%d]", i+1));
    inf.readEoln();
  }
  inf.readEof();
}

void check() {

  bool self_loop = 0;
  bool multi_edge = 0;
  set< pair<int, int> > st;
  UnionFind uf(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    tie(u, v) = minmax(a[i], b[i]);
    if(u == v) {
      self_loop = 1;
      break;
    }
    if(st.count(make_pair(u, v))) {
      multi_edge = 1;
      break;
    }
    st.insert(make_pair(u, v));
    uf.unite(u, v);
  }
  ensuref(!self_loop, "Exist self loop");
  ensuref(!multi_edge, "Exist multiple edge");
  ensuref(uf.size(0) == n, "Disconnected graph");
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
