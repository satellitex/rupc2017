#include <bits/stdc++.h>
#define MAX_V 210
#define INF ((1e9)+10)
#define N 101
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{ll to, cap,cost,rev;};

int V;                          //頂点数
vector<edge> G[MAX_V];          //グラフの隣接リスト表現
ll h[MAX_V];                   //ポテンシャル
ll dist[MAX_V];                //最短距離
int prevv[MAX_V], preve[MAX_V]; //直前の頂点と辺

//fromからtoへ向かう容量cap、コストcostの辺をグラフに追加する。
void add_edge(int from, int to, int cap, int cost){
  G[from].push_back((edge){to, cap, cost, G[to].size()});
  G[to].push_back((edge){from, 0 ,-cost, G[from].size()-1});
}

//sからtへの流量fの最小費用流を求める。
int min_cost_flow(int s, int t, int f){
  int res = 0;
  fill(h, h+V, 0); //hを初期化
  while(f > 0){
    //ダイクストラ法を用いてhを更新する。
    priority_queue <P, vector<P>, greater<P> > que;
    fill(dist,dist+V,INF);
    dist[s] = 0;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      int v= p.second;
      if(dist[v] < p.first) continue;
      for(int i=0; i<G[v].size() ;i++){
	edge &e = G[v][i];
	if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
	  dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
	  prevv[e.to] = v;
	  preve[e.to] = i;
	  que.push(P(dist[e.to],e.to));
	}
      }
    }
    if(dist[t]==INF) return 0; //これ以上流せない
    for(int v=0; v<V ;v++) h[v] += dist[v];
    
    //s−t間最短路に沿って目一杯流す。
    ll d = f;
    for(int v=t; v!=s ;v=prevv[v]) 
      d= min(d, G[prevv[v]][preve[v]].cap);
    
    f -= d;
    res += d * h[t];
    for(int v=t; v!=s; v=prevv[v]){
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }
  return 1;
}


int n,m;
ll g[N][N];
int S,T;
ll check(ll x){
  V = m+n+2;  
  for(int i=0;i<MAX_V;i++) G[i].clear();
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(g[i][j]<=x)add_edge(i,j+n,1,g[i][j]);
  
  S = n+m,T = n+m+1;
  for(int i=0;i<n;i++) add_edge(S,i,(m-1)/n+1,0);
  for(int i=0;i<m;i++) add_edge(i+n,T,1,0);

  return min_cost_flow(S,T,m);
}

int search(){
  int L=0,M,R=INF;
  while(L<R){
    M=(L+R)/2;
    if(check(M)) R = M;
    else L = M + 1;
  }
  return L;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)scanf("%lld",&g[i][j]);
  
  cout<<(m%n!=0)<<endl;
  cout<<search()<<endl;
}
