#include <bits/stdc++.h>
#define all(A) A.begin(),A.end() 
using namespace std;

vector<double>num;
int calc(double n){
  int draw = upper_bound(all(num),n) - lower_bound(all(num),n) - 1;
  int win =  lower_bound(all(num),n) - num.begin();
  return 3*win + draw;
}

int main(){
  int n;
  cin>>n;
  vector<double> A(n);
  num.resize(n);
  for(int i=0;i<n;i++)cin>>A[i],num[i] = A[i];
  sort(num.begin(),num.end());
  for(int i=0;i<n;i++)cout<<calc(A[i])<<endl;
  return 0;
}
