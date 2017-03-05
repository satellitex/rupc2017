#include <bits/stdc++.h>
#define N 100001
using namespace std;
int w,h,n;
set<int> S[N],used[N];



int dfs(int x,int y,int cnt){
  used[y].insert(y); 
 
  for(int i=-1;i<=1;i++)
    for(int j=-1;j<=1;j++){
      if(i==0&&j==0)continue;
      int nx = x+i;
      int ny = y+j;
      if(S[ny].count(nx)){
	dfs(nx,ny,cnt);

      }
      if(!S[ny].count(nx))continue;


      

    }
  
}

int main(){
  cin>>w>>h>>n;
  for(int i=0,x,y;i<n;i++)cin>>x>>y,S[y].insert(x);
  
  
  
  return 0;
}
