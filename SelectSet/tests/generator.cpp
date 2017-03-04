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

std::uniform_int_distribution<> randN( 3 , 20 );
std::uniform_int_distribution<> randA( 1 , (1<<22)-1 );

void solve(int casenum){
  string filename="03_random_"+i2s(casenum)+".in";
  ofstream fout(filename);
  int N=randN(mt);
  fout<<N<<endl;
  for(int i=0;i<N;i++){
    int bit=randA(mt);
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
  for(int i=0;i<10;i++){
    solve(i);
  }
  return 0;
}
