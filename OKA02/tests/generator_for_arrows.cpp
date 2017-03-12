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
  ofstream of(format("06_corner04.in").c_str());
  int N = MAX_N;
  ll A = 1;
  ll B = 1e9;
  of<<N<<" "<<A<<" "<<B<<endl;
  ll cnt=1;
  for(int j=1;j<=5;j++){
    for(int i=0;i<100;i++){
      ll x = 2;
      ll y = rnd.next((1e9)+1,1e12);
      of<<j<<" "<<x<<" "<<y<<endl;
    }
    cnt*=200;
  }
  return 0;
}
