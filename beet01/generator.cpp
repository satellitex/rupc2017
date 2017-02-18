#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n=rand()+100;
  while(n>100000) n=rand()+100;
  n=10;
  cout<<n<<endl;
  for(int i=0;i<n;i++){
    double x=rand()%10000;
    x*=4.0/10000;
    printf("%.4f\n",x);
  }
  return 0;
}
