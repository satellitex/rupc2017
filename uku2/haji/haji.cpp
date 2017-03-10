#include <bits/stdc++.h>
#define N 100001
using namespace std;
const int MAX_N = 1<<17;
typedef vector<int> V;

class BT{
public:
  int n,td[2*MAX_N-1];
  vector<V> dat;
  void init(int k=0,int l=0,int r=-1){
    if(r==-1) r = n;
    dat[k][0] = r-l;
    if(r-l==1) return;
    init(k*2+1,l,(l+r)/2);init(k*2+2,(l+r)/2,r);
  }

  BT(){
    n = MAX_N;
    memset(td,0,sizeof(td));
    dat.resize(2*n-1,V(10));
    init();
  }

  void shift(V &v,int x){
    V tmp=v;
    for(int i=0;i<10;i++) v[(i+x)%10] = tmp[i];
  }

  int add(int a,int b,int x,int y=0,int k=0,int l=0,int r=-1){
    if(r==-1)r=n;
    if(r<=a||b<=l) return 0; //区間の外
    if(a<=l&&r<=b){ //区間に完全に含まれる。
      shift(dat[k],x);
      td[k]+=x;
      return dat[k][y];
    }
    
    int kl=k*2+1,kr=k*2+2;
    shift(dat[kl],td[k]), shift(dat[kr],td[k]);
    td[kl]+=td[k], td[kr]+=td[k];
    td[k]=0;
    
    int vl=add(a,b,x,y,kl,l,(l+r)/2);
    int vr=add(a,b,x,y,kr,(l+r)/2,r);
    for(int i=0;i<10;i++)dat[k][i] = dat[kl][i]+dat[kr][i];
    return vl+vr;
  }
  int sum(int a,int b,int y){return add(a,b,0,y);}
};

V G[N];
vector<int> ord;
void dfs(int pos,int pre){
  ord.push_back(pos);
  for(int i=0;i<G[pos].size();i++)
    if(G[pos][i]!=pre)dfs(G[pos][i],pos);
  ord.push_back(pos);
}

BT T;
int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  for(int i=0,a,b;i<n-1;i++){
    scanf("%d%d",&a,&b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  dfs(0,-1);
  vector<int>L(n,1e9),R(n,0);
  set<int> S;
  for(int i=0;i<ord.size();i++){
    int cnt = S.size();
    L[ord[i]] = min(L[ord[i]],cnt);
    R[ord[i]] = max(R[ord[i]],cnt);
    S.insert(ord[i]);
  }
  
  while(q--){
    int t,r,x;
    scanf("%d%d%d",&t,&r,&x);
    x = (x+10)%10;
    if(t==1)T.add(L[r],R[r],x);
    else printf("%d\n",T.sum(L[r],R[r],x));
  }
   return 0;
}
