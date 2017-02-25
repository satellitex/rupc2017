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
  for(int i = 0; i < N; i++) Y.push_back(i);
  shuffle(Y.begin()+1, Y.end()-1, MT);
}

void start(int id) {
  ofstream ofs(format("03_random_%02d.in", id).c_str());

  std::mt19937 mt( (int)time(0) );
  std::uniform_int_distribution<> randA(0, N-2);
  std::uniform_int_distribution<> randB(1, N-1);
  std::uniform_int_distribution<> randC(0, 5);
  ofs.close();
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 20; t++) {
    init();
    start(t);
  }
  return 0;
}
