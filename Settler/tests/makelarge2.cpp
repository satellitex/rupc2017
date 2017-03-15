#include <bits/stdc++.h>
using namespace std;
std::mt19937 mt( (int)time(0) );

std::uniform_int_distribution<> randP( 3 , 100 );
typedef pair<int,int> P;

#define MAX 6005

int V;
vector<int> G[MAX];
int used[MAX],match[MAX];

void add_edge(int from,int to){
  G[from].push_back(to);
  G[to].push_back(from);
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

int calc(const vector<P> &vec){
  V=vec.size();
  for(int i=0;i<V;i++){
    for(int j=0;j<i;j++){
      int dx=vec[i].first-vec[j].first;
      int dy=vec[i].second-vec[j].second;
      if(dx*dx+dy*dy<4){
        add_edge(i,j);
      }
    }
  }
  return bipartite_matching();
}

bool check(int i,int j){
  return (i%2==(j/2)%2);
}

void solve(){
  
  vector<P> vec;

  for(int i=2;i<=12000;i+=4)
    if(check(1,i))vec.push_back(P(1,i));
  
  vector<P> as;
  for(int i=5;i<=70;i++){
    for(int j=5;j<=105;j++){
      if(check(i,j))as.push_back(P(i,j));
    }
  }

  shuffle( as.begin(), as.end(), mt);
  int pp=min(3000, (int)as.size());
  cerr<<"as.size = "<<as.size()<<endl;
  for(int i=0;i<pp;i++)
    vec.push_back( as[i] );
  
  
  cout<<vec.size()<<' '<< calc(vec) <<endl;
  
  for(int i=0;i<(int)vec.size();i++){
    cout<<vec[i].first<<' '<<vec[i].second<<endl;
  }
}

int main(){
  solve();
  return 0;
}
