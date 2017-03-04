#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 100000;

int n;
string s;
void input() {
  s = inf.readString();
  inf.readEof();
}

void check() {
  ensuref(s.size()<=100,"format invalid");
  ensuref(s[0]=='x',"format invalid");
  ensuref(s[1]=='^',"format invalid");
  ensuref('1'<s[2]&&s[2]<='5',"n invalid");
  for(int i=0;i<(int)s.size();i++){
    if(!isdigit(s[i])) continue;
    int tmp=0;
    while(i<(int)s.size()&&isdigit(s[i])) tmp=tmp*10+s[i++]-'0';
    ensuref(tmp<=2000,"coefficient invalid");
  }
}

int main() {
  registerValidation();
  input();
  check();
  return 0;
}
