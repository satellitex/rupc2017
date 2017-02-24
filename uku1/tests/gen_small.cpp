#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int N = 20;
const int M = 20;
const int C = 1000;
const int T = 1000;

struct UnionFind {
  vector<int> data;
  UnionFind(){}
  UnionFind(int sz):data(sz, -1){};
  int size(int x) { return -data[find(x)]; }
  int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]); }
  bool same(int x, int y) { return find(x) == find(y); }
  int unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x != y) {
      if(data[x] < data[y]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return -data[x];
  }
};

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  for(int t = 0; t < 20; t++) {
    ofstream ofs(format("01_small_%02d.in", t).c_str());

    int n = rnd.next(1, N);
    int m = rnd.next(n-1, min(M, n*(n-1)/2));

    UnionFind uf;
    set< pair<int, int> > used;
    vector< tuple<int, int, int, int> > data;
    do {
      uf = UnionFind(n);
      used.clear();
      data.clear();
      while(data.size() < m) {
	int a = rnd.next(0, n-1);
	int b = rnd.next(0, n-1);
	while(a == b) b = rnd.next(0, n-1);
	if(b < a) swap(a, b);

	if(used.count(make_pair(a, b))) continue;
	used.insert(make_pair(a, b));

	int c = rnd.next(1, C);
	int t = rnd.next(0, T);

	data.emplace_back(a, b, c, t);
	uf.unite(a, b);
      }
    } while(uf.size(0) != n);

    ofs << n << " " << m << endl;
    sort(data.begin(), data.end());
    for(auto&& d : data) {
      int a, b, c, t;
      tie(a, b, c, t) = d;
      ofs << a << " " << b << " " << c << " " << t << endl;
    }

    ofs.close();
  }
  return 0;
}
