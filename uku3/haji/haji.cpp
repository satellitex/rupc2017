#include <bits/stdc++.h>
#define N 100001
using namespace std;
const int MAX_N = 1<<17;

class BT{
public:
  int n;
  int dat[2*MAX_N-1][10],td[2*MAX_N-1][10];
  
  void init(int td[]){for(int i=0;i<10;i++)td[i]=i;}
  void init(int k=0,int l=0,int r=-1){
    if(r==-1) r = n;
    dat[k][0] = r-l;
    init(td[k]);
    if(r-l==1) return;
    init(k*2+1,l,(l+r)/2);init(k*2+2,(l+r)/2,r);
  }

  BT(){n = MAX_N;init();}
  
  int Sum(int v[],int l,int r){
    int res=0;
    for(int i=l;i<=r;i++) res+=v[i];
    return res;
  }
  
  void calc(int dat[],int t[]){
    int tmp[10]={};
    for(int i=0;i<10;i++)tmp[t[i]]+=dat[i];
    for(int i=0;i<10;i++)dat[i]=tmp[i];
  }
  
  void pr(int dat[]){for(int i=0;i<10;i++)cout<<dat[i]<<" ";cout<<endl;} 
  void marge(int td[],int x,int y){for(int i=0;i<10;i++)if(td[i]==x)td[i]=y;}
  void marge(int td[],int b[]){
    int tmp[10]={};
    for(int i=0;i<10;i++) tmp[i] = td[i];
    for(int i=0;i<10;i++)
      if(i!=b[i])
	for(int j=0;j<10;j++)if(tmp[j]==i)td[j]=b[i];
    //for(int i=0;i<10;i++)if(i!=b[i])marge(td,i,b[i]);
  }
  
  int add(int a,int b,int x,int y,int q=1,int k=0,int l=0,int r=-1){
    if(r==-1)r=n;
    if(r<=a||b<=l)return 0; //区間の外
    if(a<=l&&r<=b){ //区間に完全に含まれる。
      if(q&&x!=y){
	marge(td[k],x,y);
	dat[k][y] += dat[k][x],dat[k][x] = 0;
      }
      return Sum(dat[k],x,y);
    }
    
    int kl=k*2+1,kr=k*2+2;
    marge(td[kl],td[k]);
    marge(td[kr],td[k]);
    calc(dat[kl],td[k]);
    calc(dat[kr],td[k]);
    init(td[k]);
    int vl=add(a,b,x,y,q,kl,l,(l+r)/2);
    int vr=add(a,b,x,y,q,kr,(l+r)/2,r);
    for(int i=0;i<10;i++)dat[k][i] = dat[kl][i]+dat[kr][i]; 
    return vl+vr;
  }
  int sum(int a,int b,int x,int y){return add(a,b,x,y,0);}
};

vector<int>G[N];
vector<int> ord;
void dfs(int pos){
  ord.push_back(pos);
  for(int i=0;i<G[pos].size();i++)dfs(G[pos][i]);
  ord.push_back(pos);
}

BT T;
int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  for(int i=0,a,b;i<n-1;i++)scanf("%d%d",&a,&b),G[a].push_back(b);

  dfs(0);
  vector<int>L(n,1e9),R(n,0);
  set<int> S;
  for(int i=0;i<ord.size();i++){
    int cnt = S.size();
    L[ord[i]] = min(L[ord[i]],cnt);
    R[ord[i]] = max(R[ord[i]],cnt);
    S.insert(ord[i]);
  }
  while(q--){
    int t,r,x,y;
    scanf("%d%d%d%d",&t,&r,&x,&y);
    //cout<<(t==2? "change":"sum")<<" "<<r<<" "<<x<<" "<<y<<endl;
    if(t==2)T.add(L[r],R[r],x,y);
    else printf("%d\n",T.sum(L[r],R[r],x,y));
  }
   return 0;
}
