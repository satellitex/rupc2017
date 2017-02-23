#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_P = 100000;

int dp[2][MAX_P + 1][2];

int main()
{
    int N, P;
    scanf("%d %d", &N, &P);
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0][P][0] = 0;
    
    for (int i = 0; i < N; i++) {
        int nxt = !(i & 1), cur = (i & 1);
        for (int j = 0; j <= P; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[cur][j][k] == -1) continue;
                dp[nxt][j][0] = max(dp[nxt][j][0], dp[cur][j][k] + (X[i] >= Y[i]));
                
                int mot = max(0, X[i] - (k == 0 ? 0 : (Y[i - 1] - X[i - 1])));               
                int nj = j - (Y[i] - mot);
                if (nj >= 0) {
                    dp[nxt][nj][1] = max(dp[nxt][nj][1], dp[cur][j][k] + 1);
                }
            }
        }
        for (int j = 0; j <= P; j++) {
            for (int k = 0; k < 2; k++) {
                dp[cur][j][k] = dp[nxt][j][k];
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i <= P; i++) {
        for (int j = 0; j < 2; j++) {
            res = max(res, dp[N & 1][i][j]);
        }
    }

    printf("%d\n", res);
    return 0;
}
