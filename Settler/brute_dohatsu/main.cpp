#include<bits/stdc++.h>
using namespace std;

#define MAX 6005
int V;
vector<int> G[MAX];
vector<int> g[MAX];

int used[MAX],match[MAX];
int flg[MAX],f[MAX];

int base;
int nv,cc=0;

void add_edge(int from,int to){
  G[from].push_back(to);
  G[to].push_back(from);
}

bool dfs(int v){
  used[v]=true;
  for(int i=0;i<(int)G[v].size();i++){
    int u=G[v][i],w=match[u];
    if(flg[u])continue;
    
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
    if(flg[i])continue;
    if(match[i]!=-1)continue;
    memset(used,0,sizeof(used));
    if(dfs(i))res++;
  }
  return res;
}

void erasenode(int v){
  flg[v]=true;
  G[v].clear();
  for(int i=0;i<MAX;i++){
    for(int j=0;j<(int)G[i].size();j++){
      if(G[i][j]==v){
        G[i].erase( G[i].begin()+j );
        break;
      }
    }
  }
}

void func(int v){
  for(int i=0;i<MAX;i++){
    g[i]=G[i];
    f[i]=flg[i];
  }
  
  vector<int> target=G[v];
  target.push_back(v);
  for(int i=0;i<(int)target.size();i++)
    erasenode(target[i]);
}

void backf(){
  for(int i=0;i<MAX;i++){
    G[i]=g[i];
    flg[i]=f[i];
  }
}

bool check(int v){
  func(v);
  int nv=0;
  for(int i=0;i<V;i++)if(flg[i]==false)nv++;
  
  int k=nv-bipartite_matching();
  if(k+cc+1==base)return true;
  else return false;
}

int main(){
  int x[MAX],y[MAX];
  
  int K;
  cin>>V>>K;
  for(int i=0;i<V;i++){
    cin>>x[i]>>y[i];
    for(int j=0;j<i;j++){
      int dx=x[i]-x[j];
      int dy=y[i]-y[j];
      if(dx*dx+dy*dy<4)add_edge(i,j);
    }
  }

  for(int i=0;i<V;i++)flg[i]=false;
  
  base=V-bipartite_matching();
  if( base < K ){
    cout<<-1<<endl;
    return 0;
  }
  
  //  cout<<base<<endl;
  
  for(int v=0;v<V;v++){
    if(flg[v])continue;
    
    if(check(v)){
      cout<<v+1<<endl;
      cc++;
      if(cc==K)break;
      
    }else{
      backf();
    }
  }
  
  return 0;
}
