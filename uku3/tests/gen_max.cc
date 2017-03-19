#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 1; t++) {
    ofstream of(format("04_max_%02d.in", t+1).c_str());
    int n = 100000;
    int q = 100000;
    of << n << " " << q << endl;
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
    //assert(ed == n-1);
    while(q > 0) {
      for(int i = 0; i < 10 && q > 0; i++) {
	of << 2 << " " << 49999 << " " << i << " " << (i+1)%10 << endl, q--;
	if(q > 0) of << 1 << " " << 99999 << " " << 0 << " " << 9 << endl, q--;
      }
      if(q > 0) {
	//of << 1 << " " << 99999 << " " << 0 << " " << 9 << endl, q--;
      }
    }
    //assert(q == 0);
    of.close();
  }

  return 0;
}
