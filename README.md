# Libtorch_OpenACC
Repo for Libtorch and OpenACC mixed code experiment

-----

## Steps to Reproduce Experiment

1) Ideally, code should be compiled inside the image provided by image_factory.py

It uses hpccm (https://github.com/NVIDIA/hpc-container-maker) to generate a Dockerfile.


2) If inside the container provided in this repo, one only need to call cmake on build folder as in 


```
cmake -DCMAKE_PREFIX_PATH=`python -c 'import torch;print(torch.utils.cmake_prefix_path)'` -DCUDA_TOOLKIT_ROOT_DIR=/usr/local/cuda/ ../ 
```

3) And finally call make


```
make
```
