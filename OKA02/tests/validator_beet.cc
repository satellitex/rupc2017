#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// 制約
const long long N_MIN = 1;
const long long N_MAX = 500;
const long long A_MIN = 1;
const long long A_MAX = 1000000000000LL;
const long long B_MIN = 1;
const long long B_MAX = 1000000000000LL;

const long long T_MIN = 1;
const long long T_MAX = 5;
const long long X_MIN = -1000000000000LL;
const long long X_MAX = 1000000000000LL;
const long long Y_MIN = -1000000000000LL;
const long long Y_MAX = 1000000000000LL;

int n,a,b;
int t[N_MAX],x[N_MAX],y[N_MAX];
void input() {
  n = inf.readLong(N_MIN, N_MAX, "n");
  inf.readSpace();
  a = inf.readLong(A_MIN, A_MAX, "a");
  inf.readSpace();
  b = inf.readLong(B_MIN, B_MAX, "b");
  inf.readEoln();
  for(int i=0;i<n;i++) {
    t[i] = inf.readLong(T_MIN, T_MAX, "t");
    inf.readSpace();
    x[i] = inf.readLong(X_MIN, X_MAX, "x");
    inf.readSpace();
    y[i] = inf.readLong(Y_MIN, Y_MAX, "y");
    inf.readEoln();
  }
  inf.readEof();
}

void check() {
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
