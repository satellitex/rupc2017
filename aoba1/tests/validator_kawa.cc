#include "testlib.h"

using namespace std;

const int N_MIN =      1;
const int N_MAX = 100000;
const int p_MIN =      1;
const int p_MAX = 100000;

int N,p[N_MAX];

void input()
{
  N = inf.readInt(N_MIN, N_MAX,"N");
  inf.readEoln();
  
  for (int i = 0; i < N; i++) {
    if(i!=0)inf.readSpace();
    p[i] = inf.readInt(p_MIN, N, format("p[%d]", i+1 ));
  }
  inf.readEoln();
  inf.readEof();
}

int main()
{
  registerValidation();
    
  input();

  return 0;
}
