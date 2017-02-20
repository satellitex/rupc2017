#include "testlib.h"
#include <iostream>

constexpr int N_MIN = 1;
constexpr int N_MAX = 300000;
constexpr int p_MIN = 1;
constexpr int p_MAX = 300000;

int N;
int p[N_MAX];

void input()
{      
    N = inf.readInt(N_MIN, N_MAX, "N");
    inf.readEoln();

    for (int i = 0; i < N; i++) {
        if (i > 0) {
            inf.readSpace();
        }
        
        p[i] = inf.readInt(p_MIN, std::min(p_MAX, N), format("p[%d]", i + 1));
    }
    
    inf.readEoln();
    inf.readEof();
}

int main()
{
    registerValidation();    
    input();    
    return 0;
}
