#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N_MIN =      3;
const int N_MAX =  20000;

const int A_MIN =      1;
const int A_MAX =     22;

void input() {
  int N = inf.readInt(N_MIN, N_MAX,"N");
  inf.readEoln();
  
  
  for (int i = 0; i < N; i++) {
    int k = inf.readInt(A_MIN, A_MAX, format("K[%d]", i ));
    int last=0;
    
    for(int j=0;j<k;j++){
      inf.readSpace();
      int A=inf.readInt(A_MIN,A_MAX, format("A[%d][%d]", i , j ) );
      assert(last<A);
      last=A;
    }
      
    inf.readEoln();
  }
  inf.readEof();
}

int main(){
  registerValidation();
  input();
  return 0;
}
