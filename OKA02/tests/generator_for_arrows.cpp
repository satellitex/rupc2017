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
  for(int t=0;t<0;t++){
    registerGen(argc, argv, 1);
    ofstream of(format("00_corner%02d.in",t).c_str());
    int N = 500;
    ll A = 1e10;
    ll B = 1e11;
    
    of<<N<<" "<<A<<" "<<B<<endl;
    for(int j=1;j<=5;j++){
      for(int i=0;i<100;i++){
	ll x = rnd.next(A,B/5);
	ll y = rnd.next(B+1,MAX_xy);
	if(i<50) y = rnd.next(0LL,(A-1)/5);
	if(j>=2) x = y = rnd.next(0LL,(A-1)/5);
	if(i%2)swap(x,y);

	of<<j<<" "<<x<<" "<<y<<endl;
      }
    }

  }
  return 0;
}
