#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int N;
ll A,B;
struct mergeSegTree {
  int n;
  vector< vector<ll> > data;
  void init(const vector<ll>& v){
    if( v.empty() ) {
      n = 0; return;
    }
    int _n = v.size();
    n = 1;
    while( n < _n ) n *= 2;
    data.resize( 2 * n );
    init( v, 0 );
  }
  void init( const vector<ll> &v, int k){
    if( k >= n-1 )
      data[k].emplace_back(v[k - n + 1]);
    else {
      init( v, 2*k+1 );
      init( v, 2*k+2 );
      merge( data[2*k+1].begin(), data[2*k+1].end(),
    	     data[2*k+2].begin(), data[2*k+2].end(),
	         back_inserter( data[k] ) );
    }
  }

  bool query( int a,int b,ll x,ll y, int k, int l, int r ){

    if( r<=a || b<=l ) return false;
    if( a<=l && r<=b ){
        if( y >= *lower_bound( data[k].begin(), data[k].end(), x ) )
        return true;
      return false;
    } 
    return query( a, b, x, y, 2*k+1, l, (l+r)/2 ) || query( a, b, x, y, 2*k+2, (l+r)/2, r );    
  }
  bool query( int a,int b,ll x,ll y ){
    if( n == 0 ) return x <= 0LL && 0LL<= y;
    return query( a, b, x, y, 0, 0, n );
  }
};


int main() {
  vector<P> v[5];
  cin >> N >> A >> B;
  for(int i=0;i<N;i++){
    int t;
    ll x,y; cin >> t >> x >> y;
    v[t-1].emplace_back( x, y );
  }
  
  vector<P> base_p;
  for(int i=0;i<v[0].size();i++) 
    for(int j=0;j<v[1].size();j++)
      for(int k=0;k<v[2].size();k++)
	base_p.emplace_back( v[0][i].first + v[1][j].first + v[2][k].first,
			     v[0][i].second + v[1][j].second + v[2][k].second );
  
  vector<P> find_p;
  for(int i=0;i<v[3].size();i++) 
    for(int j=0;j<v[4].size();j++) 
      find_p.emplace_back( v[3][i].first + v[4][j].first,
			   v[3][i].second + v[4][j].second );
  
  sort( find_p.begin(), find_p.end() );
  vector<ll> find_a, find_b;
  for(int i=0;i<find_p.size();i++){
    find_a.emplace_back( find_p[i].first );
    find_b.emplace_back( find_p[i].second );
  }
  mergeSegTree S;
  S.init( find_b );
  
  for( P p : base_p ) {
    int a = lower_bound( find_a.begin(), find_a.end(), A-p.first ) - find_a.begin();
    int b = upper_bound( find_a.begin(), find_a.end(), B-p.first ) - find_a.begin();
    if( b-a <= 0 ) continue;
    if( S.query( a, b, A-p.second, B-p.second ) ) {
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0;  
}
