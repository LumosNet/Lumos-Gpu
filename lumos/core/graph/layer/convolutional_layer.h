#ifndef CONVOLUTIONAL_LAYER_H
#define CONVOLUTIONAL_LAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "layer.h"
#include "cfg_f.h"
#include "image.h"
#include "active.h"
#include "bias.h"
#include "gemm.h"
#include "cpu.h"
#include "weights.h"

#ifdef GPU
#include "convolutional_layer_gpu.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

Layer *make_convolutional_layer(int filters, int ksize, int stride, int pad, int bias, int normalization, char *active, char *weights_init);

void init_convolutional_layer(Layer *l, int w, int h, int c);
void init_convolutional_weights(Layer *l);

void forward_convolutional_layer(Layer l, int num);
void backward_convolutional_layer(Layer l, float rate, int num, float *n_delta);

void update_convolutional_layer(Layer l, float rate, int num, float *n_delta);

#ifdef __cplusplus
}
#endif

#endif