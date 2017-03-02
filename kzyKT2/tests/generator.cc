#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N=100000;
int main(int argc, char* argv[]) {
  registerGen(argc, argv);
  for(int t=0; t<30; t++) {
    ofstream ofs(format("03_random_%02d.in",t).c_str());
    ll n=rnd.next(1LL,N),m=rnd.next(0LL,min(n*(n-1),N));
    ofs << n << " " << m << endl;
    for(int i=0; i<n; i++) {
      if(i) ofs << " ";
      ofs << rnd.next(0,1000);
    }
    ofs << endl;
    set<P> s;
    s.insert(P(-1,-1));
    for(int i=0; i<m; i++) {
      int x=-1,y=-1;
      while(s.count(P(x,y))||x==y) x=rnd.next(0LL,n-1),y=rnd.next(0LL,n-1);
      ofs << x << " " << y << endl;
      s.insert(P(x,y));
    }
    ofs.close();
  }
  return 0;
}
