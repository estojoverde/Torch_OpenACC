FROM nvcr.io/nvidia/pytorch:22.04-py3

# NVIDIA HPC SDK version 22.3
RUN apt-get update -y && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        bc \
        debianutils \
        g++ \
        gcc \
        gcc-offload-nvptx \
        gfortran \
        libatomic1 \
        libnuma1 \
        openssh-client \
        wget && \
    rm -rf /var/lib/apt/lists/*
RUN mkdir -p /var/tmp && wget -q -nc --no-check-certificate -P /var/tmp https://developer.download.nvidia.com/hpc-sdk/22.3/nvhpc_2022_223_Linux_x86_64_cuda_11.6.tar.gz && \
    mkdir -p /var/tmp && tar -x -f /var/tmp/nvhpc_2022_223_Linux_x86_64_cuda_11.6.tar.gz -C /var/tmp -z && \
    cd /var/tmp/nvhpc_2022_223_Linux_x86_64_cuda_11.6 && NVHPC_ACCEPT_EULA=accept NVHPC_DEFAULT_CUDA=11.6 NVHPC_INSTALL_DIR=/opt/nvidia/hpc_sdk NVHPC_SILENT=true ./install && \
    rm -rf /var/tmp/nvhpc_2022_223_Linux_x86_64_cuda_11.6 /var/tmp/nvhpc_2022_223_Linux_x86_64_cuda_11.6.tar.gz
ENV CC=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/bin/nvc \
    CPATH=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/nvshmem/include:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/nccl/include:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/extras/qd/include/qd:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/math_libs/include:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/mpi/include:$CPATH \
    CPP=cpp \
    CXX=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/bin/nvc++ \
    F77=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/bin/nvfortran \
    F90=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/bin/nvfortran \
    FC=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/bin/nvfortran \
    LD_LIBRARY_PATH=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/nvshmem/lib:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/nccl/lib:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/math_libs/lib64:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/lib:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/cuda/lib64:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/mpi/lib:$LD_LIBRARY_PATH \
    MANPATH=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/man:$MANPATH \
    PATH=/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/nvshmem/bin:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/nccl/bin:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/profilers/bin:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/compilers/bin:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/cuda/bin:/opt/nvidia/hpc_sdk/Linux_x86_64/22.3/comm_libs/mpi/bin:$PATH
