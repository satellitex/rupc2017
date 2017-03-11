#include<bits/stdc++.h>
using namespace std;

const int MAX = 100005;

int N,M;
int C[MAX];

//強連結成分分解 O(|V|+|E|)
int V;
vector<int> G[MAX];
vector<int> rG[MAX];
vector<int> vs;
bool used[MAX];
int cmp[MAX]; //属する強連結成分のトポロジカル順序
vector<int> T[MAX][2];
int ssize[MAX];

void add_edge(int from,int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v] = true;
  for(int i = 0 ; i < G[v].size() ; i++){
    if(!used[G[v][i]]) dfs(G[v][i]);
  }
  vs.push_back(v);
}

void rdfs(int v,int k){
  used[v] = true;
  cmp[v] = k;
  ssize[k]++;
  for(int i = 0 ; i < rG[v].size() ; i++){
    if(!used[rG[v][i]]) rdfs(rG[v][i],k);
  }
}

typedef pair<int,int> P;
bool H[MAX][2];
int cost[MAX][2];
void bfs(int id) {
    queue <P> q;
    q.push(P(id, 0));
    H[id][0] = true;
    while (!q.empty()) {
        P p = q.front();
        q.pop();
        int v = p.first, f = p.second;
        for (int to : G[v]) {
            if( cmp[to] != cmp[id] ) continue;
            if (!H[to][1 - f]) {
                H[to][1 - f] = true;
                q.push(P(to, 1 - f));
            }
        }
    }
}

int scc(){ //強連結成分分解を行う。
  V = N;
  memset(used, 0, sizeof(used));
  vs.clear();
  for(int v = 0 ; v < V ; v++){
    if(!used[v]) dfs(v);
  }
  memset(used, 0, sizeof(used));
  memset(H, 0, sizeof(H));
  memset( cmp,-1,sizeof(cmp) );
  int k = 0;
  for(int i = vs.size() - 1 ; i >= 0 ; i--){
    if(!used[vs[i]]) {
        rdfs(vs[i],k++);
        bfs(vs[i]);
    }
  }

  for(int i=0;i<N;i++){
    if( H[i][0] ) cost[ cmp[i] ][ 0 ] += C[i];
    if( H[i][1] ) cost[ cmp[i] ][ 1 ] += C[i];
    for( int to : G[i] ) {
        int scv = cmp[i];
        if( cmp[to] != scv ) {
            if( H[i][0] )
                T[scv][0].emplace_back(to);
            if( H[i][1] )
                T[scv][1].emplace_back(to);
        }
    }
  }
  for(int i=0;i<N;i++) {
      for(int j=0;j<2;j++) {
          sort(T[i][j].begin(), T[i][j].end());
          T[i][j].erase(unique(T[i][j].begin(), T[i][j].end()), T[i][j].end());
      }
  }
  return k;
}

int dp[100005][2];
int solve( int v,int f ) {
    if( dp[v][f] != -1  ) return dp[v][f];
    int scv = cmp[v];
    int mg = 0;
    if( H[v][0] ) mg |= 1;
    if( H[v][1] ) mg |= 2;
    int ret = 0;
    for(int j=0;j<2;j++){
        for( int to : T[scv][j] ) {
            if ( mg & (1<<j) )
                ret = max( ret, solve( to, 1-f ) );
            if ( mg & (1<<(1-j)) )
                ret = max( ret, solve( to, f ) );
        }
    }
    int pc;
    if( mg==3 ) pc = cost[scv][0];
    else {
        int x=1;
        if( mg&1 ) x = 0;
        if( f == 1 )
            pc = cost[scv][1-x];
        else
            pc = cost[scv][x];
    }
    if( ssize[scv] == 1 && f ==1 ) pc = 0;
    return dp[v][f] = ret + pc;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> C[i];

    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        add_edge( a, b );
    }
    memset( dp,-1,sizeof(dp) );
    scc();
    cout << solve( 0, 0 ) << endl;
}