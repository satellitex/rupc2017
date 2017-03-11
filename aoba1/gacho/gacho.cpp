#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,p[N],ans[N],cnt;
stack<int> s,t[N];

int main(){
  cin>>n;
  for(int i=1;i<=n;i++){
    scanf("%d",&p[i]);
    if(!ans[p[i]])ans[p[i]]=i,cnt++;
    else t[p[i]].push(i);
  }
  int x=1;
  while(1){
    while(!t[x].empty())s.push(t[x].top()),t[x].pop();
    if(!s.empty()&&!ans[x])ans[x]=s.top(),s.pop(),cnt++;
    if(cnt==n)break;
    x++;
    if(x==n+1)x=1;
  }
  for(int i=1;i<=n;i++)
    printf("%d\n",ans[i]);
  return 0;
}
