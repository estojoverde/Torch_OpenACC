#include <iostream>

#include <torch/torch.h>
#include <c10/cuda/CUDAStream.h>
#include <openacc.h>
#include <cmath>

#include <sys/wait.h>
#include <unistd.h>


/* matrix-sum-acc.c */
#define SIZE 10000
float a[SIZE][SIZE];
float b[SIZE][SIZE];
float c[SIZE][SIZE];

int main() {

  int i,j;
  pid_t c_pid = fork();

  if (c_pid == -1) {
      perror("fork");
      exit(EXIT_FAILURE);
  } else if (c_pid > 0) {
  
      torch::Device device = torch::kCUDA;
      if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Training on GPU." << std::endl;
      }
      else {
        std::cout << "CUDA IS NOT AVAILABLE!!" << std::endl;
      }
      torch::Tensor tensor = torch::eye(3);
      torch::Tensor t = tensor.to(device);
      std::cout << t << std::endl;

      std::cout << "printed from parent process " << getpid() << std::endl;
      wait(nullptr);
  } else {
     // Initialize matrices.
      for (i = 0; i < SIZE; ++i) {
         for (j = 0; j < SIZE; ++j) {
            a[i][j] = (float)i + j;
            b[i][j] = (float)i - j;
            c[i][j] = 0.0f;
          }
       }

     // Compute matrix sum.
     #pragma acc kernels copyin(a,b) copy(c)
     for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
           c[i][j] = a[i][j] + b[i][j];
        }
     }

     std::cout << "printed from child process " << getpid() << std::endl;
     exit(EXIT_SUCCESS);
  }

 
  return 0;
}
