#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef pair<int,int> P;

int main(int argc, char* argv[]) {
  registerGen(argc, argv);
  for(int t=1; t<11; t++) {
    ofstream ofs(format("02_large_%02d.in",t).c_str());
    vector<P> v;
    int n;
    if(t==1||t==4) {
      n=100000;
      if(t==4) v.push_back(P(2,0));
      for(int i=0; i<n-1; i++) v.push_back(P(i,i+1));
    } else if(t==2||t==3) {
      n=100000;
      if(t==3) n=99999;
      for(int i=0; i<n; i++) v.push_back(P(i,(i+1)%n));
    } else if(t==5) {
      n=50000;
      for(int i=0; i<n-1; i++) {
        v.push_back(P(i,i+1));
        if(i%3==2) v.push_back(P(i,i-2));
      }
    } else if(t==6) {
      n=70000;
      for(int i=0; i<n-1; i++) {
        v.push_back(P(i,i+1));
        if(i%7==2) v.push_back(P(i,i-2));
        if(i%7==6) v.push_back(P(i,i-3));
      }
    } else if(t==7||t==8) {
      n=30001;
      if(t==8) n=30000;
      for(int i=1; i<n-1; i++) {
        v.push_back(P(i,i%(n-2)+1));
        v.push_back(P(0,i));
        v.push_back(P(i,n-1));
      }
    } else if(t==9) {
      n=60000;
      for(int i=0; i<n-1; i++) {
        v.push_back(P(i,i+1));
        if(i%4==3) v.push_back(P(i,i-3));
        if(i%8==2) v.push_back(P(i,i+2));
      }
    } else {
      n=10000;
      for(int i=1; i<n; i++) {
        int k=rnd.next(1,min(i,10));
        set<int> s;
        s.insert(-1);
        for(int j=0; j<k; j++) {
          if(v.size()>=100000) break;
          int x=-1;
          while(s.count(x)) x=rnd.next(0,i-1);
          v.push_back(P(x,i));
          s.insert(x);
        }
      }
    }
    ofs << n << " " << v.size() << endl;
    for(int i=0; i<n; i++) {
      if(i) ofs << " ";
      ofs << rnd.next(0,1000);
    }
    ofs << endl;
    for(int i=0; i<v.size(); i++) ofs << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
