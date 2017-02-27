#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 10000;
const int M = 10000;
const int C = 1000000;
const int T = 1000000;

void start(int id) {
  ofstream ofs(format("03_random_%02d.in", id).c_str());
  int n = rnd.next(2, N);
  int m = rnd.next(n-1, min(n*(n-1)/2, M));
  ofs << n << " " << m << endl;
  set< pair<int, int> > st;
  for(int b = 1; b < n; b++) {
    int a = rnd.next(0, b-1);
    st.insert(make_pair(a, b));
    int c = rnd.next(1, C);
    int t = rnd.next(0, T);
    ofs << a << " " << b << " " << c << " " << t << endl;
    m--;
  }

  for(int i = 0; i < m; i++) {
  RE:
    int a = rnd.next(0, n-1);
    int b = rnd.next(0, n-1);
    if(a > b) swap(a, b);
    if(a == b || st.count(make_pair(a, b))) goto RE;
    st.insert(make_pair(a, b));
    int c = rnd.next(1, C);
    int t = rnd.next(0, T);
    ofs << a << " " << b << " " << c << " " << t << endl;
  }
  ofs.close();
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 20; t++) {
    start(t);
  }
  return 0;
}
