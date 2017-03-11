#include<bits/stdc++.h>
using namespace std;

int n,t[4005],a[100000];
int main(){
  cin>>n;
  for(int i=0,c,d;i<n;i++){
    scanf("%d.%d",&c,&d);
    a[i]=c*1000+d+1;
    t[a[i]]++;
  }
  for(int i=0;i<4004;i++)t[i+1]+=t[i];
  for(int i=0;i<n;i++)
    cout<<t[a[i]-1]*2+t[a[i]]-1<<endl;
  return 0;
}
