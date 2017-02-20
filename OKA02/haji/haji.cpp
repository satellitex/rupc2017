#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1<<20;

class xyTree{
public:
  ll n;
  vector<set<ll> >dat;
  xyTree(){dat.resize(N*2-1);n=N;}
  xyTree(int n){dat.resize(n*2-1),this->n=n;}
  void update(ll x,ll y){
    x+=n-1;
    dat[x].insert(y);
    while(x>0){
      x=(x-1)/2;
      dat[x].insert(y);
    }
  }
  
  ll query(ll a,ll b,ll y,int k=0,int l=0,int r=0){
    if(k==0) r = n;
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return dat[k].lower_bound(y)!=dat[k].end();
    if(query(a,b,k*2+1,l,(l+r)/2))return 1;
    if(query(a,b,k*2+2,(l+r)/2,r))return 1;
    return 0;
  }
};


typedef pair<ll,ll> P;
bool compare(const vector<P> &a,const vector<P> &b){return a.size()>b.size();}
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
    for(int j=i;j<A[1].size();j++)
      used.insert(A[0][i].first+A[1][j].first);


  /*  for(int i=0;i<A[2].size();i++)
    for(int j=i;j<A[3].size();j++)
      for(int k=j;k<A[4].size();k++) 
	used.insert(A[2][i].first+A[3][j].first+A[4][k].first);
  */
  
  vector<ll> X;
  set<ll>::iterator it;
  for(it=used.begin();it!=used.end();it++) X.push_back(*it);
  
  //木の構築
  xyTree T(X.size());
  for(int i=0;i<A[0].size();i++)
    for(int j=i;j<A[1].size();j++){
      ll x = A[0][i].first+A[1][j].first;
      ll y = A[0][i].second+A[1][j].second;
      x = lower_bound(X.begin(),X.end(),x)-X.begin();
      T.update(x,y);
    }
  
  
  //探索
  for(int i=0;i<A[2].size();i++)
    for(int j=0;j<A[3].size();j++)
      for(int k=0;k<A[4].size();k++){
	ll x=S-A[2][i].first+A[3][j].first+A[4][k].first;
	ll y=S-A[2][i].second+A[3][j].second+A[4][k].second;
	x = lower_bound(X.begin(),X.end(),x)-X.begin();
	if(T.query(x,N,y)){cout<<"Yes"<<endl;exit(0);}
      }

  cout<<"No"<<endl;
  return 0;
}
