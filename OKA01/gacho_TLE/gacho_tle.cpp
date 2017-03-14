#include<bits/stdc++.h>
#define P 1000005
#define N 105
using namespace std;
int n,p,x[N],y[N],A[N][N],dp[2][N][P],ans;

int main(){
  cin>>n>>p;
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
      A[i][j]=max(0,y[j]-max(0,(x[j]-(j?A[i][j-1]:0))));
  /*  for(int i=0;i<n;i++)
    for(int j=i;j<n;j++)
    A[i][j]=min(y[j],max(0,y[j]-x[j]+(j?A[i][j-1]:0)));*/
  for(int i=0;i<n;i++){
    for(int j=i;j>=0;j--)
      for(int k=A[i-j][i];k<=p;k++){
	dp[(i+1)%2][j+1][k-A[i-j][i]]=max(dp[(i+1)%2][j+1][k-A[i-j][i]],dp[i%2][j][k]+1);
	ans=max(ans,dp[(i+1)%2][j+1][k-A[i-j][i]]);
      }
    for(int j=i;j>=0;j--)
      for(int k=0;k<=p;k++)
	dp[(i+1)%2][0][k]=max(dp[(i+1)%2][0][k],dp[i%2][j][k]);
  }
  cout<<ans<<endl;
  return 0;
}
