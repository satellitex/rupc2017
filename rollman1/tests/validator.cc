#include "testlib.h"

using namespace std;

const int NUM_OF_THETA = 2;
const int MAXTHETA = 359;
const int MINTHETA = 0;

void input(int theta[2]){
    for (int i = 0; i < NUM_OF_THETA; i++) {
        theta[i] = inf.readInt(MINTHETA, MAXTHETA, format("theta[%d]", i + 1));
        inf.readEoln();
    }
    inf.readEof();
}

void check(int theta[2]){
    ensuref(!(abs(theta[0] - theta[1]) == 180), "|theta1 - theta2| must not be 180 degree.");
}

int main() {
    int theta[NUM_OF_THETA];
    registerValidation();

    input(theta);

    check(theta);

    return 0;
}
