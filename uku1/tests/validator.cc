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
  // self loop
  bool self_loop = 0;
  for(int i = 0; i < m; i++) {
    if(a[i] == b[i]) {
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
