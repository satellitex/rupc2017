#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 100;
const int M = 100;
const int C = 1000000;
const int T = 1000000;

vector<int> X, Y;

void init() {
  mt19937 MT((int)time(0));
  Y.clear();
  for(int i = 0; i <= N; i++) Y.push_back(i);
  shuffle(Y.begin()+2, Y.end()-1, MT);
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
