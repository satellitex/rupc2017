#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<double,int> P;

map<double,int> m;
int main() {
  int n;
  cin >> n;
  P a[n];
  for(int i=0; i<n; i++) {
    cin >> a[i].F;
    a[i].S=i;
    m[a[i].F]++;
  }
  sort(a,a+n);
  int d[n];
  memset(d,0,sizeof(d));
  int x=0;
  for(int i=0; i<n; i++) {
    if(i&&a[i-1].F!=a[i].F) x+=m[a[i-1].F];
    d[a[i].S]=x*3+m[a[i].F]-1;
  }
  for(int i=0; i<n; i++) cout << d[i] << endl;
  return 0;
}
