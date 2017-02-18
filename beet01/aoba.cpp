#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    constexpr int MAX = 4010;
    vector<int> a(N), s(MAX);
    for (int i = 0; i < N; i++) {
        double in;
        cin >> in;
        a[i] = in * 1000;
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
