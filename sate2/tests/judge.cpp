// WIP あとで構築をつけるかも

#include <bits/stdc++.h>
#include "testlib.h"

const int MIN_N = 1;
const int MAX_N = 100;
const int MIN_M = 1;
const int MAX_M = 100;
const int MIN_H = 1;
const int MAX_H = 1000000000;

int N,M;
int H[MAX_N+1][MAX_M+1];
bool validate_input( string name ) {
  registerValidation( name );
  N = inf.readInt( MIN_N, MAX_N, "N" );
  inf.readSpace();
  M = inf.readInt( MIN_N, MAX_N, "M" );
  inf.readEoln();
  
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if( j ) inf.readSpace();
      H = inf.readInt( MIN_H, MAX_H, "H" );
    }
    inf.readEoln();
  }
  inf.readEof();
}

int res1,res2;
bool validate_diff( string name ){
  res_min_h = MAX_H; res_max_h = 0;
  bool flag[111] = {};
  int cnt[111] = {};
  registerValidation( name );
  for(int i=0;i<M;i++){
    int a, b;
    a = inf.readInt( MIN_N, N, "a" );
    inf.readSpace();
    b = inf.readInt( MIN_M, M, "b" );
    inf.readEoln();
    cnt[a]++;
    if( f[b] ) return false;
    f[b] = true;
    res_min_h = min( res_min_h, H[a][b] );
    res_max_h = max( res_max_h, H[a][b] );
  }
  inf.readEof();
  for(int i=0;i<N;i++)
    
  return true;
}

bool judge_output( string name ){
  bool flag[111] = {};
  int cnt[111] = {};
  int min_h = MAX_H, max_h = 0;
  registerValidation( name );
  for(int i=0;i<M;i++){
    int a, b;
    a = inf.readInt( MIN_N, N, "a" );
    inf.readSpace();
    b = inf.readInt( MIN_M, M, "b" );
    inf.readEoln();
    cnt[a]++;
    if( f[b] ) return false;
    f[b] = true;
    min_h = min( min_h, H[a][b] );
    max_h = max( max_h, H[a][b] );
  }
  inf.readEof();

  if( max_h - min_h != res_max_h - res_min_h ) return false;
  
  
}

int main(int argc, char** argv)
{
    if (argc < 4) {
        fprintf(stdout, "insufficient number of command line args\n");
        return 1;
    }

    char sInFile[MAX_FILE_NAME_LENG];
    char sDiffFile[MAX_FILE_NAME_LENG];
    char sOutFile[MAX_FILE_NAME_LENG];

    FILE *fpDiff = fopen(argv[4], "r");
    if (!fpDiff) {
        fprintf(stdout, "failed to open diff %s\n", argv[4]);
        return 1;
    }

    FILE *fpOut = fopen(argv[6], "r");
    if (!fpOut) {
        fprintf(stdout, "failed to open out %s\n", argv[6]);
        fclose(fpDiff);
        return 1;
    }

    char diff_cs[MAX_DOUBLE_LEN];
    fscanf(fpDiff, "%s", diff_cs);
    fclose(fpDiff);

    char out_cs[MAX_DOUBLE_LEN];
    fscanf(fpOut, "%s", out_cs);
    fclose(fpOut);

    if(strcmp(diff_cs, out_cs) == 0) {
      return 0;
    }

    std::string diff_str = diff_cs;
    std::string out_str = out_cs;

    if(!validate_double(diff_str)) {
      ensuref(false, "judge validation failed. judge value is not double.");
    }

    if(!validate_double(out_str)) {
      return 1;
    }

    double diff = stod(diff_str);
    double out = stod(out_str);

    if(fabs( diff - out ) <= EPS) {
        return 0;
    }
    
    return 1;
}
