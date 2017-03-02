#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
P p1=P(-1,-1),p2=P(-2,-2),a[100000];
int p[100002],r[100002],n,m,k;
int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int dx2[16]={-2,-2,-2,-2,-2,-1,-1,0,0,1,1,2,2,2,2,2},dy2[16]={-2,-1,0,1,2,-2,2,-2,2,-2,2,-2,-1,0,1,2};
bool check(int x,int y,int z){return x>=-z&&x<n+z&&y>=-z&&y<m+z;}

void init(){for(int i=0;i<100002;i++)p[i]=i,r[i]=0;}
int find(int x){return (p[x]==x)?x:(p[x]=find(p[x]));}
void unite(int x,int y) {
  x=find(x),y=find(y);
  if(x==y)return;
  if(r[x]<r[y])p[x]=y;
  else{p[y]=x;if(r[x]==r[y])r[x]++;}
}
bool same(int x,int y){return find(x)==find(y);}

map<P,int> ma;
void C(int &x,int &y){
  if(check(x,y,0)) return;
  if(y==-1||x==n) x=-1,y=-1;
  else x=-2,y=-2;
}

int main() {
  init();
  cin >> n >> m >> k;
  ma[p1]=0;
  ma[p2]=1;
  for(int i=0,x,y; i<k; i++) {
    cin >> x >> y;
    a[i]=P(x,y);
    int z=ma.size();
    ma[a[i]]=z;
    for(int j=0; j<8; j++) {
      int xx=x+dx[j],yy=y+dy[j];
      C(xx,yy);
      if(ma.count(P(xx,yy))) unite(z,ma[P(xx,yy)]);
    }
  }
  int ans=same(ma[p1],ma[p2])?0:2;
  for(int i=0; ans>1&&i<k; i++) {
    for(int j=0; j<16; j++) {
      int x=a[i].first+dx2[j],y=a[i].second+dy2[j];
      if(!check(x,y,1)) continue;
      C(x,y);
      if(!ma.count(P(x,y))) continue;
      if(same(ma[p1],ma[a[i]])&&same(ma[p2],ma[P(x,y)])) ans=1;
      if(same(ma[p2],ma[a[i]])&&same(ma[p1],ma[P(x,y)])) ans=1;
    }
  }
  cout << ans << endl;
  return 0;
}
