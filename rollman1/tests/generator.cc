#include "testlib.h"

const int NUMBER_OF_THETA = 2;
const int NUM_OF_TESTCASES = 30;
const int MAXTHETA = 359;
const int MINTHETA = 0;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    for(int t = 0; t < NUM_OF_TESTCASES; t++){
        std::ofstream of(format("50_random_%02d.in", t+1).c_str());
        int theta[NUMBER_OF_THETA];
        while(1){
            for(int i = 0; i < NUMBER_OF_THETA; i++){
                theta[i] = rnd.next(MINTHETA, MAXTHETA);
            }

            if( std::abs(theta[0] - theta[1]) == 180 || theta[0] + theta[1] == 360 ){
            }else{
                break;
            }
        }

        for(int i = 0; i < NUMBER_OF_THETA; i++){
            of << theta[i] << std::endl;
        }

        of.close();
    }
    return 0;
}
