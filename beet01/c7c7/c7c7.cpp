#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double a[n];int b[4001]={0},c[4001]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[(int)(a[i]*1000)]++;
        c[(int)(a[i]*1000)]++;
    }
    for(int i=1;i<=4000;i++)b[i]+=b[i-1];
    for(int i=0;i<n;i++){
      int sum=0;
        if(a[i]>0)sum+=b[(int)(a[i]*1000-1)]*3;
        sum+=c[(int)(a[i]*1000)]-1;
        cout<<sum<<endl;
    }
}
