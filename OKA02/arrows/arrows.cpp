#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<ll, ll>;

P sum(const P& a, const P& b)
{
    return {get<0>(a) + get<0>(b), get<1>(a) + get<1>(b)};
}

void add(vector<P>& XY, vector<P>& YX, P v)
{
    XY.emplace_back(v);
    YX.emplace_back(P{get<1>(v), get<0>(v)});
}

bool find(const vector<P>& v, int lb, int ub, ll l, ll r)
{
    for (int i = lb; i < ub; i++) {
        ll z = get<1>(v[i]);
        if (l <= z && z <= r) {
            return 1;
        }
    }
    return 0;
}

bool find(const vector<P>& XY, const vector<P>& YX,
          ll l, ll r, ll dx = 0, ll dy = 0)
{
    ll xl = l - dx, xr = r - dx;
    ll yl = l - dy, yr = r - dy;

    int x_lb = lower_bound(XY.begin(), XY.end(), P{xl, yl}) - XY.begin();
    int x_ub = upper_bound(XY.begin(), XY.end(), P{xr, yr}) - XY.begin();
    
    int y_lb = lower_bound(YX.begin(), YX.end(), P{yl, xl}) - YX.begin(); 
    int y_ub = upper_bound(YX.begin(), YX.end(), P{yr, xr}) - YX.begin();   
    
    return x_ub - x_lb < y_ub - y_lb ?
                         find(XY, x_lb, x_ub, yl, yr) : find(YX, y_lb, y_ub, xl, xr);
}

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    vector<vector<P>> p{5};
    for (int i = 0; i < N; i++) {
        ll t, x, y;
        cin >> t >> x >> y;
        p[t - 1].emplace_back(x, y);
    }

    for (int i = 0; i < 5; i++) {
        p[i].emplace_back(0, 0);
        sort(p[i].begin(), p[i].end());
        p[i].erase(unique(p[i].begin(), p[i].end()), p[i].end());
    }

    sort(p.begin(), p.end(),
         [](const vector<P>& a, const vector<P>& b) { return a.size() > b.size(); });
    
    vector<P> XY, YX;
    for (P& v0 : p[0]) {        
        for (P& v1 : p[1]) {            
            add(XY, YX, sum(v0, v1));            
        }
    }
   
    sort(XY.begin(), XY.end());
    sort(YX.begin(), YX.end());
    
    bool res = find(XY, YX, A, B);
    for (P& v2 : p[2]) {
        for (P& v3 : p[3]) {        
            for (P& v4 : p[4]) {
                P s = sum(sum(v2, v3), v4);
                res |= find(XY, YX, A, B, get<0>(s), get<1>(s));            
            }
        }
    }

    cout << (res ? "Yes" : "No") << endl;
    return 0;
}
