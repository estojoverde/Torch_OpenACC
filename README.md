
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

conda install pytorch==<1.12.0 torchvision==<0.13.0 torchaudio==<0.13.0 cudatoolkit=11.6 -c pytorch -c conda-forge

conda install cupy==<10.4.0

```

3) OpenACC Compiling


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
ENTERED C FUNCTION!
EXITING C FUNCTION!
Returned OKAY!
```


However, importing PyTorch in bind.py (uncommeting line 5, nothing else changed) and running again, it returns:

```
ENTERED C FUNCTION!

libgomp: TODO
```
