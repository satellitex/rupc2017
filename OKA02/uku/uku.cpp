#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

struct kDTree {
  struct Node {
    int location;
    int p, l, r;
    Node(){}
  };
  struct Point {
    int id, x, y;
    Point(){}
    Point(int id, int x, int y):id(id), x(x), y(y){}
    bool operator < (const Point &p) const {
      return id < p.id;
    }
  };

  static const int MAX = 50000;
  static const int NIL = -1;

  int N;
  Point P[MAX];
  Node T[MAX];
  int root, np, idx;

  kDTree(){}
  kDTree(int N):N(N), np(0), root(0), idx(0){}

  void setPoint(int x, int y) {
    P[idx] = Point(idx, x, y);
    T[idx].l = T[idx].r = T[idx].p = NIL;
    idx++;
  }

  int build(int l, int r, int depth) {
    if(!(l < r)) return NIL;

    int mid = (l + r) / 2;
    int t = np++;

    if(depth%2 == 0) {
      sort(P+l, P+r, [&](Point p1, Point p2) {
	  return p1.x < p2.x;
	});
    } else {
      sort(P+l, P+r, [&](Point p1, Point p2) {
	  return p1.y < p2.y;
	});
    }

    T[t].location = mid;
    T[t].l = build(l, mid, depth+1);
    T[t].r = build(mid+1, r, depth+1);

    return t;
  }
  void build() {
    root = build(0, N, 0);
  }

  void find(int v, int sx, int tx, int sy, int ty, int depth,
	    vector<Point> &ans) {
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if(sx <= x && x <= tx && sy <= y && y <= ty) {
      ans.push_back(P[T[v].location]);
    }

    if(depth%2 == 0) {
      if(T[v].l != NIL) {
	if(sx <= x) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
      }
      if(T[v].r != NIL) {
	if(x <= tx) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
      }
    } else {
      if(T[v].l != NIL) {
	if(sy <= y) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
      }
      if(T[v].r != NIL) {
	if(y <= ty) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
      }
    }
  }
  vector<Point> find(int sx, int tx, int sy, int ty) {
    vector<Point> res;
    find(root, sx, tx, sy, ty, 0, res);
    return res;
  }
};

int N, A, B;
vector<pint> XY[5];
kDTree tree;

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> A >> B;
  rep(i, 5) XY[i].emplace_back(0, 0);

  rep(i, N) {
    int t, x, y;
    cin >> t >> x >> y;
    XY[t-1].emplace_back(x, y);
  }

  int N0 = XY[0].size();
  int N1 = XY[1].size();
  int N2 = XY[2].size();
  int N3 = XY[3].size();
  int N4 = XY[4].size();

  tree = kDTree(N0*N1);
  rep(i, N0) {
    int x0, y0; tie(x0, y0) = XY[0][i];
    rep(j, N1) {
      int x1, y1; tie(x1, y1) = XY[1][j];
      tree.setPoint(x0+x1, y0+y1);
    }
  }
  tree.build();

  rep(i, N2) {
    int x2, y2; tie(x2, y2) = XY[2][i];
    rep(j, N3) {
      int x3, y3; tie(x3, y3) = XY[3][j];
      rep(k, N4) {
	int x4, y4; tie(x4, y4) = XY[4][k];
	int X = x2 + x3 + x4, Y = y2 + y3 + y4;
	auto ans = tree.find(A-X, B-X, A-Y, B-Y);
	if(ans.size()) {
	  cout << "Yes" << endl;
	  return 0;
	}
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
