#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 100000;
const int Q = 100000;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 10; t++) {
    ofstream of(format("03_random_%02d.in", t+1).c_str());

    int n = rnd.next(1, N);
    int q = rnd.next(1, Q);

    of << n << " " << q << endl;

    vector<int> u(n-1), v(n-1);
    for (int ch = 1; ch < n; ch++) {
      int par = rnd.next(0, ch-1);
      u[ch-1] = par; v[ch-1] = ch;
    }

    vector<int> node_num(n);
    iota(node_num.begin(), node_num.end(), 0);
    shuffle(node_num.begin()+1, node_num.end(), mt19937());

    for (int i = 0; i < n-1; i++) {
      int uu = node_num[u[i]], vv = node_num[v[i]];
      of << uu << " " << vv << endl;
    }

    for(int i = 0; i < q; i++) {
      int t = rnd.next(1, 2);
      int r = rnd.next(0, n-1);
      int x = rnd.next(0, 9);
      int y = rnd.next(0, 9);
      if(t == 1 && x > y) swap(x, y);
      of << t << " " << r << " " << x << " " << y << endl;
    }

    of.close();

  }
  return 0;
}
