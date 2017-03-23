#include <bits/stdc++.h>
#define INF 1e9
#define MAX_V 10000
#define N 6010
using namespace std;
struct edge{
  int to, cap, rev;
  edge();
  edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){};
};
vector<edge> G[MAX_V]; //グラフの隣接リスト
bool used[MAX_V];      //DFSですでに調べたかのフラグ

void add_edge(int from,int to,int cap){
  G[from].emplace_back(to,cap,G[to].size());
  G[to].emplace_back(from,0,G[from].size()-1);  
}

int dfs(int v,int t,int f){
  if(v == t)return f;
  used[v]=true;
  for(int i=0; i<(int)G[v].size() ;i++){
    edge &e = G[v][i];
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

int dfs(int v,int t,int f,int depth){
  if(v == t)return f;
  if(depth==2)return 0;

  used[v]=true;
  for(int i=0; i<(int)G[v].size() ;i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to ,t , min(f,e.cap),depth+1);
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

long long dist(double x,double y,double x2,double y2){
  return ((x-x2)*(x-x2)+(y-y2)*(y-y2));
}

int n,K,x[N],y[N];
int S,T,pos[N];
void mk_graph(){
  S = n,T=S+1;
  for(int i=0;i<n;i++){
    if(y[i]%2) add_edge(S,i,1),pos[i] = G[S].size()-1;
    else add_edge(i,T,1);
  }

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(dist(x[i],y[i],x[j],y[j])<4)
	y[i]%2?add_edge(i,j,INF):add_edge(j,i,INF);
    

}

void flow(int s,int t,int f){
  while(f){
    memset(used,0,sizeof(used));
    f-=dfs(s, t, f,0);
  }
}

vector<int> solve(){
  vector<int> res;
  int mx = max_flow(S,T);
  if(n-mx<K) return vector<int>();
  for(int i=0;(int)res.size()<K;i++){
    edge &e = y[i]%2? G[S][pos[i]]:G[i][0];
    e.cap+=INF;
    int q = max_flow(S,T);
    int r = mx+q;
    if(n-r>=K) res.push_back(i),mx = r;
    else{
      int a = y[i]%2?S:i,b = y[i]%2? i:T;
      flow(b,a,q);
      e.cap -= INF;
      flow(T,b,q);
      flow(a,S,q);
    }
  }
  return res;
}

int main(){
  cin>>n>>K;
  for(int i=0;i<n;i++)cin>>x[i]>>y[i];
  mk_graph();
  vector<int> ans = solve();
  if(ans.size()==0) cout<<-1<<endl;
  else for(int i=0;i<(int)ans.size();i++)cout<<ans[i]+1<<endl;

}
