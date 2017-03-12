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
unordered_map<int,int>rg[2][N];
int flg[N];
int topological(){

  queue<PP> Q;  
  int res=0,D[2][N]={},scol=cmp[0],sidx = S[1][scol].count(0);

  Q.push(PP(scol,P(0,sidx)));
  D[0][scol] = nC[sidx][scol];

  while(!Q.empty()){
    PP t = Q.front();Q.pop();
    int col = t.first;
    int f = t.second.first;
    int idx = t.second.second;
    res = max(res,D[f][col]);

    if(flg[col]){
      D[!f][col] = max(D[!f][col],D[f][col]);
      Q.push(PP(col,P(!f,idx)));
      flg[col]=0;
    }

    for(auto it=g[col].begin();it!=g[col].end();it++){
      int ncol = it->first;
      int from = it->second.first;
      int to = it->second.second;
      int nf = (f + (idx==from))%2;
      int c = nf==0? nC[to][ncol]:nC[!to][ncol];
      D[nf][ncol]=max(D[nf][ncol],D[f][col]+c);
      rg[nf][ncol].erase(col);
      if(rg[nf][ncol].empty())Q.push(PP(ncol,P(nf,to)));
    }
  }  

  return res;
}

int main(){
  return 0;
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)scanf("%d",&C[i]);
  for(int i=0,a,b;i<m;i++)scanf("%d%d",&a,&b),add_edge(a,b);
  V = n;
  V = scc();

  int used[N]={};
  for(int i=0;i<n;i++){
    int col = cmp[i];
    if(!used[col]++&&mkC(i,0,col)){
	flg[col] = 1;
	nC[0][col] = nC[1][col]=0;
      }
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
    for(int j=0;j<G[i].size();j++){
      int col = cmp[i];
      int nv = G[i][j];
      int ncol = cmp[nv];
      int from = S[1][col].count(i);
      int to = S[1][ncol].count(nv);
      if(col==ncol)continue;
      g[col].insert(PP(ncol,P(from,to)));
      rg[0][ncol][col]=1;
      rg[1][ncol][col]=1;
    }
  

  cout<<topological()<<endl;
  return 0;
}
