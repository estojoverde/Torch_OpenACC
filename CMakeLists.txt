cmake_minimum_required(VERSION 3.10)
set (LANGUAGES "CXX")


project(openacc_torched LANGUAGES ${LANGUAGES})



add_definitions("-DENABLE_SSE")


find_package(Torch REQUIRED)
find_package(OpenACC REQUIRED)




set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenACC_CXX_FLAGS} ${TORCH_CXX_FLAGS} ")#-Minfo=accel")




add_executable(main main.cpp)
target_link_libraries(main "${TORCH_LIBRARIES}")
target_link_libraries(main "${TORCH_CUDA_LIBRARIES}") # <-- add this line


target_link_libraries(main ${OpenACC_CXX_OPTIONS})

set_property(TARGET main PROPERTY CXX_STANDARD 14)

