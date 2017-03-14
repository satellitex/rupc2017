#include<bits/stdc++.h>
#define M 22
using namespace std;
typedef pair<int,int> P;
int n,k,Or[(1<<M)],used[(1<<M)];
vector<int> cnt[(1<<M)];
set<int> s[(1<<M)];

int solve(){
  int res=0;
  for(int S=(1<<M)-1;S>=0;S--){
    for(int i=0;i<cnt[S].size();i++){
      if(s[S].size()>=3)break;
      s[S].insert(cnt[S][i]);
    }
    if(cnt[S].size())Or[S]|=S;
    if(s[S].size()>=3)
      res=max(res,__builtin_popcount(Or[S])*__builtin_popcount(S));
    if(used[S])continue;
    used[S]=1;
    for(int i=0;i<M;i++){
      if(!(S&(1<<i)))continue;
      int nS=(S&~(1<<i));
      Or[nS]|=Or[S];
      set<int>::iterator ite=s[S].begin();
      while(ite!=s[S].end()&&s[nS].size()<3){
	s[nS].insert((*ite));
	ite++;
      }
    }
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
    cnt[S].push_back(i);
  }
  cout<<solve()<<endl;
  return 0;
}
