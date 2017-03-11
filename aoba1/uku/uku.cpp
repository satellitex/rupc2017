#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

using pint = pair<int, int>;
using tint = tuple<int, int, int>;
using vint = vector<int>;

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

#define MAX_N 100000

int N;
int p[MAX_N];
list<int> lis[MAX_N];
int ans[MAX_N];

/*
 * えぇ…。強いデータ構造ってこういうことなの…？
 * 嘘っぽい。
 */

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N;
  rep(i, N) {
    cin >> p[i]; p[i]--;
    lis[p[i]].push_back(i);
  }

  set<int> cha;
  rep(i, N) cha.insert(i);

  set<int> que;
  rep(i, N) if(lis[i].size()) que.insert(i);

  while(cha.size()) {
    int idx = *que.begin(); que.erase(idx);
    int head = lis[idx].front(); lis[idx].pop_front();
    ans[idx] = head; cha.erase(idx);
    if(lis[idx].empty()) continue;
    auto it = cha.upper_bound(idx);
    if(it == cha.end()) it = cha.begin();
    lis[*it].splice(lis[*it].end(), move(lis[idx]));
    que.insert(*it);
  }

  rep(i, N) cout << ans[i]+1 << endl;

  return 0;
}
