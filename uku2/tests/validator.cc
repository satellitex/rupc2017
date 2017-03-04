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
int t[Q_MAX], r[Q_MAX], s[Q_MAX];

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
    if(t[i] == 1) {
      s[i] = inf.readInt(-10, 10, format("s[%d]", i+1));
    } else if(t[i] == 2) {
      s[i] = inf.readInt(0, 9, format("s[%d]", i+1));
    }
    inf.readEoln();
  }
  inf.readEof();
}

void check() {
  UnionFind uf(n);
  for(int i = 0; i < n-1; i++) {
    int a, b;
    tie(a, b) = minmax(u[i], v[i]);
    uf.unite(a, b);
  }
  ensuref(uf.size(0) == n, "Disconnected graph");
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
