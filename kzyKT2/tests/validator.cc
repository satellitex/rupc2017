#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N=100000;
int main() {
  registerValidation();
  ll n=inf.readInt(1LL, N, "n");
  inf.readSpace();
  ll m=inf.readInt(0LL, min(n*(n-1),N), "m");
  inf.readEoln();
  set<P> s;
  for(int i=0; i<m; i++) {
    int x=inf.readInt(0, n, "x");
    inf.readSpace();
    int y= inf.readInt(0, n, "y");
    inf.readEoln();
    ensuref(!s.count(P(x,y)),"x,y is exist");
    ensuref(x!=y,"x==y");
    s.insert(P(x,y));
  }
  inf.readEof();
  return 0;
}
