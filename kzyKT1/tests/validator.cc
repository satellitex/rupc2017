#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N=100000;
int main() {
  registerValidation();
  int n=inf.readInt(2, N, "n");
  inf.readSpace();
  int m=inf.readInt(2, N, "m");
  inf.readSpace();
  int k=inf.readInt(0, min((ll)n*m-2,N), "k");
  inf.readEoln();
  set<P> s;
  s.insert(P(0,0));
  s.insert(P(n-1,m-1));
  for(int i=0; i<k; i++) {
    int x=inf.readInt(0, n-1, "x");
    inf.readSpace();
    int y=inf.readInt(0, m-1, "y");
    inf.readEoln();
    ensuref(!s.count(P(x,y)),"x,y is exist");
    s.insert(P(x,y));
  }
  inf.readEof();
  return 0;
}
