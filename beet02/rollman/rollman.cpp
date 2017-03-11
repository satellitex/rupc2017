#include <bits/stdc++.h>
using namespace std;

const int NO_COEFFICIENT = 123456;


int main(void){
	string S;
	cin >> S;
	int idx = 0;
	int term = 0;
	vector<int> coefficients(6, 0);
	while(idx < S.length()){
		int coefficient = NO_COEFFICIENT;
		int sign = 1;
		if(S.at(idx) == '+' || S.at(idx) == '-'){
			if(S.at(idx) == '+') sign = 1;
			else sign = -1;
			idx++;
		}
		while(idx < S.length() && isdigit(S.at(idx))){
			if(coefficient == NO_COEFFICIENT){
				coefficient = S.at(idx) - '0';
			}else{
				coefficient *= 10;
				coefficient += S.at(idx) - '0';
			}
			idx++;
		}
		coefficient *= sign;
		int degree = -1;
		if(idx < S.length() && S.at(idx) == 'x'){
			idx++;
			if(S.at(idx) == '^'){
				idx++;
				degree = S.at(idx) - '0';
			}else{
				degree = 1;
				idx--;
			}
		}else{
			degree = 0;
		}
		idx++;
		if(coefficient != NO_COEFFICIENT){
			coefficients.at(degree) = coefficient;
		}else{
			coefficients.at(degree) = 1;
		}
	}

/*
	for(int i = 5; i >= 0; i--){
		cout << coefficients[i] << "x^" << i << endl;
	}
*/

	vector<int> ans;
	for(int c = -2000; c <= 2000; c++){
		int product = 0;
		for(int i = 0; i < coefficients.size(); i++){
			product += coefficients.at(i) * pow(c, i);
		}
		if(product == 0){
			ans.push_back(c);
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for(int i = 0;  i< ans.size(); i++){
		cout <<"(x";
		if(ans.at(i) < 0){
			cout << '+';
			ans.at(i) *= -1;
		}
		else{
			ans.at(i) *= -1;
		}
		cout << ans.at(i) << ")";
	}
	cout << endl;
}
