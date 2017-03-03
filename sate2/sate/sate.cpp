#include<bits/stdc++.h>
using namespace std;

const int MAX_V = 333;
const int INF = (1<<29);
struct edge{int to,cap,rev;};
  
vector<edge> G[MAX_V];
bool used[MAX_V];
  
void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size()-1});
}
  
int dfs(int v, int t, int f){
  if(v == t)return f;
  used[v] = true;
  for(int i = 0 ; i < (int)G[v].size() ; i++){
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
void make_graph(int h){
  for(int i=0;i<V;i++) G[i].clear();

  for(int i=0;i<N;i++) {
    add_edge( s, i, r-l );
    add_edge( s, T, l );
    add_edge( S, i, l );
  
    for(int j=0;j<M;j++)
      if( D[i][j] <= h ) 
        add_edge( i, N+j, 1 );      
  }
  for(int i=0;i<M;i++)
    add_edge( N+i, t, 1 );
}

void view(){
  cout << "View" << endl;
  for(int i=0;i<V;i++){
    cout << "vertex : " << i << endl;
    for( edge e : G[i] )
      cout << " -> " << e.to << " " << e.cap << endl;
  }
}

bool isok(int h){
  make_graph( h );
  int res = 0;
  max_flow( S, T );
  max_flow( s, T );
  max_flow( S, t );
  max_flow( s, t );
  for( edge e : G[t] ){
    if( e.to == T ) continue;
    res += e.cap;
  }
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
      ed = h-1;
    } else {
      st = h+1;
    }
  }
  cout << r-l << endl;
  cout << res << endl;
}
