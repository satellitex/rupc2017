#include<bits/stdc++.h>
using namespace std;
int n,p,x[100],y[100];
int dp[101][101][101],c[101][101],ans;

int main(){
  cin>>n>>p;
  for(int i=0;i<n;i++)cin>>x[i]>>y[i];

  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
      c[i][j]=max(0,y[j]-max(0,(x[j]-(j?c[i][j-1]:0))));

  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      for(int k=0;k<=n;k++)dp[i][j][k]=1e9;
    
  dp[0][0][0]=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<=i;j++)
      for(int k=0;k<=i;k++){
	int ct=c[j][i];
	dp[i+1][ct?j:i+1][k+1]=min(dp[i+1][ct?j:i+1][k+1],dp[i][j][k]+ct);
	dp[i+1][i+1][k]=min(dp[i+1][i+1][k],dp[i][j][k]);
    }

  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      if(dp[n][i][j]<=p) ans=max(ans,j);
  cout<<ans<<endl;
  return 0;
}
