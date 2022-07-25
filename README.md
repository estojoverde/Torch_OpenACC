
# Torch_OpenACC


This repository was created to attempt a sinergy between Pytorch and OpenACC.

This particular branch uses ctypes to bind a C code (OpenACC) in Python, where PyTorch is invoked.




## Reproducibility

1) Containerization
Ideally, code should be compiled and run inside the image provided by hpccm_image_factory.py
It uses hpccm (https://github.com/NVIDIA/hpc-container-maker) to generate a Dockerfile.

2) Create Conda Environment

```
conda create --name exp01 python=3.8

conda activate exp01

conda install pytorch torchvision torchaudio cudatoolkit=11.6 -c pytorch -c conda-forge

conda install cupy

```
3) OpenACC Compiling'

It should be straightforward.

```
make
```

4) Running Python code

```
python bind.py
```


## Expected Outputs

One should expect:

```
<built-in method malloc of cupy.cuda.memory.MemoryPool object at 0x7ff636426860>
ENTERED C FUNCTION!
EXITING C FUNCTION!
0
Valor de c: [2. 2. 2. 2. 2. 2. 2. 2. 2. 2.]
Valor de b: [1. 1. 1. 1. 1. 1. 1. 1. 1. 1.]
Valor de a: [1. 1. 1. 1. 1. 1. 1. 1. 1. 1.]
```


However, importing PyTorch in bind.py (uncommeting line 5, and nothing else changed) and running again, it returns:

```
<built-in method malloc of cupy.cuda.memory.MemoryPool object at 0x7fa28de86860>
ENTERED C FUNCTION!

libgomp: TODO
```
