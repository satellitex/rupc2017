#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int MAX_N = 1<<17;

vector<int> po(10);
int ch[100000],mn[100000],cc;
vector<int> e[100000];

class RUQ{
public :
  int n;
  vector<int> dat[2*MAX_N-1];
  vector<P> td[2*MAX_N-1];
  
  RUQ(){
    n=MAX_N;
    memset(td,0,sizeof(td));
    for(int i=0,dd=1,cc=1;i<2*n-1;i++,cc++){
      for(int j=0;j<=9;j++)dat[i].push_back(0);
      dat[i][0]=n/dd;
      if(cc==dd)cc=0,dd*=2;
    }
  }
  vector<int> update(int a,int b,int x,int y,bool flg=true,int k=0,int l=0,int r=-1){
    if(r==-1) r=n;
    if(r<=a||b<=l){
      if(flg)return dat[k];
      return po;
    }
    if(a<=l&&r<=b){
      if(flg){
	dat[k][y]+=dat[k][x],dat[k][x]=0;
	td[k].push_back((P){x,y});
      }
      return dat[k];
    }
    if(td[k].size()){
      for(int i=0;i<td[k].size();i++){
	int s=td[k][i].first,t=td[k][i].second;
	dat[k*2+1][t]+=dat[k*2+1][s];
	dat[k*2+1][s]=0;
	dat[k*2+2][t]+=dat[k*2+2][s];
	dat[k*2+2][s]=0;
	td[k*2+1].push_back(P(s,t));
	td[k*2+2].push_back(P(s,t));
      }
      td[k].clear();
    }
    vector<int> vl=update(a,b,x,y,flg,k*2+1,l,(l+r)/2);
    vector<int> vr=update(a,b,x,y,flg,k*2+2,(l+r)/2,r);
    for(int i=0;i<=9;i++)vl[i]+=vr[i];
    if(flg)dat[k]=vl;
    return vl;
  }
  vector<int> find(int a,int b){return update(a,b,0,0,false);};
};

int dfs(int p){
  int res=1e9;
  for(int i=0;i<e[p].size();i++)
    res=min(res,dfs(e[p][i]));
  res=min(cc,res);
  ch[p]=cc++;
  return mn[p]=res;
}

RUQ T;

int main(){
  int q,n;
  cin>>n>>q;
  for(int i=0,u,v;i<n-1;i++)
    cin>>u>>v,e[u].push_back(v);
  dfs(0);
  while(q--){
     int cmd,r,x,y;
     scanf("%d%d%d%d",&cmd,&r,&x,&y);
     if(cmd==2){if(x!=y)T.update(mn[r],ch[r]+1,x,y);}
     else{
       vector<int> res=T.find(mn[r],ch[r]+1);
       int ans=0;
       for(int i=x;i<=y;i++)ans+=res[i];
       cout<<ans<<endl;
     }
   }
   return 0;
}
