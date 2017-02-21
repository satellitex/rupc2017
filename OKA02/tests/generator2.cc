#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1000;
const ll MAX_AB = 1e12; 
const int MAX_t = 5;
const ll MAX_xy = 1e12; 


int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  for (int t = 0; t < 5; t++) {
    ofstream of(format("03_random_All200_No_%02d.in", t+1).c_str());
    int N = 1000;
    ll A = MAX_AB;
    ll B = MAX_AB;
    of<<N<<" "<<A<<" "<<B<<endl;
    for(int j=1;j<=5;j++)
      for(int i=0;i<200;i++){
	ll x = rnd.next(-MAX_xy,(ll)1e8);
	ll y = rnd.next(-MAX_xy,(ll)1e8);
	of<<j<<" "<<x<<" "<<y<<endl;
      }
  }
  return 0;
}
