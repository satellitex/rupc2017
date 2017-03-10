#include <bits/stdc++.h>
using namespace std;

//遅延評価セグメントツリー（ある区間に一様に足す、一様に0で初期化　＋　区間の最大値 or 最小値 or 総和 を求める　動作が可能)
//一様に0に初期化に関しては若干Oが重くなる気がするので使わない時は消してください。
//指定する区間は常に [a,b) の半開区間であることに注意して下さい。
struct segtree{
    //総和を求める用
    vector<int> datasum;

    //遅延用
    vector<int> delay;

    int n;

    //初期化
    void init(int _n){
      n = 1;
      while( n < _n ) n*=2;
      datasum.resize( 2 * n );
      delay.resize( 2 * n );
    }

    //クリア(何度も使う場合）
    void clear(){
      datasum.clear();
      delay.clear();
    }

    //*    遅延評価本体
    /*    l,r に関しては総和を求める時にのみ使っている。 */
    /*    0で初期化する動作がいらない場合は三項演算子の部分と
    /*    if( delay[2*k+i]<0 && delay[k] > 0 ) delaycalc(2*k+i, i==0?l:(l+r)/2, i==0?(l+r)/2:r) の部分がいらない
    //*                                                  */
    void delaycalc(int k,int l,int r){
      datasum[k] = datasum[k] + delay[k]*(r-l);
      if( k+1 < n ){
        for(int i=1;i<=2;i++){
          delay[2*k+i] = delay[2*k+i]+delay[k];
        }
      }
      delay[k] = 0;
    }

    //区間　[a,b)　に一様に　x　を足す
    void add(int a,int b,int x,int k,int l,int r){
      delaycalc(k,l,r);
      if( r<=a || b<=l ) return;
      else if( a<=l && r<=b ){
        delay[k] = x;
        delaycalc(k,l,r);
      } else {
        add( a, b, x, 2*k + 1, l, (l+r)/2 );
        add( a, b, x, 2*k + 2, (l+r)/2, r );
        datasum[k] = datasum[2*k+1]+datasum[2*k+2];
      }
    }

    //ある区間の総和を求める
    int querysum(int a,int b,int k,int l,int r){
      delaycalc(k,l,r);
      if( r<=a || b<=l ) return 0;
      if( a<=l && r<=b ){
        return datasum[k]+delay[k]*(r-l);
      } else {
        int vl = querysum( a, b, 2*k+1, l,(l+r)/2 );
        int vr = querysum( a, b, 2*k+2, (l+r)/2,r );
        return vl+vr;
      }
    }

    void add( int a,int b,int x){ add( a, b, x, 0,0,n); }//加える
    int querysum(int a,int b){ return querysum(a,b,0,0,n); }//総和取得
};

segtree S[10];
vector<int> G[100005];
int N,Q;
int L[100005], R[100005];
void dfs(int p,int v,int &cnt){
  L[v] = cnt++;
  for( int to : G[v] ) {
    if( p == v ) continue;
    dfs( v, to, cnt );
  }
  R[v] = cnt;
}

void query(int a,int b,int c) {
  bool used[11] = {};
  for(int i=0;i<10;i++){
    if( used[i] ) continue;
    int pc = S[v].querysum(a,b);
    S[v].add(a,b,-pc);
    int v = (i+v)%10;
    while( v != i ) {
      int np =
      S[v].add(a,b,pc);
    }
  }
}

int main() {
  cin >> N >> Q;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 0; i < 10; i++) S[i].init(N);
  int cnt = 0;
  dfs(0, 0, cnt);
  S[0].add( 0, N, 1 );

  for (int i = 0; i < Q; i++) {
    int t, r, s; cin >> t >> r >> s;
    if( t == 1 ) {
      if( abs(s) == 10 ) continue;
      int p = S[0].querysum(L[r],R[r]);
      int id = 0;
      while( id)


    } else {

    }
  }

}