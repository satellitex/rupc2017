#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  for (int t = 0; t < 30; t++) {
    ofstream of(format("02_random_%02d.in", t+1).c_str());
    int n=rnd.next(2,100000);
    of<<n<<endl;
    for(int i=0;i<n;i++){
      double x=rnd.next(0.0,4.0);
      of<<fixed << setprecision(3)<<x<<endl;
    }
    of.close();
  }
  return 0;
}
