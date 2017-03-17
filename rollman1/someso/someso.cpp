#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
  double n,m,a;
  cin >> n >> m;
  a=(n+m)/2;
  if(fabs(n-m)>180)a+=180;
  if(a>=360)a-=360;
  printf("%.6f\n",a);
  return 0;
}
