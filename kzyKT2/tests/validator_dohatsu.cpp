#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int MIN_N=1;
int MAX_N=100000;
int MIN_M=0;
int MAX_M=100000;

int MIN_C=0;
int MAX_C=1000;
map< int, set<int> > G;

int main() {
  registerValidation();
  int n=inf.readInt(MIN_N,MAX_N,"N");
  inf.readSpace();
  
  if(n<1000&&n*(n-1)<MAX_M)MAX_M=n*(n-1);
  int m=inf.readInt(MIN_M,MAX_M,"M");
  inf.readEoln();
  for(int i=0;i<n;i++){
    if(i)inf.readSpace();
    int c=inf.readInt(MIN_C,MAX_C,"C");
  }
  inf.readEoln();


  for(int i=0;i<m;i++){
    int from=inf.readInt(0,n-1,"from");
    inf.readSpace();
    int to=inf.readInt(0,n-1,"to");
    assert(from!=to);
    assert( G[from].count(to)==0 );
    G[from].insert(to);
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
