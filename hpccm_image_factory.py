#!/usr/bin/env python


from distutils.version import StrictVersion
import hpccm


Stage0 = hpccm.Stage()


Stage0 += hpccm.primitives.baseimage(image='nvcr.io/nvidia/pytorch:22.04-py3')

NVHPC = hpccm.building_blocks.nvhpc( eula=True,
               cuda='11.6',
               version='22.3',
               cuda_multi=False,
               mpi=True,
               environment=True,
               extended_environment=True,
            #    ospackages=[ 'gcc-offload-nvptx',\
            #                 'bc', \
            #                 'debianutils',\
            #                 'g++', \
            #                 'gcc', \
            #                 'gfortran', \
            #                 'libatomic1', \
            #                 'libnuma1', \
            #                 'openssh-client', \
            #                 'wget' ],
               ospackages=[ 'debianutils',\
                            'openssh-client', \
                            'wget' ],            
               tarball=True)
Stage0 += NVHPC

    
print(Stage0)
 
