#include<bits/stdc++.h>
#define INF (1e9)
#define MAX_V 300
using namespace std;
struct edge{int to, cap, rev, X;};
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from,int to,int cap,int x){
  G[from].push_back((edge){to,cap,G[to].size(),x});
  G[to].push_back((edge){from,0,G[from].size()-1,0});  
}

int Mid;

int dfs(int v,int t,int f){
  if(v == t)return f;
  used[v]=true;
  for(int i=0; i<G[v].size() ;i++){
    edge &e = G[v][i];
    if(e.X>Mid)continue;
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to ,t , min(f,e.cap));
      if(d > 0){
	e.cap -= d;
	G[e.to][e.rev].cap += d;
	return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t){
  int flow = 0;
  for(;;){
    memset(used,0,sizeof(used));
    int f = dfs(s, t, INF);
    if(f == 0)return flow;
    flow += f;
  }
}

int n,m,x,A,s,g;

int bynary_search(){
  int l=0,r=INF+1;
  while(l<r){
    Mid=(l+r)/2;
    if(max_flow(s,g)==m)r=Mid;
    else l=Mid+1;
    max_flow(g,s);
  }
  return l;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      cin>>x;
      add_edge(i,j+n,1,x);
    }
  A=2*n+m+1,s=n+m,g=A+1;
  add_edge(s,A,m%n,0);
  for(int i=s+1;i<A;i++){
    add_edge(s,i,m/n,0);
    add_edge(i,i-(s+1),m/n+1,0);
    add_edge(A,i,1,0);
  }
  for(int i=n;i<s;i++)
    add_edge(i,g,1,0);
  cout<<(m%n!=0)<<endl;
  cout<<bynary_search()<<endl;
  return 0;
}
