#include "testlib.h"

using namespace std;

const int MIN_N = 1;
const int MAX_N = 100;
const int MIN_M = 1;
const int MAX_M = 100;
const int MIN_H = 1;
const int MAX_H = 1000000000;

const int NUM_OF_RANDOM_CASE = 10;


void random_gen( string name,int n = MAX_N, int m = MAX_M,int max_h = MAX_H ){
  ofstream out( name );
  out << n << " " << m << endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if( j ) out << " ";
      out << rnd.next( MIN_H, MAX_H );
    }
    out << endl;
  }
  out.close();
}

int main(int argc, char *argv[])
{
  registerGen(argc, argv, 1);

  for(int t = 0; t < NUM_OF_RANDOM_CASE; t++ ){
    random_gen( format("50_random_%02d.in", t+1),
                rnd.next( MIN_N, MAX_N ), rnd.next( MIN_M, MAX_M ), rnd.next(MIN_H,MAX_H) );
  }
  for(int t = 0; t < NUM_OF_RANDOM_CASE; t++ ){
    random_gen( format("60_random_%02d.in", t+1),
                MAX_N, rnd.next( MIN_M, MAX_M ) );
  }
  for(int t = 0; t < NUM_OF_RANDOM_CASE; t++ ){
    random_gen( format("70_random_%02d.in", t+1),
                MAX_N, rnd.next( MIN_M, MAX_M ), 30 );
  }
   
  return 0;
}
