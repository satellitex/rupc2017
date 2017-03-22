#include <bits/stdc++.h>
using namespace std;
const int N=22,Z=(1<<N)-1;
int f[1<<N],d[1<<N],n,ans;
set<int> s[1<<N];
void zeta(){
  for(int i=0; i<N; i++) {
    for(int j=0; j<(1<<N); j++) {
      if(j&1<<i) continue;
      f[j]&=f[j|(1<<i)];
      d[j]|=d[j|(1<<i)];
      for(set<int>::iterator it=s[j|(1<<i)].begin(); it!=s[j|(1<<i)].end()&&s[j].size()<3; it++) s[j].insert(*it);
    }
  }
}
int main() {
  fill(f,f+(1<<N),Z);
  cin >> n;
  for(int i=0; i<n; i++) {
    int x=0,y,k;
    cin >> k;
    for(int j=0; j<k; j++) {
      cin >> y;
      x|=1<<(y-1);
    }
    f[x]=d[x]=x;
    s[x].insert(i);
  }
  zeta();
  for(int i=0; i<(1<<N)-1; i++) {
    if(s[i].size()>=3) ans=max(ans,__builtin_popcount(f[i])*__builtin_popcount(d[i]));
  }
  cout << ans << endl;
  return 0;
}
