#include<bits/stdc++.h>
#define MAX_V 100005
using namespace std;
vector<int> G[MAX_V],rG[MAX_V],vs;
bool used[MAX_V];
int V,cmp[MAX_V];

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

int n,m,a,b;


int main(){
  cin>>n>>m;
  V=n;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    add_edge(a,b);
  }
  int r=scc();
  
  return 0;
}
