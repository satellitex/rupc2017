#include<bits/stdc++.h>
using namespace std;

const int MAX_V = 333;
const int INF = (1<<29);
struct edge{int to,cap,rev;};
  
vector<edge> G[MAX_V];
bool used[MAX_V];
  
void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, G[to].size()});
  G[to].push_back((edge){from, 0, G[from].size()-1});
}
  
int dfs(int v, int t, int f){
  if(v == t)return f;
  used[v] = true;
  for(int i = 0 ; i < G[v].size() ; i++){
    edge &e = G[v][i];
    if(!used[e.to] && e.cap > 0){
      int d = dfs(e.to,t,min(f,e.cap));
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
    int f = dfs(s,t,INF);
    if(f == 0)return flow;
    flow += f;
  }
}
 

int N,M;
int D[111][111];
int l,r;
int s,t,S,T,V;
void make_graph(int t){
  for(int i=0;i<MAX_V;i++) G[i].clear();

  for(int i=0;i<N;i++) {
    add_edge( S, i, l );
    add_edge( i, T, l );
    
    add_edge( s, i, r-l );
  
    for(int j=0;j<M;j++)
      if( D[i][j] <= t ) {
	add_edge( i, N+j, 1 );
	add_edge( N+j, t, 1 );
      }
  }
}

bool isok(int t){
  make_graph( t );
  int res = 0;
  res += max_flow( S, T );
  res += max_flow( S, t );
  res += max_flow( s, T );
  res += max_flow( s, t );
  return res == M;
}

int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      cin >> D[i][j];
  
  s = N+M, t = s+1, S = t+1, T = S+1, V = T+1;
  l = M/N;
  if( l*N == M ) r = l;
  else r = l+1;

  int st = 0, ed = 1000000000;
  int res = 0;
  while( st <= ed ){
    int h = (st+ed)/2;
    if( isok( h ) ){
      res = h;
      st = h+1;
    } else {
      ed = h-1;
    }
  }
  cout << r-l << endl;
  cout << res << endl;
}
