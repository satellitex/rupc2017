#include <bits/stdc++.h>
using namespace std;

struct state {
    int x,y,id;
    state(){}
    state(int x,int y,int id):x(x),y(y),id(id){}
    bool operator<(const state& st) const {
        return (st.x==x)?y<st.y:x<st.x;
    }
};

int N,K;
vector<state> ps;
vector<int> G[100005];
int ind[100005];
bool conf[100005];
int used[100005];

bool ume(int v){
    if( used[v] != 0 ) return false;
    for( int nv : G[v] ) {
        if( conf[nv] ) return false;
        if( used[nv] == 1 ) return false;
    }
    used[v] = 1;
    for( int nv : G[v] )
        used[nv] = -1;
    return true;
}

bool solve(int v){
    fill( used, used+N, 0 );
    if( !ume(v) ) return false;
    int cnt = 1;
    for(int i=0;i<N;i++){
        if( ume(i) ) cnt++;
        if( conf[i] && used[i] != 1 ) return false;
    }
    return cnt >= K;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        int a,b; cin >> a >> b;
        ps.emplace_back( a, b, i );
    }

    sort( ps.begin(), ps.end() );
    for(int i=0;i<N;i++) {
        ind[ps[i].id] = i;
        for(int dx=-1;dx<=1;dx++){
            for(int dy=-1;dy<=1;dy++){
                if( dx == 0 && dy == 0 ) continue;
                int nx = ps[i].x + dx, ny = ps[i].y + dy;
                auto it = lower_bound( ps.begin(), ps.end(), state( nx, ny, -1 ) );
                if( it == ps.end() ) continue;
                if( nx == it->x && ny == it->y ){
                    //cout << ps[i].x << " " << ps[i].y << "  "<< ps[i].id << endl;
                    //cout << " -> " << it->x << " " << it->y << " "<<it->id << endl;
                    G[i].emplace_back( it-ps.begin() );
                }

            }
        }
    }

    vector<int> res;
    for(int i=0;i<N;i++){
        if( solve(ind[i]) ) {
            conf[ind[i]] = true;
            res.emplace_back(i+1);
        }
    }
    if( res.size() >= K ) {
        for( int i=0;i<K;i++){
            cout<<res[i] << endl;
            //cout << " " << ps[ ind[res[i]-1] ].x << " " << ps[ ind[res[i]-1] ].y << endl;
        }

    } else
        cout << -1 << endl;



}