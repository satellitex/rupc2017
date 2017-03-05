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
  registerGen(argc, argv, 1);
  for (int t = 0; t < 3; t++) {
    ofstream of(format("04_random_All100_Yes_%02d.in", t+1).c_str());
    int N = MAX_N;
    ll A = 1;
    ll B = MAX_AB;
    of<<N<<" "<<A<<" "<<B<<endl;
    for(int j=1;j<=5;j++)
      for(int i=0;i<100;i++){
	ll x = rnd.next(1LL,(MAX_xy)/5);
	ll y = rnd.next(1LL,(MAX_xy)/5);
	of<<j<<" "<<x<<" "<<y<<endl;
      }
  }
  return 0;
}
