#include<bits/stdc++.h>
using namespace std;

#define MAX 6005
int V,K;
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


    if(flg[u]){
      assert(false);
      continue;
    }
    
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

void func(int v){
  for(int i=0;i<V;i++){
    g[i]=G[i];
    f[i]=flg[i];
  }
  
  set<int> target;
  for(int i=0;i<(int)G[v].size();i++){
    target.insert(G[v][i]);
    flg[ G[v][i] ]=true;
  }
  target.insert(v);
  flg[v]=true;
  
  for(int i=0;i<V;i++){
    vector<int> tmp;
    for(int j=0;j<(int)G[i].size();j++){
      int id=G[i][j];
      if( target.count(i) == 0 && target.count(id) == 0 ){
        tmp.push_back(id);
      }
    }
    G[i]=tmp;
  }

}

void backf(){
  for(int i=0;i<V;i++){
    G[i]=g[i];
    flg[i]=f[i];
  }
}

bool check(int v){
  func(v);
  int nv=0;
  for(int i=0;i<V;i++)if(flg[i]==false)nv++;
  
  int nr=nv-bipartite_matching();
  if(nr+cc+1>=K)return true;
  else return false;
}

int main(){
  int x[MAX],y[MAX];

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
