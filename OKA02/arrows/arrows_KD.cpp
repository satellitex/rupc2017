#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = tuple<ll, ll>;

struct Node {
    int loc;
    int l, r;
    Node() { loc = l = r = -1; }
    Node(int loc, int l, int r) : loc{loc}, l{l}, r{r} {} 
};

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x{x}, y{y} {}    
};

struct KDTree2D {
    vector<Point> p;
    vector<Node> T;
    int np = 0;
    
    void init() { T.resize(p.size()); }
    
    int make(int l, int r, int depth)
    {
        if (l >= r) return -1;
        
        int mid = (l + r) / 2;
        int curr = np++;
        
        if (depth % 2 == 0) {
            sort(p.begin() + l, p.begin() + r, [](const Point& a, const Point& b) { return a.x < b.x; });
        } else {
            sort(p.begin() + l, p.begin() + r, [](const Point& a, const Point& b) { return a.y < b.y; });
        }
        T[curr] = {mid, make(l, mid, depth + 1), make(mid + 1, r, depth + 1)};        
        return curr;
    }

    void add(P v)
    {
        p.emplace_back(get<0>(v), get<1>(v));
    }    

    bool find(int k, ll sx, ll sy, ll tx, ll ty, int depth)
    {
        ll x = p[T[k].loc].x;
        ll y = p[T[k].loc].y;
        
        if (sx <= x && x <= tx && sy <= y && y <= ty) {
            return 1;
        }
        
        ll res = 0;
        if (depth % 2 == 0) {
            if (T[k].l != -1 && sx <= x) {
                res |= find(T[k].l, sx, sy, tx, ty, depth + 1);
            }

            if (T[k].r != -1 && x <= tx) {
                res |= find(T[k].r, sx, sy, tx, ty, depth + 1);
            }
        } else {
            if (T[k].l != -1 && sy <= y) {
                res |= find(T[k].l, sx, sy, tx, ty, depth + 1);
            }

            if (T[k].r != -1 && y <= ty) {
                res |= find(T[k].r, sx, sy, tx, ty, depth + 1);
            }
        }        
        return res;
    }
};

P sum(const P& a, const P& b)
{
    return {get<0>(a) + get<0>(b), get<1>(a) + get<1>(b)};
}

bool find(KDTree2D& kd, int root, ll l, ll r, ll dx = 0, ll dy = 0)
{
    ll sx = l - dx, tx = r - dx;
    ll sy = l - dy, ty = r - dy;
    return kd.find(root, sx, sy, tx, ty, 0);
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
    
    KDTree2D kd;
    for (P& v0 : p[0]) {
        for (P& v1 : p[1]) {            
            kd.add(sum(v0, v1));           
        }
    }
    
    kd.init();
    int root = kd.make(0, kd.p.size(), 0);
    bool res = find(kd, root, A, B);
    for (P& v2 : p[2]) {
        for (P& v3 : p[3]) {
            for (P& v4 : p[4]) {
                P s = sum(sum(v2, v3), v4);
                res |= find(kd, root, A, B, get<0>(s), get<1>(s)); 
            }            
        }    
    }
    cout << (res ? "Yes" : "No") << endl;
    return 0;
}
