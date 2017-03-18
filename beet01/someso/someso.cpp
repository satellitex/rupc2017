#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<double>a(n,0);
  vector<double>b(n,0);
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[i]=a[i];
  }
  sort(b.begin(),b.end());
  for(int i=0;i<n;i++){
    int c=0;
    vector<double>::iterator l = lower_bound(b.begin(),b.end(),a[i]);
    vector<double>::iterator u = upper_bound(b.begin(),b.end(),a[i]);
    c+=(l-b.begin())*3;
    //    cout << c <<" ";
    c+=(u-l-1);
    cout << c << endl;
  }
  return 0;
}
