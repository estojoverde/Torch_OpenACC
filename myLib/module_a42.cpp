#include <string>
#include "openacc.h"
#include "stdlib.h"

#include "module_a42.h"


void Foo::bar(){
    std::cout << "Hello" << std::endl;
}


float Foo::sum( float a, float b ){
    return(a+b);
}


float Foo::cpp_compute_mean(float* A, int n)
{
    int i;
    float sum = 0.0f;
    std::cout << "N = "<< n << std::endl;
    for(i=0; i<n; ++i){
        std::cout << "A[" << i << "]= "<< A[i] << std::endl;
        sum += A[i];
    }
    return sum/n;
}

void Foo::step(float* A, int n, float step, uint8_t verbose)
{
    
    if(verbose)
        std::cout << "N = "<< n << std::endl;
    for(register int i=0; i<n; ++i){
        std::string bef = "before A[" + std::to_string(i) + "]= " + std::to_string(*(A+ i)) ;
            
        //*(A+(sizeof(float)*i)) = *(A+(sizeof(float)*i)) + step;
        *(A+i) = *(A+i) + step;
        std::string aft = "after A[" + std::to_string(i) + "]= " + std::to_string(*(A+ i)) ;
        // std::cout << "after A[" << i << "]= "<< *(A+sizeof(float)*i)  << std::endl;
        
        if(verbose)
            std::cout << bef << " |\t " << aft << std::endl;
    }

    return;
}


void Foo::step_openacc(float* A, int n, float step, uint8_t verbose)
{

    // int ngpus = acc_get_num_devices(acc_device_nvidia);
    // int devicenum = 0;
    // acc_set_device_num(devicenum,acc_device_nvidia);
    // acc_init(acc_device_nvidia);

    //#pragma acc enter data copyin(A[0:n])
    //std::cout << A[0] << std::endl;
        
    
    #pragma acc parallel loop
    //#pragma acc kernels
    for(int i=0; i<n; ++i)
    {
        //*(A+i) = *(A+i) + step;
        A[i] = A[i] + step;
    }

    //#pragma acc kernels end

    //#pragma acc exit data copyout(A[0:n])
    //#pragma acc exit data delete(A[0:n]) //if(devicerm)

    return;
}


void Foo::step_openacc2(void)
{

    // int ngpus = acc_get_num_devices(acc_device_nvidia);
    // int devicenum = 0;
    // acc_set_device_num(devicenum,acc_device_nvidia);
    // acc_init(acc_device_nvidia);

    //#pragma acc enter data copyin(A[0:n])
    //std::cout << A[0] << std::endl;
    float A[50];
    int n =50;
    float step = 1.5874;

    for(int i=0; i<n; ++i)
    {
        //*(A+i) = *(A+i) + step;
        A[i] = i;
    }
    
    #pragma acc parallel loop
    //#pragma acc kernels
    for(int i=0; i<n; ++i)
    {
        //*(A+i) = *(A+i) + step;
        A[i] = A[i] + step;
    }

    for( register int i=0; i<n; ++i)
    {
        std::cout << A[i] << std::endl;
    }

    //#pragma acc kernels end

    //#pragma acc exit data copyout(A[0:n])
    //#pragma acc exit data delete(A[0:n]) //if(devicerm)

    return;
}



void step_openacc2(void)
{

    // int ngpus = acc_get_num_devices(acc_device_nvidia);
    // int devicenum = 0;
    // acc_set_device_num(devicenum,acc_device_nvidia);
    // acc_init(acc_device_nvidia);

    //#pragma acc enter data copyin(A[0:n])
    //std::cout << A[0] << std::endl;
    float A[50];
    int n =50;
    float step = 1.5874;

    for(int i=0; i<n; ++i)
    {
        //*(A+i) = *(A+i) + step;
        A[i] = i;
    }
    
    #pragma acc parallel loop
    //#pragma acc kernels
    for(int i=0; i<n; ++i)
    {
        //*(A+i) = *(A+i) + step;
        A[i] = A[i] + step;
    }

    for( register int i=0; i<n; ++i)
    {
        std::cout << A[i] << std::endl;
    }

    //#pragma acc kernels end

    //#pragma acc exit data copyout(A[0:n])
    //#pragma acc exit data delete(A[0:n]) //if(devicerm)

    return;
}

int addvector_cab(float* a, float* b, float* c, int n)
{
    
    int i; 
    printf("ENTREI!\n");
    
    //#pragma acc parallel loop present_or_copyin(a,b) present_or_copyout(c)
    //#pragma acc parallel loop present(a,b,c)
    #pragma acc parallel loop 
    for(i = 0; i < n; i++){
        c[i] = a[i] + b[i];
    }

    printf("TO SAINDO!!\n");
    return(0);
}


void plusone(float* a, float* b, int n) {
    
    int i; 
    #pragma acc parallel loop present(a,b)
    for(i = 0; i < n; i++){
        a[i] = a[i] + b[i];
    }
}




// float cpp_compute_mean(float* A, int n)
// {
//     int i;
//     float sum = 0.0f;
//     std::cout << "N = "<< n << std::endl;
//     for(i=0; i<n; ++i)
//         std::cout << "A[" << i << "]= "<< A[i] << std::endl;
//         sum += A[i];
//     return sum/n;
// }




// int main( void)
// {
//     float v[20];

//     for( register int i=0; i<20; ++i)
//     {
//         v[i] = i;
//     }

//     Foo f;

//     f.step_openacc(v, 20, 1.35, 0);


//     for( register int i=0; i<20; ++i)
//     {
//         std::cout << v[i] << std::endl;
//     }
    
//     return(0);


// }


int main( void)
{

    step_openacc2();


    return(0);


}
