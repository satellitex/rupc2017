#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main()
{
    int N;
    cin >> N;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        q.push(make_pair(p - 1, i + 1));
    } 
    
    vector<int> seat(N, -1);
    while (!q.empty()) {
        pair<int, int> n = q.front(); q.pop();
        int p, num;
        tie(p, num) = n;

        if (seat[p] == -1) {
            seat[p] = num;
        } else {
            q.push(make_pair((p + 1) % N, num));
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << seat[i] << endl;
    }        
    return 0;
}
