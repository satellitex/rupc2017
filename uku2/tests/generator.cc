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

    // 連結になるように入力しないといけない。
    vector<int> a(n-1), b(n-1);
    for (int i = 1; i < n; i++) {
      int par = rnd.next(0, i-1);
      a[i-1] = par; b[i-1] = i;
      of << par << " " << i << endl;
    }
    /*
    vector<int> node_num(n, -1);
    set<int> used; used.insert(-1);
    for (int i = 0; i < n; i++) {
      int v = -1;
      while (used.count(v) > 0) {
	v = rnd.next(0, n-1);
      }
      used.insert(v);
      node_num[i] = v;
    }
    for (int i = 0; i < n-1; i++) {
      int aa = node_num[a[i]], bb = node_num[b[i]];
      if (aa >= bb) {
	swap(aa, bb);
      }
      of << aa << " " << bb << endl;
    }
*/
    for(int i = 0; i < q; i++) {
      int t = rnd.next(1, 2);
      int v = rnd.next(0, n-1);
      if(t == 1) {
	int x = rnd.next(-10, 10);
	of << t << " " << v << " " << x << endl;
      } else {
	int c = rnd.next(0, 9);
	of << t << " " << v << " " << c << endl;
      }
    }

    of.close();

  }
  return 0;
}
