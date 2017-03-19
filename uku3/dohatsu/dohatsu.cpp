#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100005

struct data{
  int p[10];
};

data A,B;

#define SZ (1<<17)

struct segtree{
  data t[SZ*2];
  data u[SZ*2];
  void init(int k=0,int l=0,int r=SZ){
    for(int i=0;i<10;i++){
      t[k].p[i]=0;
      u[k].p[i]=i;
    }
    
    if(r-l==1){
      t[k].p[0]=1;
      return;
    }
    
    int m=(l+r)/2;
    init(k*2+1,l,m);
    init(k*2+2,m,r);
    for(int i=0;i<10;i++){
      t[k].p[i]+=t[k*2+1].p[i];
      t[k].p[i]+=t[k*2+2].p[i];
    }
  }
  
  void add(data &td,data &ud,data &x){
    int tt[10];
    int uu[10];
    for(int i=0;i<10;i++){
      tt[i]=0;
      uu[i]=i;
    }
    for(int i=0;i<10;i++){
      tt[ x.p[i] ]+=td.p[i];
      uu[i]=x.p[ ud.p[i] ];
    }
    for(int i=0;i<10;i++){
      td.p[i]=tt[i];
      ud.p[i]=uu[i];
    }
  }
  
  
  void compute(int k,int l,int r){
    if(r-l==1)return;
    int L=k*2+1;
    int R=k*2+2;

    add(t[L],u[L],u[k]);
    add(t[R],u[R],u[k]);
    
    for(int i=0;i<10;i++){
      t[k].p[i]=t[L].p[i]+t[R].p[i];
      u[k].p[i]=i;
    }
  }

  data Get(int a,int b,int k=0,int l=0,int r=SZ){
    if(b<=l || r<=a)return A;
    compute(k,l,r);
    if(a<=l && r<=b){
      return t[k];
    }else{
      int m=(l+r)/2;
      data lc=Get(a,b,k*2+1,l,m);
      data rc=Get(a,b,k*2+2,m,r);
      for(int i=0;i<10;i++)lc.p[i]+=rc.p[i];
      return lc;
    }
  }
  
  void dfs(int a,int b,data d,int k=0,int l=0,int r=SZ){
    if(b<=l || r<=a)return;
    compute(k,l,r);
    if(a<=l && r<=b){
      add(t[k],u[k],d);
    }else{
      int m=(l+r)/2;
      dfs(a,b,d,k*2+1,l,m);
      dfs(a,b,d,k*2+2,m,r);
      for(int i=0;i<10;i++)
        t[k].p[i]=t[k*2+1].p[i]+t[k*2+2].p[i];
    }
  }
};

int N,Q;
vector<int> G[MAX_N];
int v[MAX_N],size[MAX_N],cc=0;

void dfs(int pos){
  v[pos]=cc++;
  size[pos]=1;
  for(int i=0;i<(int)G[pos].size();i++){
    int to=G[pos][i];
    dfs(to);
    size[pos]+=size[to];
  }
}


segtree T;
int main(){
  for(int i=0;i<10;i++){
    A.p[i]=0;
    B.p[i]=i;
  }
  
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N-1;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    G[a].push_back(b);
  }
  
  dfs(0);
  T.init();
  
  while(Q--){
    int type;
    int r,x,y;
    scanf("%d %d %d %d",&type,&r,&x,&y);
    
    if(type==1){
      data key=T.Get(v[r],v[r]+size[r]);
      int sum=0;
      for(int i=x;i<=y;i++)sum+=key.p[i];
      printf("%d\n",sum);
    }else if(type==2){
      data key;
      for(int i=0;i<10;i++)key.p[i]=i;
      key.p[x]=y;
      T.dfs(v[r],v[r]+size[r],key);
    }

  }
  return 0;
}
