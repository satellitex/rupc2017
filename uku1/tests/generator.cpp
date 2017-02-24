#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 10000;
const int M = 10000;
const int C = 1000000;
const int T = 1000000;

vector<int> X, Y;

void init() {
  mt19937 MT((int));
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 20; t++) {
    init();
    start(t);
    ofstream ofs(format("03_random_%02d.in", t).c_str());

    ofs.close();
  }
  return 0;
}
