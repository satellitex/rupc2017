#include <bits/stdc++.h>
using namespace std;

int main(void){
	int N; cin >> N;
	double x  = 0, y = 0;

	for(int i = 0; i < N; i++){
		int arg; cin >> arg;
		x += cos(arg * 2.0*M_PI / 360.0); y += sin(arg * 2.0*M_PI / 360.0);
	}

	// Not absolutely required.
	x = x / N; y = y / N;

	cout << atan2(y, x) * 360.0 / (2.0*M_PI) << endl;
	return 0;
}
