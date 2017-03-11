#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int N_MIN = 2;
const int N_MAX = 6000;
const int K_MIN = 2;

const int X_MIN = 1;
const int X_MAX = 1000000;
const int Y_MIN = 1;
const int Y_MAX = 1000000;

typedef pair<int,int> P;

void input() {
  int N = inf.readInt(N_MIN, N_MAX,"N");
  inf.readSpace();
  int K_MAX=N;
  
  int K = inf.readInt(K_MIN, K_MAX,"K");
  inf.readEoln();
  
  set< P > st;
  for (int i = 0; i < N; i++) {
    int px = inf.readInt(X_MIN, X_MAX, format("X[%d]", i ));
    inf.readSpace();
    int py = inf.readInt(Y_MIN, Y_MAX, format("Y[%d]", i ));
    assert ( st.count( P(px,py) ) == 0 );
    st.insert( P(px,py) );
    
    assert ( px%2 == (py/2)%2 );
    inf.readEoln();
  }
  inf.readEof();
}

int main(){
  registerValidation();
  input();
  return 0;
}
