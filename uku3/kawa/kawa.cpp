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
<<<<<<< HEAD
  int td[2*MAX_N-1][10];
  
=======
  vector<P> td[2*MAX_N-1];

>>>>>>> 8b60543536620f0191fb2e1e3a4a42608427616b
  RUQ(){
    n=MAX_N;
    for(int i=0,dd=1,cc=1;i<2*n-1;i++,cc++){
      for(int j=0;j<=9;j++)td[i][j]=j,dat[i].push_back(0);
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
	for(int i=0;i<=9;i++)if(td[k][i]==x)td[k][i]=y;
      }
      return dat[k];
    }
    int tmp[2][10]={},tp[2][10];
    for(int i=0;i<=9;i++)tp[0][i]=td[k*2+1][i],tp[1][i]=td[k*2+2][i];
    for(int i=0;i<=9;i++){
      tmp[0][td[k][i]]+=dat[k*2+1][i];
      tmp[1][td[k][i]]+=dat[k*2+2][i];
      for(int j=0;j<=9;j++){
	if(tp[0][j]==i)td[k*2+1][j]=td[k][i];
	if(tp[1][j]==i)td[k*2+2][j]=td[k][i];
      }
      td[k][i]=i;
    }
    for(int i=0;i<=9;i++)dat[k*2+1][i]=tmp[0][i],dat[k*2+2][i]=tmp[1][i];
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
       printf("%d\n",ans);
     }
   }
   return 0;
}
