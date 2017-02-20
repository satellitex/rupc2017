#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// kD_Tree
// make_tree:O(n log^2(n))
// search:O(n^(1-1/K)+D)
// K:次元数 D:領域に含まれる点の数
struct node{
  vector<ll> Point;
  int l,r;
  node(){}
  node(vector<ll> a){Point=a,l=r=-1;}
};

const int K=2;// K:次元数
ll n,D;// D:その時にソートする基準の次元
vector<vector<ll> > P;// それぞれの要素はK+1個(K個の次元の番号＋付けたいnumber)
vector<node> G;

bool compare(vector<ll> &A,vector<ll> &B){return A[D]<B[D];}

int make_tree(int depth,int l,int r){
  if(l>r)return -1;
  D=depth%K;
  sort(P.begin()+l,P.begin()+r+1,compare);
  int m=(l+r)/2,res=G.size();
  G.push_back(node(P[m]));
  int vl=make_tree(depth+1,l,m-1);
  int vr=make_tree(depth+1,m+1,r);
  G[res].l=vl; G[res].r=vr;
  return res;
}

bool search(int x,int depth,vector<ll> &L,vector<ll> &R){
  bool f=true;
  for(int i=0;i<K;i++)
    if(G[x].Point[i]<L[i]||R[i]<G[x].Point[i])f=false;
  D=depth%K;
  if(!f&&G[x].Point[D]<=R[D]&&G[x].r!=-1)f=search(G[x].r,depth+1,L,R);
  D=depth%K;
  if(!f&&L[D]<=G[x].Point[D]&&G[x].l!=-1)f=search(G[x].l,depth+1,L,R);
  return f;
}

bool com(vector<vector<ll> > &A,vector<vector<ll> > &B){
  return A.size()<B.size();
}

ll a,s,t;
vector<vector<ll> > in[5];
int main(){
  cin>>a>>s;
  for(int i=0;i<a;i++){
    cin>>t; t--;
    vector<ll> v(2);
    for(int j=0;j<K;j++)
      cin>>v[j];
    in[t].push_back(v);
  }
  sort(in,in+5,com);
  swap(in[0],in[4]);
  for(int i=0;i<in[2].size();i++)
    for(int j=i;j<in[3].size();j++)
      for(int k=j;k<in[4].size();k++){
	vector<ll> temp(K);
	for(int l=0;l<K;l++)
	  temp[l]=in[2][i][l]+in[3][j][l]+in[4][k][l];
	P.push_back(temp);
      }

  make_tree(0,0,P.size()-1);
  bool ans=false;
  for(int i=0;i<in[0].size();i++)
    for(int j=i;j<in[1].size();j++){
      vector<ll> L(K),R(K);
      for(int k=0;k<K;k++){
	L[k]=s-(in[0][i][k]+in[1][j][k]);
	R[k]=(1e17);
      }
      ans|=search(0,0,L,R);
    }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
