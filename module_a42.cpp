#include "module_a42.h"



int addvector_cab(float* a, float* b, float* c, int n)
{
    
    int i; 
    printf("ENTERED C FUNCTION!\n");

    if( n == 0 ){
        printf("DUMMY ERROR!\n");
        printf("EXITING C FUNCTION!\n");
        return(1);
    }
    
    #pragma acc parallel loop present_or_copyin(a,b) present_or_copyout(c)
    for(i = 0; i < n; i++){
        c[i] = a[i] + b[i];
    }

    printf("EXITING C FUNCTION!\n");
    return(0);
}
