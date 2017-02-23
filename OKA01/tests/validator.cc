#include "testlib.h"

using namespace std;

const int N_MIN =      1;
const int N_MAX =    100;
const int P_MIN =      0;
const int P_MAX = 100000;
const int X_MIN =      0;
const int X_MAX = 100000;
const int Y_MIN =      0;
const int Y_MAX = 100000;

int N,P;
int X[N_MAX], Y[N_MAX];

void input()
{
  N = inf.readInt(N_MIN, N_MAX,"N");
  inf.readSpace();
  P = inf.readInt(P_MIN, P_MAX,"P");
  inf.readEoln();
  
  for (int i = 0; i < N; i++) {
    X[i] = inf.readInt(X_MIN, X_MAX, format("X[%d]", i ));
    inf.readSpace();
    Y[i] = inf.readInt(Y_MIN, Y_MAX, format("Y[%d]", i ));
    inf.readEoln();
  }
  inf.readEof();
}

int main()
{
  registerValidation();
    
  input();

  return 0;
}
