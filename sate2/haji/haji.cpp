#include <bits/stdc++.h>
#define MAX_V 500
#define INF ((1e9)+10)
#define N 110
using namespace std;

/*最大流アルゴリズム(Ford_Fulerson法使用)　O(F|E|)*/

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


int n,m;
int g[N][N];
int calc(int x){
  for(int i=0;i<MAX_V;i++) G[i].clear();
  
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(g[i][j]<=x)add_edge(i,j+n*2,1),add_edge(n+i,j+n*2,1);
  
  int f1=m/n,f2 = m%n;
  int S1 = 2*n+m,S2 = S1+1,S = S2+1,T = S+1;
  add_edge(S,S1,f1*n);
  add_edge(S,S2,f2);
  for(int i=0;i<n;i++) add_edge(S1,i,f1),add_edge(S2,i+n,1);
  for(int i=0;i<m;i++) add_edge(i+n*2,T,1);
  return max_flow(S,T);
}

int search(){
  int L=0,M,R=INF;
  while(L<R){
    M=(L+R)/2;
    if(calc(M)>=m) R = M;
    else L = M + 1;
  }
  return L;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)scanf("%d",&g[i][j]);
  
  cout<<(m%n!=0)<<endl;
  cout<<search()<<endl;
}
