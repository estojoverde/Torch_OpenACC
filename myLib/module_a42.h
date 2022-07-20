#pragma once

#ifndef __MODULE_A42_H_INCLUDED__
#define __MODULE_A42_H_INCLUDED__

#include <iostream>
#include <string>
#include "openacc.h"
#include "stdlib.h"


class Foo{
    public:
        void bar();
        float sum( float a, float b );
        float cpp_compute_mean(float* A, int n);
        void step(float* A, int n, float step, uint8_t verbose);
        void step_openacc(float* A, int n, float step, uint8_t verbose);
        void step_openacc2(void);

};




//float cpp_compute_mean(float* A, int n);






extern "C" {
    Foo* Foo_new(){ return new Foo(); }
    void Foo_bar(Foo* foo){ foo->bar(); }
    float Foo_sum(Foo* foo, float a, float b){ return(foo->sum(a,b)); }
    //float compute_mean(float* A, int n){ return(cpp_compute_mean(A, n) ); }
    float Foo_mean(Foo* foo, float* A, int n){ return(foo->cpp_compute_mean(A, n) ); }
    void Foo_step(Foo* foo, float* A, int n, float step, uint8_t verbose){  foo->step(A, n, step, verbose);  }
    void Foo_step_openacc(Foo* foo, float* A, int n, float step, uint8_t verbose){  foo->step_openacc(A, n, step, verbose);  }
    void Foo_step_openacc2(Foo* foo){  foo->step_openacc2();  }
    void step_openacc2(void);

    int addvector_cab(float* a, float* b, float* c, int n);
    void plusone(float* a, float* b, int n);

}

#endif

