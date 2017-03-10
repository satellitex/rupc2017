#include <bits/stdc++.h>
using namespace std;
stack<int> st[111111],s;
int a[111111];

int main() {
  int n;
  cin >> n;
  for(int i=0,x; i<n; i++) {
    cin >> x;
    st[x-1].push(i+1);
  }
  for(int k=0; k<2; k++) {
    for(int i=0; i<n; i++) {
      while(!st[i].empty()) s.push(st[i].top()),st[i].pop();
      if(!a[i]&&!s.empty()) a[i]=s.top(),s.pop();
    }
  }
  for(int i=0; i<n; i++) cout << a[i] << endl;
  return 0;
}
