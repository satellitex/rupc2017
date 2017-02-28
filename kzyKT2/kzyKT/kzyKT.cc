#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int,int> P;
#define N 100001
vector<int> G[N],rG[N],g;
vector<P> v[N];
int n,cmp[N],u[N],c[N],a[N],d[N][2],z[N][2],o[N],h[N],uu[N][2];
  
void add_edge(int x,int y){G[x].push_back(y);rG[y].push_back(x);}

void dfs(int x){
  u[x]=1;
  for(int i=0;i<G[x].size();i++)if(!u[G[x][i]])dfs(G[x][i]);
  g.push_back(x);
}

void rdfs(int x,int k){
  u[x]=1,cmp[x]=k;
  for(int i=0;i<rG[x].size();i++)if(!u[rG[x][i]])rdfs(rG[x][i],k);
}

int scc(){
  memset(u,0,sizeof(u));g.clear();
  for(int i=0;i<n;i++)if(!u[i])dfs(i);
  memset(u,0,sizeof(u));
  int k=0;
  for(int i=g.size()-1; i>=0; i--)if(!u[g[i]])rdfs(g[i],k++);
  return k;
}

int q[N],r[N];
void init(){for(int i=0;i<N;i++)q[i]=i,r[i]=0;}
int find(int x){return (q[x]==x)?x:(q[x]=find(q[x]));}
void unite(int x,int y) {
  x=find(x),y=find(y);
  if(x==y)return;
  if(r[x]<r[y])q[x]=y;
  else{q[y]=x;if(r[x]==r[y])r[x]++;}
}

void dfs(int x,int t,int p) {
  for(int i=0;i<G[x].size();i++) {
    int y=G[x][i];
    if(uu[y][t^1]) continue;
    if(p>=0&&cmp[y]==cmp[p]) unite(y,p);
    uu[y][t^1]=1;
    dfs(y,t^1,x);
  }
}

void calc() {
  init();
  memset(uu,0,sizeof(uu));
  uu[0][0]=1;
  dfs(0,0,-1);
  memset(o,-1,sizeof(o));
  fill(h,h+N,1);
  set<int> s;
  map<int,int> ma;
  for(int i=0; i<n; i++) {
    ma[cmp[i]]++;
    if(o[find(i)]!=-1) continue;
    if(s.count(cmp[i])) h[cmp[i]]=0;
    o[find(i)]=s.count(cmp[i]);
    s.insert(cmp[i]);
  }
  for(int i=0; i<n; i++)if(ma[cmp[i]]==1)h[cmp[i]]=0;
  queue<P> que;
  que.push(P(0,0));
  memset(uu,0,sizeof(uu));
  uu[0][0]=1;
  z[cmp[0]][o[find(0)]]+=a[0];
  while(!que.empty()) {
    P p=que.front();que.pop();
    int x=p.F,t=p.S;
    for(int i=0;i<G[x].size();i++) {
      int y=G[x][i];
      if(uu[y][t^1]) continue;
      uu[y][t^1]=1;
      if(t) z[cmp[y]][o[find(y)]]+=a[y];
      que.push(P(y,t^1));
    }
  }
  for(int i=0; i<n; i++) if(h[cmp[i]]) z[cmp[i]][1]=z[cmp[i]][0];
}

void make(){
  for(int i=0;i<n;i++){
    for(int j=0;j<G[i].size();j++){
      if(cmp[i]!=cmp[G[i][j]]) v[cmp[i]].push_back(P(G[i][j],o[find(i)]));
    }
  }
  for(int i=0;i<n;i++){
    sort(v[i].begin(),v[i].end());
    v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
    for(int j=0;j<v[i].size();j++) c[cmp[v[i][j].F]]++;
  }
}

void erase() {
  queue<int> que;
  for(int i=0; i<n; i++) if(i!=cmp[0]&&!c[i]) que.push(i);
  while(!que.empty()) {
    int x=que.front();que.pop();
    for(int i=0; i<v[x].size(); i++) {
      int y=v[x][i].F;
      c[cmp[y]]--;
      if(!c[y]) que.push(y);
    }
  }
}

int main() {
  int m;
  cin >> n >> m;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0,x,y; i<m; i++) {
    cin >> x >> y;
    add_edge(x,y);
  }
  scc();
  calc();
  make();
  erase();
  for(int i=0;i<n;i++)d[i][0]=d[i][1]=-1<<29;
  d[cmp[0]][o[find(0)]]=z[cmp[0]][o[find(0)]];
  queue<int> que;
  que.push(cmp[0]);
  while(!que.empty()) {
    int x=que.front();que.pop();
    for(int i=0; i<v[x].size(); i++) {
      P p=v[x][i];
      int y=p.F,t=p.S;
      c[cmp[y]]--;
      d[cmp[y]][o[find(y)]]=max(d[cmp[y]][o[find(y)]],d[x][t^1]+z[cmp[y]][o[find(y)]]);
      d[cmp[y]][o[find(y)]^1]=max(d[cmp[y]][o[find(y)]^1],d[x][t]+z[cmp[y]][o[find(y)]^1]);
      if(h[x]) {
        d[cmp[y]][o[find(y)]]=max(d[cmp[y]][o[find(y)]],d[x][t]+z[cmp[y]][o[find(y)]]);
        d[cmp[y]][o[find(y)]^1]=max(d[cmp[y]][o[find(y)]^1],d[x][t^1]+z[cmp[y]][o[find(y)]^1]);
      }
      if(!c[cmp[y]]) que.push(cmp[y]);
    }
  }
  int ans=0;
  for(int i=0;i<n;i++)for(int j=0;j<2;j++) ans=max(ans,d[cmp[i]][j]);
  cout << ans << endl;
  return 0;
}
