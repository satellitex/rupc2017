#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct SegmentTree {
    int N;
    vector<vector<int>> s;
    vector<int> rn;
    
    SegmentTree(int N_) {            
        N = 1;
        while (N < N_) {
            N *= 2;
        }
        
        s.assign(N * 2 + 1, vector<int>(10, 0));
        rn.assign(N * 2 + 1, 0);
        
        for (int i = 0; i < N; i++) {
            s[i + N - 1][0] = 1;
        }

        for (int i = N - 2; i >= 0; i--) {
            s[i][0] = s[i * 2 + 1][0] + s[i * 2 + 2][0];
        }
    }
        
    void push(int k)
    {
        if (rn[k] == 0) return;
        
        int next[10];
        for (int i = 0; i < 10; i++) {
            next[(i + rn[k]) % 10] = s[k][i];
        }

        for (int i = 0; i < 10; i++) {
            s[k][i] = next[i];
        }       
        
        if (k < N) {
            rn[k * 2 + 1] += rn[k];
            rn[k * 2 + 2] += rn[k];
        }

        rn[k] = 0;
    }
    
    void update(int k)
    {
        for (int i = 0; i < 10; i++) {
            s[k][i] = s[k * 2 + 1][i] + s[k * 2 + 2][i];            
        }
    }

    void rot(int a, int b, int k, int l, int r, int p)
    {
        push(k);
        
        if (r <= a || b <= l) {
            return;
        } else if (a <= l && r <= b) {            
            rn[k] = (rn[k] + p) % 10;
            push(k);
        } else {
            rot(a, b, k * 2 + 1, l, (l + r) / 2, p);
            rot(a, b, k * 2 + 2, (l + r) / 2, r, p);
            update(k);
        }    
    }

    int sum(int a, int b, int k, int l, int r, int c)
    {
        push(k);

        if (r <= a || b <= l) {
            return 0;
        } else if (a <= l && r <= b) {
            return s[k][c];
        } else {    
            int vl = sum(a, b, k * 2 + 1, l, (l + r) / 2, c);
            int vr = sum(a, b, k * 2 + 2, (l + r) / 2, r, c);
            update(k);
            return vl + vr;
        }
    }

    void rot(int l, int r, int p)
    {
        rot(l, r, 0, 0, N, p);
    }

    int sum_c(int l, int r, int c)
    {
        return sum(l, r, 0, 0, N, c);
    }
};

vector<vector<int>> G;
vector<int> L, R;

void dfs(int curr)
{
    static int k = 0;
    L[curr] = k++;
    for (int next : G[curr]) {
        dfs(next);
    }        
    R[curr] = k;
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    G.resize(N); L.resize(N); R.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
    }
    
    dfs(0);
    SegmentTree seg(N);
    for (int i = 0; i < Q; i++) {
        int t, r, s;
        scanf("%d %d %d", &t, &r, &s);
        if (t == 1) {
            s = (s + 10) % 10;
            seg.rot(L[r], R[r], s);
        } else {
            printf("%d\n", seg.sum_c(L[r], R[r], s));
        }
    }
    
    return 0;
}
