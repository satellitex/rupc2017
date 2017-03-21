#include<bits/stdc++.h>
#define M 22
using namespace std;
set<short> s[(1<<M)];
int n,k,Or[(1<<M)],nS;
bool flag[(1<<M)];
set<short>::iterator ite;

int solve(){
  int res=0;
  for(int S=(1<<M)-1;S>=0;S--){
    for(int i=0;i<M;i++){
      if(!(S&(1<<i)))continue;
      nS=(S&~(1<<i));
      Or[nS]|=Or[S];
      ite=s[S].begin();
      while(ite!=s[S].end()&&s[nS].size()<3){
	s[nS].insert((*ite));
	ite++;
      }
      if(s[nS].size()==3){
	flag[nS]=1;
	s[nS].clear();
      }
    }
    if(flag[S])
      res=max(res,__builtin_popcount(Or[S])*__builtin_popcount(S));
    s[S].clear();
  }
  return res;
}

int main(){
  cin>>n;
  int S,a;
  for(int i=0;i<n;i++){
    scanf("%d",&k);
    S=0;
    for(int j=0;j<k;j++)
      scanf("%d",&a),S|=(1<<(a-1));
    if(!flag[S]&&s[S].size()<3)s[S].insert(i);
    if(s[S].size()==3){
      flag[S]=1;
      s[S].clear();
    }
    Or[S]|=S;
  }
  cout<<solve()<<endl;
  return 0;
}
