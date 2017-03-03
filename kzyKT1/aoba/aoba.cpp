#include <bits/stdc++.h>

using namespace std;

class Union_Find {
  public:
    vector<int> par, rank;
    
    Union_Find(int N) {
        par.resize(N); rank.resize(N);

        for (int i = 0; i < N; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) return;
        
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

bool in_field(int x, int y, int W, int H)
{
    return 0 <= x && x < W && 0 <= y && y < H;
}

int main()
{    
    map<pair<int, int>, int> f;
    
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<int> x(K), y(K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &x[i], &y[i]);
        f[make_pair(y[i], x[i])] = i;        
    }
    
    constexpr int dx[] = {-1, -1, -1, +0, +0, +1, +1, +1};
    constexpr int dy[] = {-1, +0, +1, -1, +1, -1, +0, +1};

    Union_Find uf(K + 4);    
    int res = 2;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 8; j++) {
            int nx = x[i] + dx[j], ny = y[i] + dy[j];
            if (in_field(nx, ny, N, M)) {
                if (f.count(make_pair(ny, nx))) {
                    uf.unite(i, f[make_pair(ny, nx)]);
                }
            } else {
                if (nx == -1) uf.unite(i, K);     // left
                if (ny == -1) uf.unite(i, K + 1); // up
                if (nx == N)  uf.unite(i, K + 2); // right
                if (ny == M)  uf.unite(i, K + 3); // down
            }
        }

        if (uf.same(K, K + 1) ||      // connect left & up
            uf.same(K, K + 2) ||      // connect left & right
            uf.same(K + 1, K + 3) ||  // connect up & down
            uf.same(K + 2, K + 3)) {  // connect right & down
            res = 0;
        }        
    }   
    
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 8; j++) {
            int nx = x[i] + dx[j], ny = y[i] + dy[j];
            if (!in_field(nx, ny, N, M) || f.count(make_pair(ny, nx))) {
                continue;
            }
            vector<bool> fill(4);
            for (int k = 0; k < 8; k++) {
                int nnx = nx + dx[k], nny = ny + dy[k];
                if (nnx == -1) fill[0] = 1; // left
                if (nnx == N)  fill[1] = 1; // up
                if (nny == -1) fill[2] = 1; // right
                if (nny == M)  fill[3] = 1; // down
               
                if (f.count(make_pair(nny, nnx))) {
                    int p = f[make_pair(nny, nnx)];
                    if (uf.same(p, K))     fill[0] = 1; // left
                    if (uf.same(p, K + 1)) fill[1] = 1; // up
                    if (uf.same(p, K + 2)) fill[2] = 1; // right
                    if (uf.same(p, K + 3)) fill[3] = 1; // down
                }
            }

            if ((fill[0] && fill[1]) || // connect left & up
                (fill[0] && fill[2]) || // connect left & right
                (fill[1] && fill[3]) || // connect up & down
                (fill[2] && fill[3])) { // connect right & down
                res = min(res, 1);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
