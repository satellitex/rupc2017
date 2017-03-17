#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 10000;
const int Q = 10000;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 30; t++) {
    ofstream of(format("05_binary_%02d.in", t+1).c_str());
    int n = rnd.next(1, N);
    int q = n*10;//rnd.next(1, Q);
    of << n << " " << q << endl;
    for(int v = 1; v < n; v++) {
      int u = rnd.next(0, v-1);
      of << u << " " << v << endl;
    }
    for(int i = 0; i < q; i++) {
      int t = rnd.next(1, 2);
      int r = rnd.next(0, n-1);
      int x = rnd.next(0, 1);
      int y = rnd.next(0, 1);
      if(t == 1 && x > y) swap(x, y);
      of << t << " " << r << " " << x << " " << y << endl;
    }
    of.close();
  }

  return 0;
}
