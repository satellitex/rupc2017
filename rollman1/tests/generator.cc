#include "testlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <complex>
#include <math.h>

using namespace std;

const double EPS = 0.00000001;

const int NUM_OF_TESTCASES = 30;
const int MAXN = 10;
const int MINN = 1;
const int MAXTHETA = 359;
const int MINTHETA = 0;

bool is_unique(const vector<int> &theta);
bool check_k_sum(complex<double> arg, int size, const vector<int> &theta, vector<int> &used);
bool is_valid(complex<double> arg, const vector<int> &theta, const vector<int> &used);

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int N;
    for (int t = 0; t < NUM_OF_TESTCASES; t++) {
        ofstream of(format("50_random_%02d.in", t+1).c_str());
        N = rnd.next(MINN, MAXN);
        of << N << endl;

        vector<int> theta;
        while(1){
            theta = vector<int>(N);
            for(int i = 0; i < N; i++){
                theta[i] = rnd.next(MINTHETA, MAXTHETA);
            }
            if(is_unique(theta)){
                break;
            }
        }

        for(int i = 0; i < theta.size(); i++){
            of << theta[i] << endl;
        }

        of.close();
    }
    return 0;
}

bool is_unique(const vector<int> &theta){
    if(theta.size() == 1) return true;

    vector<int> used(theta.size());
    for(size_t k = 1; k < theta.size()-1; k++){
        for(int i = 0; i < used.size(); i++) used[i] = false;
        bool ok = check_k_sum(complex<double>((double)0.0, (double)0.0), k, theta, used);
        if(ok == false) return false;
    }
    return true;
}

bool check_k_sum(complex<double> arg, int size, const vector<int> &theta, vector<int> &used){
    if(size == 0){
        is_valid(arg, theta, used);
    }

    bool res = true;
    for(int i = 0; i < theta.size(); i++){
        if(used[i]) continue;
        used[i] = true;
        complex<double> org(arg);
        arg += complex<double>(cos(theta[i]), sin(theta[i]));
        res &= check_k_sum(arg, size-1, theta, used);

        arg = org;
        used[i] = false;
    }
    return res;
}

bool is_valid(complex<double> arg, const vector<int> &theta, const vector<int> &used){
    double theta1 = atan2(arg.imag(), arg.real());
    for(int i = 0; i < theta.size(); i++){
        if(used[i]) continue;
        double theta2 = theta[i];
        /* 角度のまま差が180度ではないか確認（まずそう）
        if( abs(theta1 - theta2) == M_PI ){
            return false;
        }
        */

        /* ベクトルにして確認*/
        complex<double> v1(cos(theta1), sin(theta1));
        complex<double> v2(cos(theta2), sin(theta2));
        complex<double> v_diff = v1 - v2;

        if( abs(v_diff.real()) < EPS && abs(v_diff.imag()) < EPS ){
            cout << "Invalid case has occured. One more loop." << endl;
            return false;
        }
    }
    return true;
}
