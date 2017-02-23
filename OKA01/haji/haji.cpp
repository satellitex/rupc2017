#include <bits/stdc++.h>
using namespace std;
int n;
int x[101],y[101];

int mem[101][10001][2],used[101][10001][2];
int dfs(int pos,int P,int f){

  if(pos==n) return 0;
  if(used[pos][P][f]++) return mem[pos][P][f];

  int a = x[pos],b = y[pos];
  if(f) a=max(0,a-(y[pos-1]-x[pos-1]));
  if(a>=b) return 1+dfs(pos+1,P,0);
  int &res = mem[pos][P][f] = dfs(pos+1,P,0);
  if(b-a<=P) res=max(res,1+dfs(pos+1,P-(b-a),1));
  return res;
}

int main(){
  int P;
  cin>>n>>P;
  for(int i=0;i<n;i++)cin>>x[i]>>y[i];
  cout<< dfs(0,P,0)<<endl;
  return 0;
}
