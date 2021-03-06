#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N = 2;
	double x  = 0, y = 0;

	for(int i = 0; i < N; i++){
		int arg; cin >> arg;
		x += cos(arg * 2.0*M_PI / 360.0); y += sin(arg * 2.0*M_PI / 360.0);
	}

	// Not absolutely required.
	x = x / N; y = y / N;

    double ans = atan2(y, x) * 180.0 / (M_PI);
    if(ans < 0){
        ans = 360.0 + ans;
    }
    cout << setprecision(10) << ans + (1e-5)<< endl;
	return 0;
}
