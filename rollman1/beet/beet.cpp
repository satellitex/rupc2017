#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  double a1,a2;
  cin>>a1>>a2;
  if(a1>a2) swap(a1,a2);
  if(a1+360.0-a2<a2-a1){
    if(a1-(a1+360.0-a2)/2>0)
      printf("%.12f\n",a1-(a1+360.0-a2)/2);
    else
      printf("%.12f\n",a2+(a1+360.0-a2)/2);
  }else printf("%.12f\n",(a1+a2)/2);
  return 0;
}
