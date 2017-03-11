#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1<<18;
#define MAX_C 10
int n,dat[MAX_C][2*MAX-1],laz[2*MAX-1];
void init(int n_){
  n=1;
  while(n<n_) n*=2;
  for(int i=0;i<2*n-1;i++){
    for(int j=0;j<MAX_C;j++){
      dat[j][i]=0;
    }
    laz[i]=0;
  }
  for(int i=n-1;i<n-1+n_;i++) dat[0][i]=1;
  for(int i=n-2;i>=0;i--) dat[0][i]=dat[0][i*2+1]+dat[0][i*2+2];
}
void eval(int len,int k){
  laz[k]%=MAX_C;
  //cout<<laz[k]<<endl;
  for(int i=0;i<laz[k];i++){
    int tmp=dat[MAX_C-1][k];
    for(int j=MAX_C-1;j>0;j--){
      dat[j][k]=dat[j-1][k];
    }
    dat[0][k]=tmp;
  }
  if(k*2+1<n*2-1){
    laz[k*2+1]+=laz[k];
    laz[k*2+2]+=laz[k];
  }
  laz[k]=0;
}
void update(int a,int b,int x,int k=0,int l=0,int r=n){
  eval(r-l,k);
  if(r<=a||b<=l) return;
  if(a<=l&&r<=b){
    laz[k]+=x;
    eval(r-l,k);
    return;
  }
  update(a,b,x,k*2+1,l,(l+r)/2);
  update(a,b,x,k*2+2,(l+r)/2,r);
  for(int i=0;i<MAX_C;i++) dat[i][k]=dat[i][k*2+1]+dat[i][k*2+2];
}
int query(int a,int b,int c,int k=0,int l=0,int r=n){
  eval(r-l,k);
  if(r<=a||b<=l) return 0;
  if(a<=l&&r<=b) return dat[c][k];
  int vl=query(a,b,c,k*2+1,l,(l+r)/2);
  int vr=query(a,b,c,k*2+2,(l+r)/2,r);
  return vl+vr;
}

vector<int> G[MAX];
int st[MAX],en[MAX];
int pos=0;
void dfs(int v,int p=-1){
  st[v]=pos++;
  for(auto i:G[v]) if(i!=p) dfs(i,v);
  en[v]=pos;
}

void update(int k,int x){
  //cout<<x<<endl;
  update(st[k],en[k],x);
}
int query(int k,int c){
  return query(st[k],en[k],c);
}

int main(){
  int N,Q;
  cin>>N>>Q;
  init(N);
  for(int i=0;i<N-1;i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0);
  //for(int i=0;i<N;i++) cout<<st[i]<<" "<<en[i]<<endl;
  for(int i=0;i<Q;i++){
    int t,k,x;
    cin>>t>>k>>x;
    if(t==1) update(k,(x+10)%10);
    else{
      cout<<query(k,x)<<endl;
    }
  }
  return 0;
}
