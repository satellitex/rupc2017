#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N_MIN = 1;
const int N_MAX = 100000;
const int Q_MIN = 1;
const int Q_MAX = 100000;

int n, q;
int u[N_MAX], v[N_MAX];
int t[Q_MAX], r[Q_MAX], c[Q_MAX];

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readSpace();
  q = inf.readInt(Q_MIN, Q_MAX, "q");
  inf.readEoln();
  for(int i = 0; i < n-1; i++) {
    u[i] = inf.readInt(0, n-1, format("u[%d]", i));
    inf.readSpace();
    v[i] = inf.readInt(0, n-1, format("v[%d]", i));
    inf.readEoln();
  }
  for(int i = 0; i < q; i++) {
    t[i] = inf.readInt(1, 2, format("t[%d]", i));
    inf.readSpace();
    if(t[i] == 1) {
      r[i] = inf.readInt(0, n-1, format("r[%d]", i));
    } else if(t[i] == 2) {
      r[i] = inf.readInt(0, n-1, format("r[%d]", i));
      inf.readSpace();
      c[i] = inf.readInt(0, 2, format("c[%d]", i));
    }
    inf.readEoln();
  }
  inf.readEof();
}

void check() {
  // self loop
  bool self_loop = 0;
  for(int i = 0; i < n-1; i++) {
    if(u[i] == v[i]) {
      self_loop = 1;
      break;
    }
  }
  ensuref(!self_loop, "Exist self loop");
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
