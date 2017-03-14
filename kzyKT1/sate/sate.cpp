#include <bits/stdc++.h>
using namespace std;

struct uni {
    int d[200015];
    int find( int a ) { return d[a]<0?a:(d[a]=find(d[a])); }
    void init(){ memset( d,-1,sizeof(d) ); }
    bool merge(int a,int b){
        a = find(a); b = find(b);
        if( a == b ) return false;
        if( d[a] > d[b] ) swap( a, b );
        d[a] += d[b]; d[b] = a;
        return true;
    }
    bool same(int a,int b){
        return find(a) == find(b);
    }
};

int n,m,K;
int S,T;
typedef pair<int,int> P;

bool checkS(int x,int y){
    return x == 0 || y == m - 1;
}
bool checkT(int x,int y){
    return x == n - 1 || y == 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> K;
    map<P, int> fie;
    vector<P> ps;
    S = K;
    T = K + 1;
    uni U; U.init();
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        if ( checkS(x,y) ) U.merge(S, i);
        if ( checkT(x,y) ) U.merge(T, i);
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = x + dx, ny = y + dy;
                if( 0 > nx || n <= nx || 0 > ny || m <= ny ) continue;
                if (fie.count(P(nx, ny)))
                    U.merge(i, fie[P(nx, ny)]);
                else
                    ps.emplace_back( nx, ny );
            }
        }
        fie[P(x, y)] = i;
    }
    if (U.same(S, T)) {
        cout << 0 << endl;
    } else if (fie.count(P(0, 1)) || fie.count(P(1, 0)) ||
               fie.count(P(n - 1, m - 2)) || fie.count(P(n - 2, m - 1))) {
        cout << 1 << endl;
    } else {
        sort( ps.begin(), ps.end() );
        ps.erase( unique( ps.begin(), ps.end() ), ps.end() );
        for( P p : ps ) {
            int st = 0;
            if( checkS(p.first,p.second) ) st|= 1;
            if( checkT(p.first,p.second) ) st|= 2;
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    P np = P( p.first + dx, p.second + dy );
                    if( fie.count(np) ) {
                        if( U.same( fie[np], S ) ) st |= 1;
                        if( U.same( fie[np], T ) ) st |= 2;
                    }
                }
            }
            if( st == 3 ) {
                cout << 1 << endl;
                return 0;
            }
        }
        cout << 2 << endl;
    }
}