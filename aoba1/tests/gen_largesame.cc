#include "testlib.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    constexpr int N_MIN = 100000;
    constexpr int N_MAX = 300000;
    
    int N;
    for (int t = 0; t < 10; t++) {
        std::ofstream of(format("04_largesame_%02d.in", t + 1).c_str());
        N = rnd.next(N_MIN, N_MAX);        
        of << N << std::endl;

        int num = rnd.next(3, 10);
        
        std::vector<int> v;
        std::vector<bool> used(N);        
        for (int i = 0; i < num; i++) {            
            int n;
            do {
                n = rnd.next(1, N);
            } while (used[n - 1]);
            
            used[n - 1] = 1;
            v.emplace_back(n);
        }
        
        for (int j = 0; j < N; j++) {
            if (j > 0) {
                of << " ";
            }
            
            int p;
            p = rnd.next(0, num - 1);
            of << v[p];
        }
        
        of << std::endl;
    }

    return 0;
}
