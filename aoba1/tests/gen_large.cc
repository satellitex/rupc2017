#include "testlib.h"
#include <iostream>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    constexpr int N_MIN = 100000;
    constexpr int N_MAX = 300000;
    
    int N;
    for (int t = 0; t < 3; t++) {
        std::ofstream of(format("03_large_%02d.in", t + 1).c_str());
        N = rnd.next(N_MIN, N_MAX);
        
        of << N << std::endl;
        for (int j = 0; j < N; j++) {
            if (j > 0) {
                of << " ";
            }
            
            int p;
            p = rnd.next(1, N);
            of << p;
        }
        
        of << std::endl;
    }

    return 0;
}
