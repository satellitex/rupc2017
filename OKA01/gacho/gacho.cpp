#include<bits/stdc++.h>
#define INF (1e9)
#define P 1000005
#define N 105
using namespace std;
int n,p,x[N],y[N],A[N][N],dp[N][N][N],ans;

int main(){
  cin>>n>>p;
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
      A[i][j]=max(0,y[j]-max(0,(x[j]-(j?A[i][j-1]:0))));
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      for(int k=0;k<=n;k++)
	dp[i][j][k]=INF;
  dp[0][0][0]=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<=i;j++)
      for(int k=0;k<n;k++){
	if(dp[i][j][k]==INF)continue;
	if(A[i-j][i]<=p-dp[i][j][k])
	  dp[i+1][j+1][k+1]=min(dp[i+1][j+1][k+1],dp[i][j][k]+A[i-j][i]);
	dp[i+1][0][k]=min(dp[i+1][0][k],dp[i][j][k]);
      }
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      for(int k=0;k<=n;k++)
	if(dp[i][j][k]!=INF)ans=max(ans,k);
  cout<<ans<<endl;
  return 0;
}
