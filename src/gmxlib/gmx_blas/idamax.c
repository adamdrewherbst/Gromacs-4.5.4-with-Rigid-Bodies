#include <math.h>
#include "gmx_blas.h"

int
F77_FUNC(idamax,IDAMAX)(int *n,
                        double *dx,
                        int *incx)
{
  int i,ix,idxmax;
  double dmax,tmp;

  if(*n<1 || *incx<=0)
    return -1;

  if(*n==1)
    return 1;

  dmax = fabs(dx[0]);
  idxmax = 1;

  if(*incx==1) {
    for(i=1;i<*n;i++) {
      tmp = fabs(dx[i]);
      if(tmp>dmax) {
	dmax = tmp;
	idxmax = i+1;
      }
    }
  } else {
    /* Non-unit increments */
    ix = *incx; /* this is really 0 + an increment */
    for(i=1;i<*n;i++,ix+=*incx) {
      tmp = fabs(dx[ix]);
      if(tmp>dmax) {
	dmax = tmp;
	idxmax = ix+1;
      }
    }    
  }
  return idxmax;
}