#include "testlib.h"

const int N_MIN =    2;
const int N_MAX = 6000;
const int K_MIN =    2;
const int K_MAX = 6000;
const int xy_MIN =       1;
const int xy_MAX = 1000000;

void input(int& N, int& K, std::vector<int>& x, std::vector<int>& y){
	N = inf.readInt(N_MIN, N_MAX, "N");
	inf.readSpace();
	K = inf.readInt(K_MIN,     N, "K");
	inf.readEoln();

	x = std::vector<int>(N);
	y = std::vector<int>(N);

	for(int i = 0; i < N; i++){
		x[i] = inf.readInt(xy_MIN, xy_MAX, format("x[%d]", i+1));
		inf.readSpace();
		y[i] = inf.readInt(xy_MIN, xy_MAX, format("y[%d]", i+1));
		inf.readEoln();
	}
	inf.readEof();
}

void check(const int& N, const int& K, const std::vector<int>& x, const std::vector<int>& y){
	// x_i mod 2 = floor( y_i ÷ 2 ) mod 2   ( 1 <= i <= N )
	for(int i = 0; i < N; i++){
		ensuref(x[i] % 2 == (int)(y[i] / 2) % 2,
			"x_i mod 2 = floor( y_i ÷ 2) mod 2. (x[%d],y[%d])=(%d,%d)", i, i, x[i], y[i]);
	}

	// 同じ座標に複数の空き地が存在することはない。
	// x_i != x_j      or     y_i != y_j ( 1<= i < j <= N )
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			ensuref(x[i] != x[j] || y[i] != y[j],
				"Two or more buildings never stand at a same coordinate. %d, %d", i, j);
		}
	}

}

int main(void){
	int N;
	int K;
	std::vector<int> x;
	std::vector<int> y;
	
	registerValidation();

	input(N, K, x, y);

	check(N, K, x, y);

	return 0;
}
