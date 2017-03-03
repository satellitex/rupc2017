#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN_N = 1;
const int MAX_N = 100;
const int MIN_M = 1;
const int MAX_M = 100;
const int MIN_H = 1;
const int MAX_H = 1000000000;

int main() {
  registerValidation();
  int N = inf.readInt( MIN_N, MAX_N, "N" );
  inf.readSpace();
  int M = inf.readInt( MIN_N, MAX_N, "M" );
  inf.readEoln();
  
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if( j ) inf.readSpace();
      int H = inf.readInt( MIN_H, MAX_H, "H" );
    }
    inf.readEoln();
  }
  inf.readEof();

  return 0;
}
