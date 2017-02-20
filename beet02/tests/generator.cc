#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);
  for (int t = 0; t < 30; t++) {
    ofstream of(format("02_random_%02d.in", t+1).c_str());
    int n=rnd.next(2,5);
    int a[n+1];
    while(1){
      int x[n];
      for(int i=0;i<n;i++){
	bool ff=0;
	while(!ff){
	  x[i]=rnd.next(-100,100);
	  if(!x[i]) x[i]=rnd.next(-100,100);
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
      if(i!=n&&a[i]>0) of<<"+";
      if(abs(a[i])!=1) of<<a[i];
      if(i) of<<"x";
      if(i>1) of<<"^"<<i;
    }
    of<<endl;
    of.close();
  }
  return 0;
}
