#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main() {
  registerValidation();
  int n=inf.readInt(2,100000,"n");
  inf.readEoln();
  for(int i=0; i<n; i++) {
    string s=inf.readToken(format("[0-9.]{5}","ai"));
    for(int j=0; j<5; j++) {
      if(j==1) ensuref(s[j]=='.',"ai");
      else ensuref(isdigit(s[j]),"ai");
    }
    double d;
    stringstream ss;
    ss << s;
    ss >> d;
    ensuref(0<=d&&d<=4,"ai");
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
