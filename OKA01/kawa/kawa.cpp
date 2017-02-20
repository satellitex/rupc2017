#include<bits/stdc++.h>
using namespace std;
int dp[101][10001][2];
int main(){
  int n,p,x[100],y[100],ans=0;
  cin>>n>>p;
  for(int i=0;i<n;i++)cin>>x[i]>>y[i];
  for(int i=0;i<n;i++)
    for(int j=0;j<=p;j++)
      for(int k=0;k<2;k++){
	int t=x[i];
	if(k==1&&i)t=max(0,t-(y[i-1]-x[i-1]));
	if(t>=y[i])
	  dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][k]+1);
	else if(j+y[i]-t<=p)
	  dp[i+1][j+y[i]-t][1]=max(dp[i+1][j+y[i]-t][1],dp[i][j][k]+1);
	dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][k]);
    }
  for(int i=0;i<=p;i++)
    ans=max(ans,max(dp[n][i][0],dp[n][i][1]));
  cout<<ans<<endl;
  return 0;
}
