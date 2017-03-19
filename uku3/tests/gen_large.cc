#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 10; t++) {
    ofstream of(format("02_large_%02d.in", t+1).c_str());
    int n = 100000;
    int q = 100000;
    of << n << " " << q << endl;
    for(int v = 1; v < n; v++) {
      int u = rnd.next(0, v-1);
      of << u << " " << v << endl;
    }
    for(int i = 0; i < q; i++) {
      int t = rnd.next(1, 2);
      int r = rnd.next(0, 100);
      int x = rnd.next(0, 9);
      int y = rnd.next(0, 9);
      if(t == 1 && x > y) swap(x, y);
      of << t << " " << r << " " << x << " " << y << endl;
    }
    of.close();
  }

  return 0;
}
