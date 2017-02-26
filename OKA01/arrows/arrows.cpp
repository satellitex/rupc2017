#include <bits/stdc++.h>

using namespace std;

void update(int& l, int r)
{
    if (l < r) l = r;
}

int main()    
{
    int N, P;
    scanf("%d %d", &N, &P);
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &Y[i]);        
    }
    
    vector<vector<int>> p(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {                        
            int np = 0, pp = 0;
            for (int k = i; k <= j; k++) {
                int mot = max(0, X[k] - pp);
                np += pp = max(0, Y[k] - mot);                
            }            
            p[i][j] = np;
        }
    }
    
    int dp[838][252][2];
    memset(dp, -1, sizeof(dp));
    dp[0][0][1] = P;    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[i][j][k] == -1) continue;

                update(dp[i + 1][j][1], dp[i][j][k]);
                
                if (k == 0) continue;
                for (int l = 0; l < N - i; l++) {                    
                    int np = dp[i][j][k] - p[i][i + l];
                    if (np >= 0) {
                        update(dp[i + l + 1][j + l + 1][0], np);
                    }
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            if (dp[N][i][j] >= 0) {
                update(res, i);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
