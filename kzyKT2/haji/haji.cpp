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
  for(int i=0;i<G[v].size();i++)if(!used[G[v][i]])dfs(G[v][i]);
  vs.push_back(v);
}

void rdfs(int v,int k){
  used[v]=true;
  cmp[v]=k;
  for(int i=0;i<rG[v].size();i++) if(!used[rG[v][i]])rdfs(rG[v][i],k);
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

//////////////////////////////////////////////////////////////////////

int C[N],nC[2][N];
set<int> S[2][N];
int mkC(int pos,bool f,int col){
  if(S[f][col].count(pos)) return 0;
  if(S[!f][col].count(pos)) return 1;
  S[f][col].insert(pos);
  nC[f][col]+=C[pos];

  for(int i=0;i<(int)G[pos].size();i++){
    int nx = G[pos][i];
    if(cmp[nx] == col&&mkC(nx,!f,col)) return 1;
  }
  return 0;
}

typedef pair<int,int> P;
typedef pair<int,P> PP;
set<PP> g[N];
int flg[N];
int D[2][2][N];

void Max(int &a,int b){a=max(a,b);}
void calc(int pos,int f,int idx){
  for(auto it=g[pos].begin();it!=g[pos].end();it++){
    int npos = it->first;
    int from = it->second.first;
    int to = it->second.second;
    int nf = (f + (idx==from))%2;
    int c = nf==0? nC[to][npos]:nC[!to][npos];
    Max(D[nf][to][npos],D[f][idx][pos]+c);
    if(flg[npos])Max(D[!nf][to][npos],D[f][idx][pos]+c);
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)scanf("%d",&C[i]);
  for(int i=0,a,b;i<m;i++)scanf("%d%d",&a,&b),add_edge(a,b);

  V = n; V = scc();

  int used[N]={};
  for(int i=0;i<n;i++){
    int col = cmp[i];
    if(!used[col]++&&mkC(i,0,col))flg[col] = 1,nC[0][col]=nC[1][col]=0;
  }
  
  for(int i=0;i<n;i++){ 
    int col = cmp[i];
    if(flg[col]){
      nC[0][col]+=C[i];
      nC[1][col]+=C[i];
      S[0][col].insert(i);
      S[1][col].insert(i);
    }
  }

  for(int i=0;i<n;i++)
    for(int j=0;j<(int)G[i].size();j++){
      int col = cmp[i];
      int nv = G[i][j];
      int ncol = cmp[nv];
      int from = S[1][col].count(i);
      int to = S[1][ncol].count(nv);
      if(col==ncol)continue;
      g[col].insert(PP(ncol,P(from,to)));
    }

  
  
  for(int i=0;i<N;i++) G[i].clear(),rG[i].clear();
  for(int i=0;i<V;i++) 
    for(auto j=g[i].begin();j!=g[i].end();j++)add_edge(i,j->first);

  memset(used,0,sizeof(used));
  vs.clear();
  for(int v=0;v<V;v++) if(!used[v]) dfs(v);
    
  memset(D,-1,sizeof(D));
  int scol = cmp[0];
  int idx = S[1][scol].count(0);
  D[0][idx][scol] = nC[idx][scol];
  if(flg[cmp[0]])D[1][idx][scol] = nC[idx][scol];

  int ans =0;
  for(int i=0;i<V;i++){
    for(int f=0;f<2;f++)
      for(int idx=0;idx<2;idx++){
	if(D[f][idx][vs[i]]!=-1)calc(vs[i],f,idx);
	Max(ans,D[f][idx][vs[i]]);
      }
  }
  cout<<ans<<endl;
  return 0;
}
