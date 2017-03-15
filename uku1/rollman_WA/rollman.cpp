#include <bits/stdc++.h>
using namespace std;
int n, m;
const double D_INF = 1e8;
const int C_INF = 1e8;

struct A{
    public:
    int dest;
    int c;
    int t;
    A(){dest = 0; c = 0; t = 0;}
    A(int dest, int c, int t){
        this->dest = dest;
        this->c = c;
        this->t = t; }
};

bool all_used(vector<int>& used){
    for(int i = 0; i < n; i++){
        if(used[i] == false) return false;
    }
    return true;
}

int dfs(int pos, vector< vector<A> > &v, int t, int D, int c, vector<int> &used){

    used[pos] = true;
    int res = D_INF;
    for(int i = 0; i < n; i++){
        if(used[i] == true) continue;
        if(all_used(used)){
            return 0;
        }else{
            return D_INF;
        }
        int next_t;
        for(int j = 0; j < v[i].size(); i++){
            if(v[i][j].dest == pos){
                next_t = v[i][j].t;
            }
        }
        res = min(res, dfs(i, v, t+next_t, D, c, used));
    }
    return res;
}

bool solve(vector< vector<A> > &v, int D, int c){
    int ans=D_INF;
    vector<int> used(n, false);
    for(int i = 0; i < n; i++){
        ans = min(ans, dfs(i, v, 0, D, c, used));
    }
    return (double)ans/(double)c <= D;
}

bool check(vector< vector< A > > &v, int D){
    int l = 0, r = C_INF;
    while(l + 1 < r){
        int mid = (l+r) / 2;
        if(solve(v, D, mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l <= D;
}

int main(void){
    vector< vector< A > > v;
    cin >> n >> m;
    v = vector< vector< A > >(n, vector< A >(0));
    for(int i = 0; i < m; i++){
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        v.at(a).push_back(A(b, c, t));
        v.at(b).push_back(A(a, c, t));
    }
    double l = 0.0, r = D_INF;
    for(int asd = 0; asd < 1000; asd++){
        double mid = (l+r) / 2.0;
        if(check(v, mid)){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
}
