#include<bits/stdc++.h>
using namespace std;

int N;
int L[22],R[22];
int D[22][22];

int dp[22][(1<<16)];
const int INF = 1<<30;

void update(int &a,int b){
  a = min( a, b );
}

int solve( int t ){
  for(int i=0;i<N;i++) {
    L[i] -= t; R[i] -= t;
  }

  fill( dp[0], dp[N], INF );
  for(int i=0;i<N;i++) d[i][(1<<i)] = 0;
  for(int st=0;st<(1<<N);st++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
	int nst = st|(1<<j);
	if( nst == st ) continue;
	if( dp[i][st] + D[i][j] > R[j] ) continue;
	update( dp[i][nst], max( dp[i][st] + D[i][j], L[j] ) );	
      }
    }
  }
  int res = INF;
  for(int i=0;i<N;i++)
    update( res, dp[i][(1<<N)-1] );
  for(int i=0;i<N;i++) {
    L[i] += t; R[i] += t;
  }
}

int main() {
  cin >> N;
  L[0] = -INF; R[0] = INF;
  for(int i=1;i<=N;i++){
    int l,r; cin >> l >> r;
    L[i] = l; R[i] = r;
  }
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin >> D[i][j];

  int res = 0;
  for(int i=0;i<N;i++){
    res = min( res, solve( L[i] ) );
  }
}
