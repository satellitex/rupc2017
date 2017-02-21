#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 制約
const int MAX_N = 1000;
const int MIN_N = 1;
const ll MAX_AB = 1e12; 
const ll MIN_AB = 1;
const int MAX_t = 5;
const int MIN_t = 1;
const ll MAX_xy = 1e12; 
const ll MIN_xy = -1e12;


// 入力変数
int N;
ll A,B,t[MAX_N],x[MAX_N],y[MAX_N];

void input() {
  N = inf.readInt(MIN_N,MAX_N, "N");
  inf.readSpace();
  A = inf.readLong(MIN_AB, MAX_AB,"A");
  inf.readSpace();
  B = inf.readLong(MIN_AB, MAX_AB,"B");
  inf.readEoln();
  
  for(int i=0;i<N;i++) {
    t[i] = inf.readInt(MIN_t,MAX_t,"t");
    inf.readSpace();
    x[i] = inf.readLong(MIN_xy,MAX_xy,"x");
    inf.readSpace();
    y[i] = inf.readLong(MIN_xy,MAX_xy,"y");
    inf.readEoln();
  }
  inf.readEof();
}

int main() {
  registerValidation();
  input();
  return 0;
}
