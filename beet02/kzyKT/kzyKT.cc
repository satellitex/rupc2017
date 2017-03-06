#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> P;

int main() {
  string s;
  cin >> s;
  vector<P> v;
  vector<int> t;
  t.push_back(1);
  for(int i=0; i<s.size(); i++) {
    if(s[i]=='+'||s[i]=='-') {
      if(s[i]=='+') t.push_back(1);
      else t.push_back(-1);
      s[i]=' ';
    }
  }
  stringstream ss;
  ss << s;
  int k=0;
  while(ss >> s) {
    int x=0;
    P p=P(-1,0);
    for(int i=0; i<s.size(); i++) {
      if(isdigit(s[i])) {
        x*=10;
        x+=s[i]-'0';
      } else {
        if(p.F==-1) {
          if(!x) x=1;
          p.F=x;
          x=0;
        } else continue;
      }
    }
    if(p.F==-1) {
      if(!x) x=1;
      p.F=x;
    } else {
      if(!x) x=1;
      p.S=x;
    }
    p.F*=t[k++];
    v.push_back(p);
  }
  vector<int> z;
  for(int x=-2000; x<=2000; x++) {
    int sum=0;
    for(int i=0; i<v.size(); i++) sum+=v[i].F*pow(x,v[i].S);
    if(!sum) z.push_back(-x);
  }
  sort(z.begin(),z.end());
  for(int i=0; i<z.size(); i++) cout << "(x" << (z[i]>0?"+":"") << z[i] << ")";
  cout << endl;
  return 0;
}
