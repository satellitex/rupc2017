#include<bits/stdc++.h>
#define EPS (1e-8)
#define N 100005
#define M 4005
using namespace std;
const double x=1000.0;
int n,A[M];
double a[N];

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    A[(int)(a[i]*x+EPS)+1]++;
  }
  for(int i=1;i<M;i++)A[i]+=A[i-1];
  for(int i=0;i<n;i++){
    int p=(int)(a[i]*x+EPS)+1;
    cout<<A[p-1]*3+(A[p]-A[p-1]-1)<<endl;
  }
  return 0;
}
