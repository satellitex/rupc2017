#include<bits/stdc++.h>
using namespace std;
int main(){
  double a,b;
  cin>>a>>b;
  double t1=max(a,b),t2=min(a,b);
  if(abs(360-t1)+t2>=t1-t2)printf("%.5f",(a+b)/2);
  else{
    if((a+b-360)<0)printf("%.6f",t1-(a+b-360)/2);
    else printf("%.6f",(a+b-360)/2);
  }cout<<endl;
}
