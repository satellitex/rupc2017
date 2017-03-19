#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 3; t++) {
    ofstream of(format("10_hand_%02d.in", t+1).c_str());
    int n = 100000;
    int q = 100000;
    of << n << " " << q << endl;
    if(t == 0) {
      queue< pair<int, int> > que;
      que.push(make_pair(1, 0));
      que.push(make_pair(2, 0));
      int to = 3, ed = 0;
      while(!que.empty()) {
	int cur, par;
	tie(cur, par) = que.front(); que.pop();
	if(cur == n) break;
	ed++;
	of << par << " " << cur << endl;
	que.push(make_pair(to++, cur));
	que.push(make_pair(to++, cur));
      }
    } else {
      for(int v = 1; v < n; v++) {
	of << v-1 << " " << v << endl;
      }
    }
    if(t == 2) {
      for(int i = 0; i < q-10; i++) {
	int x = rnd.next(0, 9);
	int y = rnd.next(0, 9);
	of << 2 << " " << 0 << " " << x << " " << y << endl;
      }
      for(int i = 0; i < 10; i++) {
	of << 1 << " " << n-1 << " " << i << " " << i << endl;
      }
    } else {
      while(q > 0) {
	for(int i = 0; i < 10 && q > 0; i++, q--) {
	  of << 2 << " " << 0 << " " << i << " " << (i+1)%10 << endl;
	}
	if(q > 0) {
	  of << 1 << " " << 0 << " " << 0 << " " << 9 << endl; q--;
	}
      }
    }

    of.close();
  }

  return 0;
}
