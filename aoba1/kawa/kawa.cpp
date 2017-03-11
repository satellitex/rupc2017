#include<bits/stdc++.h>
using namespace std;
deque<int> Q,v[100001];
int ans[100001],c,n;
int main(){
  cin>>n;
  for(int i=1,p;i<=n;i++){
    scanf("%d",&p);
    v[p-1].push_back(i);
  }
  for(int i=0;c!=n;i++,i%=n){
    while(!v[i].empty())Q.push_front(v[i].back()),v[i].pop_back();
    if(!ans[i]&&!Q.empty())ans[i]=Q.front(),Q.pop_front(),c++;
  }
  for(int i=0;i<n;i++)printf("%d\n",ans[i]);
  return 0;
}
