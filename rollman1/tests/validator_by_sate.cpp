#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

const int MIN_S = 0;
const int MAX_S = 360-1;

const int mod = 3600;

int main() {
    registerValidation();
    int s1 = inf.readInt( MIN_S, MAX_S, "s1" );
    inf.readEoln();
    int s2 = inf.readInt( MIN_S, MAX_S, "s2" );
    inf.readEoln();
    inf.readEof();

    assert( abs( s1 - s2 ) != 180 );

    s1 *= 10; s2 *= 10;
    int res1 = ( s1 + s2 ) / 2; res1 %= mod;
    int res2 = ( s1 + s2 + mod ) / 2; res2 %= mod;

    int t1 = min(abs(s1 - res1), min( abs(s1 - res1 + mod)%mod, abs(res1 - s1 + mod)%mod ) );
    int t2 = min(abs(s1 - res2), min( abs(s1 - res2 + mod)%mod, abs(res2 - s1 + mod)%mod ) );

    if( t1 > t2 ) {
        assert( res2 != 0 );
    } else if( t1 < t2 ) {
        assert( res1 != 0 );
    } else
        assert( false );

}