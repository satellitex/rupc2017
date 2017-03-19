#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

string i2s(int x){
  char tmp[100];
  sprintf(tmp,"%02d",x);
  string res(tmp);
  return res;
}

std::mt19937 mt( (int)time(0) );


std::uniform_int_distribution<> randA( 1 , (1<<22)-1 );
std::uniform_int_distribution<> randB( 1 , (1<<19)-1 );
std::uniform_int_distribution<> randC( 1 , (1<<16)-1 );

void solve(int casenum){
  string filename="05_randomlarge_"+i2s(casenum)+".in";
  ofstream fout(filename);
  
  int N=20000 - randA(mt)%100;
  
  fout<<N<<endl;
  for(int i=0;i<N;i++){
    
    int bit;
    if(casenum%3==0)bit=randA(mt);
    else if(casenum%3==1)bit=randB(mt);
    else bit=randC(mt);
    
    int K=__builtin_popcount(bit);
    fout<<K;
    for(int j=0;j<22;j++){
      if(bit>>j&1){
        fout<<' '<<j+1;
      }
    }
    fout<<endl;
      
  }
}

int main(){
  for(int i=0;i<9;i++){
    solve(i);
  }
  return 0;
}
