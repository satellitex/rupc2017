#include <bits/stdc++.h>
using namespace std;

int main(){
  double a,b;
  cin>>a>>b;
  double s = (a+b)/2;
  double t = (180+s);
  if(t>=360) t-=360;
  if(abs(a-b)<(360-abs(a-b)))printf("%.10f\n",s);
  else printf("%.10f\n",t);
  return 0;
}
