#include <bits/stdc++.h>
#define N 100001
using namespace std;
typedef pair<int,int> P;
typedef set<P> S;
typedef S::iterator Sit;
int w,h,n;
S mp;

void bfs(S &D,S &D2,int x,int y){
  queue<P> Q;
  Q.push(P(x,y)),D.insert(P(x,y));
  
  while(!Q.empty()){
    P t = Q.front();Q.pop();
    x = t.first, y = t.second;
    for(int i=-1;i<=1;i++)
      for(int j=-1;j<=1;j++){
	int nx = x+i, ny = y+j;
	P nt = P(nx,ny);
	if((nx==0&&ny==0)||(nx==w-1&&ny==h-1)||D.count(nt))continue;

	if(!mp.count(nt))D2.insert(nt);
	else Q.push(nt),D.insert(nt);
      }
  }
}

int main(){
  cin>>w>>h>>n;
  for(int i=0,x,y;i<n;i++)cin>>x>>y,mp.insert(P(x,y));
  
  S A,B,A2,B2;
  for(Sit it=mp.begin();it!=mp.end();it++){
    int x = it->first,y = it->second;
    if(x==0||y==h-1) bfs(A,A2,x,y);
    if(x==w-1||y==0) bfs(B,B2,x,y);
  }
  
  
    for(int i=1;i<h;i++)A2.insert(P(0,i));
    for(int i=0;i<w-1;i++)A2.insert(P(i,h-1));
    
    for(int i=0;i<h-1;i++)B2.insert(P(w-1,i));
    for(int i=1;i<w;i++)B2.insert(P(i,0));
    /*
  for(int i=1;i<h-1;i++)A2.insert(P(0,i)),B2.insert(P(w-1,i));
  for(int i=1;i<w-1;i++)A2.insert(P(i,h-1)),B2.insert(P(i,0));
    */

  int ans = 2;
  for(Sit it=A2.begin();it!=A2.end();it++)if(B2.count(*it))ans=1;
  for(Sit it=A.begin();it!=A.end();it++)if(B.count(*it))ans=0;
  cout<<ans<<endl;
  return 0;
}
