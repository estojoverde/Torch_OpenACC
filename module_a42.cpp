#include "module_a42.h"

void handler( void )
{
    void *trace_elems[20];
    int trace_elem_count(backtrace( trace_elems, 20 ));
    char **stack_syms(backtrace_symbols( trace_elems, trace_elem_count ));
    for ( int i = 0 ; i < trace_elem_count ; ++i )
    {
        std::cout << stack_syms[i] << "\n";
    }
    free( stack_syms );

    exit(1);
}  


int wrapper_add(void)
{
    std::set_terminate( handler );
    int ret;
    ret = addvector_cab();

    return(ret);
}

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
