#include <bits/stdc++.h>
using namespace std;

int N,K;

const int MAX_V = 6666;
struct edge{
  int to,cap,rev;
  edge(){
  }
  edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};
const int INF = MAX_V;

vector<edge> G[MAX_V];
bool used[MAX_V];

int add_edge(int from, int to, int cap){
    G[from].push_back(edge(to,cap,G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
    return (int)G[from].size()-1;
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
    if( s == t ) return 0;
    for(;;){
        memset(used,0,sizeof(used));
        int f = dfs(s,t,INF);
        if(f == 0)return flow;
        flow += f;
    }
}

typedef pair<int,int> P;
vector<int> U,V;
map<P,int> S;
bool F[6666];

bool inf_check( int id ){
  for( edge e : G[id] ) {
    if( e.to < N &&  F[e.to] ) return true;
  }
  return false;
}

int main(){

    cin >> N >> K;
    for(int i=0;i<N;i++){
        int x,y; cin >> x >> y;
        S[P(x,y)] = i;
        if( y&1 ) {
            U.push_back( i );
            F[i] = true;
        }
        else V.push_back( i );
    }

    for( auto p : S ) {
        int id = p.second;
        if( !F[id] )  continue;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                int nx = p.first.first + dx, ny = p.first.second + dy;
                if( dx == 0 && dy == 0 ) continue;
                if( S.count( P(nx,ny) ) ) {
                    int nid = S[P(nx,ny)];
                    add_edge( id, nid, INF );
                }
            }
        }
    }

    int s = N, t = N+1;
    int nk = 0;
    vector<int> res;
    vector<P> E;
    for(int i=0;i<N;i++){
        if( G[i].empty() ) {
            nk++;
            res.push_back( i );
        } else {
            if (F[i]) {
                E.emplace_back( s, add_edge( s, i, 1 ) );
            } else {
                E.emplace_back( i, add_edge( i, t, 1 ) );
            }
        }
    }

    int V = N - nk;
    int cut_n = max_flow(s,t);
    int safe_n = V - cut_n;

    if( nk + safe_n < K ){
        cout << -1 << endl;
        return 0;
    }

    memset( F,0,sizeof(F) );

    for( auto p : E ){
        edge &e = G[p.first][p.second];
        int id = p.first; if( id == s ) id = e.to;
        if( inf_check(id) ) continue;

        e.cap = INF;

        int ret = max_flow(s,t);
        if( nk + safe_n - ret < K ) {
          e.cap = 1;
          G[e.to][e.rev].cap = 0;
          int tmp = max_flow( t, e.to );
          tmp = max_flow( p.first, s );
          tmp = max_flow( s, t );
        } else {
            res.push_back( id );
            safe_n -= ret;
            F[id] = true;
        }
    }

    sort( res.begin(), res.end() );
    assert( K <= res.size() );
    for(int i=0;i<K;i++){
        cout << res[i]+1 << endl;
    }

}