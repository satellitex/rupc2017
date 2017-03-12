#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<ll, ll>;

P sum(const P& a, const P& b)
{
    return {get<0>(a) + get<0>(b), get<1>(a) + get<1>(b)};
}

bool find(const vector<P>& v, int lb, int ub, ll l, ll r)
{
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        ll m = get<1>(v[mid]);
        
        if (l <= m && m <= r) {
            return 1;
        }
        (l < m ? lb : ub) = mid;
    }
    return 0;
}

bool find(const vector<P>& XY, ll l, ll r, ll dx = 0, ll dy = 0)
{
    ll xl = l - dx, xr = r - dx;
    ll yl = l - dy, yr = r - dy;
    int x_lb = lower_bound(XY.begin(), XY.end(), P{xl, yl}) - XY.begin();
    int x_ub = upper_bound(XY.begin(), XY.end(), P{xr, yr}) - XY.begin();    
    return find(XY, x_lb, x_ub, yl, yr);
}

int main()
{
    ll N, A, B, t, x, y;
    cin >> N >> A >> B;
    vector<vector<P>> p{5};
    for (int i = 0; i < N; i++) {
        cin >> t >> x >> y;
        p[t - 1].emplace_back(x, y);
    }

    for (int i = 0; i < 5; i++) {
        p[i].emplace_back(0, 0);
    }

    sort(p.begin(), p.end(),
         [](const vector<P>& a, const vector<P>& b) { return a.size() > b.size(); });
    
    vector<P> XY, YX;
    for (P& v0 : p[0]) {        
        for (P& v1 : p[1]) {            
            XY.emplace_back(sum(v0, v1));
        }
    }
   
    sort(XY.begin(), XY.end());
    
    auto solve = [&]() {
        for (P& v2 : p[2]) {
            for (P& v3 : p[3]) {        
                for (P& v4 : p[4]) {
                    P s = sum(sum(v2, v3), v4);
                    if (find(XY, A, B, get<0>(s), get<1>(s))) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    };

    cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}
