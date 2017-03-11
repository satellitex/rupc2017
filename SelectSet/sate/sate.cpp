#include <bits/stdc++.h>
using namespace std;

int N;
typedef set<int> Set;
typedef pair<int,Set> P;
unordered_map<int,P> S[23];

int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    int k; cin >> k;
    int st = 0;
    for(int j=0;j<k;j++){
      int a; cin >> a; --a;
      st |= (1<<a);
    }
    int num = __builtin_popcount(st);
    if( !S[num].count( st ) ) {
        set<int> s; s.insert(i);
        S[num][st] = P(st, s);
    }
    else
      S[num][st].second.insert(i);

  }
  int res = 0;
  for(int i=22;i>0;i--){
    for( auto p : S[i] ) {
      int st = p.first, wst = p.second.first;
      Set &s = p.second.second;
      if( s.size() >= 3 ) s.clear();
      int cnt = s.size();
      if( cnt == 0 ) {
          res = max( res, i * __builtin_popcount(wst) );
      }
      for (int j = 0; j < 22; j++) {
        if( st & (1<<j) ) {
          int nst = st - (1<<j);
          if( !S[i-1].count( nst ) )
            S[i-1][nst] = P( wst, s );
          else {
            S[i-1][nst].first |= wst;
            if( !S[i-1][nst].second.empty() )
                for( int id : s )
                    S[i-1][nst].second.insert( id );
          }
        }
      }
    }
  }
  cout << res << endl;
}