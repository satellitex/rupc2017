#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

typedef long long ll;

const ll N = 100000;
const ll M = 100000;
const ll K = 100000;

int n, m, k;
int x[K], y[K];

void input() {
  n = inf.readInt(2, N, "n");
  inf.readSpace();
  m = inf.readInt(2, M, "m");
  inf.readSpace();
  k = inf.readInt(0, min((ll)n*m-2, K), "k");
  inf.readEoln();

  for(int i = 0; i < k; i++) {
    x[i] = inf.readInt(0, n-1, format("x[%d]", i+1));
    inf.readSpace();
    y[i] = inf.readInt(0, m-1, format("y[%d]", i+1));
    inf.readEoln();
  }
  inf.readEof();
}

void check() {
  bool ex = false;
  set< pair<int, int> > st;
  st.insert(make_pair(0, 0));
  st.insert(make_pair(n-1, m-1));
  for(int i = 0; i < k; i++) {
    if(st.count(make_pair(x[i], y[i]))) {
      ex = true;
      break;
    }
    st.insert(make_pair(x[i], y[i]));
  }
  ensuref(!ex, "Exist x, y pair");
}


int main() {
  registerValidation();
  input();
  check();
  return 0;
}
