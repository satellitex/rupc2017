#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define MAX 6005
int V;
vector<int> G[MAX];
int used[MAX],match[MAX];
int A[MAX];

int flgS[MAX],flgT[MAX];

void add_edge(int from,int to){
  G[from].push_back(to);
  G[to].push_back(from);
}

void init(int v,int depth){
  if(A[v]!=-1){
    assert(A[v]==depth%2);
    
    return;
  }
  A[v]=depth%2;
  for(int i=0;i<(int)G[v].size();i++){
    init(G[v][i],depth+1);
  }
}

bool dfs(int v){
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    int u=G[v][i],w=match[u];
    if(w==-1 || ( !used[w]&&dfs(w) ) ){
      match[v]=u;
      match[u]=v;
      return true;
    }
  }
  return false;
}

int bipartite_matching(){
  memset(match,-1,sizeof(match));
  int res=0;
  for(int i=0;i<V;i++){
    if(match[i]!=-1)continue;
    memset(used,0,sizeof(used));
    if(dfs(i))res++;
  }
  return res;
}

void dfsS(int v){
  if(flgS[v])return;
  flgS[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    int to=G[v][i];
    if(A[v]==1 && to!=match[v])continue;
    dfsS(to);
  }
}

void dfsT(int v){
  if(flgT[v])return;
  flgT[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    int to=G[v][i];
    if(A[v]==0 && to!=match[v])continue;
    dfsT(to);
  }
}

int main(){
  int N,K;
  cin>>N>>K;

  map< P ,int> T;
  for(int i=0;i<N;i++){
    int x,y;
    cin>>x>>y;

    assert( T.count( P(x,y) ) == 0 );
    assert( x%2 == (y/2)%2 );
    
    for(int dx=-1;dx<=1;dx++){
      for(int dy=-1;dy<=1;dy++){
        int nx=x+dx;
        int ny=y+dy;
        if( T.count( P(nx,ny) ) == 0 )continue;
        add_edge(i, T[P(nx,ny)] );
      }
    }
    T[ P(x,y) ]=i;
  }

  V=N;
  
  memset(A,-1,sizeof(A));
  for(int i=0;i<V;i++)
    if(A[i]==-1)init(i,0);

  int ans=V-bipartite_matching();
  if(ans<K){
    cout<<-1<<endl;
    return 0;
  }

  for(int v=0;v<V;v++){
    if(match[v]!=-1)continue;
    if(A[v]==0)dfsS(v);
    else dfsT(v);
  }

  int cc=0;
  for(int v=0;v<V;v++){
    if(A[v]==0){
      if(flgT[v])continue;
      dfsS(v);
    }else{
      if(flgS[v])continue;
      dfsT(v);
    }
    cout<<v+1<<endl;
    cc++;
    if(cc==K)break;
  }
  return 0;
}

