#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N_MIN = 1;
const int N_MAX = 1e4;
const int M_MAX = 1e4;
const int C_MIN = 1;
const int C_MAX = 1e6;
const int T_MIN = 0;
const int T_MAX = 1e6;
int N,M;
int a[M_MAX], b[M_MAX],c[M_MAX], t[M_MAX];

void input()
{
  N = inf.readInt(N_MIN, N_MAX,"N");
  inf.readSpace();
  M = inf.readInt(N-1, min(N*(N-1)/2,M_MAX),"M");
  inf.readEoln();
  
  const int ab_MIN = 0,ab_MAX = N-1;
  
  for (int i = 0; i < M; i++) {
    a[i] = inf.readInt(ab_MIN, ab_MAX, format("a[%d]", i ));
    inf.readSpace();
    b[i] = inf.readInt(ab_MIN, ab_MAX, format("b[%d]", i ));
    inf.readSpace();
    c[i] = inf.readInt(C_MIN, C_MAX, format("c[%d]", i ));
    inf.readSpace();
    t[i] = inf.readInt(T_MIN, T_MAX, format("t[%d]", i ));
    inf.readEoln();
  }
  inf.readEof();
}

vector<int>G[N_MAX];
int used[N_MAX];
void dfs(int pos){
  if(used[pos]++) return;
  for(int i=0;i<G[pos].size();i++)dfs(G[pos][i]);
}

void check(){
  set<pair<int,int> > S;
  for(int i=0;i<M;i++){
    ensuref(a[i]!=b[i],"self loop");
    ensuref(!S.count(make_pair(a[i],b[i])),"multi edge");
    S.insert(make_pair(a[i],b[i]));
    S.insert(make_pair(b[i],a[i]));
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  dfs(0);
  for(int i=0;i<N;i++)ensuref(used[i],"Disconnected");
}

int main()
{
  registerValidation();
  input();
  check();
  return 0;
}
