#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 500;
const ll MAX_AB = 1e12; 
const int MAX_t = 5;
const ll MAX_xy = 1e12; 

int main(int argc, char *argv[]){
  registerGen(argc, argv, 1);
  for(int t=0;t<3;t++){
    ofstream of(format("03_All100_yes_%02d.in",t).c_str());
    int N = 500;
    ll A  = rnd.next(1LL,MAX_xy);
    ll B  = A;
    if(A>B) swap(A,B);
    
    of<<N<<" "<<A<<" "<<B<<endl;
    vector<int> T,X,Y;
    for(int j=1;j<=5;j++){
      for(int i=0;i<99;i++){
	ll x = rnd.next(-MAX_xy,MAX_xy);
	ll y = rnd.next(-MAX_xy,MAX_xy);
	if(rnd.next(0,1))swap(x,y);
	T.push_back(j);
	X.push_back(x);
	Y.push_back(y);
      }
    } 
      
    ll a = rnd.next(0LL,A);
    ll b = rnd.next(0LL,A-a);
    ll c = rnd.next(0LL,A-a-b);
    ll d = rnd.next(0LL,A-a-b-c);
    ll e = A-a-b-c-d;
    assert(a+b+c+d+e==A);
    T.push_back(1),X.push_back(a),Y.push_back(a);
    T.push_back(2),X.push_back(b),Y.push_back(b);
    T.push_back(3),X.push_back(c),Y.push_back(c);
    T.push_back(4),X.push_back(d),Y.push_back(d);
    T.push_back(5),X.push_back(e),Y.push_back(e);
    for(int i=0;i<10000;i++){
      int a = rnd.next(0,(int)T.size()-1);
      int b = rnd.next(0,(int)T.size()-1);
      swap(T[a],T[b]),swap(X[a],X[b]),swap(Y[a],Y[b]);
    }

    for(int i=0;i<T.size();i++)of<<T[i]<<" "<<X[i]<<" "<<Y[i]<<endl;
  }
  return 0;
}



    /*int N = 500;
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
      }*/
