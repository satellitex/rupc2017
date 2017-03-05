#include <bits/stdc++.h>
using namespace std;

int main() {
  double x,y;
  cin >> x >> y;
  double r=(x+y)/2;
  if(abs(x-r)>90||abs(y-r)>90) {
    r+=180;
    if(r>=360) r-=360;
  }
  printf("%.10f\n",r);
  return 0;
}
