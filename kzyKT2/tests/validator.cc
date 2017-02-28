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
  for(int i=0; i<n; i++) {
    if(i) inf.readSpace();
    inf.readInt(0, 1000, "c");
  }
  inf.readEoln();
  set<P> s;
  for(int i=0; i<m; i++) {
    int a=inf.readInt(0, n-1, "a");
    inf.readSpace();
    int b=inf.readInt(0, n-1, "b");
    inf.readEoln();
    ensuref(!s.count(P(a,b)),"a,b is exist");
    ensuref(a!=b,"a==b");
    s.insert(P(a,b));
  }
  inf.readEof();
  return 0;
}
