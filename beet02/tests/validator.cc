#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 100000;

int n;
string s[N_MAX];
void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readEoln();
  for(int i=0;i<n;i++) {
    s[i] = inf.readString();
  }
  inf.readEof();
}

void check() {
  for (int i=0;i<n;i++){
    ensuref(0.0<=stof(s[i])&&stof(s[i])<=4.0,"out of range");
    ensuref(s[i].size()==5,"format invalid");
  }
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
