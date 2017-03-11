#include<bits/stdc++.h>
using namespace std;
int N,P;
int X[111],Y[111];
const int INF = (1<<29);
int dp[111][111][111];
int H[111][111];
void update( int &a, int b ){
  a = min( a, b );
}
int solve(){
  fill( dp[0][0], dp[N+1][N+1], INF );
  dp[0][0][0] = 0;
  int res = 0;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=i;j++){
      for(int k=0;k<=i;k++){
	if( dp[i][j][k] == INF ) continue;
	if( dp[i][j][k] <= P ) res = max( res, j );
	if( i==N ) continue;
	int x = max( 0, X[i]-H[i-k][i] );
	if( x >= Y[i] ) {
	  update( dp[i+1][j+1][0], dp[i][j][k] );
	} else {
	  update( dp[i+1][j+1][k+1], dp[i][j][k] + (Y[i]-x) );
	  update( dp[i+1][j][0], dp[i][j][k] );
	}
      }
    }
  }
  return res;
}


int main(){
  cin >> N >> P;
  for(int i=0;i<N;i++){
    cin >> X[i] >> Y[i];
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      H[i][j] = max( 0, Y[j-1]-max(0,(X[j-1]-H[i][j-1])) );
    }
  }
  cout << solve() << endl;
}
