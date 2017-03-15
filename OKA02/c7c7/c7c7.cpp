#include<bits/stdc++.h>
#define f first
#define s second
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
class Node{
public:
  int location;
  int p,l,r;
  Node(){}
};
class Point{
public:
  int id,x,y;
  Point(){}
  Point(int id,int x,int y): id(id),x(x),y(y){}
  bool operator < (const Point &p){return id<p.id;}
};
static const int MAX =10000000;
static const int NIL = -1;
int n,c=0;
Point P[MAX];
Node T[MAX];
int np;
bool lessX(const Point &p1,const Point &p2){return p1.x<p2.x;}
bool lessY(const Point &p1,const Point &p2){return p1.y<p2.y;}
int makeKDTree(int l,int r, int d){
  if(!(l<r))return NIL;
  int mid=(l+r)/2;
  int t=np++;
  if(d%2==0)sort(P+l,P+r,lessX);
  else sort(P+l,P+r,lessY);
  T[t].location=mid;
  T[t].l=makeKDTree(l,mid,d+1);
  T[t].r=makeKDTree(mid+1,r,d+1);
  return t;
}
void find(int v,int sx,int tx,int sy,int ty,int d,vector<Point> &ans){
  int x=P[T[v].location].x;
  int y=P[T[v].location].y;
  if(sx<=x&&x<=tx&&sy<=y&&y<=ty)ans.push_back(P[T[v].location]);
  if(d%2==0){
    if(T[v].l!=NIL)if(sx<=x)find(T[v].l,sx,tx,sy,ty,d+1,ans);
    if(T[v].r!=NIL)if(x<=tx)find(T[v].r,sx,tx,sy,ty,d+1,ans);
  }
  else{
    if(T[v].l!=NIL)if(sy<=y)find(T[v].l,sx,tx,sy,ty,d+1,ans);
    if(T[v].r!=NIL)if(y<=ty)find(T[v].r,sx,tx,sy,ty,d+1,ans);
  }
}
main(){
  int n,ma,mi,c1=1,c2=1;
  pair<int,int>tt[5];
  vector<pair<int,int> > q[5],a[5];
  cin>>n>>mi>>ma;
  rep(i,5)tt[i]=make_pair(0,i);
  rep(i,n){
    int t,x,y;
    cin>>t>>x>>y;tt[t-1].f++;
    q[t-1].push_back(make_pair(x,y));
  }
  sort(tt,tt+5);
  rep(i,5){rep(j,q[tt[i].s].size()){
    a[i].push_back(q[tt[i].s][j]);
  }/*cout<<tt[i].s;*/}
 
  rep(i,a[4].size()){//cout<<1;
    P[c++]=Point(c,a[4][i].f,a[4][i].s);
    rep(j,a[2].size()){//cout<<2;
      if(c1)P[c++]=Point(c,a[2][j].f,a[2][j].s);
      P[c++]=Point(c,a[4][i].f+a[2][j].f,a[4][i].s+a[2][j].s);
      rep(k,a[0].size()){
        if(c2)P[c++]=Point(c,a[0][k].f,a[0][k].s);
        P[c++]=Point(c,a[0][k].f+a[4][i].f,a[0][k].s+a[4][i].s);
        P[c++]=Point(c,a[2][j].f+a[0][k].f,a[2][j].s+a[0][k].s);
        P[c++]=Point(c,a[0][k].f+a[2][j].f+a[4][i].f,a[0][k].s+a[2][j].s+a[4][i].s);
      }c2=0;
    }c1=0;
  }
  int root=makeKDTree(0,c,0);
  vector<Point>ans;
  rep(i,c)if(P[i].x>=mi&&P[i].x<=ma&&P[i].y<=ma&&P[i].y>=mi)goto L;
  rep(i,a[3].size()){
    find(root,mi-a[3][i].f,ma-a[3][i].f,mi-a[3][i].s,ma-a[3][i].s,0,ans);
    rep(j,a[1].size()){
      int x=a[3][i].f+a[1][j].f,y=a[3][i].s+a[1][j].s;
      int sx=mi-x,tx=ma-x,sy=mi-y,ty=ma-y;
      find(root,sx,tx,sy,ty,0,ans);
      find(root,mi-a[1][j].f,ma-a[1][j].f,mi-a[1][j].s,ma-a[1][j].s,0,ans);
    }
    if(ans.size())goto L;
  }
  cout<<"No"<<endl;
  if(0)L:cout<<"Yes"<<endl;
}
