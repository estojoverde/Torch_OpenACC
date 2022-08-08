#pragma once

#ifndef __MODULE_A42_H_INCLUDED__
#define __MODULE_A42_H_INCLUDED__

#include <iostream>
#include <string>
#include "openacc.h"
#include "stdlib.h"

#include <cstdlib>
#include <stdexcept>
#include <execinfo.h>



void handler( void );



int addvector_cab(void);

extern "C" {

    int wrapper_add(void);
}

#endif

