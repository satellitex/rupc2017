#include<iostream>
using namespace std;
int main(){
  double n,m,a;
  cin >> n >> m;
  a=(n+m)/2;
  while(1){
    if(a>=180)a-=180;
    else break;
  }
  cout << a << endl;
  return 0;
}
