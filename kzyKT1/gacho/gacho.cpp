#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,m,k,x,y,ans=2;
map<P,int> G;
set<P> sl,sr,used;
int dy[3]={-1,0,1};
int dx[3]={-1,0,1};
int d[5]={-2,-1,0,1,2};
queue<P> q;

void bfs(P p){
  q.push(p);
  while(!q.empty()){
    P X=q.front(); q.pop();
    if(used.count(X))continue;
    used.insert(X);
    G[X]=0;
    if(X.first==0||X.second==m-1)ans=0;
    if(X.first==1||X.second==m-2)ans=min(ans,1);
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	int ny=X.first+dy[i],nx=X.second+dx[j];
	if(!i&&!j)continue;
	if(G.count(P(ny,nx)))q.push(P(ny,nx));
      }
    }
  }
}

void bfs2(P p){
  q.push(p);
  while(!q.empty()){
    P X=q.front(); q.pop();
    if(used.count(X))continue;
    used.insert(X);
    if(X.first==n-2||X.second==1)ans=1;
    for(int i=0;i<5;i++){
      int ny=X.first-2,nx=X.second+d[i];
      if(G.count(P(ny,nx))&&!G[P(ny,nx)])ans=1;
    }
    for(int i=0;i<5;i++){
      int ny=X.first+2,nx=X.second+d[i];
      if(G.count(P(ny,nx))&&!G[P(ny,nx)])ans=1;
    }
    for(int i=0;i<5;i++){
      int ny=X.first+d[i],nx=X.second-2;
      if(G.count(P(ny,nx))&&!G[P(ny,nx)])ans=1;
    }
    for(int i=0;i<5;i++){
      int ny=X.first+d[i],nx=X.second+2;
      if(G.count(P(ny,nx))&&!G[P(ny,nx)])ans=1;
    }
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	int ny=X.first+dy[i],nx=X.second+dx[j];
	if(!i&&!j)continue;
	if(G.count(P(ny,nx)))q.push(P(ny,nx));
      }
    }
  }
}

int main(){
  cin>>n>>m>>k;
  swap(n,m);
  for(int i=0;i<k;i++){
    cin>>x>>y;
    G[P(y,x)]=-1;
    if(x==0||y==n-1)sl.insert(P(y,x));
    if(x==m-1||y==0)sr.insert(P(y,x));
  }
  set<P>::iterator ite=sl.begin();
  while(ite!=sl.end()){
    bfs((*ite));
    ite++;
  }
  if(ans==0){
    cout<<0<<endl;
    return 0;
  }
  ite=sr.begin();
  used.clear();
  while(ite!=sr.end()){
    bfs2((*ite));
    ite++;
  }
  cout<<ans<<endl;
  return 0;
}
