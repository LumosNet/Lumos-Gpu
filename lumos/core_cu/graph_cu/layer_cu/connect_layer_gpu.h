#ifndef CONNECT_LAYER_GPU_H
#define CONNECT_LAYER_GPU_H

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include "curand.h"
#include "cublas_v2.h"

#include <stdio.h>
#include <stdlib.h>
#include "gpu.h"
#include "layer.h"
#include "active_gpu.h"
#include "bias_gpu.h"
#include "cpu_gpu.h"
#include "gemm_gpu.h"

#ifdef __cplusplus
extern "C" {
#endif

void forward_connect_layer_gpu(Layer l, int num);
void backward_connect_layer_gpu(Layer l, float rate, int num, float *n_delta);

void update_connect_layer_gpu(Layer l, float rate, int num, float *n_delta);

#ifdef __cplusplus
}
#endif
#endif
