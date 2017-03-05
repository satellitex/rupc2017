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
  for (int t = 0; t < 20; t++) {
    ofstream of(format("05_random_%02d.in", t+1).c_str());
    int N = rnd.next(1, MAX_N);
    ll A =  MAX_AB;
    ll B =  MAX_AB;
    if(A>B) swap(A,B);
    of<<N<<" "<<A<<" "<<B<<endl;
    for(int i=0;i<N;i++){
      int t = rnd.next(1,MAX_t);
      ll x = rnd.next(-MAX_xy,MAX_xy);
      ll y = rnd.next(-MAX_xy,MAX_xy);
      of<<t<<" "<<x<<" "<<y<<endl;
    }
  }
  return 0;
}
