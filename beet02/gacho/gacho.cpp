#include<bits/stdc++.h>
using namespace std;
string s,t;
int n,x[5],A[5];
vector<int> v;
int flag,K,S;

void dfs2(int d,int cnt,int cal){
  if(d==n){
    if(cnt==n-K)S+=cal;
    return;
  }
  dfs2(d+1,cnt+1,cal*A[d]);
  dfs2(d+1,cnt,cal);
}

void dfs(int d,int num){
  if(d==n){
    int cal=1,sum=0;
    for(int i=0;i<n;i++)cal*=A[i],sum+=A[i];
    if(cal==x[0]&&sum==x[n-1]){
      flag=0;
      for(int i=1;i<n-1;i++){
	K=i;
	S=0;
	dfs2(0,0,1);
	if(S!=x[i])flag=1;
      }
      if(!flag){
	for(int i=0;i<n;i++){
	  cout<<"(x";
	  if(A[i]>0)cout<<'+';
	  cout<<A[i]<<")";
	}
	cout<<endl;
      }
    }
    return;
  }
  for(int i=num+1;i<v.size();i++){
    A[d]=v[i];
    dfs(d+1,i);
  }
}

int main(){
  cin>>s;
  s+='+';
  for(int i=0;i<s.size()-1;i++){
    t+=s[i];
    if(s[i]=='x'&&s[i+1]!='^')t+="^1";
    else if(s[i]=='x'){
      t+=s[i+1],t+=s[i+2],i+=2;
      continue;
    }
    if('0'<=s[i]&&s[i]<='9'&&(s[i+1]=='+'||s[i+1]=='-'))t+="x^0";
  }
  s=t;
  int num=0,p=0,f=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='-')p=1;
    if('0'<=s[i]&&s[i]<='9')num=num*10+s[i]-'0',f=1;
    if(s[i]=='x'){
      if(!f&&!num)num=1;
      if(p)num*=-1;
      n=max(n,s[i+2]-'0');
      x[s[i+2]-'0']=num,num=0,p=0,f=0,i+=2;
    }
  }
  int temp=x[0];
  if(temp<0)temp*=-1;
  for(int i=1;i*i<=temp;i++)
    if(!(temp%i)){
      v.push_back(i);
      v.push_back(-i);
      if(i*i!=temp){
	v.push_back(temp/i);
	v.push_back(-temp/i);
      }
    }
  sort(v.begin(),v.end());
  dfs(0,-1);
  return 0;
}
