#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

pair<int, int> item(const string& s)
{
    int N = s.size(), cur = 0;
    string coef, expo;
    bool xf = 0;
    
    while (cur < N && s[cur] != 'x') {
        coef += s[cur++];
    }
    
    xf = (cur < N && s[cur] == 'x');
    cur += (cur + 1 < N && s[cur + 1] == '^' ? 2 : 1);

    while (cur < N) {
        expo += s[cur++];
    }

    coef = (coef.empty() ? "1" : coef);
    expo = (expo.empty() ? (xf ? "1" : "0") : expo);
    
    return make_pair(stoi(coef), stoi(expo)); 
}

int main()
{
    string s, t;
    cin >> s;
    
    using ll = long long;
    vector<char> op;
    vector<pair<ll, ll>> f;
    
    ll N = 0;
    for (char c : s) {
        if (c == '+' || c == '-') {
            f.emplace_back(item(t));
            op.emplace_back(c);
            
            N = max(N, f.back().second);
            t.clear();
        } else {
            t += c;            
        }
    }    
    f.emplace_back(item(t));
    
    for (ll i = 2525, cnt = 0; cnt < N; i--) {        
        ll res = f[0].first * pow(i, f[0].second);
        for (int j = 1; j < (int)f.size(); j++) {
            if (op[j - 1] == '+') {
                res += f[j].first * pow(i, f[j].second);
            } else {
                res -= f[j].first * pow(i, f[j].second);
            }
        }
        if (res == 0) {
            cnt += 1;
            cout << "(x" << (i > 0 ? "-" : "+") << to_string(abs(i)) + ")";
        }
    }
    cout << endl;
    return 0;
}
