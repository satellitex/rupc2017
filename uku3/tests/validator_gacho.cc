#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;

const int N_MIN=1;
const int N_MAX=(1e5);
const int Q_MIN=1;
const int Q_MAX=(1e5);
int n,q,u[N_MAX],v[N_MAX];
int t[Q_MAX],r[Q_MAX],X[Q_MAX],Y[Q_MAX];

void input(){
  n=inf.readInt(N_MIN,N_MAX,"N");
  inf.readSpace();
  q=inf.readInt(Q_MIN,Q_MAX,"Q");
  inf.readEoln();
  for(int i=0;i<n-1;i++){
    u[i]=inf.readInt(0,n-1,format("u[%d]",i+1));
    inf.readSpace();
    v[i]=inf.readInt(0,n-1,format("v[%d]",i+1));
    inf.readEoln();
  }
  for(int i=0;i<q;i++){
    t[i]=inf.readInt(1,2,format("t[%d]",i+1));
    inf.readSpace();
    r[i]=inf.readInt(0,n-1,format("r[%d]",i+1));
    inf.readSpace();
    X[i]=inf.readInt(0,9,format("x[%d]",i+1));
    inf.readSpace();
    Y[i]=inf.readInt(0,9,format("y[%d]",i+1));
    inf.readEoln();
  }
  inf.readEof();
}

vector<int> G[N_MAX];
bool used[N_MAX];

void dfs(int x){
  if(used[x])return;
  used[x]=true;
  for(int i=0;i<G[x].size();i++)dfs(G[x][i]);
}

set<pair<int,int> > S;

void check(){
  for(int i=0;i<n-1;i++){
    ensuref(u[i]!=v[i],"self loop");
    G[u[i]].push_back(v[i]);
    G[v[i]].push_back(u[i]);
    ensuref(!S.count(pair<int,int>(min(u[i],v[i]),max(u[i],v[i]))),"multi edge");
    S.insert(pair<int,int>(min(u[i],v[i]),max(u[i],v[i])));
  }
  dfs(0);
  for(int i=0;i<n;i++)
    ensuref(used[i],"Disconnected graph");
  for(int i=0;i<q;i++)
    if(t[i]==1)ensuref(X[i]<=Y[i],"t[i]==1 && x[i]>y[i]");
}

int main(){
  registerValidation();
  input();
  check();
  return 0;
}
