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

bool in_field(int x, int y, int N, int M)
{
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool is_connect(int x, int y, int N, int M)
{
    if (x == 0 && y == 0) return 0; // start
    if (x == N - 1 && y == M - 1) return 0; // goal    
    return 1;
}

bool check(int x, int y, int N, int M)
{    
    return is_connect(x, y, N, M) && in_field(x, y, N, M);
}

int main()
{    
    map<pair<int, int>, int> f;
    
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<int> x(K), y(K);
    
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &x[i], &y[i]);
        f[{y[i], x[i]}] = i;        
    }
    
    constexpr int dx[] = {-1, -1, -1, +0, +0, +1, +1, +1};
    constexpr int dy[] = {-1, +0, +1, -1, +1, -1, +0, +1};
    
    Union_Find uf(K + 4);    
    int res = 2;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 8; j++) {
            int nx = x[i] + dx[j], ny = y[i] + dy[j];
            if (check(nx, ny, N, M)) {
                if (f.count({ny, nx})) {
                    uf.unite(i, f[{ny, nx}]);
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
            if (!check(nx, ny, N, M) || f.count({ny, nx})) {
                continue;
            }
            vector<bool> fill(4);
            for (int k = 0; k < 8; k++) {
                int nnx = nx + dx[k], nny = ny + dy[k];
                if (!is_connect(nnx, nny, N, M)) continue;
                if (nnx == -1) fill[0] = 1; // left               
                if (nny == -1) fill[1] = 1; // up
                if (nnx == N)  fill[2] = 1; // right
                if (nny == M)  fill[3] = 1; // down

                if (f.count({nny, nnx})) {
                    int p = f[{nny, nnx}];                                    
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
