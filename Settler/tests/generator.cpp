#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

string i2s(int x){
  char tmp[100];
  sprintf(tmp,"%02d",x);
  string res(tmp);
  return res;
}

std::mt19937 mt( (int)time(0) );

std::uniform_int_distribution<> randP( 3 , 100 );
std::uniform_int_distribution<> randN( 10 , 20 );

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

void solve(int casenum){
  string filename="03_random_"+i2s(casenum)+".in";
  ofstream fout(filename);

  vector<P> vec;
  
  int v=randN(mt);
  for(int i=1;i<=7;i++)
    for(int j=1;j<=7;j++)
      if(i%2 == (j/2)%2 )
        vec.push_back(P(i,j));
  
  shuffle( vec.begin(), vec.end() , mt );
  vec.erase( vec.begin() + v , vec.end() );
  assert( (int)vec.size() == v );
  
  int nk=calc(vec);
  int u=randP(mt);
  if(u%2==0){
    nk=max(2,nk-u%5);
  }
  
  fout<<vec.size()<<' '<< nk <<endl;

  for(int i=0;i<(int)vec.size();i++){
    fout<<vec[i].first<<' '<<vec[i].second<<endl;
  }
}

void solve2(int casenum){
  string filename="03_random_"+i2s(casenum)+".in";
  ofstream fout(filename);

  vector<P> vec;
  
  int v=randN(mt)*10;
  
  for(int i=1;i<=20;i++)
    for(int j=1;j<=20;j++)
      if(i%2 == (j/2)%2 )
        vec.push_back(P(i,j));
  
  shuffle( vec.begin(), vec.end() , mt );
  vec.erase( vec.begin() + v , vec.end() );
  assert( (int)vec.size() == v );
  
  int nk=calc(vec);
  int u=randP(mt);
  
  if(u%2==0){
    nk=max(1,nk-u%10);
  }
  
  fout<<vec.size()<<' '<< nk <<endl;

  for(int i=0;i<(int)vec.size();i++){
    fout<<vec[i].first<<' '<<vec[i].second<<endl;
  }
}

int main(){
  for(int i=0;i<20;i++){
    solve(i);
  }
  
  for(int i=20;i<40;i++){
    solve2(i);
  }
  return 0;
}
