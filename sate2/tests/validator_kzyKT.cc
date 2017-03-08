#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main() {
  registerValidation();
  int n=inf.readInt(1, 100, "n");
  inf.readSpace();
  int m=inf.readInt(1, 100, "m");
  inf.readEoln();
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(j) inf.readSpace();
      inf.readInt(1,1000000000,"h");
    }
    inf.readEoln();
  }
  inf.readEof();
  return 0;
}
