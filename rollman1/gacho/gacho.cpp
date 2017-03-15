#include<bits/stdc++.h>
using namespace std;
int a,b;

int main(){
  cin>>a>>b;
  double A=(a+b)/2.0-min(a,b);
  double B=(min(a,b)+360-max(a,b))/2.0;
  double ans;
  if(A<B)ans=min(a,b)+A;
  else ans=max(a,b)+B;
  if(ans>=360)ans-=360;
  printf("%.8f\n",ans);
  return 0;
}
