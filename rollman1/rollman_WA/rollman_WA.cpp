#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N = 2;
	double ans = 0.0;
	for(int i = 0; i < N; i++){
		int arg; cin >> arg;
		ans += arg;
	}
	cout << ans / N << endl;
	return 0;
}
