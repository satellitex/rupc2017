#include <bits/stdc++.h>
using namespace std;

int flg[100][100];
int main(){
  const int n = 13;
  int m,tmp;
  cin>>m>>tmp;
  
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    flg[y][x] = i+1;
    assert(x%2==(y/2)%2);
  }

  int cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(flg[i][j]) cout<<" "<<(char)('A'+flg[i][j]-1)<<" ";
      else if(j%2==(i/2)%2) cout<<" O ";
      else cout<<"   ";
    }
    cout<<endl;
  }  


  return 0;
}
