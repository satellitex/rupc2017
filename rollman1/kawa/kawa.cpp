#include<bits/stdc++.h>
using namespace std;
int main(){
  double a,b;
  cin>>a>>b;
  if(a>b)swap(a,b);
  if((b-a)/2<-(b-360-a)/2)a+=(b-a)/2;
  else a+=(b-360-a)/2;
  if(a<0)a+=360;
  cout<<a<<endl;
  return 0;
}
