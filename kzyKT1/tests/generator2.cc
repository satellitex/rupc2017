#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef pair<int,int> P;

int main() {
  vector<P> v;
  for(int i=0; i<100000; i++) v.push_back(P(99999,i));
  for(int t=3; t<8; t++) {
    ofstream ofs(format("02_large_%02d.in",t).c_str());
    ofs << 100000 << " " << 100000 << " ";
    if(t==3) ofs << 100000 << endl;
    else if(t==4||t==5||t==6) ofs << 99999 << endl;
    else ofs << 99998 << endl;
    for(int i=0; i<v.size(); i++) {
      if(t==4&&i==0) continue;
      if(t==5&&i==v.size()-1) continue;
      if(t==6&&i==55555) continue;
      if(t==7&&(i==40000||i==60000)) continue;
      ofs << v[i].first << " " << v[i].second << endl;
    }
  }
  return 0;
}
