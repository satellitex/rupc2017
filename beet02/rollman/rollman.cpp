#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll NO_COEFFICIENT = 123456;


int main(void){
	string S;
	cin >> S;
	ll idx = 0;
	ll term = 0;
	vector<ll> coefficients(6, 0);
	while(idx < S.length()){
		ll coefficient = NO_COEFFICIENT;
		ll sign = 1;
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
        if(coefficient != NO_COEFFICIENT)
            coefficient *= sign;
		ll degree = -1;
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
			coefficients.at(degree) = sign*1;
		}
	}

    /*
	for(ll i = 5; i >= 0; i--){
		cout << coefficients[i] << "x^" << i << endl;
	}
    */

	vector<ll> ans;
	for(ll c = -2000; c <= 2000; c++){
		ll product = 0;
		for(ll i = 0; i < coefficients.size(); i++){
			product += coefficients.at(i) * pow(c, i);
		}
		if(product == 0){
			ans.push_back(c);
		}
	}
	sort(ans.begin(), ans.end(), greater<ll>());
	for(ll i = 0;  i< ans.size(); i++){
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
