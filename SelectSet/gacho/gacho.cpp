#include<bits/stdc++.h>
#define M 22
using namespace std;
int n,k,Or[(1<<M)],nS;
short s[(1<<M)][3];

void merge(int S,int x){
  for(int i=0;i<3;i++){
    if(s[S][i]==x)return;
    if(s[S][i]==-1){
      s[S][i]=x;
      return;
    }
  }
}

int solve(){
  int res=0;
  for(int S=(1<<M)-1;S>=0;S--){
    for(int i=0;i<M;i++){
      if(!(S&(1<<i)))continue;
      nS=(S&~(1<<i));
      Or[nS]|=Or[S];
      for(int j=0;j<3;j++)
	if(s[S][j]!=-1)merge(nS,s[S][j]);
    }
    if(s[S][2]!=-1)
      res=max(res,
	      __builtin_popcount(Or[S])
	      *__builtin_popcount(S));
  }
  return res;
}

int main(){
  cin>>n;
  int S,a;
  memset(s,-1,sizeof(s));
  for(int i=0;i<n;i++){
    scanf("%d",&k);
    S=0;
    for(int j=0;j<k;j++)
      scanf("%d",&a),S|=(1<<(a-1));
    if(s[S][2]==-1)merge(S,i);
    Or[S]|=S;
  }
  cout<<solve()<<endl;
  return 0;
}
