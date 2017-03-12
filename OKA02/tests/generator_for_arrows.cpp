#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 500;
const ll MAX_AB = 1e12; 
const int MAX_t = 5;
const ll MAX_xy = 1e12; 

int main(int argc, char *argv[])
{
  for(int t=0;t<2;t++){
    registerGen(argc, argv, 1);
    ofstream of(format("00_corner%02d.in",t).c_str());
    int N = MAX_N;
    ll A = 1;
    ll B = 1e9;
    of<<N<<" "<<A<<" "<<B<<endl;
    for(int j=1;j<=5;j++){
      for(int i=0;i<100;i++){
	ll x =2;
	ll y = rnd.next(B+1,MAX_xy);
	of<<j<<" "<<x<<" "<<y<<endl;
      }
    }

  }
  return 0;
}
