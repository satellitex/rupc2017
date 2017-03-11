#include<bits/stdc++.h>
using namespace std;

#define MAX 22

int N,ans=0;
int A[(1<<MAX)];
int dp[(1<<MAX)];
int prx[(1<<MAX)];
int pry[(1<<MAX)];
int prz[(1<<MAX)];

void insert(int &a,int &b,int &c,int x){
  if(x==-1||a==x||b==x||c==x)return;
  c=b;
  b=a;
  a=x;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int k,a,bit=0;
    scanf("%d",&k);
    for(int j=0;j<k;j++){
      scanf("%d",&a);
      a--;
      bit|=(1<<a);
    }
    A[bit]++;
  }
  
  for(int i=(1<<MAX)-1;i>0;i--){
    int a=-1,b=-1,c=-1;
    if(A[i]){
      dp[i]=i;
      a=i;
    }
    
    for(int j=0;j<MAX;j++){
      int nbit=i|(1<<j);
      if(i==nbit)continue;
      dp[i]|=dp[nbit];
      insert(a,b,c,prx[nbit]);
      insert(a,b,c,pry[nbit]);
      insert(a,b,c,prz[nbit]);
    }
    prx[i]=a;
    pry[i]=b;
    prz[i]=c;
    int cnt=0;
    if(a!=-1)cnt+=A[a];
    if(b!=-1)cnt+=A[b];
    if(c!=-1)cnt+=A[c];
    if(cnt>=3)ans=max(ans,__builtin_popcount(i)*__builtin_popcount(dp[i]));
  }
  printf("%d\n",ans);
  return 0;
}
