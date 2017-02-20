#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int power(int a, int x)
{
  int b = 1;
  rep(i, x) b *= a;
  return b;
}

bool solve(int num[], int idx)
{
  if(idx == 1 && num[idx] == 1) {
    printf("(x%+d)", num[0]);
    return true;
  }
  else if(idx == 1) return false;
  for(int x = -10000; x <= 10000; x++) {
    int ans = 0;
    rep(i, idx+1) ans += power(x, i)*num[i];
    if(ans == 0) {
      int tmp[10]={}, tmp2[10]={};
      rep(i, idx+1) tmp[i] = num[i];
      rep(i, idx+1) tmp2[i] = num[i];
      for(int i = idx; i >= 0; i--) {
	tmp[i] = tmp2[i+1];
	tmp2[i] -= (-x)*tmp[i];
      }
      if(solve(tmp, idx-1)) {
	printf("(x%+d)", -x);
	return true;
      }
    }
  }
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  char s[128], t[128];
  strcpy(s, "+1");
  scanf("%s", s+2);
  int len = strlen(s);
  rep(i, len) {
    if(s[i] == 'x') {
      if(s[i-1] == '+' || s[i-1] == '-') {
	strcpy(t, s+i);
	sprintf(s+i, "1%s", t);
	len++; i++;
      }
      if(s[i+1] != '^') {
	strcpy(t, s+i+1);
	sprintf(s+i, "x^1%s", t);
	len+=2; i+=2;
      }
    }
  }
  strcat(s, "x^0");
  char a[128], b[128];
  int num[10]={}, of = 0;
  int mx = 0;
  //puts(s);
  while(sscanf(s + of, "%[^x]x^%[^+-]", a, b) != EOF) {
    of += strlen(a) + 2 + strlen(b);
    num[atoi(b)] = atoi(a);
    mx = max(mx, (int)atoi(b));
  }
  solve(num, mx);
  puts("");

  return 0;
}
