// alloc utilities :( OMG I definitely did not miss C...

#include <stdlib.h> // malloc, free

void initDoubleVec(double *vec, int size, double defval) {
  for (int i=0; i<size; i++) vec[i] = defval;
}

void initIntVec(int *vec, int size, int defval) {
  for (int i=0; i<size; i++) vec[i] = defval;
}

int* allocIntVec(int size, int defval) {
  int *ret = (int*)malloc(size * sizeof(int));
  initIntVec(ret, size, defval);
  return ret;
}

double* allocDoubleVec(int size, double defval) {
  double *ret = (double*)malloc(size * sizeof(double));
  initDoubleVec(ret, size, defval);
  return ret;
}

double** allocMat(int nrows, int ncols, double defval) {
  double **ret = (double**)malloc(nrows * sizeof(double*));
  for (int r=0; r<nrows; r++)
    ret[r] = allocDoubleVec(ncols, defval);
  return ret;
}

double** copyMat(double **orig, int nrows, int ncols) {
  double **ret = allocMat(nrows, ncols, 0);
  for (int r=0; r<nrows; r++)
    for (int c=0; c<ncols; c++)
      ret[r][c] = orig[r][c];
  return ret;
}
