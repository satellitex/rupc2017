#include <bits/stdc++.h>
#define N 100001
using namespace std;
typedef long long ll;
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

  V shift(V v,int x){
    V res=V(10);
    for(int i=0;i<10;i++) res[(i+x)%10] = v[i];
    return res;
  }
  V compare(V a,V b){
    V res=V(10);
    for(int i=0;i<10;i++) res[i] = b[i]-a[i];
    return res;
  }

  V add(int a,int b,int x,int k=0,int l=0,int r=-1){
    if(r==-1)r=n;
    if(r<=a||b<=l) return V(10); //区間の外
    if(a<=l&&r<=b){ //区間に完全に含まれる。
      V tmp = dat[k];
      dat[k] = shift(dat[k],x);
      td[k]+=x;
      return compare(tmp,dat[k]);
    }

    ll kl=k*2+1,kr=k*2+2;
    dat[kl]=shift(dat[kl],td[k]), dat[kr]=shift(dat[kr],td[k]);
    td[kl]+=td[k], td[kr]+=td[k];
    td[k]=0;
    
    V vl = add(a,b,x,kl,l,(l+r)/2);
    V vr = add(a,b,x,kr,(l+r)/2,r);
    V res(10);
    for(int i=0;i<10;i++)res[i]=vl[i]+vr[i],dat[k][i]+=res[i];
    return res;
  }

  int sum(int a,int b,int y,int k=0,int l=0,int r=-1){
    if(r==-1)r=n,add(a,b,0);
    if(r<=a||b<=l) return 0; //区間の外
    if(a<=l&&r<=b)return dat[k][y];//区間に完全に含まれる。
    ll vl = sum(a,b,y,k*2+1,l,(l+r)/2);
    ll vr = sum(a,b,y,k*2+2,(l+r)/2,r);
    return vl+vr;
  }
};

V G[N];
vector<int> ord;
void dfs(int pos){
  ord.push_back(pos);
  for(int i=0;i<G[pos].size();i++)dfs(G[pos][i]);
  ord.push_back(pos);
}

BT T;
int main(){
  int n,q;
  cin>>n>>q;
  for(int i=0,a,b;i<n-1;i++)cin>>a>>b,G[a].push_back(b);
  dfs(0);
  vector<int>L(N,1e9),R(N,0);
  set<int> S;
  for(int i=0;i<ord.size();i++){
    int cnt = S.size();
    L[ord[i]] = min(L[ord[i]],cnt);
    R[ord[i]] = max(R[ord[i]],cnt);
    S.insert(ord[i]);
  }
  
  while(q--){
    int t,r,x;
    cin>>t>>r>>x;
    x = (x+10)%10;
    if(t==1)T.add(L[r],R[r],x);
    else printf("%d\n",T.sum(L[r],R[r],x));
  }
   return 0;
}
