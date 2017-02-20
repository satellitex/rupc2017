#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

bool compare(const vector<P> &a,const vector<P> &b){return a.size()<b.size();}

int main(){
  ll n,S;
  cin>>n>>S;
  
  //入力
  vector<P>A[5];
  for(int i=0;i<5;i++) A[i].push_back(P(0,0));
  for(int i=0;i<n;i++){
    ll t,x,y;
    cin>>t>>x>>y;
    A[t-1].push_back(P(x,y));
  }
  sort(A,A+5,compare);

  //座標圧縮
  set<ll> used;
  for(int i=0;i<A[0].size();i++)
    for(int j=i;j<A[1].size();j++) used.insert(A[0][i].first+A[1][j].first);
  
  vector<ll> X;
  set<ll>::iterator it;
  for(it=used.begin();it!=used.end();it++) X.push_back(*it);

  vector <set<ll> > T(X.size());
  for(int i=0;i<A[0].size();i++)
    for(int j=i;j<A[1].size();j++){
      ll x = A[0][i].first+A[1][j].first;
      ll y = A[0][i].second+A[1][j].second;
      x = lower_bound(X.begin(),X.end(),x)-X.begin();
      for(ll k=x;k<(ll)X.size();k++)T[k].insert(y);
    }

  
  for(int i=0;i<A[2].size();i++)
    for(int j=0;j<A[3].size();j++)
      for(int k=0;k<A[4].size();k++){
	ll x=S-A[2][i].first+A[3][j].first+A[4][k].first;
	ll y=S-A[2][i].second+A[3][j].second+A[4][k].second;
	x = lower_bound(X.begin(),X.end(),x)-X.begin();
	if(x<X.size()&&T[x].lower_bound(y)!=T[x].end()){
	  cout<<"Yes"<<endl;exit(0);
	}
      }
  cout<<"No"<<endl;
  
  return 0;
}
