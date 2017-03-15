#include<bits/stdc++.h>
using namespace std;
#define MAX 6005
int N,K;
set<int> G[MAX];
int x[MAX],y[MAX];

int stk[MAX];
bool dfs(int p,int r){
  if(r==K){
    for(int i=0;i<K;i++)cout<<stk[i]+1<<endl;
    return true;
  }
  if(N-p+r<K)return false;

  bool flg=true;
  for(int i=0;i<r;i++){
    int id=stk[i];
    int dx=x[id]-x[p];
    int dy=y[id]-y[p];
    if(dx*dx+dy*dy<4)flg=false;
  }
  
  if(flg){
    stk[r]=p;
    if( dfs(p+1,r+1) )return true;
  }
  return dfs(p+1,r);
}

int main(){
  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>x[i]>>y[i];
    for(int j=0;j<i;j++){
      int dx=x[i]-x[j];
      int dy=y[i]-y[j];
      if(dx*dx+dy*dy<4){
        G[i].insert(j);
        G[j].insert(i);
      }
    }
  }
  
  if(!dfs(0,0)){
    cout<<-1<<endl;
  }
  
  return 0;
}
