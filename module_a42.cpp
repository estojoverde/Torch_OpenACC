#include "module_a42.h"



int addvector_cab(void)
{
    
    int i;
    float a[50];
    float b[50];
    float c[50];
    int n=50;

    for( i=0; i<n; i++)
    {
        a[i] = 1;
        b[i] = 1;
        c[i] = 0;
    }
    
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
