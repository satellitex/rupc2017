#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 10; t++) {
    ofstream of(format("04_max_%02d.in", t+1).c_str());
    int n = 100000;
    int q = 100000;
    of << n << " " << q << endl;
    for(int v = 1; v < n; v++) {
      int u = rnd.next(0, v-1);
      of << u << " " << v << endl;
    }
    for(int i = 0; i < q; i++) {
      int t = rnd.next(1, 2);
      int r = rnd.next(0, n-1);
      if(t == 1) {
	int x = rnd.next(-10, 10);
	of << t << " " << r << " " << x << endl;
      } else if(t == 2) {
	int c = rnd.next(0, 9);
	of << t << " " << r << " " << c << endl;
      }
    }
    of.close();
  }

  return 0;
}
