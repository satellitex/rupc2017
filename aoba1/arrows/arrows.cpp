#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, p;
    scanf("%d", &N);
    
    vector<int> s(N, -1);    
    vector<stack<int>> G(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &p);
        s[p - 1] += 1;
        G[p - 1].push(i);
    }

    for (int i = 1; i < N; i++) {
        s[i] += s[i - 1];
    }
    
    int min = N, min_idx = -1;
    for (int i = 0; i < N; i++) {
        if (s[i] < min) {
            min = s[i];
            min_idx = i;
        }
    }

    min_idx = (min_idx + 1) % N;
    
    vector<int> res(N);
    stack<int> st;
    for (int i = 0; i < N; i++) {
        int p = (i + min_idx) % N;
        while (!G[p].empty()) {
            int t = G[p].top();
            G[p].pop();
            st.push(t);            
        }
        res[p] = st.top();
        st.pop();
    }

    for (int num : res) {
        printf("%d\n", num + 1);
    }    
    return 0;
}
