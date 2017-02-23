#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
  registerGen(argc,argv,1);
  for (int t=0;t<50;t++) {
    ofstream of(format("03_random_%02d.in",t+1).c_str());
    int n,p;
    n=rnd.next(1, 100);
    p=rnd.next(0, 100000);
    of<<n<<' '<<p<<endl;
    for(int i=0;i<n;i++)
      of<<rnd.next(0,100000)<<' '<<rnd.next(0,100000)<<endl;
  }
  return 0;
}
