#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n=rnd.next(2,5);
  int a[n+1];

  while(1){
    int x[n];
    for(int i=0;i<n;i++){
      bool ff=0;
      while(!ff){
	x[i]=rnd.next(-1000,1000);
	if(!x[i]) x[i]=rnd.next(-1000,1000);
	ff=1;
	for(int j=0;j<i;j++) ff&=x[i]!=x[j];
      }
      //cout<<x[i]<<endl;
    }
    memset(a,0,sizeof(a));
    for(int i=0;i<(1<<n);i++){
      int c=0,r=1;
      for(int j=0;j<n;j++){
	if(((i>>j)&1)==0) continue;
	r*=x[j];c++;
      }
      a[n-c]+=r;
    }
    bool f=1;
    for(int i=0;i<=n;i++) f&=(abs(a[i])<=1000);
    if(f) break;
  }
    
  for(int i=n;i>=0;i--){
    //cout<<a[i]<<endl;
    if(!a[i]) continue;
    if(i!=n&&a[i]>0) cout<<"+";
    if(abs(a[i])!=1) cout<<a[i];
    if(i) cout<<"x^"<<i;
  }
  cout<<endl;
  return 0;
}
