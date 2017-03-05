#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A[6];
string str;

void mk(int &i){
  int a = 0,f = (str[i++]=='+' ? 1:-1);
  while(isdigit(str[i])) a=a*10+str[i++]-'0';
  a=max(1,a);
  
  int k=0; 
  if(str[i]=='x')i++,k=1; 
  if(str[i]=='^')k=str[i+1]-'0',i+=2;
  A[k] = a*f;
}

ll calc(ll x){
  ll sum=0,X = 1;
  for(int i=0;i<6;i++) sum+=A[i]*X,X*=x;
  return sum;
}

int main(){
  cin>>str;
  str='+'+str;
  for(int i=0;i<(int)str.size();mk(i));

  int k=0;
  for(int i=0;i<6;i++)if(A[i])k = i;
  
  vector<int> ans;
  int num = 2*1000;
  while(ans.size()<k)if(calc(num--)==0)ans.push_back(-(num+1));
  
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++)cout<<"(x"<<(ans[i]>0? "+":"")<<ans[i]<<")";
  cout<<endl;
  return 0;
}
