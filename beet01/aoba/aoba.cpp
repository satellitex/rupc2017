#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    constexpr int MAX = 4010;
    vector<int> a(N), s(MAX);
    for (int i = 0; i < N; i++) {
        string in;
        cin >> in;
        a[i] = (stoi(in.substr(0, 1)) * 1000 + stoi(in.substr(2)));
        s[a[i]] += 1;
    }
    
    for (int i = 1; i < MAX; i++) {
        s[i] += s[i - 1];
    }
    
    for (int i = 0; i < N; i++) {
        int d = s[a[i]] - (a[i] > 0 ? s[a[i] - 1] : 0);
        int w = (a[i] > 0 ? s[a[i] - 1] : 0);
        cout << (d - 1) + w * 3 << endl;
    }        
    return 0;
}
