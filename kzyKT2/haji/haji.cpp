#include <bits/stdc++.h>
#define MAX_V 100010
#define N MAX_V
using namespace std;

/* 強連結成分分解 O(|V|+|E|) */
int V; //頂点数
vector<int> G[MAX_V]; //グラフの隣接リストの表現
vector<int> rG[MAX_V];//辺の向きを逆にしたグラフ
vector<int> vs;       //帰りがけ順の並び
bool used[MAX_V];     //すでに調べたか
int cmp[MAX_V];       //属する強連結成分のトポロジカル順

void add_edge(int from,int to){
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v){
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++)if(!used[G[v][i]])dfs(G[v][i]);
  vs.push_back(v);
}

void rdfs(int v,int k){
  used[v]=true;
  cmp[v]=k;
  for(int i=0;i<(int)rG[v].size();i++) if(!used[rG[v][i]])rdfs(rG[v][i],k);
}

int scc(){
  memset(used,0,sizeof(used));
  vs.clear();
  for(int v=0;v<V;v++) if(!used[v]) dfs(v);
  
  memset(used,0,sizeof(used));
  int k=0;
  for(int i=vs.size()-1;i>=0;i--)if(!used[vs[i]]) rdfs(vs[i],k++);
  return k;
}

int C[N],nC[2][N];
vector<int> g[N];
void mkC(int pos,int f,int col){
  nC[f][col]+=C[pos];
  for(int i=0;i<(int)G[pos].size();i++){
    int nx = G[pos][i];
    if(cmp[nx] == col)mkC(nx,!f,col);
  }
}

int calc(int pos,int f){
  static int mem[N][2],used[N][2]={};
  if(used[pos][f]++) return mem[pos][f];
  
  int res=0;
  for(int i=0;i<(int)g[pos].size();i++)
    for(int j=0;j<(int)G[g[pos][i]].size();j++){
      int nx = cmp[G[g[pos][i]][j]];
      if(nx==pos)continue;
      res = max(res, calc(nx,!f));
    }

  return mem[pos][f] = res + nC[pos][f]*(f==0);
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++) cin>>C[i];
  for(int i=0,a,b;i<m;i++)cin>>a>>b,add_edge(a,b);
  V = n;
  n = scc();
  int used[N]={};
  for(int i=0;i<n;i++)if(!used[cmp[i]]++) mkC(i,0,cmp[i]);
  for(int i=0;i<n;i++) g[cmp[i]].push_back(i);
  
  cout<< calc(cmp[0],0)<<endl;
  return 0;
}
