#include<bits/stdc++.h>
using namespace std;

int N;
int p[100005];
vector<int> v[100005];

int main() {
  cin >> N;
  for (int i = 0; i < N;i++) {
    cin >> p[i]; --p[i];
    v[p[i]].push_back( i );
  }
  for(int i=0;i<N;i++) reverse( v[i].begin(), v[i].end() );
  stack<int> Q;
  stack<int> S;

  int head = N-1, tail = 0;
  for(int i=0;i<N;i++){
    int now;
    if( S.empty() )
      now = tail++;
    else
      now = head--;
    S.push( now );
    for( int t : v[now] ) Q.push( t );
    while( !Q.empty() ) {
      if( S.empty() ) break;
      int ps = S.top(); S.pop();
      p[ps] = Q.top(); Q.pop();
    }
  }

  for(int i=0;i<N;i++) cout << p[i]+1 << endl;

}