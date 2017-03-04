#include <bits/stdc++.h>
using namespace std;

const double EPS = 0.0001;

bool eq(double a, double b){
    return abs(a - b) < EPS;
}

struct PLAYER{
    int idx;
    double gpa;
    int point;
    bool operator<(const PLAYER o)const{
        if(eq(gpa, o.gpa)) return false;
        return gpa < o.gpa;
    }
};

bool idx_lt(const PLAYER a, const PLAYER b){
    if(eq(a.idx, b.idx)) return false;
    return a.idx < b.idx;
}

bool gt(const PLAYER a, const PLAYER b){
    if(eq(a.gpa, b.gpa)) return false;
    return a.gpa > b.gpa;
}

int main(void){
    int N; cin >> N;
    vector<PLAYER> p(N);
    for(int i = 0; i < N; i++){
        p[i].idx = i;
        cin >> p[i].gpa;
        p[i].point = 0;
    }
    sort(p.begin(), p.end());
    vector<PLAYER> reved(p);
    reverse(reved.begin(), reved.end());

    for(int i = 0; i < N; i++){
        vector<PLAYER>::iterator up = upper_bound(p.begin()+i, p.end(), p[i]);
        int pos;
        pos = (up - (p.begin() + i)) - 1;
        p[i].point += pos;
        int rev_i = N - i - 1;
        vector<PLAYER>::iterator low = upper_bound(reved.begin() + rev_i, reved.end(), reved[rev_i], gt);
        pos = (low - (reved.begin() + rev_i)) - 1;
        p[i].point += pos;

        pos = (reved.end() - low) * 3;
        p[i].point += pos;
    }

    sort(p.begin(), p.end(), idx_lt);
    for(int i = 0; i < N; i++) cout << p[i].point << endl;
    return 0;
}
