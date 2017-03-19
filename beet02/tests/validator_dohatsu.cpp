#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s2ll(string s){
  assert(s.size()<10);
  stringstream ss;
  ss<<s;
  ll res;
  ss>>res;
  return res;
}

bool check0(string s){
  string tmp="0123456789x+-^";
  for(int i=0;i<(int)s.size();i++){
    char ch=s[i];
    if( tmp.find(ch) == string::npos )return false;
  }
  return true;
}

bool check2(string s){
  if(s=="")return false;
  int px=-1,py=-1,len=s.size();
  
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='x'){
      if(px!=-1)return false;
      px=i;
    }
    if(s[i]=='^'){
      if(py!=-1)return false;
      py=i;
    }
  }
  if(px!=-1&&py!=-1){
    return (px+1==py&&py<len-1);
  }
  if(px!=-1){
    return (py==-1&&px==len-1);
  }
  return true;
}

int calc(string s){
  if( s.find('x') == string::npos ){
    if( s2ll(s) < 1 || 2000 < s2ll(s) )return -1;
    return 0;
  }
  
  if( s.find('^') == string::npos ){
    if(s.size()==1)return 1;
    string k=s.substr(0, s.size()-1);
    if( s2ll(k)<=1 || 2000<s2ll(k))return -1;
    return 1;
  }
  
  string A=s.substr(0, s.find('x') );
  if(A.size()>1&&A[0]=='0')return -1;
  if(A.size()>0 && s2ll(A)<=1 || 2000<s2ll(A) )return -1;
  
  string B=s.substr( s.find('^')+1 );
  
  ll numB=s2ll(B);
  
  if(numB<2 || 5<numB)return -1;
  return numB;
};

bool check1(string s){
  s.push_back('=');
  string tmp="";
  ll last=100;
  for(int i=0;i<(int)s.size();i++){
    if(s[i]=='+'||s[i]=='-'||s[i]=='='){
      if(!check2(tmp))return false;
      int num=calc(tmp);
      if(num==-1 || last<=num)return false;
      if(last==100&&num!=1)return false;
      last=num;
      tmp="";
    }else{
      tmp.push_back(s[i]);
    }
  }
  return true;
}

int main(){
  string s;
  cin>>s;
  assert(check0(s));
  assert(check1(s));

  return 0;
}
