#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
/*
3 ≦ N ≦ 20000

1 ≦ |N個それぞれの集合に含まれている整数の値| ≦ 22
*/

const int MIN_N = 3;
const int MAX_N = 20000;
const int MIN_A = 1;
const int MAX_A = 22;
const int MIN_K = 1;
const int MAX_K = 22;

int main() {
    registerValidation();
    int N = inf.readInt( MIN_N, MAX_N, "N" );
    inf.readEoln();
    for(int i=0;i<N;i++) {
        int k = inf.readInt( MIN_K, MAX_K, "K" );
        int p = 0;
        for(int j=0;j<k;j++){
            inf.readSpace();
            int a = inf.readInt( MIN_A, MAX_A );
            assert( p < a );
            p = a;
        }
        inf.readEoln();
    }
    inf.readEof();
}