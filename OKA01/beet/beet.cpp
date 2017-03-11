#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[114][114][114];
signed main(){
  int n,p;
  cin>>n>>p;
  int x[n],y[n];
  for(int i=0;i<n;i++) cin>>x[i]>>y[i];
  memset(dp,-1,sizeof(dp));
  dp[0][0][0]=0;
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
	if(dp[i][j][k]<0) continue;
	if(dp[i+1][0][k]<0) dp[i+1][0][k]=dp[i][j][k];
	dp[i+1][0][k]=min(dp[i+1][0][k],dp[i][j][k]);
	int tmp=0;
	for(int l=0;l<=j;l++)
	  tmp=max(0LL,y[i-j+l]-max(0LL,x[i-j+l]-tmp));
	if(dp[i][j][k]+tmp<=p){
	  if(dp[i+1][j+1][k+1]<0) dp[i+1][j+1][k+1]=dp[i][j][k]+tmp;
	  dp[i+1][j+1][k+1]=min(dp[i+1][j+1][k+1],dp[i][j][k]+tmp);
	  ans=max(ans,k+1);
	}
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
