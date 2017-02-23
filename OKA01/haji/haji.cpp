#include <bits/stdc++.h>
#define INF 1e9
#define N 101
using namespace std;
int n,P;
int x[N],y[N];
void Min(int &a,int b){a=min(a,b);}

int calc(int idx,int cnt){
  if(idx-cnt<0) return INF;
  int sum=0,t=0;
  for(int i=idx-cnt;i<=idx;i++)t=(y[i]-x[i])+sum, sum+=t;
   if(t<0) return 0;
   return sum;
 }

 int dp[N][N][N];
 int DP(){
   for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
       for(int k=0;k<N;k++) dp[i][j][k] = INF;
   dp[0][0][0] = 0;
   
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
       for(int k=0;k<n;k++){
	 int a = dp[i][j][k],c = calc(i,j);
	 Min(dp[i+1][0][k],a);
	 if(a==INF) continue;
	 if(c)Min(dp[i+1][j+1][k+1],a+c);
	 else Min(dp[i+1][0][k+1],a);
      }
  
  
  int res=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) if(dp[n][i][j]<=P) res=max(res,j);
  return res;
}

int main(){
  cin>>n>>P;
  for(int i=0;i<n;i++)cin>>x[i]>>y[i];
  cout<<DP()<<endl;
  return 0;
}
