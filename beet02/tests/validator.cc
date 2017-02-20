#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 100000;

int n;
string s;
void input() {
  s = inf.readString();
  inf.readEof();
}

void check() {
  ensuref(s.size()<=100,"format invalid");
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
