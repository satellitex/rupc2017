#include<bits/stdc++.h>
#define MAX_V 6005
#define INF (1e9)
using namespace std;
typedef long long ll;

//辺を表す構造体(行き先、容量、逆辺)
struct edge{int to, cap, rev;};

vector<edge> G[MAX_V]; //グラフの隣接リスト
bool used[MAX_V];      //DFSですでに調べたかのフラグ

//fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from,int to,int cap){
  G[from].push_back((edge){to,cap,G[to].size()});
  G[to].push_back((edge){from,0,G[from].size()-1});
}

//増加パスをDFSで探す
int dfs(int v,int t,int f){
  if(v == t)return f;
  used[v]=true;
  for(int i=0; i<G[v].size() ;i++){
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

//sからtへの最大流を求める
int max_flow(int s,int t){
  int flow = 0;
  for(;;){
    memset(used,0,sizeof(used));
    int f = dfs(s, t, INF);
    if(f == 0)return flow;
    flow += f;
  }
}

void rev(int s,int t,int f){
  while(f){
    memset(used,0,sizeof(used));
    f-=dfs(s,t,f);
    
  }
}

ll n,k,x[MAX_V],y[MAX_V];
vector<int> ans;

int main(){
  cin>>n>>k;
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
  int s=n,t=n+1;
  for(int i=0;i<n;i++){
    if(y[i]%2)continue;
    for(int j=0;j<n;j++){
      if(!(y[j]%2))continue;
      if(i==j)continue;
      if((x[i]-x[j])*(x[i]-x[j])
	 +(y[i]-y[j])*(y[i]-y[j])<4){
	add_edge(i,j,INF);
      }
    }
  }
  for(int i=0;i<n;i++){
    if(!(y[i]%2))add_edge(s,i,1);
    else add_edge(i,t,1);
  }
  int F=max_flow(s,t);
  if(n-F<k)cout<<-1<<endl;
  else{
    for(int i=0;i<n;i++){
      if(!(y[i]%2)){
	for(int j=0;j<G[s].size();j++)
	  if(G[s][j].to==i)G[s][j].cap+=INF;
      }else{
	for(int j=0;j<G[i].size();j++)
	  if(G[i][j].to==t)G[i][j].cap+=INF;
      }
      int r=max_flow(s,t);
      if(!r)ans.push_back(i+1);
      else{
	if(!(y[i]%2)){
	  memset(used,0,sizeof(used));
	  rev(t,i,r);
	  for(int j=0;j<G[s].size();j++)
	    if(G[s][j].to==i){
	      G[s][j].cap-=INF-r;
	      G[G[s][j].to][G[s][j].rev].cap-=r;
	    }
	}else{
	  memset(used,0,sizeof(used));
	  rev(i,s,r);
	  for(int j=0;j<G[i].size();j++){
	    if(G[i][j].to==t){
	      G[i][j].cap-=INF-r;
	      G[G[i][j].to][G[i][j].rev].cap-=r;
	    }
	  }
	}
      }
    }
    for(int i=0;i<k;i++){
      //cout<<(char)(ans[i]+'A'-1)<<endl;
      cout<<ans[i]<<endl;
    }
  }
  return 0;
}
